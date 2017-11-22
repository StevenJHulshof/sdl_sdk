#include "World.h"

World::World():
    Container(),
    GameObjectUnionUtility(),
    camera(CAMERA_OFFSET_X_START, CAMERA_OFFSET_Y_START)
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    generator.fillGrid(_tileGrid, TEXTURE_TILE_GRASS_0000);
    generator.fillGrid(_playableGrid, TEXTURE_TYPE_EMPTY);
    generator.generatePatch(_tileGrid, TEXTURE_TILE_SAND_0000, 40, 20);
    generator.generatePatch(_tileGrid, TEXTURE_TILE_WATER_0000, 40, 20);
    generator.generatePatch(_playableGrid, TEXTURE_RESOURCE_RAW_WOOD, 10, 50, _tileGrid, TEXTURE_TILE_GRASS_0000);
    generator.generatePatch(_playableGrid, TEXTURE_RESOURCE_RAW_STONE, 5, 10, _tileGrid, TEXTURE_TILE_GRASS_0000);  

    for(int x = 0; x < TILE_GRID_X; x++) 
    {
        for(int y = 0; y < TILE_GRID_Y; y++) 
        {
            if(_playableGrid[x][y] == TEXTURE_RESOURCE_RAW_WOOD)
            {
                GameObjectUnion<World> gameObjectUnion;
                gameObjectUnion.rawWood = new RawWood<World>(x, y);
                setGameObjectUnion(&gameObjectUnion, GAME_OBJECT_RAW_WOOD, this);
                _playablePool.push_back(gameObjectUnion);
            }
            if(_playableGrid[x][y] == TEXTURE_RESOURCE_RAW_STONE)
            {
                GameObjectUnion<World> gameObjectUnion;
                gameObjectUnion.resource = new Resource<World>(x, y, _playableGrid[x][y]);
                setGameObjectUnion(&gameObjectUnion, GAME_OBJECT_RESOURCE, this);
                _playablePool.push_back(gameObjectUnion);
            }
            
            GameObjectUnion<World> gameObjectUnion;
            gameObjectUnion.tile = new Tile<World>(x, y, _tileGrid[x][y]);
            setGameObjectUnion(&gameObjectUnion, GAME_OBJECT_TILE, this);
            _tilePool.push_back(gameObjectUnion);
        }
    }
    
    for(int i = 0; i < 100; i++)
    {
        int xRand = rand() % TILE_GRID_X;
        int yRand = rand() % TILE_GRID_Y;
        if(_tileGrid[xRand][yRand] != TEXTURE_TILE_WATER_0000 && _playableGrid[xRand][yRand] == TEXTURE_TYPE_EMPTY)
        {
            GameObjectUnion<World> gameObjectUnion;
            gameObjectUnion.warrior = new Warrior<World>(xRand, yRand);
            setGameObjectUnion(&gameObjectUnion, GAME_OBJECT_WARRIOR, this);
            _playablePool.push_back(gameObjectUnion);
        }
    }

    _objectPool.push_back(_tilePool);
    _objectPool.push_back(_playablePool);
}

World::~World() {
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

void World::update() 
{
    camera.update();
    
    int offsetX, offsetY;
    float zoom;
    
    camera.template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_X, &offsetX);
    camera.template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_Y, &offsetY);
    camera.template send<int, float>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_ZOOM, &zoom);
    
    for(size_t i = 0; i < _objectPool.size(); i++)
    {
        for(size_t l = 0; l < _objectPool[i].size(); l++) 
        {
            sendToGameObjectUnion<GameObjectUnion<World>, int, int>(&_objectPool[i][l], MSG_SET_GRAPHICS_OFFSET_X, offsetX);
            sendToGameObjectUnion<GameObjectUnion<World>, int, int>(&_objectPool[i][l], MSG_SET_GRAPHICS_OFFSET_Y, offsetY);
            sendToGameObjectUnion<GameObjectUnion<World>, float, int>(&_objectPool[i][l], MSG_SET_GRAPHICS_ZOOM, zoom);
            updateGameObjectUnion(&_objectPool[i][l]);
            
            if(fastSendToGameObjectUnion<GameObjectUnion<World>, int, bool>(&_objectPool[i][l], MSG_GET_INPUT, MSG_DATA_INPUT_SELECTED))
            {
                selection.addSelectedCandidate(&_objectPool[i][l]);
            }
            if(fastSendToGameObjectUnion<GameObjectUnion<World>, int, bool>(&_objectPool[i][l], MSG_GET_INPUT, MSG_DATA_INPUT_HOVERED))
            {
                selection.addHoveredCandidate(&_objectPool[i][l]);
            }
        }
        
        sortGameObjects(_objectPool[i]);
    }
    
   selection.update();
}

void World::render() 
{    
    for(size_t i = 0; i < _objectPool.size(); i++)
    {
        for(int l = _objectPool[i].size() - 1; l >= 0; l--)
        {
            renderGameObjectUnion<GameObjectUnion<World>>(&_objectPool[i][l]);
        }  
    }
    
    selection.render();
    gTextTexture.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, 1);
}

void World::sortGameObjects(std::vector<GameObjectUnion<World>> &objectPool)
{
    for(size_t i = 1; i < objectPool.size(); i++) 
    {
        GameObjectUnion<World> index = objectPool[i];
        int j = i - 1;
        int indexScreenPosY;
        sendToGameObjectUnion<GameObjectUnion<World>, int, int>(&index, MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_Y, &indexScreenPosY);
        
        for(;j >= 0 && fastSendToGameObjectUnion<GameObjectUnion<World>, int, int>(&objectPool[j], MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_Y) < indexScreenPosY; j--)
        {
            objectPool[j + 1] = objectPool[j];
            
        }
        objectPool[j + 1] = index;
    }
}
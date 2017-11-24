#include "World.h"

World::World():
    Container(),
    GameObjectUnionUtility(),
    grassTile(0, 0, WORLD_TILE_GRASS, TEXTURE_TILE_GRASS_0000),
    sandTile(0, 0, WORLD_TILE_SAND, TEXTURE_TILE_SAND_0000),
    waterTile(0, 0, WORLD_TILE_WATER, TEXTURE_TILE_WATER_0000),
    camera(CAMERA_OFFSET_X_START, CAMERA_OFFSET_Y_START)
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    DEBUG_FUN_VAR("%p | START | %s\n", this, __PRETTY_FUNCTION__);

    generator.fillGrid(_tileGrid, WORLD_TILE_GRASS);
    generator.fillGrid(_playableGrid, WORLD_EMPTY);
    generator.generatePatch(_tileGrid, WORLD_TILE_SAND, 40, 20);
    generator.generatePatch(_tileGrid, WORLD_TILE_WATER, 40, 20);
    generator.generatePatch(_playableGrid, WORLD_RESOURCE_RAW_WOOD, 10, 50, _tileGrid, WORLD_TILE_GRASS);
    generator.generatePatch(_playableGrid, WORLD_RESOURCE_RAW_STONE, 5, 10, _tileGrid, WORLD_TILE_GRASS);  
    
    for(int x = 0; x < TILE_GRID_X; x++) 
    {
        for(int y = 0; y < TILE_GRID_Y; y++) 
        {
            GameObjectUnion<World> gameObjectUnion;
            if(_playableGrid[x][y] == WORLD_RESOURCE_RAW_WOOD)
            {
                gameObjectUnion.rawWood = new RawWood<World>(x, y);
                setGameObjectUnion(&gameObjectUnion, GAME_OBJECT_RAW_WOOD, this);
                _playablePool.push_back(gameObjectUnion);
            }
            if(_playableGrid[x][y] == WORLD_RESOURCE_RAW_STONE)
            {
                gameObjectUnion.resource = new Resource<World>(x, y, WORLD_RESOURCE_RAW_STONE, TEXTURE_RESOURCE_RAW_STONE);
                setGameObjectUnion(&gameObjectUnion, GAME_OBJECT_RESOURCE, this);
                _playablePool.push_back(gameObjectUnion);
            }
        }
    }
    
    for(int i = 0; i < 100; i++)
    {
        int xRand = rand() % TILE_GRID_X;
        int yRand = rand() % TILE_GRID_Y;
        if(_tileGrid[xRand][yRand] != WORLD_TILE_WATER && _playableGrid[xRand][yRand] == WORLD_EMPTY)
        {
            GameObjectUnion<World> gameObjectUnion;
            gameObjectUnion.warrior = new Warrior<World>(xRand, yRand);
            setGameObjectUnion(&gameObjectUnion, GAME_OBJECT_WARRIOR, this);
            _playablePool.push_back(gameObjectUnion);
        }
    }
    
    _objectPool.push_back(_playablePool);
    DEBUG_FUN_VAR("%p | STOP | %s\n", this, __PRETTY_FUNCTION__);
}

World::~World() {
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

void World::update() 
{
    DEBUG_FUN_VAR("%p | START | %s\n", this, __PRETTY_FUNCTION__);
    
    camera.update();
    
    int offsetX, offsetY;
    float zoom;
    
    camera.template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_X, &offsetX);
    camera.template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_Y, &offsetY);
    camera.template send<int, float>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_ZOOM, &zoom);
    
    // FlyWeight
    grassTile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, offsetX);
    grassTile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, offsetY);
    grassTile.update();
    
    sandTile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, offsetX);
    sandTile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, offsetY);
    sandTile.update();
    
    waterTile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, offsetX);
    waterTile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, offsetY);
    waterTile.update();
 
    // GameObjects
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
              //  selection.addSelectedCandidate(&_objectPool[i][l]);
            }
            if(fastSendToGameObjectUnion<GameObjectUnion<World>, int, bool>(&_objectPool[i][l], MSG_GET_INPUT, MSG_DATA_INPUT_HOVERED))
            {
                selection.addHoveredCandidate(&_objectPool[i][l]);
            }
        }

        sortGameObjects(_objectPool[i]);
    }
    //selection.update();
    DEBUG_FUN_VAR("%p | STOP | %s\n", this, __PRETTY_FUNCTION__);
}

void World::render() 
{    
    for(int x = 0; x < TILE_GRID_X; x++) 
    {
        for(int y = 0; y < TILE_GRID_Y; y++) 
        {
            switch(_tileGrid[x][y])
            {
                case WORLD_TILE_GRASS:
                grassTile.render(x, y);
                break;
                
                case WORLD_TILE_SAND:
                sandTile.render(x, y);
                break;

                case WORLD_TILE_WATER:
                waterTile.render(x, y);
                break;                

                default:
                break;
            }
        }
    }
    DEBUG_FUN_VAR("%p | START | %s\n", this, __PRETTY_FUNCTION__);
    for(size_t i = 0; i < _objectPool.size(); i++)
    {
        for(int l = _objectPool[i].size() - 1; l >= 0; l--)
        {
            renderGameObjectUnion<GameObjectUnion<World>>(&_objectPool[i][l]);
        }  
    }
    
    selection.render();
    gTextTexture.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, 1);
    DEBUG_FUN_VAR("%p | STOP  | %s\n", this, __PRETTY_FUNCTION__);
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
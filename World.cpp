#include "World.h"

bool pre = true;
bool post = false;

World::World():
    Container(),
    camera(CAMERA_OFFSET_X_START, CAMERA_OFFSET_Y_START)
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    generator.fillGrid(_tileGrid, TEXTURE_TILE_GRASS_0000);
    generator.fillGrid(_resourceGrid, TEXTURE_TYPE_EMPTY);
    generator.generatePatch(_tileGrid, TEXTURE_TILE_SAND_0000, 40, 20);
    generator.generatePatch(_tileGrid, TEXTURE_TILE_WATER_0000, 40, 20);
    generator.generatePatch(_resourceGrid, TEXTURE_RESOURCE_WOOD, 10, 50, _tileGrid, TEXTURE_TILE_GRASS_0000);
    generator.generatePatch(_resourceGrid, TEXTURE_RESOURCE_STONE, 5, 10, _tileGrid, TEXTURE_TILE_GRASS_0000);
  

    for(int x = 0; x < TILE_GRID_X; x++) 
    {
        for(int y = 0; y < TILE_GRID_Y; y++) 
        {
            if(_resourceGrid[x][y] != TEXTURE_TYPE_EMPTY)
            {
                GameObjectUnion<World> gameObjectUnion;
                gameObjectUnion.resource = new Resource<World>(x, y, _resourceGrid[x][y]);
                gameObjectUnion.resource->setContainer(this);
                gameObjectUnion.tag = GAME_OBJECT_RESOURCE;
                _playablePool.push_back(gameObjectUnion);
            }
            
            GameObjectUnion<World> gameObjectUnion;
            gameObjectUnion.tile = new Tile<World>(x, y, _tileGrid[x][y]);
            gameObjectUnion.tile->setContainer(this);
            gameObjectUnion.tag = GAME_OBJECT_TILE;
            _tilePool.push_back(gameObjectUnion);
        }
    }
    
    for(int i = 0; i < 100; i++)
    {
        int xRand = rand() % TILE_GRID_X;
        int yRand = rand() % TILE_GRID_Y;
        if(_tileGrid[xRand][yRand] != TEXTURE_TILE_WATER_0000 && _resourceGrid[xRand][yRand] == TEXTURE_TYPE_EMPTY)
        {
            GameObjectUnion<World> gameObjectUnion;
            gameObjectUnion.unit = new Unit<World>(xRand, yRand, TEXTURE_UNIT_WARRIOR);
            gameObjectUnion.unit->setContainer(this);
            gameObjectUnion.tag = GAME_OBJECT_UNIT;
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

void World::updateGameObjectUnion(GameObjectUnion<World> *object)
{
    switch(object->tag)
    {
        case GAME_OBJECT_TILE:
        object->tile->update();
        break;
        
        case GAME_OBJECT_RESOURCE:
        object->resource->update();
        break;
        
        case GAME_OBJECT_UNIT:
        object->unit->update();
        break;
        
        default:
        break;
    }
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
            sendToGameObjectUnion<int, int>(&_objectPool[i][l], MSG_SET_GRAPHICS_OFFSET_X, offsetX);
            sendToGameObjectUnion<int, int>(&_objectPool[i][l], MSG_SET_GRAPHICS_OFFSET_Y, offsetY);
            sendToGameObjectUnion<float, int>(&_objectPool[i][l], MSG_SET_GRAPHICS_ZOOM, zoom);
           
            updateGameObjectUnion(&_objectPool[i][l]);
        }
        sortGameObjects(_objectPool[i]);
    }
}

void World::renderGameObjectUnion(GameObjectUnion<World> *object)
{
    switch(object->tag)
    {
        case GAME_OBJECT_TILE:
        object->tile->render();
        break;
        
        case GAME_OBJECT_RESOURCE:
        object->resource->render();
        break;
        
        case GAME_OBJECT_UNIT:
        object->unit->render();
        break;
        
        default:
        break;
    }
}

void World::render() 
{    
    for(size_t i = 0; i < _objectPool.size(); i++)
    {
        for(int l = _objectPool[i].size() - 1; l >= 0; l--)
        {
            renderGameObjectUnion(&_objectPool[i][l]);
        }  
    }
}

void World::sortGameObjects(std::vector<GameObjectUnion<World>> &objectPool)
{
    for(size_t i = 1; i < objectPool.size(); i++) 
    {
        GameObjectUnion<World> index = objectPool[i];
        int j = i - 1;
        int indexScreenPosY;
        sendToGameObjectUnion<int, int>(&index, MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_Y, &indexScreenPosY);
        
        for(;j >= 0 && fastSendToGameObjectUnion<int, int>(&objectPool[j], MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_Y) < indexScreenPosY; j--)
        {
            objectPool[j + 1] = objectPool[j];
            
        }
        objectPool[j + 1] = index;
    }
}
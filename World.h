#pragma once

#include <vector>
#include <deque>
#include "world_types.h"
#include "Container.h"
#include "Tile.h"
#include "Resource.h"
#include "Unit.h"
#include "Camera.h"
#include "Sort.h"
#include "Generator.h"

enum GameObjectUnionTag {
    GAME_OBJECT_TILE, 
    GAME_OBJECT_RESOURCE,
    GAME_OBJECT_UNIT,
    GAME_OBJECT_TOTAL
};

enum {
    WORLD_LAYER_TILES,
    WORLD_LAYER_PLAYABLES,
    WORLD_LAYER_TOTAL
};

template <class con_t>
struct GameObjectUnion{
    enum GameObjectUnionTag tag;
    union {
        Tile<con_t> *tile;
        Resource<con_t> *resource;
        Unit<con_t> *unit;
    };
};

class World: public Container
{
private:
    void renderGameObjectUnion(GameObjectUnion<World> *object);
    void updateGameObjectUnion(GameObjectUnion<World> *object);
    template <class data_t, class response_t>
    void sendToGameObjectUnion(GameObjectUnion<World> *object, int message, data_t data, response_t *response = NULL);
    template <class data_t, class response_t>
    response_t fastSendToGameObjectUnion(GameObjectUnion<World> *object, int message, data_t data);
    void sortGameObjects(std::vector<GameObjectUnion<World>> &objectPool);
    
public:
    World();
    ~World();

    Camera<World> camera;
    Generator generator;
    int _tileGrid[TILE_GRID_X][TILE_GRID_Y];
    int _resourceGrid[TILE_GRID_X][TILE_GRID_Y];
    std::vector<GameObjectUnion<World>> _tilePool;
    std::vector<GameObjectUnion<World>> _playablePool;   
    std::vector<std::vector<GameObjectUnion<World>>> _objectPool;
    
    void update();
    void render();
};

template <class data_t, class response_t>
void World::sendToGameObjectUnion(GameObjectUnion<World> *object, int message, data_t data, response_t *response)
{
    switch(object->tag)
    {
        case GAME_OBJECT_TILE:
        object->tile->template send<data_t, response_t>(message, data, response);
        break;

        case GAME_OBJECT_RESOURCE:
        object->resource->template send<data_t, response_t>(message, data, response);
        break;

        case GAME_OBJECT_UNIT:
        object->unit->template send<data_t, response_t>(message, data, response);
        break;
        
        default:
        break;
    }
}

template <class data_t, class response_t>
response_t World::fastSendToGameObjectUnion(GameObjectUnion<World> *object, int message, data_t data)
{
    response_t response = 0;
    sendToGameObjectUnion<data_t, response_t>(object, message, data, &response);
    return response;
}
#pragma once

#include <vector>
#include <deque>
#include "world_types.h"
#include "Container.h"
#include "Camera.h"
#include "Cursor.h"
#include "Sort.h"
#include "Generator.h"
#include "GameObjectUnion.h"
#include "Selection.h"

class World: public Container, public GameObjectUnionUtility
{
private:
    void sortGameObjects(std::vector<GameObjectUnion<World>> &objectPool);
    
public:
    World();
    ~World();

    Tile<World> grassTile;
    Tile<World> sandTile;
    Tile<World> waterTile;
    
    Camera<World> camera;
    Cursor<World> cursor;
    Generator generator;
    Selection<GameObjectUnion<World>> selection;
    int _tileGrid[TILE_GRID_X][TILE_GRID_Y];
    int _playableGrid[TILE_GRID_X][TILE_GRID_Y];
    std::vector<GameObjectUnion<World>> _playablePool;   
    std::vector<std::vector<GameObjectUnion<World>>> _objectPool;
        
    void update();
    void render();
};

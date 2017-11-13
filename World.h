#pragma once

#include <vector>
#include <deque>
#include "world_types.h"
#include "Container.h"
#include "Tile.h"
#include "Camera.h"

class World: public Container 
{
private:
    
public:
    World();
    ~World();

    int _tileGrid[TILE_GRID_X][TILE_GRID_Y];
    int _heightMap[TILE_GRID_X][TILE_GRID_Y];
    std::vector<Tile<World>> _tilePool;

    void update();
    void render();
};
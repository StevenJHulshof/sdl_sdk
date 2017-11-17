#pragma once

#include <vector>
#include <deque>
#include "world_types.h"
#include "Container.h"
#include "Tile.h"
#include "Resource.h"
#include "Unit.h"
#include "Camera.h"

class World: public Container 
{
private:
    
public:
    World();
    ~World();

    Camera<World> camera;
    int _tileGrid[TILE_GRID_X][TILE_GRID_Y];
    int _resourceGrid[TILE_GRID_X][TILE_GRID_Y];
    std::vector<Tile<World>> _tilePool;
    std::vector<Resource<World>> _resourcePool;
    std::vector<Unit<World>> _unitPool;
    
    void update();
    void render();
};
#pragma once

#include <vector>
#include <deque>
#include "world_types.h"
#include "GameObject.h"
#include "Tile.h"

class World {
    
private:
    Tile tile_0;
    Tile tile_1;
public:
    World();
    ~World();

    std::vector<Tile> _tilePool;
    void fillTileGrid();
    void fillTilePool();
    void renderTilePool();


};


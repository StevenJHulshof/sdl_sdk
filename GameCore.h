#pragma once

#define TILE_GRID_X 30
#define TILE_GRID_Y 20
#define TILE_GRID_Z 10

#include <vector>
#include "Tile.h"

class GameCore {
private:
    int _tileGrid[TILE_GRID_X][TILE_GRID_Y][TILE_GRID_Z];
    int _heightMap[TILE_GRID_X][TILE_GRID_Y];
    std::vector<Tile> _tilePool;

public:
    GameCore();
    void update();
    void render();
};
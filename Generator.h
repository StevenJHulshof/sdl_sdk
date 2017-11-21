#pragma once

#include <stdlib.h>
#include "world_types.h"

enum {
    GENERATOR_UP,
    GENERATOR_DOWN,
    GENERATOR_LEFT,
    GENERATOR_RIGHT
};

class Generator
{
public:
    Generator();
    ~Generator();

    void fillGrid(int grid[TILE_GRID_X][TILE_GRID_Y], int type);
    void generatePatch( int grid[TILE_GRID_X][TILE_GRID_Y], 
                        int type, int size, int density, 
                        int baseGrid[TILE_GRID_X][TILE_GRID_Y] = NULL, int baseType = 0);
};


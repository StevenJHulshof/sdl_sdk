#pragma once

#include <iostream>
#include <stdlib.h>
#include "grid_types.h"

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

    void fillGrid(int grid[GRID_X][GRID_Y], int type);
    void generatePatch( int grid[GRID_X][GRID_Y],
                        int type, int size, int density, 
                        int baseGrid[GRID_X][GRID_Y] = NULL, int baseType = 0);
    void generateBorder(int grid[GRID_X][GRID_Y], int type);
};


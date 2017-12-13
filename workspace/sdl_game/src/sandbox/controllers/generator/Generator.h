#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Grid.h"

enum {
    GENERATOR_X_P,
    GENERATOR_X_N,
    GENERATOR_Y_P,
    GENERATOR_Y_N,
    GENERATOR_Z_P,
    GENERATOR_Z_N
};

class Generator
{
public:
    Generator();
    ~Generator();

    void fillGrid(Tile *tile);
    void generatePatch( int grid[GRID_X][GRID_Y][GRID_Z],
                        int type, int size, int density, 
                        int baseGrid[GRID_X][GRID_Y][GRID_Z] = NULL, int baseType = 0);
    void generateBorder(int grid[GRID_X][GRID_Y][GRID_Z], int type);
};


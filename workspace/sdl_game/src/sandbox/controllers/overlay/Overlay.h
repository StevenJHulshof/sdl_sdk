#pragma once

#include <iostream>
#include "grid_types.h"

class Overlay
{
public:
    Overlay();
    ~Overlay();
    static int getTileOverlay(int tileGrid[GRID_X][GRID_Y][GRID_Z], int xPos, int yPos, int zPos, int type);
};


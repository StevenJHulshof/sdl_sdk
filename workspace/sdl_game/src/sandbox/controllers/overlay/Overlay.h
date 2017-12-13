#pragma once

#include <iostream>
#include "Generator.h"

class Overlay
{
public:
    Overlay();
    ~Overlay();
    static int getTileOverlay(int tileGrid[GRID_X][GRID_Y], int xPos, int yPos, int type);
};


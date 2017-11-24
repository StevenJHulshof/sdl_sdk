#pragma once

#include "world_types.h"

class Overlay
{
public:
    Overlay();
    ~Overlay();
    static int getTileOverlay(int tileGrid[TILE_GRID_X][TILE_GRID_Y], int xPos, int yPos, int type);
};


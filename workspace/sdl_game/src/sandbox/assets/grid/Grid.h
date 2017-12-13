#pragma once

#include "grid_types.h"

class Grid
{
public:
	Grid();
	virtual ~Grid();

    static int _tileGrid[GRID_X][GRID_Y];
    static int _playableGrid[GRID_X][GRID_Y];
};

#pragma once

#include <vector>
#include <algorithm>
#include "grid_types.h"
#include "TileData.h"
#include "Tile.h"

class Grid
{
public:
	Grid();
	virtual ~Grid();

	static void config();
	static std::vector<TileData<Tile>*> _tileGrid;
	static void setTileData(int xPos, int yPos, int zPos, Tile *tile);
	static void renderTileGrid();
	static void deleteGrid();

    static int _playableGrid[GRID_X][GRID_Y][GRID_Z];
};

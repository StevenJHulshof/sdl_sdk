#pragma once

#include <algorithm>
#include "grid_types.h"
#include "Tile.h"

class Map {
public:
	Map();
	virtual ~Map();

	std::vector<TileData> _tileMap;
	void render();
	void setTiles(Tile *tile);
	void printTileMap();
};

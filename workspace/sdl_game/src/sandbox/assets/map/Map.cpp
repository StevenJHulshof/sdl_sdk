#include "Map.h"

Map::Map()
{
	for(int x = -GRID_N; x <= GRID_N; x++)
	{
		for(int y = std::max(-GRID_N, -x - GRID_N); y <= std::min(GRID_N, -x + GRID_N); y++)
		{
			_tileMap.push_back(TileData(x, y, -x - y));
		}
	}
}

Map::~Map()
{

}

void Map::render()
{
	for(size_t i = 0; i < _tileMap.size(); i++)
	{
		_tileMap[i].render();
	}
}

void Map::setTiles(Tile *tile)
{
	for(size_t i = 0; i < _tileMap.size(); i++)
	{
		_tileMap[i]._tile = tile;
	}
}

void Map::printTileMap()
{
	for(size_t i = 0; i < _tileMap.size(); i++)
	{
		std::cout << i << "\t( " << _tileMap[i]._xPos << ", " << _tileMap[i]._yPos << ", " << _tileMap[i]._zPos << ", ";

		if(_tileMap[i]._tile != NULL)
		{
			std::cout << _tileMap[i]._tile->_type << " )" << std::endl;
		}
		else
		{
			std::cout << "NULL )" << std::endl;
		}
	}
}
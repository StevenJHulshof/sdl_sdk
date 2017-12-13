/*
 * Grid.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: Steven
 */

#include "Grid.h"

std::vector<TileData<Tile>*> Grid::_tileGrid;

Grid::Grid()
{

}

Grid::~Grid()
{

}

void Grid::config()
{
	for(int x = -GRID_N; x <= GRID_N; x++)
	{
		for(int y = std::max(-GRID_N, -x - GRID_N); y <= std::min(GRID_N, -x + GRID_N); y++)
		{
			int z = -x - y;
			std::cout << "ID: " << _tileGrid.size() << " x: " << x << " y: " << y << " z: " << z << std::endl;
			_tileGrid.push_back(new TileData<Tile>(x, y, z));
		}
	}
}

void Grid::setTileData(int xPos, int yPos, int zPos, Tile *tile)
{
	for(size_t i = 0; i < _tileGrid.size(); i++)
	{
		if(	_tileGrid[i]->_xPos == xPos &&
			_tileGrid[i]->_yPos == yPos &&
			_tileGrid[i]->_zPos == zPos)
		{

			_tileGrid[i]->_tile = tile;
		}
	}
}

void Grid::renderTileGrid()
{
	for(size_t i = 0; i < _tileGrid.size(); i++)
	{
		_tileGrid[i]->_tile->render(_tileGrid[i]->_xPos, _tileGrid[i]->_yPos, _tileGrid[i]->_zPos);
	}
}

void Grid::deleteGrid()
{
	for(size_t i = 0; i < _tileGrid.size(); i++)
	{
		_tileGrid[i]->deleteSelf();
	}
}

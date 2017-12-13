#pragma once

template <class tile_t>
class TileData
{
public:
	int _xPos;
	int _yPos;
	int _zPos;
	tile_t *_tile;

	TileData(int xPos, int yPos, int zPos);
	~TileData();

	void deleteSelf();
};

template <class tile_t>
TileData<tile_t>::TileData(int xPos, int yPos, int zPos):
	_tile(NULL)
{
	_xPos = xPos;
	_yPos = yPos;
	_zPos = zPos;
}

template <class tile_t>
TileData<tile_t>::~TileData()
{

}

template <class tile_t>
void TileData<tile_t>::deleteSelf()
{
	delete this;
}


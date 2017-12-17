#pragma once

#include "container_types.h"
#include "GameObject.h"
#include "Overlay.h"

class Tile: public GameObject
{
protected:
	virtual void setTextureType();

public:
	Tile(int type);
	virtual ~Tile();

	virtual void render(int xPos, int zPos);

	virtual void renderGraphics(int xPos, int zPos);
};

class TileData
{
public:
	int _xPos, _yPos, _zPos;
	Tile *_tile;
	TileData(int xPos, int yPos, int zPos)
	{
		_xPos = xPos;
		_yPos = yPos;
		_zPos = zPos;
		_tile = NULL;
	}

	void render()
	{
		if(_tile != NULL)
		{
			_tile->render(_xPos, _zPos);
		}
	}
};

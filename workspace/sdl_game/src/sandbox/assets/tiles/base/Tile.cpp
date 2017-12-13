#include "Tile.h"

Tile::Tile(int type):
	GameObject()
{
	_type = type;
	setTextureType();
}

Tile::~Tile()
{

}

void Tile::render(int xPos, int yPos, int zPos) {
	renderGraphics(xPos, yPos, zPos);
}

void Tile::renderGraphics(int xPos, int yPos, int zPos)
{
	int w = gTextures[TEXTURE_TEMPLATE].getWidth() * _zoom;
	int h = gTextures[TEXTURE_TEMPLATE].getHeight() * _zoom;
//
	Translate::gridToScreenPos(xPos, yPos, zPos, w, h, &_screenPosX, &_screenPosY);
//
	gTextures[_textureType].render(0, 0, NULL, 0, NULL, _flip, _zoom);
	if(_type == TYPE_TILE_WATER || _type == TYPE_TILE_SAND)
	{
//		//int overlay = Overlay::getTileOverlay(Grid::_tileGrid, xPos, yPos, zPos, _type);
//		int overlay = 0;
//		if(overlay < 63)
//		{
//			//gTextures[TEXTURE_TILE_OVERLAY_0000 + overlay].render(_screenPosX + _offsetX, _screenPosY + _offsetY, NULL, 0, NULL, _flip, _zoom);
//		}
	}
}

void Tile::setTextureType()
{
	switch(_type)
	{
	case TYPE_TILE_GRASS:
		_textureType = TEXTURE_TILE_GRASS_0000;
		break;
	case TYPE_TILE_SAND:
		_textureType = TEXTURE_TILE_SAND_0000;
		break;
	case TYPE_TILE_WATER:
		_textureType = TEXTURE_TILE_WATER_0000;
		break;
	default:
		break;
	}
}

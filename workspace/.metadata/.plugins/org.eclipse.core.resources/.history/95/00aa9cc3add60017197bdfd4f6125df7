#include "RawWood.h"

RawWood::RawWood(int xPos, int yPos):
	RawResource(xPos, yPos, TYPE_RESOURCE_RAW_WOOD)
{

}

RawWood::~RawWood()
{

}


void RawWood::renderGraphics()
{
	RawResource::renderGraphics();

	if(_hovered)
	{
		gTextures[TEXTURE_RESOURCE_RAW_WOOD_HOVERED].render(_screenPosX + _offsetX, _screenPosY + _offsetY, NULL, 0, NULL, _flip, _zoom);
	}
}

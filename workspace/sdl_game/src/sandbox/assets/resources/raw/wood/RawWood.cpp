#include "RawWood.h"

RawWood::RawWood(int xPos, int yPos, int zPos):
	RawResource(xPos, yPos, zPos, TYPE_RESOURCE_RAW_WOOD)
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
		gTextures[_textureType + TEXTURE_RESOURCE_RAW_WOOD_0000_HOVERED - TEXTURE_RESOURCE_RAW_WOOD_0000].render(_screenPosX + _offsetX, _screenPosY + _offsetY, NULL, 0, NULL, _flip, _zoom);
	}
}

std::vector<RawWood*> gRawWoodPool;

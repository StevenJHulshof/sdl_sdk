#include "RawStone.h"

RawStone::RawStone(int xPos, int yPos):
	RawResource(xPos, yPos, TYPE_RESOURCE_RAW_STONE)
{

}

RawStone::~RawStone()
{

}


void RawStone::renderGraphics()
{
	RawResource::renderGraphics();

	if(_hovered)
	{
		gTextures[TEXTURE_RESOURCE_RAW_STONE_HOVERED].render(_screenPosX + _offsetX, _screenPosY + _offsetY, NULL, 0, NULL, _flip, _zoom);
	}
}

std::vector<RawStone*> gRawStonePool;

#include "Resource.h"

Resource::Resource(int xPos, int yPos, int zPos, int type):
	GameObject()
{
	_xPos = xPos;
	_yPos = yPos;
	_zPos = zPos;
	_type = type;
	setTextureType();
	_priority = _basePriority = PRIORITY_RESOURCE;
}

Resource::~Resource()
{

}

void Resource::setTextureType()
{
	switch(_type)
	{
	case TYPE_RESOURCE_RAW_WOOD:
		_textureType = (rand() % 5) + TEXTURE_RESOURCE_RAW_WOOD_0000;
		break;
	case TYPE_RESOURCE_RAW_STONE:
		_textureType = TEXTURE_RESOURCE_RAW_STONE;
		break;
	default:
		break;
	}

	_flip = (rand() % 2) == 0 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
}

std::vector<Resource*> gResourcePool;

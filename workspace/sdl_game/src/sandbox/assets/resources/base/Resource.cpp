#include "Resource.h"

Resource::Resource(int xPos, int yPos, int type):
	GameObject()
{
	_xPos = xPos;
	_yPos = yPos;
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
		_textureType = TEXTURE_RESOURCE_RAW_WOOD;
		break;
	case TYPE_RESOURCE_RAW_STONE:
		_textureType = TEXTURE_RESOURCE_RAW_STONE;
		break;
	default:
		break;
	}
}

std::vector<Resource*> gResourcePool;

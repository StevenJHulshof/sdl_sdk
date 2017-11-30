#include "Unit.h"

Unit::Unit(int xPos, int yPos, int type):
	GameObject()
{
	_xPos = xPos;
	_yPos = yPos;
	_type = type;
	_priority = _basePriority = PRIORITY_UNIT;
	setTextureType();
}

Unit::~Unit()
{

}

void Unit::setTextureType()
{
	switch(_type)
	{
	case TYPE_UNIT_WARRIOR:
		_textureType = TEXTURE_UNIT_WARRIOR;
		break;
	default:
		break;
	}
}

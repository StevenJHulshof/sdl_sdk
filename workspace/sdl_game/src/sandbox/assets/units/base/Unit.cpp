#include "Unit.h"

Unit::Unit(int xPos, int yPos, int type):
	GameObject(),
	_health(UNIT_HEALTH_DEFAULT),
	_defense(UNIT_DEFENSE_DEFAULT),
	_movementSpeed(UNIT_MOVEMENT_SPEED_DEFAULT),
	_pStatMenu(NULL),
	_pActionMenu(NULL)
{
	_xPos = xPos;
	_yPos = yPos;
	_type = type;
	_priority = _basePriority = PRIORITY_UNIT;
	setTextureType();

	_pStatMenu = new StatMenu(_xPos, _yPos);
	gStatMenuPool.push_back(_pStatMenu);

	_pStatMenu->addStat(STAT_TYPE_HEALTH, &_health);
	_pStatMenu->addStat(STAT_TYPE_DEFENSE, &_defense);
	_pStatMenu->addStat(STAT_TYPE_MOVEMENT_SPEED, &_movementSpeed);

	_pActionMenu = new ActionMenu(_xPos, _yPos);
	gActionMenuPool.push_back(_pActionMenu);
}

Unit::~Unit()
{

}

void Unit::renderInput()
{
	GameObject::renderInput();

	_pStatMenu->_isActive = _selected;
	_pActionMenu->_isActive = _selected;
}

void Unit::setTextureType()
{
	switch(_type)
	{
	case TYPE_UNIT_WARRIOR:
		_textureType = TEXTURE_UNIT_WARRIOR;
		break;
	case TYPE_UNIT_RANGER:
		_textureType = TEXTURE_UNIT_RANGER;
		break;
	default:
		std::cout << "object type invalid" << std::endl;
		break;
	}
}

std::vector<Unit*> gUnitPool;

#include "Warrior.h"

Warrior::Warrior(int xPos, int yPos, int zPos):
	Unit(xPos, yPos, zPos, TYPE_UNIT_WARRIOR),
	_attackMelee(WARRIOR_ATTACK_MELEE_DEFAULT)
{
	_health = WARRIOR_HEALTH_DEFAULT;
	_defense = WARRIOR_DEFENSE_DEFAULT;
	_pStatMenu->addStat(STAT_TYPE_ATTACK_MELEE, &_attackMelee);
}

Warrior::~Warrior()
{

}

void Warrior::renderGraphics()
{
	Unit::renderGraphics();

	if(_hovered)
	{
		gTextures[TEXTURE_UNIT_WARRIOR_HOVERED].render(_screenPosX + _offsetX, _screenPosY + _offsetY, NULL, 0, NULL, _flip, _zoom);
	}
}

std::vector<Warrior*> gWarriorPool;

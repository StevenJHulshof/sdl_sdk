#include "Ranger.h"

Ranger::Ranger(int xPos, int yPos, int zPos):
	Unit(xPos, yPos, zPos, TYPE_UNIT_RANGER),
	_attackRanged(RANGER_ATTACK_RANGED_DEFAULT)
{
	_health = RANGER_HEALTH_DEFAULT;
	_defense = RANGER_DEFENSE_DEFAULT;
	_pStatMenu->addStat(STAT_TYPE_ATTACK_RANGED, &_attackRanged);
}

Ranger::~Ranger()
{

}

void Ranger::renderGraphics()
{
	Unit::renderGraphics();

	if(_hovered)
	{
		gTextures[TEXTURE_UNIT_RANGER_HOVERED].render(_screenPosX + _offsetX, _screenPosY + _offsetY, NULL, 0, NULL, _flip, _zoom);
	}
}

std::vector<Ranger*> gRangerPool;

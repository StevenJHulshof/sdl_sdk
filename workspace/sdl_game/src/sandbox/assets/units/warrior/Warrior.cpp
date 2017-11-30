#include "Warrior.h"

Warrior::Warrior(int xPos, int yPos):
	Unit(xPos, yPos, TYPE_UNIT_WARRIOR)
{

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
	if(_selected)
	{
		gTextures[TEXTURE_UNIT_WARRIOR_SELECTED].render(_screenPosX + _offsetX, _screenPosY + _offsetY, NULL, 0, NULL, _flip, _zoom);
	}
}

#include "ActionMenu.h"

ActionMenu::ActionMenu(int xPos, int yPos, int zPos):
	Menu(xPos, yPos, zPos, TYPE_OBJECT_MENU_ACTION)
{

}

ActionMenu::~ActionMenu()
{

}

void ActionMenu::updateGraphics()
{
	Menu::updateGraphics();

	_screenPosX -= 32;
	_screenPosY += 32;
}

std::vector<ActionMenu*> gActionMenuPool;

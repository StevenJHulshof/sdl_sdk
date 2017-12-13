#pragma once

#include "Menu.h"

class ActionMenu: public Menu
{
public:
	ActionMenu(int xPos, int yPos, int zPos);
	virtual ~ActionMenu();

	virtual void updateGraphics();
};

extern std::vector<ActionMenu*> gActionMenuPool;

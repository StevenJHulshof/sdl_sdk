#pragma once

#include "warrior_types.h"
#include "Unit.h"

class Warrior: public Unit
{
public:
	Warrior(int xPos, int yPos, int zPos);
	virtual ~Warrior();

	int _attackMelee;

	virtual void renderGraphics();
};

extern std::vector<Warrior*> gWarriorPool;

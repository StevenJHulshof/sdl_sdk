#pragma once

#include "ranger_types.h"
#include "Unit.h"

class Ranger: public Unit
{
public:
	Ranger(int xPos, int yPos);
	virtual ~Ranger();

	int _attackRanged;

	virtual void renderGraphics();
};

extern std::vector<Ranger*> gRangerPool;

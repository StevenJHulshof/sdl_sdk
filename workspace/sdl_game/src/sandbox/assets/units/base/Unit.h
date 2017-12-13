#pragma once

#include "container_types.h"
#include "unit_types.h"
#include "GameObject.h"
#include "StatMenu.h"
#include "ActionMenu.h"

class Unit: public GameObject
{
protected:
	virtual void setTextureType();

public:
	Unit(int xPos, int yPos, int zPos, int type);
	virtual ~Unit();

	virtual void renderInput();

	int _health, _defense, _movementSpeed;

	StatMenu *_pStatMenu;
	ActionMenu *_pActionMenu;
};

extern std::vector<Unit*> gUnitPool;

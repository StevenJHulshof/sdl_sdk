#pragma once

#include "container_types.h"
#include "GameObject.h"

class Unit: public GameObject
{
protected:
	virtual void setTextureType();

public:
	Unit(int xPos, int yPos, int type);
	virtual ~Unit();
};

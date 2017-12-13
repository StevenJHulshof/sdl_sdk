#pragma once

#include "container_types.h"
#include "GameObject.h"

class Menu: public GameObject
{
protected:
	virtual void setTextureType();

public:
	Menu(int xPos, int yPos, int zPos, int type);
	virtual ~Menu();
};

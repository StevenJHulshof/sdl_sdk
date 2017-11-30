#pragma once

#include "GameObject.h"

class Cursor: public GameObject
{
public:
	Cursor();
	virtual ~Cursor();

	virtual void updateInput();
	virtual void updateGraphics();
};

#pragma once

#include "RawResource.h"

class RawWood: public RawResource
{
public:
	RawWood(int xPos, int yPos);
	virtual ~RawWood();

	virtual void renderGraphics();
};

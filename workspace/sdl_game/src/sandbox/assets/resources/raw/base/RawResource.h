#pragma once

#include "Resource.h"

class RawResource: public Resource
{
public:
	RawResource(int xPos, int yPos, int type);
	virtual ~RawResource();
};

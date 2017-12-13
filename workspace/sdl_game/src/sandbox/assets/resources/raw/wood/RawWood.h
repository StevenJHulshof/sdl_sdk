#pragma once

#include "RawResource.h"

class RawWood: public RawResource
{
public:
	RawWood(int xPos, int yPos, int zPos);
	virtual ~RawWood();

	virtual void renderGraphics();
};

extern std::vector<RawWood*> gRawWoodPool;

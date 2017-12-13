#pragma once

#include "RawResource.h"

class RawStone: public RawResource
{
public:
	RawStone(int xPos, int yPos, int zPos);
	virtual ~RawStone();

	virtual void renderGraphics();
};

extern std::vector<RawStone*> gRawStonePool;

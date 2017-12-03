#pragma once

#include "RawResource.h"

class RawStone: public RawResource
{
public:
	RawStone(int xPos, int yPos);
	virtual ~RawStone();

	virtual void renderGraphics();
};

extern std::vector<RawStone*> gRawStonePool;

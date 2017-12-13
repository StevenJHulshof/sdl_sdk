#pragma once

#include "container_types.h"
#include "GameObject.h"

class Resource: public GameObject
{
protected:
	virtual void setTextureType();
public:
	Resource(int xPos, int yPos, int type);
	virtual ~Resource();
};

extern std::vector<Resource*> gResourcePool;

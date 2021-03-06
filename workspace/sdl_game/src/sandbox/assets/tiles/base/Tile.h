#pragma once

#include "container_types.h"
#include "GameObject.h"
#include "Overlay.h"

class Tile: public GameObject
{
protected:
	virtual void setTextureType();

public:
	Tile(int type);
	virtual ~Tile();

	virtual void render(int xPos, int yPos);

	virtual void renderGraphics(int xPos, int yPos);
};

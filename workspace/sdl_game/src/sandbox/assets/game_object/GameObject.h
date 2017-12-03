#pragma once

#include "sdl_includes.h"
#include <string>
#include "Texture.h"
#include "Translate.h"
#include "Grid.h"
#include "Input.h"

class GameObject
{
protected:
	virtual void setTextureType();

public:
	bool _selected, _hovered, _isActive;
	int _textureType, _screenPosX, _screenPosY,
		_offsetX, _offsetY, _priority, _basePriority,
		_velocity, _xPos, _yPos, _type, _slot;
	SDL_RendererFlip _flip;
	float _zoom;

	GameObject();
	virtual ~GameObject();

	void update();
	void render();

	virtual void updateInput();
	virtual void updatePhysics();
	virtual void updateGraphics();

	virtual void renderInput();
	virtual void renderPhysics();
	virtual void renderGraphics();

	virtual void deleteSelf();
};

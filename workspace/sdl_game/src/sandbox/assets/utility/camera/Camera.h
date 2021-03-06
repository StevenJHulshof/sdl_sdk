#pragma once

#include "camera_types.h"
#include "config_types.h"
#include "GameObject.h"

class Camera: public GameObject
{
public:
	bool _dragFlag;
	int _dragStartX, _dragStartY;

	Camera(int screenPosX, int screenPosY);
	virtual ~Camera();

	virtual void updateInput();
};

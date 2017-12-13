#include "Camera.h"

Camera::Camera(int offsetX, int offsetY):
	GameObject(),
	_dragFlag(false),
	_dragStartX(0),
	_dragStartY(0)
{
	_offsetX = offsetX;
	_offsetY = offsetY;
	_velocity = CAMERA_VELOCITY;
}

Camera::~Camera()
{

}

void Camera::updateInput()
{
	int w = gTextures[TEXTURE_TEMPLATE].getWidth() * _zoom;
	int h = gTextures[TEXTURE_TEMPLATE].getHeight() * _zoom;

	int dragX = 0, dragY = 0;
	Input::getMousePos(&dragX, &dragY);

	if(Input::onRightMouseClickDown() && !Input::onLeftMouseClickDown())
	{
		if(!_dragFlag)
		{
			_dragStartX = _offsetX - dragX;
			_dragStartY = _offsetY - dragY;
			_dragFlag = true;
		}
		if(_dragStartY + dragY < (GRID_Z * h * 0.25 - h * 0.75) && _dragStartY + dragY - SCREEN_HEIGHT > -(GRID_Z * h * 0.25 + h))
		{
			_offsetY = _dragStartY + dragY;
		}
		else
		{
			_dragStartY = _offsetY - dragY;
		}
		if(_dragStartX + dragX < (GRID_X * w * 0.75 + w) && _dragStartX + dragX - SCREEN_WIDTH  > -(GRID_Y * w * 0.75 + w))
		{
			_offsetX = _dragStartX + dragX;
		}
		else
		{
			_dragStartX = _offsetX - dragX;
		}
	}
	else
	{
		_dragFlag = false;

		if(Input::onKeyPressed(VK_UP))
		{
			if(_offsetY < (GRID_Z * h * 0.25 - h * 0.75))
			{
				_offsetY += _velocity;
			}
		}
		if(Input::onKeyPressed(VK_DOWN))
		{
			if(_offsetY - SCREEN_HEIGHT > -(GRID_Z * h * 0.25 + h))
			{
				_offsetY -= _velocity;
			}
		}
		if(Input::onKeyPressed(VK_LEFT))
		{
			if(_offsetX < (GRID_X * w * 0.75 + w))
			{
				_offsetX += _velocity;
			}
		}
		if(Input::onKeyPressed(VK_RIGHT))
		{
			if(_offsetX - SCREEN_WIDTH > -(GRID_Y * w * 0.75 + w))
			{
				_offsetX -= _velocity;
			}
		}
	}
}

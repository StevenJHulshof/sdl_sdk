#include "Cursor.h"

Cursor::Cursor():
	GameObject()
{
	_textureType = TEXTURE_CURSOR_ARROW;
}

Cursor::~Cursor()
{

}

void Cursor::updateInput()
{
	Input::getMousePos(&_screenPosX, &_screenPosY);

    if(Input::onRightMouseClickDown() && !Input::onLeftMouseClickDown())
    {
        _textureType = TEXTURE_CURSOR_DRAG;
    }
    else
    {
        _textureType = TEXTURE_CURSOR_ARROW;
    }
}

void Cursor::updateGraphics()
{
	_offsetX = 0;
	_offsetY = 0;

	if(_textureType == TEXTURE_CURSOR_DRAG)
	{
		int w = gTextures[_textureType].getWidth() * _zoom;
		int h = gTextures[_textureType].getHeight() * _zoom;

		_offsetX = (int)(-w / 2);
		_offsetY = (int)(-h / 2);
	}
}

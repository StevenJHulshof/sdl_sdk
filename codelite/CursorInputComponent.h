#pragma once

#include "Input.h"
#include "InputComponent.h"
#include "config_types.h"

template <class obj_t>
class CursorInputComponent: public InputComponent<obj_t>
{ 
private:

public:
    CursorInputComponent();
    virtual ~CursorInputComponent();
    
    virtual void update();
};

template <class obj_t>
CursorInputComponent<obj_t>::CursorInputComponent():
    InputComponent<obj_t>()
{
    
}

template <class obj_t>
CursorInputComponent<obj_t>::~CursorInputComponent()
{
    
}

template <class obj_t>
void CursorInputComponent<obj_t>::update()
{
    InputComponent<obj_t>::update();
    
    int screenPosX, screenPosY;
    Input::getMousePos(&screenPosX, &screenPosY);
    this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_SCREEN_POS_X, screenPosX);
    this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_SCREEN_POS_Y, screenPosY);
    
    if(Input::onRightMouseClickDown() && !Input::onLeftMouseClickDown())
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, TEXTURE_CURSOR_DRAG);
    }
    else
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, TEXTURE_CURSOR_ARROW);        
    }
}
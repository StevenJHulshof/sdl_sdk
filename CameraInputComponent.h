#pragma once

#include "Input.h"
#include "InputComponent.h"

template <class obj_t>
class CameraInputComponent: public InputComponent<obj_t>
{ 
private:
    const float ZOOM_FACTOR_0 = 1.00;
    const float ZOOM_FACTOR_1 = 0.5;

public:
    CameraInputComponent();
    ~CameraInputComponent();
    
    virtual void update();
};

template <class obj_t>
CameraInputComponent<obj_t>::CameraInputComponent():
    InputComponent<obj_t>()
{
    
}

template <class obj_t>
CameraInputComponent<obj_t>::~CameraInputComponent()
{
    
}

template <class obj_t>
void CameraInputComponent<obj_t>::update()
{
    InputComponent<obj_t>::update();
    
    int x, y, velocity;
    this->getGameObject()->template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_Y, &y);
    this->getGameObject()->template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_X, &x);
    this->getGameObject()->template send<int, int>(MSG_GET_PHYSICS, MSG_DATA_PHYSICS_VELOCITY, &velocity);
    
    if(Input::onKeyPressed(VK_UP)) 
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, y + velocity);
    } 
    if(Input::onKeyPressed(VK_DOWN)) 
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, y - velocity);
    }
    if(Input::onKeyPressed(VK_LEFT)) 
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, x + velocity);
    }
    if(Input::onKeyPressed(VK_RIGHT)) 
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, x - velocity);
    }
    if(Input::onKeyPressed('Z')) 
    {
        this->getGameObject()->template send<float, int>(MSG_SET_GRAPHICS_ZOOM, ZOOM_FACTOR_0);
    }
    if(Input::onKeyPressed('X')) 
    {
        this->getGameObject()->template send<float, int>(MSG_SET_GRAPHICS_ZOOM, ZOOM_FACTOR_1);
    }
}
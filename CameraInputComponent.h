#pragma once

#include "InputComponent.h"

template <class obj_t>
class CameraInputComponent: public InputComponent<obj_t>
{  
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
    if(GetAsyncKeyState(VK_UP) & 0x8000) 
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, y - velocity);
    } 
    if(GetAsyncKeyState(VK_DOWN) & 0x8000) 
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, y + velocity);
    }
    if(GetAsyncKeyState(VK_LEFT) & 0x8000) 
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, x - velocity);
    }
    if(GetAsyncKeyState(VK_RIGHT) & 0x8000) 
    {
        this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, x + velocity);
    }
}
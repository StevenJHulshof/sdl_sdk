#pragma once

#include "Input.h"
#include "InputComponent.h"
#include "config_types.h"

template <class obj_t>
class CameraInputComponent: public InputComponent<obj_t>
{ 
private:
    const float ZOOM_FACTOR_0 = 1.00;
    const float ZOOM_FACTOR_1 = 0.5;
    int dragStartX, dragStartY;
    bool dragFlag;

public:
    CameraInputComponent();
    virtual ~CameraInputComponent();
    
    virtual void update();
};

template <class obj_t>
CameraInputComponent<obj_t>::CameraInputComponent():
    InputComponent<obj_t>(),
    dragStartX(0),
    dragStartY(0),
    dragFlag(false)
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
    float zoom;
    this->getGameObject()->template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_Y, &y);
    this->getGameObject()->template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_X, &x);
    this->getGameObject()->template send<int, float>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_ZOOM, &zoom);
    this->getGameObject()->template send<int, int>(MSG_GET_PHYSICS, MSG_DATA_PHYSICS_VELOCITY, &velocity);
    
    int w = (int) gTextures[TEXTURE_TEMPLATE].getWidth() * zoom;
    int h = (int) gTextures[TEXTURE_TEMPLATE].getHeight() * zoom;
     
    if(Input::onRightMouseClickDown())
    {
        int dragX = 0, dragY = 0;
        Input::getMousePos(&dragX, &dragY);
        if(!dragFlag)
        {
            dragStartX = x - dragX;
            dragStartY = y - dragY;
            dragFlag = true;
        }
        if( dragStartX + dragX < -16 && dragStartX + dragX - SCREEN_WIDTH - 16 > (int) -TILE_GRID_X * w * 0.75 &&
            dragStartY + dragY < -96 && dragStartY + dragY - SCREEN_HEIGHT + 64 > (int) -TILE_GRID_Y * (h / 4) )
        {
            this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, dragStartY + dragY); 
            this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, dragStartX + dragX); 
        }   
    }
    else
    {
        dragFlag = false;
        
        if(Input::onKeyPressed(VK_UP)) 
        {
            if(y < -96)
            {
                this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, y + velocity);
            }
        } 
        if(Input::onKeyPressed(VK_DOWN)) 
        {
            if(y - SCREEN_HEIGHT + 64 > (int) -TILE_GRID_Y * (h / 4))
            {
                this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, y - velocity);
            }
        }
        if(Input::onKeyPressed(VK_LEFT)) 
        {
            if(x < -16)
            {
                this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, x + velocity);
            }
        }
        if(Input::onKeyPressed(VK_RIGHT)) 
        {
            if(x - SCREEN_WIDTH - 16 > (int) -TILE_GRID_X * w * 0.75)
            {
                this->getGameObject()->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, x - velocity);
            }
        }
    }
}
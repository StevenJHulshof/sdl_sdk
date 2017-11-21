#pragma once

#include "Component.h"
#include "windows.h"
#include "Texture.h"
#include "Input.h"
#include "Translate.h"

template <class obj_t>
class InputComponent: public Component<obj_t> 
{
protected:
    bool selected;

public:
    InputComponent();
    virtual ~InputComponent();
            
    virtual void update();
    
    virtual void receive(int message, bool data, int *response);
    virtual void receive(int message, int data, bool *response);
};

template <class obj_t>
InputComponent<obj_t>::InputComponent():
    Component<obj_t>(),
    selected(false)
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
InputComponent<obj_t>::~InputComponent()
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
void InputComponent<obj_t>::update()
{
    int x = 0, y = 0, screenPosX = 0, screenPosY = 0, textureType = 0;
    float zoom = 0.0;

    this->getGameObject()->template send(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_X, &screenPosX);
    this->getGameObject()->template send(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_Y, &screenPosY);
    this->getGameObject()->template send(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_TEXTURE_TYPE, &textureType);
    this->getGameObject()->template send(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_ZOOM, &zoom);
        
    int w = gTextures[TEXTURE_TEMPLATE].getWidth() * zoom;
    int h = gTextures[TEXTURE_TEMPLATE].getHeight() * zoom;
    
    if(Input::onLeftMouseClickDown(&x, &y))
    {   
        if( (x > screenPosX) && (x < (screenPosX + w)) &&
            (y > screenPosY) && (y < (screenPosY + h))) 
        {
            if(gTextures[textureType].getPixelColor(x - screenPosX, y - screenPosY) != 0xFFFFFF00)
            {
                int xPos, yPos;
                Translate::screenPosToGrid(screenPosX, screenPosY, w, h, &xPos, &yPos);
                selected = true;
            }
            else
            {
                selected = false;
            }
        }
        else
        {
            selected = false;
        }
    }
    
    DEBUG_FUN_VAR("%p | %s\nselected: %s\n", this->getGameObject(), __PRETTY_FUNCTION__, (selected) ? "true" : "false");
}

template <class obj_t>
void InputComponent<obj_t>::receive(int message, bool data, int *response)
{
    switch(message) 
    {  
        case MSG_SET_INPUT_SELECTED:
        selected = data;
        break;
        
        default:
        break;
    }
}

template <class obj_t>
void InputComponent<obj_t>::receive(int message, int data, bool *response)
{
    switch(message) 
    {    
        case MSG_GET_INPUT:
        switch(data) 
        {           
            case MSG_DATA_INPUT_SELECTED:
            *response = selected;
            break;
            
            default:
            break;
        }
        break;
        
        default:
        break;
    }
}


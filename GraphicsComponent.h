#pragma once

#include "sdl_includes.h"
#include "Debug.h"
#include "Component.h"
#include "Texture.h"

template <class obj_t>
class GraphicsComponent: public Component<obj_t> 
{    
protected:
    SDL_RendererFlip flip;
    int textureType, screenPosX, screenPosY;
    float zoom;
       
public:

    GraphicsComponent();
    ~GraphicsComponent();

    virtual void receive(int message, int data, int *response);
    
    virtual void receive(int message, SDL_RendererFlip data, int *response);
    virtual void receive(int message, int data, SDL_RendererFlip *response);
    
    virtual void receive(int message, float data, int *response);
    virtual void receive(int message, int data, float *response);
    
    virtual void update();
    virtual void render();
};

template <class obj_t>
GraphicsComponent<obj_t>::GraphicsComponent():
    Component<obj_t>(),
    flip(SDL_FLIP_NONE),
    textureType(0),
    screenPosX(0),
    screenPosY(0),
    zoom(1)
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
GraphicsComponent<obj_t>::~GraphicsComponent()
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
void GraphicsComponent<obj_t>::receive(int message, int data, int *response)
{
    switch(message) 
    {    
        case MSG_GET_GRAPHICS:
        switch(data) 
        {
            case MSG_DATA_GRAPHICS_TEXTURE_TYPE:
            *response = textureType;
            break;
            
            case MSG_DATA_GRAPHICS_SCREEN_POS_X:
            *response = screenPosX;
            break;
            
            case MSG_DATA_GRAPHICS_SCREEN_POS_Y:
            *response = screenPosY;
            break;
            
            case MSG_DATA_GRAPHICS_FLIP:
            *response = flip;
            break;
            
            default:
            break;
        }
        break;
         
        case MSG_SET_GRAPHICS_TEXTURE_TYPE:
        textureType = data;
        break;
        
        case MSG_SET_GRAPHICS_SCREEN_POS_X:
        screenPosX = data;
        break;
        
        case MSG_SET_GRAPHICS_SCREEN_POS_Y:
        screenPosY = data;
        break;

        default:
        break;
    }
}

template <class obj_t>
void GraphicsComponent<obj_t>::receive(int message, SDL_RendererFlip data, int *response)
{
    switch(message) 
    {  
        case MSG_SET_GRAPHICS_FLIP:
        flip = data;
        break;
        
        default:
        break;
    }
}

template <class obj_t>
void GraphicsComponent<obj_t>::receive(int message, int data, SDL_RendererFlip *response)
{
    switch(message) 
    {    
        case MSG_GET_GRAPHICS:
        switch(data) 
        {           
            case MSG_DATA_GRAPHICS_FLIP:
            *response = flip;
            break;
            
            default:
            break;
        }
        break;
        
        default:
        break;
    }
}

template <class obj_t>
void GraphicsComponent<obj_t>::receive(int message, float data, int *response)
{
    switch(message) 
    {  
        case MSG_SET_GRAPHICS_ZOOM:
        zoom = data;
        break;
        
        default:
        break;
    }
}

template <class obj_t>
void GraphicsComponent<obj_t>::receive(int message, int data, float *response)
{
    switch(message) 
    {    
        case MSG_GET_GRAPHICS:
        switch(data) 
        {           
            case MSG_DATA_GRAPHICS_ZOOM:
            *response = zoom;
            break;
            
            default:
            break;
        }
        break;
        
        default:
        break;
    }
}

template <class obj_t>
void GraphicsComponent<obj_t>::update() 
{
    int x, y = 0;
    this->getGameObject()->send(MSG_GET_PHYSICS, MSG_DATA_PHYSICS_X_POS, &x);
    this->getGameObject()->send(MSG_GET_PHYSICS, MSG_DATA_PHYSICS_Y_POS, &y);
    
    int w = gTextures[TEXTURE_TEMPLATE].getWidth() * zoom;
    int h = gTextures[TEXTURE_TEMPLATE].getHeight() * zoom;
    
    this->screenPosX = x * w * 0.5 - y * h * 0.5 + 600;
    this->screenPosY = x * h * 0.25 + y * h * 0.25;
    
    DEBUG_FUN_VAR("%p | %s\ntextureType: %d, screenPosX: %d, screenPosY: %d, zoom: %d\n",
        this->getGameObject(), __PRETTY_FUNCTION__, textureType, screenPosX, screenPosY, zoom);
}

template <class obj_t>
void GraphicsComponent<obj_t>::render() 
{
    gTextures[textureType].render(
        screenPosX,
        screenPosY,
        NULL, 0, NULL, flip, zoom);
}

#pragma once

#include "GraphicsComponent.h"

template <class obj_t>
class CursorGraphicsComponent: public GraphicsComponent<obj_t>
{  
public:
    CursorGraphicsComponent();
    virtual ~CursorGraphicsComponent();
    
    virtual void update();
    virtual void render();
};

template <class obj_t>
CursorGraphicsComponent<obj_t>::CursorGraphicsComponent():
    GraphicsComponent<obj_t>()
{

}

template <class obj_t>
CursorGraphicsComponent<obj_t>::~CursorGraphicsComponent()
{
    
}

template <class obj_t>
void CursorGraphicsComponent<obj_t>::update()
{
}

template <class obj_t>
void CursorGraphicsComponent<obj_t>::render()
{
    int textureOffsetX = 0, textureOffsetY = 0;
    
    if(this->textureType == TEXTURE_CURSOR_DRAG)
    {
        int w = gTextures[TEXTURE_CURSOR_DRAG].getWidth() * this->zoom;
        int h = gTextures[TEXTURE_CURSOR_DRAG].getHeight() * this->zoom;
        
        textureOffsetX = (int)(-w / 2);
        textureOffsetY = (int)(-h / 2);
    }
    
    gTextures[this->textureType].render(this->screenPosX + textureOffsetX, this->screenPosY + textureOffsetY, NULL, 0, NULL, this->flip, this->zoom);
}


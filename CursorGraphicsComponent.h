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
    gTextures[this->textureType].render(this->screenPosX, this->screenPosY, NULL, 0, NULL, this->flip, this->zoom);
}


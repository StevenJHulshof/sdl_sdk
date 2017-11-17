#pragma once

#include "GraphicsComponent.h"

template <class obj_t>
class UnitGraphicsComponent: public GraphicsComponent<obj_t>
{  
public:
    UnitGraphicsComponent();
    ~UnitGraphicsComponent();
    
    virtual void update();
    virtual void render();
};

template <class obj_t>
UnitGraphicsComponent<obj_t>::UnitGraphicsComponent():
    GraphicsComponent<obj_t>()
{
    
}

template <class obj_t>
UnitGraphicsComponent<obj_t>::~UnitGraphicsComponent()
{
    
}

template <class obj_t>
void UnitGraphicsComponent<obj_t>::update()
{
    GraphicsComponent<obj_t>::update();
        
    this->screenPosY -= (gTextures[this->textureType].getHeight() * 0.5 * this->zoom);
}

template <class obj_t>
void UnitGraphicsComponent<obj_t>::render()
{
    GraphicsComponent<obj_t>::render();
}
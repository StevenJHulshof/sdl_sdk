#pragma once

#include "GraphicsComponent.h"

template <class obj_t>
class ResourceGraphicsComponent: public GraphicsComponent<obj_t>
{  
public:
    ResourceGraphicsComponent();
    virtual ~ResourceGraphicsComponent();
    
    virtual void update();
    virtual void render();
};

template <class obj_t>
ResourceGraphicsComponent<obj_t>::ResourceGraphicsComponent():
    GraphicsComponent<obj_t>()
{
    
}

template <class obj_t>
ResourceGraphicsComponent<obj_t>::~ResourceGraphicsComponent()
{
    
}

template <class obj_t>
void ResourceGraphicsComponent<obj_t>::update()
{
    GraphicsComponent<obj_t>::update();
}

template <class obj_t>
void ResourceGraphicsComponent<obj_t>::render()
{
    GraphicsComponent<obj_t>::render();
}
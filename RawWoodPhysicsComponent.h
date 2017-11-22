#pragma once

#include "ResourcePhysicsComponent.h"

template <class obj_t>
class RawWoodPhysicsComponent: public ResourcePhysicsComponent<obj_t>
{
public:
    RawWoodPhysicsComponent();
    virtual ~RawWoodPhysicsComponent();
};

template <class obj_t>
RawWoodPhysicsComponent<obj_t>::RawWoodPhysicsComponent():
    ResourcePhysicsComponent<obj_t>()
{
    
}

template <class obj_t>
RawWoodPhysicsComponent<obj_t>::~RawWoodPhysicsComponent()
{
    
}
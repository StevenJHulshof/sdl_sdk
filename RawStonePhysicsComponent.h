#pragma once

#include "ResourcePhysicsComponent.h"

template <class obj_t>
class RawStonePhysicsComponent: public ResourcePhysicsComponent<obj_t>
{
public:
    RawStonePhysicsComponent();
    virtual ~RawStonePhysicsComponent();
};

template <class obj_t>
RawStonePhysicsComponent<obj_t>::RawStonePhysicsComponent():
    ResourcePhysicsComponent<obj_t>()
{
    
}

template <class obj_t>
RawStonePhysicsComponent<obj_t>::~RawStonePhysicsComponent()
{
    
}
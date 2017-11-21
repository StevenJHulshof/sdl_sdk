#pragma once

#include "PhysicsComponent.h"

template <class obj_t>
class ResourcePhysicsComponent: public PhysicsComponent<obj_t>
{
public:
    ResourcePhysicsComponent();
    virtual ~ResourcePhysicsComponent();
};

template <class obj_t>
ResourcePhysicsComponent<obj_t>::ResourcePhysicsComponent():
    PhysicsComponent<obj_t>()
{
    
}

template <class obj_t>
ResourcePhysicsComponent<obj_t>::~ResourcePhysicsComponent()
{
    
}
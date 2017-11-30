#pragma once

#include "PhysicsComponent.h"

template <class obj_t>
class UnitPhysicsComponent: public PhysicsComponent<obj_t>
{
public:
    UnitPhysicsComponent();
    virtual ~UnitPhysicsComponent();
};

template <class obj_t>
UnitPhysicsComponent<obj_t>::UnitPhysicsComponent():
    PhysicsComponent<obj_t>()
{
    
}

template <class obj_t>
UnitPhysicsComponent<obj_t>::~UnitPhysicsComponent()
{
    
}
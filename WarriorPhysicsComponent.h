#pragma once

#include "UnitPhysicsComponent.h"

template <class obj_t>
class WarriorPhysicsComponent: public UnitPhysicsComponent<obj_t>
{
public:
    WarriorPhysicsComponent();
    virtual ~WarriorPhysicsComponent();
};

template <class obj_t>
WarriorPhysicsComponent<obj_t>::WarriorPhysicsComponent():
    UnitPhysicsComponent<obj_t>()
{
    
}

template <class obj_t>
WarriorPhysicsComponent<obj_t>::~WarriorPhysicsComponent()
{
    
}
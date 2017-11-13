#pragma once

#include "PhysicsComponent.h"

template <class obj_t>
class TilePhysicsComponent: public PhysicsComponent<obj_t>
{
public:
    TilePhysicsComponent();
    ~TilePhysicsComponent();
};

template <class obj_t>
TilePhysicsComponent<obj_t>::TilePhysicsComponent():
    PhysicsComponent<obj_t>()
{
    
}

template <class obj_t>
TilePhysicsComponent<obj_t>::~TilePhysicsComponent()
{
    
}
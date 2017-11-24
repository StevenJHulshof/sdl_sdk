#pragma once

#include "PhysicsComponent.h"

template <class obj_t>
class TilePhysicsComponent: public PhysicsComponent<obj_t>
{
public:
    TilePhysicsComponent();
    virtual ~TilePhysicsComponent();
    
    virtual void render(int xPos, int yPos);
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

template <class obj_t>
void TilePhysicsComponent<obj_t>::render(int xPos, int yPos)
{
    
}
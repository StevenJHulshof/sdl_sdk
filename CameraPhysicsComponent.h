#pragma once

#include "PhysicsComponent.h"

template <class obj_t>
class CameraPhysicsComponent: public PhysicsComponent<obj_t>
{  
public:
    CameraPhysicsComponent();
    ~CameraPhysicsComponent();
};

template <class obj_t>
CameraPhysicsComponent<obj_t>::CameraPhysicsComponent():
    PhysicsComponent<obj_t>()
{
    
}

template <class obj_t>
CameraPhysicsComponent<obj_t>::~CameraPhysicsComponent()
{
    
}
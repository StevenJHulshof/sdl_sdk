#pragma once

#include "GraphicsComponent.h"

template <class obj_t>
class CameraGraphicsComponent: public GraphicsComponent<obj_t>
{  
public:
    CameraGraphicsComponent();
    virtual ~CameraGraphicsComponent();
};

template <class obj_t>
CameraGraphicsComponent<obj_t>::CameraGraphicsComponent():
    GraphicsComponent<obj_t>()
{
    
}

template <class obj_t>
CameraGraphicsComponent<obj_t>::~CameraGraphicsComponent()
{
    
}

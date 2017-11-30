#pragma once

#include "ResourceInputComponent.h"

template <class obj_t>
class RawWoodInputComponent: public ResourceInputComponent<obj_t>
{  
public:
    RawWoodInputComponent();
    virtual ~RawWoodInputComponent();
    
    virtual void update();
};

template <class obj_t>
RawWoodInputComponent<obj_t>::RawWoodInputComponent():
    ResourceInputComponent<obj_t>()
{
    
}

template <class obj_t>
RawWoodInputComponent<obj_t>::~RawWoodInputComponent()
{
    
}

template <class obj_t>
void RawWoodInputComponent<obj_t>::update()
{
    InputComponent<obj_t>::update();
}
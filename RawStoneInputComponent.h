#pragma once

#include "ResourceInputComponent.h"

template <class obj_t>
class RawStoneInputComponent: public ResourceInputComponent<obj_t>
{  
public:
    RawStoneInputComponent();
    virtual ~RawStoneInputComponent();
    
    virtual void update();
};

template <class obj_t>
RawStoneInputComponent<obj_t>::RawStoneInputComponent():
    ResourceInputComponent<obj_t>()
{
    
}

template <class obj_t>
RawStoneInputComponent<obj_t>::~RawStoneInputComponent()
{
    
}

template <class obj_t>
void RawStoneInputComponent<obj_t>::update()
{
    InputComponent<obj_t>::update();
}
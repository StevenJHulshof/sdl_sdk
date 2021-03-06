#pragma once

#include "InputComponent.h"

template <class obj_t>
class ResourceInputComponent: public InputComponent<obj_t>
{  
public:
    ResourceInputComponent();
    virtual ~ResourceInputComponent();
    
    virtual void update();
};

template <class obj_t>
ResourceInputComponent<obj_t>::ResourceInputComponent():
    InputComponent<obj_t>()
{
    
}

template <class obj_t>
ResourceInputComponent<obj_t>::~ResourceInputComponent()
{
    
}

template <class obj_t>
void ResourceInputComponent<obj_t>::update()
{
    InputComponent<obj_t>::update();
}
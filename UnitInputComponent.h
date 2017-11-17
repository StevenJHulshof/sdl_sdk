#pragma once

#include "InputComponent.h"

template <class obj_t>
class UnitInputComponent: public InputComponent<obj_t>
{  
public:
    UnitInputComponent();
    ~UnitInputComponent();
    
    virtual void update();
};

template <class obj_t>
UnitInputComponent<obj_t>::UnitInputComponent():
    InputComponent<obj_t>()
{
    
}

template <class obj_t>
UnitInputComponent<obj_t>::~UnitInputComponent()
{
    
}

template <class obj_t>
void UnitInputComponent<obj_t>::update()
{
    InputComponent<obj_t>::update();
}
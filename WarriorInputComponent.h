#pragma once

#include "UnitInputComponent.h"

template <class obj_t>
class WarriorInputComponent: public UnitInputComponent<obj_t>
{  
public:
    WarriorInputComponent();
    virtual ~WarriorInputComponent();
    
    virtual void update();
};

template <class obj_t>
WarriorInputComponent<obj_t>::WarriorInputComponent():
    UnitInputComponent<obj_t>()
{
    
}

template <class obj_t>
WarriorInputComponent<obj_t>::~WarriorInputComponent()
{
    
}

template <class obj_t>
void WarriorInputComponent<obj_t>::update()
{
    InputComponent<obj_t>::update();
}
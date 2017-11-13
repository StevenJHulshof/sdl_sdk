#pragma once

#include "Component.h"
#include "windows.h"

template <class obj_t>
class InputComponent: public Component<obj_t> 
{
public:
    InputComponent();
    ~InputComponent();
    
    virtual void update();
};

template <class obj_t>
InputComponent<obj_t>::InputComponent():
    Component<obj_t>() 
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
InputComponent<obj_t>::~InputComponent()
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
void InputComponent<obj_t>::update()
{
    
}



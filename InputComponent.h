#pragma once

#include "Component.h"

template <class obj_t>
class InputComponent: public Component<obj_t> {
public:
    InputComponent();
       
};

template <class obj_t>
InputComponent<obj_t>::InputComponent():
    Component<obj_t>() {
}





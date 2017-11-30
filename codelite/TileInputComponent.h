#pragma once

#include "InputComponent.h"

template <class obj_t>
class TileInputComponent: public InputComponent<obj_t>
{  
public:
    TileInputComponent();
    virtual ~TileInputComponent();
    
    virtual void update();
    virtual void render(int xPos, int yPos);
};

template <class obj_t>
TileInputComponent<obj_t>::TileInputComponent():
    InputComponent<obj_t>()
{
    
}

template <class obj_t>
TileInputComponent<obj_t>::~TileInputComponent()
{
    
}

template <class obj_t>
void TileInputComponent<obj_t>::update()
{
    InputComponent<obj_t>::update();
}

template <class obj_t>
void TileInputComponent<obj_t>::render(int xPos, int yPos)
{
    
}
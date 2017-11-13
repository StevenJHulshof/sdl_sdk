#pragma once

#include "GraphicsComponent.h"

template <class obj_t>
class TileGraphicsComponent: public GraphicsComponent<obj_t>
{  
public:
    TileGraphicsComponent();
    ~TileGraphicsComponent();
};

template <class obj_t>
TileGraphicsComponent<obj_t>::TileGraphicsComponent():
    GraphicsComponent<obj_t>()
{
    
}

template <class obj_t>
TileGraphicsComponent<obj_t>::~TileGraphicsComponent()
{
    
}
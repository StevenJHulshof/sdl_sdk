#pragma once

#include "GraphicsComponent.h"

template <class obj_t>
class TileGraphicsComponent: public GraphicsComponent<obj_t>
{  
public:
    TileGraphicsComponent();
    ~TileGraphicsComponent();
    
    virtual void render();
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

template <class obj_t>
void TileGraphicsComponent<obj_t>::render()
{
    GraphicsComponent<obj_t>::render();
    
    bool selected = false;
    this->getGameObject()->template send(MSG_GET_INPUT, MSG_DATA_INPUT_SELECTED, &selected);
    
    if(selected)
    {
        gTextures[TEXTURE_TILE_SELECTED].render(this->screenPosX, this->screenPosY, NULL, 0, NULL, this->flip, this->zoom);
    }
}
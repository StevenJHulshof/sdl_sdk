#pragma once

#include "world_types.h"
#include "GraphicsComponent.h"
#include "Overlay.h"

template <class obj_t>
class TileGraphicsComponent: public GraphicsComponent<obj_t>
{  
public:
    TileGraphicsComponent();
    virtual ~TileGraphicsComponent();
    
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
    
    bool hovered = false;
    int type = 0;
    this->getGameObject()->template send<int, bool>(MSG_GET_INPUT, MSG_DATA_INPUT_HOVERED, &hovered);
    this->getGameObject()->template send<int, int>(MSG_GET_PHYSICS, MSG_DATA_PHYSICS_TYPE, &type);
    
    
    if(type == WORLD_TILE_WATER || type == WORLD_TILE_SAND)
    {
        int xPos, yPos;
        this->getGameObject()->template send<int, int>(MSG_GET_PHYSICS, MSG_DATA_PHYSICS_X_POS, &xPos);
        this->getGameObject()->template send<int, int>(MSG_GET_PHYSICS, MSG_DATA_PHYSICS_Y_POS, &yPos);
        
        int overlay = Overlay::getTileOverlay(this->getGameObject()->getContainer()->_tileGrid, xPos, yPos, type);
  
        if(overlay < 63)
        {
            gTextures[TEXTURE_TILE_OVERLAY_0000 + overlay].render(this->screenPosX, this->screenPosY, NULL, 0, NULL, this->flip, this->zoom);
        }
    }
    
    if(hovered)
    {
        gTextures[TEXTURE_TILE_HOVERED].render(this->screenPosX, this->screenPosY, NULL, 0, NULL, this->flip, this->zoom);
    }
}
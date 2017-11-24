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
    
    virtual void render(int xPos, int yPos);
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
void TileGraphicsComponent<obj_t>::render(int xPos, int yPos)
{    
    int type = 0;
    this->getGameObject()->template send<int, int>(MSG_GET_PHYSICS, MSG_DATA_PHYSICS_TYPE, &type);
    
    int screenPosX = 0, screenPosY = 0;
    
    int w = gTextures[this->textureType].getWidth() * this->zoom;
    int h = gTextures[this->textureType].getHeight() * this->zoom;
    Translate::gridToScreenPos(xPos, yPos, w, h, &screenPosX, &screenPosY);
    
    gTextures[this->textureType].render(screenPosX + this->offsetX, screenPosY + this->offsetY, NULL, 0, NULL, this->flip, this->zoom);   
    if(type == WORLD_TILE_WATER || type == WORLD_TILE_SAND)
    {        
        int overlay = Overlay::getTileOverlay(this->getGameObject()->getContainer()->_tileGrid, xPos, yPos, type);
        if(overlay < 63)
        {
            gTextures[TEXTURE_TILE_OVERLAY_0000 + overlay].render(screenPosX + this->offsetX, screenPosY + this->offsetY, NULL, 0, NULL, this->flip, this->zoom);
        }
    }
}
#pragma once

#include "tile_types.h"
#include "GameObject.h"
#include "GraphicsComponent.h"

template <class obj_t>
class TileGraphicsComponent: public GraphicsComponent<obj_t>
{
private:
    int overlay;
    
    void renderOverlayQ0();
    
public:
    TileGraphicsComponent();
    ~TileGraphicsComponent();

    virtual void receive(int message, int data, int *respons);
    virtual void update();
    virtual void render();
};

template <class obj_t>
TileGraphicsComponent<obj_t>::TileGraphicsComponent():
    GraphicsComponent<obj_t>(),
    overlay(0)
{

}

template <class obj_t>
TileGraphicsComponent<obj_t>::~TileGraphicsComponent()
{
}

template <class obj_t>
void TileGraphicsComponent<obj_t>::receive(int message, int data, int *response) {
    
    switch(message) 
    {    
        case MSG_GET_GRAPHICS:
        switch(data) 
        {
            case TILE_TEXTURE_TYPE:
            *response = this->textureType;
            break;  
        }
        break;
         
        case MSG_TILE_TYPE:
        switch(data) 
        {
            case TILE_TYPE_GRASS:
            this->textureType = TEXTURE_TILE_GRASS_0000;
            break;
            
            case TILE_TYPE_WATER:
            this->textureType = TEXTURE_TILE_WATER_0000;
            break;          
        }
        break;

        default:
        break;
    }
}

template <class obj_t>
void TileGraphicsComponent<obj_t>::update() 
{
    int x = this->getGameObject()->send(MSG_GET_PHYSICS, TILE_POS_X);
    int y = this->getGameObject()->send(MSG_GET_PHYSICS, TILE_POS_Y);
    int z = this->getGameObject()->send(MSG_GET_PHYSICS, TILE_POS_Z);
    
    overlay = 0;
    for(int xPos = -1; xPos < 2; xPos++)
    {
        for(int yPos = -1; yPos < 2; yPos++)
        {
            if(x + xPos >= 0 && x + xPos < TILE_GRID_X && y + yPos >= 0 && y + yPos < TILE_GRID_Y && z + 1 < TILE_GRID_Z)
            {
                if(this->getGameObject()->getContainer()->_tileGrid[x+xPos][y+yPos][z+1] != TILE_TYPE_EMPTY)
                {
                    overlay |= (1 << (xPos + 1 + (yPos + 1) * 3));
                }
            }
        }
    }
    
    int w = gTextures[TEXTURE_TILE_TEMPLATE].getWidth();
    int h = gTextures[TEXTURE_TILE_TEMPLATE].getHeight();
    
    this->screenPosX = x * w * 0.5 - y * h * 0.5 + 600;
    this->screenPosY = x * h * 0.25 + y * h * 0.25 - z * h * 0.25;
    
    DEBUG_FUN_VAR("%p | %s\ntextureType: %d, screenPosX: %d, screenPosY: %d\n", this->getGameObject(), __PRETTY_FUNCTION__, this->textureType, this->screenPosX, this->screenPosY);
}

template <class obj_t>
void TileGraphicsComponent<obj_t>::render() 
{
    gTextures[this->textureType].render(
        this->screenPosX,
        this->screenPosY,
        NULL, 0, NULL, this->flip);
        
    renderOverlayQ0();
}

template <class obj_t>
void TileGraphicsComponent<obj_t>::renderOverlayQ0()
{
    int overlayQ0 = ( ((overlay & 1) << 1) | 
                      (((overlay >> 1) & 1) << 2) |
                      ((overlay >> 3) & 1) );
                      
    if(overlayQ0 == 1 || overlayQ0 == 3)
    {
        gTextures[this->textureType + 1].render(
        this->screenPosX,
        this->screenPosY,
        NULL, 0, NULL, this->flip);
    }
    else if(overlayQ0 == 4 || overlayQ0 == 6) 
    {
        gTextures[this->textureType + 2].render(
        this->screenPosX,
        this->screenPosY,
        NULL, 0, NULL, this->flip);
    }
    else if(overlayQ0 == 2) 
    {
        gTextures[this->textureType + 3].render(
        this->screenPosX,
        this->screenPosY,
        NULL, 0, NULL, this->flip);
    } 
    else if(overlayQ0 == 5 || overlayQ0 == 7)
    {
        gTextures[this->textureType + 4].render(
        this->screenPosX,
        this->screenPosY,
        NULL, 0, NULL, this->flip);
    }
}
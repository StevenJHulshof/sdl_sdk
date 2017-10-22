#pragma once

#include "tile_types.h"
#include "GameObject.h"
#include "GraphicsComponent.h"

template <class obj_t>
class TileGraphicsComponent: public GraphicsComponent<obj_t>
{
public:
    TileGraphicsComponent();
    ~TileGraphicsComponent();

    virtual void receive(int message, int data, int *respons);
    virtual void update();
    virtual void render(int x, int y);
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
void TileGraphicsComponent<obj_t>::receive(int message, int data, int *response) {
    
    switch(message) {
        
        case MSG_GET:
        switch(data) {
            case TILE_TEXTURE_TYPE:
            *response = this->textureType;
            break;  
        }
        break;
         
        case MSG_TILE_TYPE:
        switch(data) {
            
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
void TileGraphicsComponent<obj_t>::update() {
    
}

template <class obj_t>
void TileGraphicsComponent<obj_t>::render(int x, int y) {
    gTextures[this->textureType].render(x, y, NULL, 0, NULL, this->flip);
}

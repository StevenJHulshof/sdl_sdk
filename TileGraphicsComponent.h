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
void TileGraphicsComponent<obj_t>::receive(int message, int data, int *response) {
    
    switch(message) {
        
        case MSG_GET_GRAPHICS:
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
    DEBUG_FUN_VAR("%p | %s\ntextureType: %d\n", this->getGameObject(), __PRETTY_FUNCTION__, this->textureType);
}

template <class obj_t>
void TileGraphicsComponent<obj_t>::render() {

    gTextures[this->textureType].render(
        this->getGameObject()->send(MSG_GET_PHYSICS, TILE_POS_X),
        this->getGameObject()->send(MSG_GET_PHYSICS, TILE_POS_Y),
        NULL, 0, NULL, this->flip);
}

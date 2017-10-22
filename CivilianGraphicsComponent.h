#pragma once

#include "civilian_types.h"
#include "GraphicsComponent.h"
#include "GameObject.h"

template <class obj_t>
class CivilianGraphicsComponent: public GraphicsComponent<obj_t>
{
private:
    
public:
    CivilianGraphicsComponent();
    ~CivilianGraphicsComponent();

    virtual void receive(int message, int data, int *response);
    virtual void update();
    virtual void render();
};

template <class obj_t>
CivilianGraphicsComponent<obj_t>::CivilianGraphicsComponent():
    GraphicsComponent<obj_t>() {
    this->textureType = TEXTURE_UNIT_CIVILIAN_0000 + rand() % UNIT_CIVILIAN_TEXTURES_TOTAL;
}

template <class obj_t>
CivilianGraphicsComponent<obj_t>::~CivilianGraphicsComponent() {

}

template <class obj_t>
void CivilianGraphicsComponent<obj_t>::receive(int message, int data, int *response) {
    
    switch(message) {
        
        case MSG_CIVILIAN_MOVE:
        switch(data) {
            
            case CIVILIAN_MOVE_LEFT:
            this->flip = SDL_FLIP_HORIZONTAL;
            break;
            
            case CIVILIAN_MOVE_RIGHT:
            this->flip = SDL_FLIP_NONE;
            break;            
        }
        break;

        default:
        break;
    }
}

template <class obj_t>
void CivilianGraphicsComponent<obj_t>::update() {
}

template <class obj_t>
void CivilianGraphicsComponent<obj_t>::render() {
    gTextures[this->textureType].render(
        this->getGameObject()->send(MSG_GET, CIVILIAN_POS_X),
        this->getGameObject()->send(MSG_GET, CIVILIAN_POS_Y),
        NULL, 0, NULL, this->flip);
}


#pragma once

#include "tile_types.h"
#include "GameObject.h"
#include "PhysicsComponent.h"

template <class obj_t>
class TilePhysicsComponent: public PhysicsComponent<obj_t> {
public:
    TilePhysicsComponent();
    ~TilePhysicsComponent();

    virtual void receive(int message, int data, int *respons);
    virtual void update();
};

template <class obj_t>
TilePhysicsComponent<obj_t>::TilePhysicsComponent():
    PhysicsComponent<obj_t>()
{
}

template <class obj_t>
TilePhysicsComponent<obj_t>::~TilePhysicsComponent()
{
}

template <class obj_t>
void TilePhysicsComponent<obj_t>::receive(int message, int data, int *response) {
    
    switch(message) {
        
        case MSG_GET_PHYSICS:
        switch(data) {

            case TILE_POS_X:
            *response = this->xPos;
            break;
            
            case TILE_POS_Y:
            *response = this->yPos;
            break;
            
            default:
            break;
        }
        break;
        
        case MSG_TILE_POS_Y:
        this->yPos = data;
        break;
        
        case MSG_TILE_POS_X:
        this->xPos = data;
        break;

        default:
        break;
    }
}

template <class obj_t>
void TilePhysicsComponent<obj_t>::update() {
     DEBUG_FUN_VAR("%p | %s\nxPos: %d, yPos: %d\n", this->getGameObject(), __PRETTY_FUNCTION__, this->xPos, this->yPos);
}
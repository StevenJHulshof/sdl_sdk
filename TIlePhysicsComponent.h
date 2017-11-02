#pragma once

#include "tile_types.h"
#include "GameObject.h"
#include "PhysicsComponent.h"

template <class obj_t>
class TilePhysicsComponent: public PhysicsComponent<obj_t> {

private:
    int tilePosX, tilePosY, tilePosZ;

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
            *response = tilePosX;
            break;
            
            case TILE_POS_Y:
            *response = tilePosY;
            break;
            
            case TILE_POS_Z:
            *response = tilePosZ;
            break;
            
            default:
            break;
        }
        break;
        
        case MSG_TILE_POS_Y:
        tilePosY = data;
        break;
        
        case MSG_TILE_POS_X:
        tilePosX = data;
        break;
        
        case MSG_TILE_POS_Z:
        tilePosZ = data;
        break;

        default:
        break;
    }
}

template <class obj_t>
void TilePhysicsComponent<obj_t>::update() {
     DEBUG_FUN_VAR("%p | %s\nvelocity: %d\n", this->getGameObject(), __PRETTY_FUNCTION__, this->velocity);
}
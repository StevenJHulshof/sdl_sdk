#pragma once

#include "Component.h"

template <class obj_t>
class PhysicsComponent: public Component<obj_t> 
{
protected:
    int velocity, xPos, yPos;
public:
    PhysicsComponent();
    ~PhysicsComponent();

    virtual void receive(int message, int data, int *response);
    
    virtual void update();
};

template <class obj_t>
PhysicsComponent<obj_t>::PhysicsComponent():
    Component<obj_t>(),
    velocity(0),
    xPos(0),
    yPos(0)
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
PhysicsComponent<obj_t>::~PhysicsComponent() {
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
void PhysicsComponent<obj_t>::receive(int message, int data, int *response)
{
     switch(message) {
        
        case MSG_GET_PHYSICS:
        switch(data) {

            case MSG_DATA_PHYSICS_X_POS:
            *response = xPos;
            break;
            
            case MSG_DATA_PHYSICS_Y_POS:
            *response = yPos;
            break;
            
            case MSG_DATA_PHYSICS_VELOCITY:
            *response = velocity;
            break;
            
            default:
            break;
        }
        break;
        
        case MSG_SET_PHYSICS_X_POS:
        xPos = data;
        break;
        
        case MSG_SET_PHYSICS_Y_POS:
        yPos = data;
        break;
        
        case MSG_SET_PHYSICS_VELOCITY:
        velocity = data;
        break;

        default:
        break;
    }
}

template <class obj_t>
void PhysicsComponent<obj_t>::update()
{
     DEBUG_FUN_VAR("%p | %s\nxPos: %d, yPos: %d, velocity: %d\n", this->getGameObject(), __PRETTY_FUNCTION__, xPos, yPos, velocity);
}
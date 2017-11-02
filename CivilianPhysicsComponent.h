#pragma once

#include "civilian_types.h"
#include "config_types.h"
#include "GameObject.h"
#include "PhysicsComponent.h"

template <class obj_t>
class CivilianPhysicsComponent: public PhysicsComponent<obj_t>
{
public:
    CivilianPhysicsComponent();
    ~CivilianPhysicsComponent();

    virtual void receive(int message, int data, int *response);
    virtual void update();
};

template <class obj_t>
CivilianPhysicsComponent<obj_t>::CivilianPhysicsComponent():
    PhysicsComponent<obj_t>()
{
}

template <class obj_t>
CivilianPhysicsComponent<obj_t>::~CivilianPhysicsComponent()
{
}

template <class obj_t>
void CivilianPhysicsComponent<obj_t>::receive(int message, int data, int *response) {
    
//    switch(message) {
//        
//        case MSG_GET_PHYSICS:
//        switch(data) {
//            
//            case CIVILIAN_POS_X:
//            *response = this->xPos;
//            break; 
//
//            case CIVILIAN_POS_Y:
//            *response = this->yPos;
//            break;     
//        }
//        break;
//        
//        case MSG_CIVILIAN_MOVE:
//
//        switch(data) {
//            
//            case CIVILIAN_MOVE_UP:
//            if(this->yPos > 0)
//                this->yPos -= this->velocity;
//            break;
//            
//            case CIVILIAN_MOVE_DOWN:
//            if(this->yPos < SCREEN_HEIGHT)
//                this->yPos += this->velocity;
//            break;
//          
//            case CIVILIAN_MOVE_LEFT:
//            if(this->xPos > 0)
//                this->xPos -= this->velocity*2;
//            break;
//            
//            case CIVILIAN_MOVE_RIGHT:
//            if(this->xPos < SCREEN_WIDTH)
//                this->xPos += this->velocity*2;
//            break;            
//        }
//        break;
//
//        case MSG_CIVILIAN_POS_X:
//        this->xPos = data;
//        break;
//        
//        case MSG_CIVILIAN_POS_Y:
//        this->yPos = data;
//        break;
//        
//        case MSG_CIVILIAN_VELOCITY:
//        this->velocity = data;
//        break;
//        
//        default:
//        break;
//    }
}

template <class obj_t>
void CivilianPhysicsComponent<obj_t>::update() {
}

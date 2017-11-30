#pragma once

#include "priority.h"
#include "GameObject.h"
#include "ResourceInputComponent.h"
#include "ResourcePhysicsComponent.h"
#include "ResourceGraphicsComponent.h"

template <class con_t>
class Resource: public GameObject<Resource<con_t>, con_t>
{
private:
    ResourceInputComponent<Resource<con_t>> resourceInputComponent;
    ResourcePhysicsComponent<Resource<con_t>> resourcePhysicsComponent;
    ResourceGraphicsComponent<Resource<con_t>> resourceGraphicsComponent;
    
public:
    
    Resource(int x, int y, int type, int textureType);
    virtual ~Resource();
};

template <class con_t>
Resource<con_t>::Resource(int x, int y, int type, int textureType):
    GameObject<Resource<con_t>, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    
    this->addComponent(this, &resourceInputComponent);
    this->addComponent(this, &resourcePhysicsComponent);
    this->addComponent(this, &resourceGraphicsComponent);
    
    this->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, textureType);
    
    this->template send<int, int>(MSG_SET_PHYSICS_X_POS, x);
    this->template send<int, int>(MSG_SET_PHYSICS_Y_POS, y);
    
    this->template send<int, int>(MSG_SET_PHYSICS_TYPE, type);
    
    this->template send<int, int>(MSG_SET_INPUT_PRIORITY, PRIORITY_RESOURCE);
}

template <class con_t>
Resource<con_t>::~Resource()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}
#pragma once

#include "priority.h"
#include "Resource.h"
#include "RawWoodInputComponent.h"
#include "RawWoodPhysicsComponent.h"
#include "RawWoodGraphicsComponent.h"

template <class con_t>
class RawWood: public GameObject<RawWood<con_t>, con_t>
{
private:
    RawWoodInputComponent<RawWood<con_t>> rawWoodInputComponent;
    RawWoodPhysicsComponent<RawWood<con_t>> rawWoodPhysicsComponent;
    RawWoodGraphicsComponent<RawWood<con_t>> rawWoodGraphicsComponent;
    
public:
    
    RawWood(int x, int y);
    virtual ~RawWood();
};

template <class con_t>
RawWood<con_t>::RawWood(int x, int y):
    GameObject<RawWood<con_t>, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    
    this->addComponent(this, &rawWoodInputComponent);
    this->addComponent(this, &rawWoodPhysicsComponent);
    this->addComponent(this, &rawWoodGraphicsComponent);
    
    this->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, TEXTURE_RESOURCE_RAW_WOOD);
    this->template send<int, int>(MSG_SET_PHYSICS_X_POS, x);
    this->template send<int, int>(MSG_SET_PHYSICS_Y_POS, y);
    this->template send<int, int>(MSG_SET_INPUT_PRIORITY, PRIORITY_RESOURCE);
}

template <class con_t>
RawWood<con_t>::~RawWood()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}
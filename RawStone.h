#pragma once

#include "priority.h"
#include "world_types.h"
#include "Resource.h"
#include "RawStoneInputComponent.h"
#include "RawStonePhysicsComponent.h"
#include "RawStoneGraphicsComponent.h"

template <class con_t>
class RawStone: public GameObject<RawStone<con_t>, con_t>
{
private:
    RawStoneInputComponent<RawStone<con_t>> rawStoneInputComponent;
    RawStonePhysicsComponent<RawStone<con_t>> rawStonePhysicsComponent;
    RawStoneGraphicsComponent<RawStone<con_t>> rawStoneGraphicsComponent;
    
public:
    
    RawStone(int x, int y);
    virtual ~RawStone();
};

template <class con_t>
RawStone<con_t>::RawStone(int x, int y):
    GameObject<RawStone<con_t>, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    
    this->addComponent(this, &rawStoneInputComponent);
    this->addComponent(this, &rawStonePhysicsComponent);
    this->addComponent(this, &rawStoneGraphicsComponent);
    
    this->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, TEXTURE_RESOURCE_RAW_STONE);
    this->template send<int, int>(MSG_SET_PHYSICS_X_POS, x);
    this->template send<int, int>(MSG_SET_PHYSICS_Y_POS, y);
    this->template send<int, int>(MSG_SET_PHYSICS_TYPE, WORLD_RESOURCE_RAW_STONE);
    this->template send<int, int>(MSG_SET_INPUT_PRIORITY, PRIORITY_RESOURCE);
}

template <class con_t>
RawStone<con_t>::~RawStone()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}
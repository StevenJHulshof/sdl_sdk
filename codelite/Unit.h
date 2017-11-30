#pragma once

#include "priority.h"
#include "GameObject.h"
#include "UnitInputComponent.h"
#include "UnitPhysicsComponent.h"
#include "UnitGraphicsComponent.h"

template <class con_t>
class Unit: public GameObject<Unit<con_t>, con_t>
{
private:
    UnitInputComponent<Unit<con_t>> unitInputComponent;
    UnitPhysicsComponent<Unit<con_t>> unitPhysicsComponent;
    UnitGraphicsComponent<Unit<con_t>> unitGraphicsComponent;
    
public:
    
    Unit(int x, int y, int type, int textureType);
    virtual ~Unit();
};

template <class con_t>
Unit<con_t>::Unit(int x, int y, int type, int textureType):
    GameObject<Unit<con_t>, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    
    this->addComponent(this, &unitInputComponent);
    this->addComponent(this, &unitPhysicsComponent);
    this->addComponent(this, &unitGraphicsComponent);
    
    this->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, textureType);
    this->template send<int, int>(MSG_SET_PHYSICS_X_POS, x);
    this->template send<int, int>(MSG_SET_PHYSICS_Y_POS, y);
    this->template send<int, int>(MSG_SET_PHYSICS_TYPE, type);
    this->template send<int, int>(MSG_SET_INPUT_PRIORITY, PRIORITY_UNIT);
}

template <class con_t>
Unit<con_t>::~Unit()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}
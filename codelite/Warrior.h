#pragma once

#include "priority.h"
#include "world_types.h"
#include "Unit.h"
#include "WarriorInputComponent.h"
#include "WarriorPhysicsComponent.h"
#include "WarriorGraphicsComponent.h"

template <class con_t>
class Warrior: public GameObject<Warrior<con_t>, con_t>
{
private:
    WarriorInputComponent<Warrior<con_t>> warriorInputComponent;
    WarriorPhysicsComponent<Warrior<con_t>> warriorPhysicsComponent;
    WarriorGraphicsComponent<Warrior<con_t>> warriorGraphicsComponent;
    
public:
    
    Warrior(int x, int y);
    virtual ~Warrior();
};

template <class con_t>
Warrior<con_t>::Warrior(int x, int y):
    GameObject<Warrior<con_t>, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    
    this->addComponent(this, &warriorInputComponent);
    this->addComponent(this, &warriorPhysicsComponent);
    this->addComponent(this, &warriorGraphicsComponent);
    
    this->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, TEXTURE_UNIT_WARRIOR);
    this->template send<int, int>(MSG_SET_PHYSICS_X_POS, x);
    this->template send<int, int>(MSG_SET_PHYSICS_Y_POS, y);
    this->template send<int, int>(MSG_SET_PHYSICS_TYPE, WORLD_UNIT_WARRIOR);
    this->template send<int, int>(MSG_SET_INPUT_PRIORITY, PRIORITY_UNIT);
}

template <class con_t>
Warrior<con_t>::~Warrior()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}
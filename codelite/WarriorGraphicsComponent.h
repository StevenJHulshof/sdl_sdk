#pragma once

#include "UnitGraphicsComponent.h"

template <class obj_t>
class WarriorGraphicsComponent: public UnitGraphicsComponent<obj_t>
{  
public:
    WarriorGraphicsComponent();
    virtual ~WarriorGraphicsComponent();
    
    virtual void update();
    virtual void render();
};

template <class obj_t>
WarriorGraphicsComponent<obj_t>::WarriorGraphicsComponent():
    UnitGraphicsComponent<obj_t>()
{
    
}

template <class obj_t>
WarriorGraphicsComponent<obj_t>::~WarriorGraphicsComponent()
{
    
}

template <class obj_t>
void WarriorGraphicsComponent<obj_t>::update()
{
    GraphicsComponent<obj_t>::update();
}

template <class obj_t>
void WarriorGraphicsComponent<obj_t>::render()
{
    GraphicsComponent<obj_t>::render();
    
    bool selected = false, hovered = false;
    this->getGameObject()->template send<int, bool>(MSG_GET_INPUT, MSG_DATA_INPUT_SELECTED, &selected);
    this->getGameObject()->template send<int, bool>(MSG_GET_INPUT, MSG_DATA_INPUT_HOVERED, &hovered);
    
    if(hovered)
    {
        gTextures[TEXTURE_UNIT_WARRIOR_HOVERED].render(this->screenPosX, this->screenPosY, NULL, 0, NULL, this->flip, this->zoom);
    }
    
    if(selected)
    {
        gTextures[TEXTURE_UNIT_WARRIOR_SELECTED].render(this->screenPosX, this->screenPosY, NULL, 0, NULL, this->flip, this->zoom);
    }
}
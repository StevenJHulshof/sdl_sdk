#pragma once

#include "ResourceGraphicsComponent.h"

template <class obj_t>
class RawStoneGraphicsComponent: public ResourceGraphicsComponent<obj_t>
{  
public:
    RawStoneGraphicsComponent();
    virtual ~RawStoneGraphicsComponent();
    
    virtual void update();
    virtual void render();
};

template <class obj_t>
RawStoneGraphicsComponent<obj_t>::RawStoneGraphicsComponent():
    ResourceGraphicsComponent<obj_t>()
{
    
}

template <class obj_t>
RawStoneGraphicsComponent<obj_t>::~RawStoneGraphicsComponent()
{
    
}

template <class obj_t>
void RawStoneGraphicsComponent<obj_t>::update()
{
    GraphicsComponent<obj_t>::update();
}

template <class obj_t>
void RawStoneGraphicsComponent<obj_t>::render()
{
    GraphicsComponent<obj_t>::render();
    
    bool hovered = false;
    this->getGameObject()->template send(MSG_GET_INPUT, MSG_DATA_INPUT_HOVERED, &hovered);
    
    if(hovered)
    {
        gTextures[TEXTURE_RESOURCE_RAW_STONE_HOVERED].render(this->screenPosX, this->screenPosY, NULL, 0, NULL, this->flip, this->zoom);
    }
}
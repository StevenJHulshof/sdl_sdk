#pragma once

#include "priority.h"
#include "GameObject.h"
#include "TileInputComponent.h"
#include "TilePhysicsComponent.h"
#include "TileGraphicsComponent.h"

template <class con_t>
class Tile: public GameObject<Tile<con_t>, con_t>
{
private:
    TileInputComponent<Tile<con_t>> tileInputComponent;
    TilePhysicsComponent<Tile<con_t>> tilePhysicsComponent;
    TileGraphicsComponent<Tile<con_t>> tileGraphicsComponent;
    
public:
    
    Tile(int x, int y, int type, int textureType);
    virtual ~Tile();
    
    void render(int xPos, int yPos);
};

template <class con_t>
Tile<con_t>::Tile(int x, int y, int type, int textureType):
    GameObject<Tile<con_t>, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    
    this->addComponent(this, &tileInputComponent);
    this->addComponent(this, &tilePhysicsComponent);
    this->addComponent(this, &tileGraphicsComponent);
    
    this->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, textureType);
    this->template send<int, int>(MSG_SET_PHYSICS_X_POS, x);
    this->template send<int, int>(MSG_SET_PHYSICS_Y_POS, y);
    this->template send<int, int>(MSG_SET_PHYSICS_TYPE, type);
    this->template send<int, int>(MSG_SET_INPUT_PRIORITY, PRIORITY_TILE);
}

template <class con_t>
Tile<con_t>::~Tile()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class con_t>
void Tile<con_t>::render(int xPos, int yPos) 
{
    for(Component<Tile<con_t>> *component : this->_components) 
    {
        component->render(xPos, yPos);
    }
}
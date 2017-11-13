#pragma once

#include "GameObject.h"
#include "TilePhysicsComponent.h"
#include "TileGraphicsComponent.h"

template <class con_t>
class Tile: public GameObject<Tile<con_t>, con_t>
{
private:
    TilePhysicsComponent<Tile> tilePhysicsComponent;
    TileGraphicsComponent<Tile> tileGraphicsComponent;
    
public:
    
    Tile(int x, int y, int textureType);
    ~Tile();
};

template <class con_t>
Tile<con_t>::Tile(int x, int y, int textureType):
    GameObject<Tile<con_t>, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
        
    this->addComponent(this, &tilePhysicsComponent);
    this->addComponent(this, &tileGraphicsComponent);
    
    this->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, textureType);
    this->template send<int, int>(MSG_SET_PHYSICS_X_POS, x);
    this->template send<int, int>(MSG_SET_PHYSICS_Y_POS, y);
}

template <class con_t>
Tile<con_t>::~Tile()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}
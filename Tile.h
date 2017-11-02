#pragma once

#include "TileGraphicsComponent.h"
#include "TilePhysicsComponent.h"

template <class con_t>
class Tile: public GameObject<Tile<con_t>, con_t>
{
private:

    TilePhysicsComponent<Tile> physicsComponent;
    TileGraphicsComponent<Tile> graphicsComponent;
public:
    
    Tile(int x, int y, int z, int tileType);
    ~Tile();
};

template <class con_t>
Tile<con_t>::Tile(int x, int y, int z, int tileType):
    GameObject<Tile, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
        
    this->addComponent(this, &physicsComponent);
    this->addComponent(this, &graphicsComponent);
    
    this->send(MSG_TILE_TYPE, tileType);
    this->send(MSG_TILE_POS_X, x);
    this->send(MSG_TILE_POS_Y, y);
    this->send(MSG_TILE_POS_Z, z);
}

template <class con_t>
Tile<con_t>::~Tile()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}
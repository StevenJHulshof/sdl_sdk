#include "Tile.h"

Tile::Tile(int x, int y, int tileType):
    GameObject<Tile>() 
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
        
    addComponent(this, &physicsComponent);
    addComponent(this, &graphicsComponent);
    
    send(MSG_TILE_TYPE, tileType);
    send(MSG_TILE_POS_X, x);
    send(MSG_TILE_POS_Y, y);
}

Tile::~Tile()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}
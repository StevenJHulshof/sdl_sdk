#include "Tile.h"

Tile::Tile(int x, int y, int tileType):
    GameObject<Tile>() {
        
    addComponent(this, &physicsComponent);
    addComponent(this, &graphicsComponent);
    
    send(MSG_TILE_TYPE, tileType);
    send(MSG_TILE_POS_X, x);
    send(MSG_TILE_POS_Y, y);
}

Tile::~Tile()
{
}
#include "Tile.h"

Tile::Tile(int tileType):
    GameObject<Tile>() {
        
    addComponent(this, &graphicsComponent);
    send(MSG_TILE_TYPE, tileType);
}

Tile::~Tile()
{
}
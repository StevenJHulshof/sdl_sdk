#pragma once

#include "TileGraphicsComponent.h"
#include "TilePhysicsComponent.h"

class Tile: public GameObject<Tile>
{
private:

    TilePhysicsComponent<Tile> physicsComponent;
    TileGraphicsComponent<Tile> graphicsComponent;
public:

    Tile(int x, int y, int tileType);
    ~Tile();
        

};


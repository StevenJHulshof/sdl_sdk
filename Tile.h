#pragma once

#include "GameObjectFlyWeight.h"
#include "TileGraphicsComponent.h"

class Tile: public GameObject<Tile>
{
private:

    
public:

    Tile(int tileType);
    ~Tile();
        
    TileGraphicsComponent<Tile> graphicsComponent;
};


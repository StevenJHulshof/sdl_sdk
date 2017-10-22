#pragma once

#include "Tile.h"

class Generator {

private:
    static int _gridWidth, _gridLength;
    
public:
    Generator(int gridWidth, int gridLength);
    ~Generator();

    void fill(Tile tileGrid[_gridWidth][_gridLength], Tile *tile);
};


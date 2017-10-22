#include "Generator.h"

Generator::Generator(int gridWidth, int gridLength) {
    _gridWidth = gridWidth;
    _gridLength = gridLength;
}

Generator::~Generator()
{
}

void Generator::fill(Tile tileGrid[_gridWidth][_gridLength], Tile *tile) {
    for(int y = 0; y < gridWidth; y++) {
        for(int x = 0; x < gridLength; x++) {
            tileGrid[x][y] = tile;
        }
    }
}

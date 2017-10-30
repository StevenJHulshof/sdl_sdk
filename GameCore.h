#pragma once

#include "Tile.h"

class GameCore {
private:

    Tile tile;

public:
    GameCore();
    void update();
    void render();
};
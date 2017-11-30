#pragma once

#include "Container.h"

class GameCore
{
private:
    Container container;

public:
    GameCore();
    void update();
    void render();
};

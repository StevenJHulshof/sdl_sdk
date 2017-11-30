#pragma once

#include "World.h"

class GameCore {
private:
   World world; 
    
public:
    GameCore();
    void update();
    void render();
};
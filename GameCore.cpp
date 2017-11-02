#include "GameCore.h"

GameCore::GameCore():
    world()
{
    
}

void GameCore::update() {
    
    world.update();
}

void GameCore::render() {
    
    world.render();
}
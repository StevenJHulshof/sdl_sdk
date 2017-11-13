#include "GameCore.h"

GameCore::GameCore():
    world()
{
    
}

void GameCore::update() {
    
    world.update();
}

void GameCore::render() {
  //  gTextures[TEXTURE_TILE_GRASS_OVERLAY_0007].render(10, 10, NULL, 0, NULL, SDL_FLIP_NONE);
    world.render();
}
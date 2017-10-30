#include "GameCore.h"

GameCore::GameCore():
    tile(100, 100, TILE_TYPE_GRASS) {
    
}

void GameCore::update() {
    tile.update();
}

void GameCore::render() {
    tile.render();
}
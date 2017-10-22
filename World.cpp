#include "World.h"


World::World():
    civ0(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ1(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ3(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ4(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ5(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ6(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ7(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ8(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ9(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ10(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    civ11(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1), 
    grassTile(TILE_TYPE_GRASS),
    waterTile(TILE_TYPE_WATER) {
    
    fillTileGrid(&grassTile);
}

World::~World()
{
}

void World::update() {
    civ0.update();
    civ1.update();
    civ2.update();
    civ3.update();
    civ4.update();
    civ5.update();
    civ6.update();
    civ7.update();
    civ8.update();
    civ9.update();
    civ10.update();
    civ11.update();
}

void World::render() {
    
    int tileWidth = gTextures[TEXTURE_TILE_GRASS_0000].getWidth();
    int tileHeight =  gTextures[TEXTURE_TILE_GRASS_0000].getHeight() / 2;
    
    for(int y = 0; y < WORLD_GRID_LENGTH; y++) {
        for(int x = 0; x < WORLD_GRID_WIDTH; x++) {
            _tileGrid[x][y]->graphicsComponent.render(SCREEN_WIDTH/2 + (x * tileWidth / 2) - (y * tileWidth / 2), (y * tileHeight / 2) + (x * tileHeight / 2));
        }
    }
    
    for(int y = 5; y < 20; y++) {
        for(int x = 5; x < 15; x++) {
        gTextures[TEXTURE_RESOURCE_RAW_WOOD_0000].render(SCREEN_WIDTH/2 + (x * tileWidth / 2) - (y * tileWidth / 2), 0 + (y * tileHeight / 2) + (x * tileHeight / 2),
            NULL, 0, NULL, SDL_FLIP_NONE);
        }
    }
    
    
    
    civ0.render();
    civ1.render();
    civ2.render();
    civ3.render();
    civ4.render();
    civ5.render();
    civ6.render();
    civ7.render();
    civ8.render();
    civ9.render();
    civ10.render();
    civ11.render();
}

void World::fillTileGrid(Tile *tile) {
    for(int y = 0; y < WORLD_GRID_LENGTH; y++) {
        for(int x = 0; x < WORLD_GRID_WIDTH; x++) {
            _tileGrid[x][y] = tile;
        }
    }
}
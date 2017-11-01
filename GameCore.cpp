#include "GameCore.h"

GameCore::GameCore()
{
    
    for(int y = 0; y < TILE_GRID_Y; y++) 
    {
        for(int x = 0; x < TILE_GRID_X; x++) 
        {
            _heightMap[x][y] = rand() % 3 + 1;
        }
    }
    
    for(int y = 0; y < TILE_GRID_Y; y++) 
    {
        for(int x = 0; x < TILE_GRID_X; x++) 
        {
            for(int z = 0; z < TILE_GRID_Z; z++) 
            {
                if(z < _heightMap[x][y])
                {
                    _tileGrid[x][y][z] = TILE_TYPE_GRASS;
                }
                else
                {
                    _tileGrid[x][y][z] = TILE_TYPE_EMPTY;
                }
            }
        }
    }
    
    
    
    int w = gTextures[TEXTURE_TILE_GRASS_0000].getWidth();
    int h = gTextures[TEXTURE_TILE_GRASS_0000].getHeight(); 

    for(int z = 0; z < TILE_GRID_Z; z++) 
    {
        for(int y = 0; y < TILE_GRID_Y; y++) 
        {
            for(int x = 0; x < TILE_GRID_X; x++) 
            {
                if(_tileGrid[x][y][z] != TILE_TYPE_EMPTY)
                {
                    Tile *tile = new Tile(600 + x * w * 0.5 - y * h * 0.5, 100 + x * h * 0.25 + y * h * 0.25 - z * h * 0.25, TILE_TYPE_GRASS);
                    _tilePool.push_back(*tile);
                }
            }
        }
    }
}

void GameCore::update() {
    
    for(Tile tile: _tilePool) {
       tile.update();
    }
}

void GameCore::render() {
    
    for(Tile tile: _tilePool) {
       tile.render();
    }
}
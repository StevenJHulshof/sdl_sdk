#include "World.h"

World::World():
    tile_0(10, 10, TILE_TYPE_GRASS),
    tile_1(100, 100, TILE_TYPE_GRASS)
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

World::~World() {
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

void World::renderTilePool() 
{
    tile_0.render();
    tile_1.render();
    
    for(Tile tile: _tilePool) 
    {
        tile.render();
    }
}

void World::fillTileGrid() {

}

void World::fillTilePool() {

    int w = gTextures[TEXTURE_TILE_GRASS_0000].getWidth();
    int h = gTextures[TEXTURE_TILE_GRASS_0000].getHeight();
    
    for(int z = 0; z < TILE_GRID_Z; z++) 
    {
        for(int y = 0; y < TILE_GRID_Y; y++) 
        {
            for(int x = 0; x < TILE_GRID_X; x++) 
            {
                _tilePool.push_back(Tile(600 + x * w * 0.5 - y * h * 0.5, 100 + x * h * 0.25 + y * h * 0.25 - z * h * 0.25, TILE_TYPE_GRASS));
            }
        }
    }
}
#include "World.h"

World::World():
    Container()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif

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

    
    for(int x = 0; x < TILE_GRID_X; x++) 
    {
        for(int y = 0; y < TILE_GRID_Y; y++) 
        {
            for(int z = 0; z < TILE_GRID_Z; z++) 
            {
                if(_tileGrid[x][y][z] != TILE_TYPE_EMPTY)
                {
                    Tile<World> *tile = new Tile<World>(x, y, z, _tileGrid[x][y][z]);
                    tile->setContainer(this);
                    _tilePool.push_back(*tile);
                }
            }
        }
    }
}

World::~World() {
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

void World::update() 
{
    for(Tile<World> tile: _tilePool) 
    {
        tile.update();
    }  
}

void World::render() 
{
    for(Tile<World> tile: _tilePool) 
    {
        tile.render();
    }
}
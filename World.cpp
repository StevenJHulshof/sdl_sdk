#include "World.h"

World::World():
    Container(),
    camera(CAMERA_OFFSET_X_START, CAMERA_OFFSET_Y_START)
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
    
    for(int y = 0; y < TILE_GRID_Y; y++) 
    {
        for(int x = 0; x < TILE_GRID_X; x++) 
        {
            _tileGrid[x][y] = TEXTURE_TILE_GRASS_0000;
        }
    }

    for(int x = 0; x < TILE_GRID_X; x++) 
    {
        for(int y = 0; y < TILE_GRID_Y; y++) 
        {
            Tile<World> *tile = new Tile<World>(x, y, _tileGrid[x][y]);
            tile->setContainer(this);
            _tilePool.push_back(*tile);
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
    camera.update();
    
    for(Tile<World> tile: _tilePool) 
    {
        int offsetX, offsetY;
        camera.template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_X, &offsetX);
        camera.template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_Y, &offsetY);
        tile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, offsetX);
        tile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, offsetY);
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
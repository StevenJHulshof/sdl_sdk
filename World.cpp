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
            
            int r = rand() % 100;
            
            if(r < 25)
            {
                _resourceGrid[x][y] = TEXTURE_RESOURCE_WOOD;               
            }
            else if(r < 40)
            {
                _resourceGrid[x][y] = TEXTURE_RESOURCE_STONE;
            }
            else
            {
                _resourceGrid[x][y] = TEXTURE_TYPE_EMPTY;
            }
        }
    }

    for(int x = 0; x < TILE_GRID_X; x++) 
    {
        for(int y = 0; y < TILE_GRID_Y; y++) 
        {
            if(_resourceGrid[x][y] != TEXTURE_TYPE_EMPTY)
            {
                Resource<World> *resource = new Resource<World>(x, y, _resourceGrid[x][y]);
                resource->setContainer(this);
                _resourcePool.push_back(*resource);
            }
            
            Tile<World> *tile = new Tile<World>(x, y, _tileGrid[x][y]);
            tile->setContainer(this);
            _tilePool.push_back(*tile);
        }
    }
    
    Unit<World> *unit = new Unit<World>(10, 10, TEXTURE_UNIT_WARRIOR);
    unit->setContainer(this);
    _unitPool.push_back(*unit);
}

World::~World() {
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

void World::update() 
{
    camera.update();
    
    int offsetX, offsetY;
    float zoom;
    
    camera.template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_X, &offsetX);
    camera.template send<int, int>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_OFFSET_Y, &offsetY);
    camera.template send<int, float>(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_ZOOM, &zoom);
    
    for(Tile<World> tile: _tilePool) 
    {
        tile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, offsetX);
        tile.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, offsetY);
        tile.template send<float, int>(MSG_SET_GRAPHICS_ZOOM, zoom);
        tile.update();
    }  
    for(Resource<World> resource: _resourcePool) 
    {
        resource.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, offsetX);
        resource.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, offsetY);
        resource.template send<float, int>(MSG_SET_GRAPHICS_ZOOM, zoom);
        resource.update();
    }
    for(Unit<World> unit: _unitPool) 
    {
        unit.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, offsetX);
        unit.template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, offsetY);
        unit.template send<float, int>(MSG_SET_GRAPHICS_ZOOM, zoom);
        unit.update();
    }
}

void World::render() 
{    
    for(Tile<World> tile: _tilePool) 
    {
        tile.render();
    }
    for(Resource<World> resource: _resourcePool) 
    {
        resource.render();
    }
    for(Unit<World> unit: _unitPool) 
    {
        unit.render();
    }
}
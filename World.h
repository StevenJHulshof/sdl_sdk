#pragma once

#include "world_types.h"
#include "config_types.h"
#include "Tile.h"
#include "Civilian.h"

class World {

private:
    
    Civilian civ0;
    Civilian civ1;
    Civilian civ2;
    Civilian civ3;
    Civilian civ4;
    Civilian civ5;
    Civilian civ6;
    Civilian civ7;
    Civilian civ8;
    Civilian civ9;
    Civilian civ10;
    Civilian civ11;
    
    
    Tile grassTile;
    Tile waterTile;
    Tile *_tileGrid[WORLD_GRID_WIDTH][WORLD_GRID_LENGTH];
    
public:
    World();
    ~World();
    
    void update();
    void render();
    
    void fillTileGrid(Tile *tile);
};


#pragma once

#define CAMERA_OFFSET_X_START (int) -16
#define CAMERA_OFFSET_Y_START (int) -96
#define TILE_GRID_X (int) 100
#define TILE_GRID_Y (int) 100

enum {
    WORLD_LAYER_TILES,
    WORLD_LAYER_PLAYABLES,
    WORLD_LAYER_TOTAL
};

enum {
    WORLD_EMPTY,
    WORLD_TILE_GRASS,
    WORLD_TILE_SAND,
    WORLD_TILE_WATER,
    WORLD_UNIT_WARRIOR,
    WORLD_RESOURCE_RAW_WOOD,
    WORLD_RESOURCE_RAW_STONE
};

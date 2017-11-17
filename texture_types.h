#pragma once

#include <string>

enum {
    TEXTURE_TEMPLATE,
    TEXTURE_TILE_GRASS_0000,
    TEXTURE_TILE_WATER_0000,
    TEXTURE_RESOURCE_WOOD,
    TEXTURE_RESOURCE_STONE,
    TEXTURE_TILE_SELECTED,
    TEXTURE_UNIT_WARRIOR,
    TEXTURES_TOTAL,
    TEXTURE_TYPE_EMPTY
};

const std::string gTextureStringNames[TEXTURES_TOTAL] = {
    "template",
    "tile_grass_0000",
    "tile_water_0000",
    "resource_wood",
    "resource_stone",
    "tile_selected",
    "unit_warrior"
};
#pragma once

#include <string>

enum {
    TEXTURE_UNIT_CIVILIAN_0000,
    TEXTURE_UNIT_CIVILIAN_0001,
    TEXTURE_UNIT_CIVILIAN_0002,
    TEXTURE_UNIT_CIVILIAN_0003,
    TEXTURE_UNIT_CIVILIAN_0004,
    TEXTURE_UNIT_CIVILIAN_0005,
    TEXTURE_UNIT_CIVILIAN_0006,
    TEXTURE_UNIT_CIVILIAN_0007,
    TEXTURE_UNIT_CIVILIAN_0008,
    TEXTURE_UNIT_CIVILIAN_0009,
    TEXTURE_UNIT_CIVILIAN_0010,
    TEXTURE_UNIT_CIVILIAN_0011,
    TEXTURE_UNIT_CIVILIAN_0012,
    TEXTURE_UNIT_CIVILIAN_0013,
    TEXTURE_UNIT_CIVILIAN_0014,
    TEXTURE_UNIT_CIVILIAN_0015,
    TEXTURE_UNIT_CIVILIAN_0016,
    TEXTURE_UNIT_CIVILIAN_0017,
    TEXTURE_UNIT_CIVILIAN_0018,
    TEXTURE_UNIT_CIVILIAN_0019,
    TEXTURE_UNIT_CIVILIAN_0020,
    TEXTURE_UNIT_CIVILIAN_0021,
    TEXTURE_UNIT_CIVILIAN_0022,
    TEXTURE_UNIT_CIVILIAN_0023,
    TEXTURE_UNIT_CIVILIAN_0024,
    TEXTURE_UNIT_CIVILIAN_0025,
    TEXTURE_UNIT_CIVILIAN_0026,
    TEXTURE_TILE_GRASS_0000,
    TEXTURE_TILE_WATER_0000,
    TEXTURE_RESOURCE_RAW_WOOD_0000,
    TEXTURES_TOTAL,
    UNIT_CIVILIAN_TEXTURES_TOTAL = 27,
    TILE_TEXTURES_TOTAL = 2,
    RESOURCE_RAW_TEXTURES_TOTAL = 1
};

const std::string gTextureStringNames[TEXTURES_TOTAL] = {
    "civilian_0000",
    "civilian_0001",
    "civilian_0002",
    "civilian_0003",
    "civilian_0004",
    "civilian_0005",
    "civilian_0006",
    "civilian_0007",
    "civilian_0008",
    "civilian_0009",
    "civilian_0010",
    "civilian_0011",
    "civilian_0012",
    "civilian_0013",
    "civilian_0014",
    "civilian_0015",
    "civilian_0016",
    "civilian_0017",
    "civilian_0018",
    "civilian_0019",
    "civilian_0020",
    "civilian_0021",
    "civilian_0022",
    "civilian_0023",
    "civilian_0024",
    "civilian_0025",
    "civilian_0026",
    "grass_0000",
    "water_0000",
    "wood_0000"
};

struct TextureConfig {
    int type;
    SDL_Rect *clip;
    double angle;
    SDL_Point *center;
    SDL_RendererFlip flip;
};

const TextureConfig textureConfigDefault = {0, NULL, 9, NULL, SDL_FLIP_NONE};


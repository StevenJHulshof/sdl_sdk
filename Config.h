#pragma once

#include "texture_types.h"
#include "config_types.h"

class Config {
public:
    static bool init();
    static bool loadMedia();
    static void closeMedia();
};


#pragma once

#include "texture_types.h"
#include "config_types.h"
#include "windows.h"

extern HWND hwnd;

class Config {
public:
    static bool init();
    static bool loadMedia();
    static void closeMedia();
};


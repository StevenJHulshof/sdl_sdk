#pragma once

#include <iostream>
#include "sdl_includes.h"

enum {
    SCREEN_WIDTH = 1600,
    SCREEN_HEIGHT = 900
};

/** The SDL window. */
extern SDL_Window* gWindow;
/** The windows renderer. */
extern SDL_Renderer* gRenderer;
//Globally used font
extern TTF_Font *gFont;

extern HWND hwnd;

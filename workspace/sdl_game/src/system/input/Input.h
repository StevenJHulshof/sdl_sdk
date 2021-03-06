#pragma once

#include "config_types.h"
#include <iostream>
#include "sdl_includes.h"

class Input
{
private:
    SDL_Event event;
     
public:
    Input();
    ~Input();

    static void getMousePos(int *x, int *y);
    static bool onKeyPressed(int key);
    static bool onKeyPressed(char key);
    static bool onLeftMouseClickDown();
    static bool onRightMouseClickDown();
};


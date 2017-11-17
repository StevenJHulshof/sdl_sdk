#pragma once

#include "windows.h"
#include <iostream>
#include "sdl_includes.h"

class Input
{
private:
    SDL_Event event;
     
public:
    Input();
    ~Input();


    static bool onKeyPressed(int key);
    static bool onKeyPressed(char key);
    static bool onLeftMouseClickDown(int *x, int *y);
};


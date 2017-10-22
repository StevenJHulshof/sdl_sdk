#pragma once

#include <stdio.h>
#include "sdl_includes.h"

class Cursor {
public:
    Cursor();
    ~Cursor();
    
    void setOnCursorDown();
    bool getOnCursorDown();
    void resetEventFlags();
    
    int getX();
    int getY();
    
private:
    int mX, mY;
    bool mOnCursorDown;
};

extern Cursor cursor;

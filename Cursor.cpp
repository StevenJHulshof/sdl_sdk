#include "Cursor.h"

Cursor::Cursor(){
    resetEventFlags();
}

Cursor::~Cursor(){
}

void Cursor::resetEventFlags() {
    mX = 0;
    mY = 0;
    mOnCursorDown = false;
}

void Cursor::setOnCursorDown() {
    mOnCursorDown = true;
    SDL_GetMouseState(&mX, &mY);
    printf("Cursor button down\tx: %d, y: %d\n", mX, mY);
}

bool Cursor::getOnCursorDown() {
    return mOnCursorDown;
}

int Cursor::getX() {
    return mX;
}

int Cursor::getY() {
    return mY;
}

Cursor cursor;

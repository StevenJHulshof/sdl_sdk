#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

bool Input::onKeyPressed(int key)
{
    return (GetAsyncKeyState(key) & 0x8000);
}

bool Input::onKeyPressed(char key)
{
    return (GetAsyncKeyState(key));
}

bool Input::onLeftMouseClickDown(int *x, int *y)
{
    bool clicked = false;

    if(GetAsyncKeyState(VK_LBUTTON) & 0x8000)
    {
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        *x = cursorPos.x;
        *y = cursorPos.y;
        clicked = true;
    }
    
    return clicked;
}

bool Input::onRightMouseClickDown(int *x, int *y)
{
    bool clicked = false;

    if(GetAsyncKeyState(VK_RBUTTON) & 0x8000)
    {
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        *x = cursorPos.x;
        *y = cursorPos.y;
        clicked = true;
    }
    
    return clicked;
}


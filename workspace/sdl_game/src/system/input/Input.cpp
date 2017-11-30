#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::getMousePos(int *x, int *y)
{
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    ScreenToClient(hwnd, &cursorPos);
    *x = cursorPos.x;
    *y = cursorPos.y;
}

bool Input::onKeyPressed(int key)
{
    return (GetAsyncKeyState(key) & 0x8000);
}

bool Input::onKeyPressed(char key)
{
    return (GetAsyncKeyState(key));
}

bool Input::onLeftMouseClickDown()
{
    bool clicked = false;

    if(GetAsyncKeyState(VK_LBUTTON) & 0x8000)
    {
        clicked = true;
    }
    
    return clicked;
}

bool Input::onRightMouseClickDown()
{
    bool clicked = false;

    if(GetAsyncKeyState(VK_RBUTTON) & 0x8000)
    {
        clicked = true;
    }
    
    return clicked;
}


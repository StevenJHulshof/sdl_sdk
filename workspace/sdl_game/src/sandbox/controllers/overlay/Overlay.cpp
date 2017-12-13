#include "Overlay.h"

Overlay::Overlay()
{
}

Overlay::~Overlay()
{
}

int Overlay::getTileOverlay(int tileGrid[GRID_X][GRID_Y][GRID_Z], int xPos, int yPos, int zPos, int type)
{
    int overlay = 0;
    
    if(xPos > 0)
    {
        if(tileGrid[xPos - 1][yPos][zPos] == type)
        {
            overlay |= 0x20;
        }
    }
    else
    {
        overlay |= 0x20;
    }
    if(xPos < GRID_X - 1)
    {
        if(tileGrid[xPos + 1][yPos][zPos] == type)
        {
            overlay |= 0x04;
        }
    }
    else
    {
        overlay |= 0x04;
    }
    if(yPos > 0)
    {
        if(tileGrid[xPos][yPos - 1][zPos] == type)
        {
            overlay |= 0x02;
        }
    }
    else
    {
        overlay |= 0x02;
    }
    if(yPos < GRID_Y - 1)
    {
        if(tileGrid[xPos][yPos + 1][zPos] == type)
        {
            overlay |= 0x10;
        }
    }
    else
    {
        overlay |= 0x10;
    }
    if(zPos > GRID_Z)
    {
        if(tileGrid[xPos][yPos][zPos - 1] == type)
        {
            overlay |= 0x08;
        }
    }
    else
    {
        overlay |= 0x08;
    }
    if(zPos < GRID_Z - 1 + GRID_Z)
    {
        if(tileGrid[xPos][yPos][zPos + 1] == type)
        {
            overlay |= 0x01;
        }
    }
    else
    {
        overlay |= 0x01;
    }

    
    return overlay;
}

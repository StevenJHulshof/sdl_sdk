#include "Overlay.h"

Overlay::Overlay()
{
}

Overlay::~Overlay()
{
}

int Overlay::getTileOverlay(int tileGrid[TILE_GRID_X][TILE_GRID_Y], int xPos, int yPos, int textureType)
{
    int overlay = 0;
    
    if(yPos > 0)
    {
        if(tileGrid[xPos][yPos - 1] == textureType)
        {
             overlay |= 0x01;
        }
    }
    if(yPos < TILE_GRID_Y - 1)
    {
        if(tileGrid[xPos][yPos + 1] == textureType)
        {
            overlay |= 0x08;
        }
    }
    if(xPos % 2 == 0)
    {
        if(xPos < TILE_GRID_X - 1) 
        {
            if(tileGrid[xPos + 1][yPos] == textureType) 
            {
                overlay |= 0x02;  
            }
        }
        if(xPos < TILE_GRID_X - 1 && yPos < TILE_GRID_Y - 1) 
        {     
            if(tileGrid[xPos + 1][yPos + 1] == textureType)
            {
                overlay |= 0x04;
            }
        }

        if(xPos > 0 && yPos < TILE_GRID_Y - 1)
        {
            if(tileGrid[xPos - 1][yPos + 1] == textureType)
            {
                overlay |= 0x10;
            }
        }
        if(xPos > 0)
        {
            if(tileGrid[xPos - 1][yPos] == textureType)
            {
                overlay |= 0x20;        
            }
        }
    }
    else
    {
        if(xPos < TILE_GRID_X - 1 && yPos > 0) 
        {
            if(tileGrid[xPos + 1][yPos - 1] == textureType) 
            {
                overlay |= 0x02;  
            }
        }
        if(xPos < TILE_GRID_X - 1) 
        {     
            if(tileGrid[xPos + 1][yPos] == textureType)
            {
                overlay |= 0x04;
            }
        }

        if(xPos > 0)
        {
            if(tileGrid[xPos - 1][yPos] == textureType)
            {
                overlay |= 0x10;
            }
        }
        if(xPos > 0 && yPos > 0)
        {
            if(tileGrid[xPos - 1][yPos - 1] == textureType)
            {
                overlay |= 0x20;        
            }
        }
    }
    
    return overlay;
}

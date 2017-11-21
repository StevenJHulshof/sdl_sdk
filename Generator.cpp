#include "Generator.h"

Generator::Generator()
{
}

Generator::~Generator()
{
}

void Generator::fillGrid(int grid[TILE_GRID_X][TILE_GRID_Y], int type)
{
    for(int x = 0; x < TILE_GRID_X; x++)
    {
        for(int y = 0; y < TILE_GRID_Y; y++)
        {
            grid[x][y] = type;
        }
    }
}

void Generator::generatePatch(int grid[TILE_GRID_X][TILE_GRID_Y], int type, int size, int density, int baseGrid[TILE_GRID_X][TILE_GRID_Y], int baseType)
{
    for(int d = 0; d < density; d++)
    {
        int xRand = rand() % TILE_GRID_X;
        int yRand = rand() % TILE_GRID_Y;

        for(int i = 0; i < size; i++)
        {
            if(baseGrid == NULL)
            {
                grid[xRand][yRand] = type;
            }
            else if(baseGrid[xRand][yRand] == baseType)
            {
                grid[xRand][yRand] = type;
            }
            
            int direction = rand() % 4;
            
            switch(direction)
            {
                case GENERATOR_UP:
                if(yRand > 0)
                {
                    yRand--;
                }
                break;
                
                case GENERATOR_DOWN:
                if(yRand < TILE_GRID_Y - 1)
                {
                    yRand++;
                }
                break;
                
                case GENERATOR_LEFT:
                if(xRand > 0)
                {
                    xRand--;
                }
                break;
                
                case GENERATOR_RIGHT:
                if(xRand < TILE_GRID_X - 1)
                {
                    xRand++;
    
                }
                break;
                
                default:
                break;
            }
        }
    }
}
#include "Generator.h"

Generator::Generator()
{
}

Generator::~Generator()
{
}

void Generator::fillGrid(int grid[GRID_X][GRID_Y], int type)
{
    for(int x = 0; x < GRID_X; x++)
    {
        for(int y = 0; y < GRID_Y; y++)
        {
            grid[x][y] = type;
        }
    }
}

void Generator::generatePatch(int grid[GRID_X][GRID_Y],  int type, int size, int density, int baseGrid[GRID_X][GRID_Y], int baseType)
{
    float densFactor = (float) density * 0.01;
    long int tilesTotal = GRID_X * GRID_Y;
    int dens = (int) ((float) tilesTotal * densFactor / (float) size);
    
    for(int d = 0; d < dens; d++)
    {
        int xRand = rand() % GRID_X;
        int yRand = rand() % GRID_Y;

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
                if(yRand < GRID_Y - 1)
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
                if(xRand < GRID_X - 1)
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

void Generator::generateBorder(int grid[GRID_X][GRID_Y], int type)
{
	for(int x = 0; x < GRID_X; x++)
	{
		grid[x][0] = type;
		grid[x][GRID_Y - 1] = type;
	}
	for(int y = 0; y < GRID_Y; y++)
	{
		grid[0][y] = type;
		grid[GRID_X - 1][y] = type;
	}
}

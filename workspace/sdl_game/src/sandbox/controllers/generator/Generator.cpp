#include "Generator.h"

Generator::Generator()
{
}

Generator::~Generator()
{
}

void Generator::fillGrid(Tile *tile)
{
	for(int x = -GRID_N; x <= GRID_N; x++)
	{
		for(int y = std::max(-GRID_N, -x - GRID_N); y <= std::min(GRID_N, -x + GRID_N); y++)
		{
			int z = -x - y;
			Grid::setTileData(x, y, z, tile);
        }
    }
}

void Generator::generatePatch(int grid[GRID_X][GRID_Y][GRID_Z],  int type, int size, int density, int baseGrid[GRID_X][GRID_Y][GRID_Z], int baseType)
{
//    float densFactor = (float) density * 0.01;
//    long int tilesTotal = GRID_X * GRID_Y * 4;
//    int dens = (int) ((float) tilesTotal * densFactor / (float) size);
//
//    for(int d = 0; d < dens; d++)
//    {
//        int xRand = rand() % GRID_X;
//        int yRand = rand() % GRID_Y;
//        int zRand = rand() % GRID_Z;
//
//        for(int i = 0; i < size; i++)
//        {
//            if(baseGrid == NULL)
//            {
//                grid[xRand][yRand][zRand] = type;
//            }
//            else if(baseGrid[xRand][yRand][zRand] == baseType)
//            {
//                grid[xRand][yRand][zRand] = type;
//            }
//
//            int direction = rand() % 6;
//
//            switch(direction)
//            {
//            case GENERATOR_X_P:
//                if(xRand > 0)
//                {
//                    xRand--;
//                }
//                break;
//            case GENERATOR_X_N:
//                if(xRand < GRID_X - 1)
//                {
//                    xRand++;
//                }
//                break;
//            case GENERATOR_Y_P:
//                if(yRand > 0)
//                {
//                    yRand--;
//                }
//                break;
//            case GENERATOR_Y_N:
//                if(yRand < GRID_Y - 1)
//                {
//                    yRand++;
//                }
//                break;
//            case GENERATOR_Z_P:
//                if(zRand > 0)
//                {
//                    zRand--;
//                }
//                break;
//            case GENERATOR_Z_N:
//                if(zRand < GRID_Z - 1)
//                {
//                    zRand++;
//                }
//                break;
//            default:
//                break;
//            }
//        }
//    }
}

void Generator::generateBorder(int grid[GRID_X][GRID_Y][GRID_Z], int type)
{
//	for(int x = 0; x < GRID_X; x++)
//	{
//		grid[x][0][GRID_Z-1] = type;
//		grid[x][GRID_Y - 1][0] = type;
//	}
//	for(int y = 0; y < GRID_Y; y++)
//	{
//		grid[0][y][GRID_Z - 1] = type;
//		grid[GRID_X - 1][y][0] = type;
//	}
//	for(int z = 0; z < GRID_Z; z++)
//	{
//		grid[0][GRID_Y - 1][z] = type;
//		grid[GRID_X - 1][0][z] = type;
//	}
}

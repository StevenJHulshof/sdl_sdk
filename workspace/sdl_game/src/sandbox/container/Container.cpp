/*
 * Container.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: Steven
 */

#include "Container.h"

Container::Container():
	grassTile(TYPE_TILE_GRASS),
	sandTile(TYPE_TILE_SAND),
	waterTile(TYPE_TILE_WATER),
	generator(),
	camera(CAMERA_OFFSET_X_START, CAMERA_OFFSET_Y_START),
	cursor()
{
	Grid::config();
	createWorld();
}

Container::~Container()
{
	Grid::deleteGrid();
}

void Container::update()
{
	camera.update();
	grassTile._offsetX = camera._offsetX;
	grassTile._offsetY = camera._offsetY;
	sandTile._offsetX = camera._offsetX;
	sandTile._offsetY = camera._offsetY;
	waterTile._offsetX = camera._offsetX;
	waterTile._offsetY = camera._offsetY;

	gGlobalObjectPool.update(camera._offsetX, camera._offsetY);

	cursor.update();
}

void Container::render()
{
	gTextures[TEXTURE_BACKGROUND].render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, 1.0);

	Grid::renderTileGrid();

//	for(int z = 0; z < GRID_Z; z++)
//	{
//		if(z == 0)
//		{
//			for(int x = 0; x < GRID_X; x++)
//			{
//				for(int y = 0; y < GRID_Y; y++)
//				{
//					switch(Grid::_tileGrid[x][y][z])
//					{
//					case TYPE_TILE_GRASS:
//						grassTile.render(x, y, z + GRID_Z);
//						break;
//					case TYPE_TILE_SAND:
//						sandTile.render(x, y, z + GRID_Z);
//						break;
//					case TYPE_TILE_WATER:
//						waterTile.render(x, y, z + GRID_Z);
//						break;
//					default:
//						break;
//					}
//				}
//			}
//		}
//		else
//		{
//			for(int x = 1; x < GRID_X; x++)
//			{
//				switch(Grid::_tileGrid[x][0][z])
//				{
//				case TYPE_TILE_GRASS:
//					grassTile.render(x, 0, z + GRID_Z);
//					break;
//				case TYPE_TILE_SAND:
//					sandTile.render(x, 0, z + GRID_Z);
//					break;
//				case TYPE_TILE_WATER:
//					waterTile.render(x, 0, z + GRID_Z);
//					break;
//				default:
//					break;
//				}
//			}
//			for(int y = 0; y < GRID_Y; y++)
//			{
//				switch(Grid::_tileGrid[0][y][z])
//				{
//				case TYPE_TILE_GRASS:
//					grassTile.render(0, y, z + GRID_Z);
//					break;
//				case TYPE_TILE_SAND:
//					sandTile.render(0, y, z + GRID_Z);
//					break;
//				case TYPE_TILE_WATER:
//					waterTile.render(0, y, z + GRID_Z);
//					break;
//				default:
//					break;
//				}
//			}
//		}
//	}

//	gGlobalObjectPool.render();

	cursor.render();
}

void Container::createWorld()
{
	generator.fillGrid(&grassTile);
//	generator.generatePatch(Grid::_tileGrid, TYPE_TILE_SAND, 40, 20);
//	generator.generatePatch(Grid::_tileGrid, TYPE_TILE_WATER, 80, 60);
//	generator.generateBorder(Grid::_tileGrid, TYPE_TILE_WATER);
//
//	generator.fillGrid(Grid::_playableGrid, TYPE_EMPTY);
//	generator.generatePatch(Grid::_playableGrid, TYPE_UNIT_WARRIOR, 1, 3, Grid::_tileGrid, TYPE_TILE_GRASS);
//	generator.generatePatch(Grid::_playableGrid, TYPE_UNIT_RANGER, 1, 3, Grid::_tileGrid, TYPE_TILE_GRASS);
//	generator.generatePatch(Grid::_playableGrid, TYPE_RESOURCE_RAW_WOOD, 10, 60, Grid::_tileGrid, TYPE_TILE_GRASS);
//	generator.generatePatch(Grid::_playableGrid, TYPE_RESOURCE_RAW_STONE, 5, 10, Grid::_tileGrid, TYPE_TILE_GRASS);
//	for(int z = 0; z < GRID_Z; z++)
//	{
//		if(z == 0)
//		{
//			for(int x = 0; x < GRID_X; x++)
//			{
//				for(int y = 0; y < GRID_Y; y++)
//				{
//					if(Grid::_playableGrid[x][y][z] == TYPE_RESOURCE_RAW_STONE)
//					{
//						RawStone *rawStone = new RawStone(x, y, z + GRID_Z);
//						gRawStonePool.push_back(rawStone);
//					}
//					else if(Grid::_playableGrid[x][y][z] == TYPE_RESOURCE_RAW_WOOD)
//					{
//						RawWood *rawWood = new RawWood(x, y, z + GRID_Z);
//						gRawWoodPool.push_back(rawWood);
//					}
//					else if(Grid::_playableGrid[x][y][z] == TYPE_UNIT_WARRIOR)
//					{
//						Warrior *warrior = new Warrior(x, y, z + GRID_Z);
//						gWarriorPool.push_back(warrior);
//					}
//					else if(Grid::_playableGrid[x][y][z] == TYPE_UNIT_RANGER)
//					{
//						Ranger *ranger = new Ranger(x, y, z + GRID_Z);
//						gRangerPool.push_back(ranger);
//					}
//				}
//			}
//		}
//		else
//		{
//			for(int x = 1; x < GRID_X; x++)
//			{
//				if(Grid::_playableGrid[x][0][z] == TYPE_RESOURCE_RAW_STONE)
//				{
//					RawStone *rawStone = new RawStone(x, 0, z);
//					gRawStonePool.push_back(rawStone);
//				}
//				else if(Grid::_playableGrid[x][0][z] == TYPE_RESOURCE_RAW_WOOD)
//				{
//					RawWood *rawWood = new RawWood(x, 0, z);
//					gRawWoodPool.push_back(rawWood);
//				}
//				else if(Grid::_playableGrid[x][0][z] == TYPE_UNIT_WARRIOR)
//				{
//					Warrior *warrior = new Warrior(x, 0, z + GRID_Z);
//					gWarriorPool.push_back(warrior);
//				}
//				else if(Grid::_playableGrid[x][0][z] == TYPE_UNIT_RANGER)
//				{
//					Ranger *ranger = new Ranger(x, 0, z + GRID_Z);
//					gRangerPool.push_back(ranger);
//				}
//			}
//			for(int y = 0; y < GRID_Y; y++)
//			{
//				if(Grid::_playableGrid[0][y][z] == TYPE_RESOURCE_RAW_STONE)
//				{
//					RawStone *rawStone = new RawStone(0, y, z + GRID_Z);
//					gRawStonePool.push_back(rawStone);
//				}
//				else if(Grid::_playableGrid[0][y][z] == TYPE_RESOURCE_RAW_WOOD)
//				{
//					RawWood *rawWood = new RawWood(0, y, z + GRID_Z);
//					gRawWoodPool.push_back(rawWood);
//				}
//				else if(Grid::_playableGrid[0][y][z] == TYPE_UNIT_WARRIOR)
//				{
//					Warrior *warrior = new Warrior(0, y, z + GRID_Z);
//					gWarriorPool.push_back(warrior);
//				}
//				else if(Grid::_playableGrid[0][y][z] == TYPE_UNIT_RANGER)
//				{
//					Ranger *ranger = new Ranger(0, y, z + GRID_Z);
//					gRangerPool.push_back(ranger);
//				}
//			}
//		}
//	}
//	for(int y = 0; y < GRID_Y; y++)
//	{
//		for(int x = 0; x < GRID_X; x++)
//		{
//			for(int z = 0; z < GRID_Z; z++)
//			{
//				if(Grid::_playableGrid[x][y][z] == TYPE_RESOURCE_RAW_STONE)
//				{
//					RawStone *rawStone = new RawStone(x, y, z + GRID_Z);
//					gRawStonePool.push_back(rawStone);
//				}
//				else if(Grid::_playableGrid[x][y][z] == TYPE_RESOURCE_RAW_WOOD)
//				{
//					RawWood *rawWood = new RawWood(x, y, z + GRID_Z);
//					gRawWoodPool.push_back(rawWood);
//				}
//				else if(Grid::_playableGrid[x][y][z] == TYPE_UNIT_WARRIOR)
//				{
//					Warrior *warrior = new Warrior(x, y, z + GRID_Z);
//					gWarriorPool.push_back(warrior);
//				}
//				else if(Grid::_playableGrid[x][y][z] == TYPE_UNIT_RANGER)
//				{
//					Ranger *ranger = new Ranger(x, y, z + GRID_Z);
//					gRangerPool.push_back(ranger);
//				}
//			}
//		}
//	}
}

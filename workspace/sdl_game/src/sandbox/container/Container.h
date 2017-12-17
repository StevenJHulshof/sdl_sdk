#pragma once

#include "GlobalObjectPool.h"
#include "Generator.h"
#include "Map.h"
#include "Tile.h"
#include "Camera.h"
#include "Cursor.h"

class Container
{
private:
	void createWorld();

public:
	Container();
	virtual ~Container();

	Map map;

	Tile grassTile;
	Tile sandTile;
	Tile waterTile;

    Generator generator;
    Camera camera;
    Cursor cursor;

	virtual void update();
	virtual void render();
};

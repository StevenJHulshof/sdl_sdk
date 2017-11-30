#include "GlobalObjectPool.h"

GlobalObjectPool::GlobalObjectPool()
{

}

GlobalObjectPool::~GlobalObjectPool()
{

}

void GlobalObjectPool::update(int offsetX, int offsetY)
{
	updatePool(_resourcePool, offsetX, offsetY);
	updatePool(_rawStonePool, offsetX, offsetY);
	updatePool(_rawWoodPool, offsetX, offsetY);
	updatePool(_unitPool, offsetX, offsetY);
	updatePool(_warriorPool, offsetX, offsetY);
}

void GlobalObjectPool::render()
{
	int resourceIndex = _resourcePool.size() - 1;
	int rawStoneIndex = _rawStonePool.size() - 1;
	int rawWoodIndex = _rawWoodPool.size() - 1;
	int unitIndex = _unitPool.size() - 1;
	int warriorIndex = _warriorPool.size() - 1;

	for(int y = 0; y < GRID_Y; y++)
	{
		renderPool(_resourcePool, y, &resourceIndex);
		renderPool(_rawStonePool, y, &rawStoneIndex);
		renderPool(_rawWoodPool, y, &rawWoodIndex);
		renderPool(_unitPool, y, &unitIndex);
		renderPool(_warriorPool, y, &warriorIndex);
	}
}

void GlobalObjectPool::deleteAllPools()
{
	deletePool(_resourcePool);
	deletePool(_rawStonePool);
	deletePool(_rawWoodPool);
	deletePool(_unitPool);
	deletePool(_warriorPool);
}

GlobalObjectPool gGlobalObjectPool;

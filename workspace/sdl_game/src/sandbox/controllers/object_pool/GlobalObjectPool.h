#pragma once

#include <vector>
#include "grid_types.h"
#include "Unit.h"
#include "Warrior.h"
#include "Resource.h"
#include "RawStone.h"
#include "RawWood.h"

class GlobalObjectPool
{
private:
	template <class object_t>
	void updatePool(std::vector<object_t> &pool, int offsetX, int offsetY);
	template <class object_t>
	void renderPool(std::vector<object_t> &pool, int yPos, int *index);
	template <class object_t>
	void deletePool(std::vector<object_t> &pool);
	template <class object_t>
	void sortObjectPool(std::vector<object_t> &pool);

public:
	GlobalObjectPool();
	virtual ~GlobalObjectPool();

	std::vector<Unit*> _unitPool;
	std::vector<Warrior*> _warriorPool;
	std::vector<Resource*> _resourcePool;
	std::vector<RawStone*> _rawStonePool;
	std::vector<RawWood*> _rawWoodPool;


	void update(int offsetX, int offsetY);
	void render();

	void deleteAllPools();
};

template <class object_t>
void GlobalObjectPool::sortObjectPool(std::vector<object_t> &pool)
{
	for(size_t i = 1; i < pool.size(); i++)
	{
		object_t index = pool[i];
		int j = i - 1;

		for(;j >= 0 && pool[j]->_screenPosY < index->_screenPosY; j--)
		{
			pool[j + 1] = pool[j];
		}
		pool[j + 1] = index;
	}
}

template <class object_t>
void GlobalObjectPool::updatePool(std::vector<object_t> &pool, int offsetX, int offsetY)
{
	for(size_t i = 0; i < pool.size(); i++)
	{
		pool[i]->_offsetX = offsetX;
		pool[i]->_offsetY = offsetY;
		pool[i]->update();
	}
	sortObjectPool(pool);
}

template <class object_t>
void GlobalObjectPool::renderPool(std::vector<object_t> &pool, int yPos, int *index)
{
	if(*index >= 0)
	{
		while(true)
		{
			pool[*index]->render();
			(*index)--;
			if(*index < 0 || pool[*index]->_yPos != yPos)
			{
				break;
			}
		}
	}
}

template <class object_t>
void GlobalObjectPool::deletePool(std::vector<object_t> &pool)
{
	for(size_t i = 0; i < pool.size(); i++)
	{
		pool[i]->deleteSelf();
	}
}

extern GlobalObjectPool gGlobalObjectPool;
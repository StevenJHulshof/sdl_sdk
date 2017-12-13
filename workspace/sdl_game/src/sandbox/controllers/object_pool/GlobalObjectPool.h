#pragma once

#include <vector>
#include "global_object_pool_types.h"
#include "grid_types.h"
#include "Unit.h"
#include "Warrior.h"
#include "Ranger.h"
#include "Resource.h"
#include "RawStone.h"
#include "RawWood.h"
#include "ActionMenu.h"
#include "StatMenu.h"

class GlobalObjectPool
{
private:
	template <class object_t>
	void updatePool(std::vector<object_t> &pool, std::vector<object_t> &object, int offsetX, int offsetY);
	template <class object_t>
	void renderPool(std::vector<object_t> &pool, int yPos, int *index);
	template <class object_t>
	void deletePool(std::vector<object_t> &pool);
	template <class object_t>
	void sortObjectPool(std::vector<object_t> &pool);
	template <class object_t>
	void prioritize(std::vector<object_t> &pool, std::vector<object_t> &object, bool *member, int memberType, int index);
	template <class object_t, class member_t>
	void setObjectMember(object_t object, member_t *member, member_t value);

	void resetAllObjectBuffers();
	void resetObjectBuffers(int memberType);
	void setObjectBuffersMember(int memberType, bool value);

public:
	GlobalObjectPool();
	virtual ~GlobalObjectPool();

	int _maxPriority[OBJECT_MEMBER_TOTAL];

	std::vector<Resource*> _resourceBuffer;
	std::vector<RawStone*> _rawStoneBuffer;
	std::vector<RawWood*> _rawWoodBuffer;
	std::vector<Unit*> _unitBuffer;
	std::vector<Warrior*> _warriorBuffer;
	std::vector<Ranger*> _rangerBuffer;
	std::vector<ActionMenu*> _actionMenuBuffer;
	std::vector<StatMenu*> _statMenuBuffer;

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
void GlobalObjectPool::updatePool(std::vector<object_t> &pool, std::vector<object_t> &object, int offsetX, int offsetY)
{
	sortObjectPool(pool);
	for(size_t i = 0; i < pool.size(); i++)
	{
		pool[i]->_offsetX = offsetX;
		pool[i]->_offsetY = offsetY;
		pool[i]->update();

		prioritize(pool, object, &pool[i]->_hovered, OBJECT_MEMBER_HOVERED, i);
		prioritize(pool, object, &pool[i]->_selected, OBJECT_MEMBER_SELECTED, i);
	}
}

template <class object_t>
void GlobalObjectPool::renderPool(std::vector<object_t> &pool, int zPos, int *index)
{
	if(*index >= 0 && pool[*index]->_zPos == zPos)
	{
		while(true)
		{
			pool[*index]->render();
			(*index)--;
			if(*index < 0 || pool[*index]->_zPos != zPos)
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

template <class object_t>
void GlobalObjectPool::prioritize(std::vector<object_t> &pool, std::vector<object_t> &object, bool *member, int memberType, int index)
{
	if(*member && pool[index]->_priority > _maxPriority[memberType])
	{
		setObjectBuffersMember(memberType, false);
		resetObjectBuffers(memberType);
		_maxPriority[memberType] = pool[index]->_priority;
		*member = true;
		object[memberType] = pool[index];
	}
	else
	{
		*member = false;
	}
}

template <class object_t, class member_t>
void GlobalObjectPool::setObjectMember(object_t object, member_t *member, member_t value)
{
	if(object != NULL)
	{
		*member = value;
	}
}

extern GlobalObjectPool gGlobalObjectPool;

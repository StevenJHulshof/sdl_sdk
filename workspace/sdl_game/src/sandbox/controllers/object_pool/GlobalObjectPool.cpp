#include "GlobalObjectPool.h"

GlobalObjectPool::GlobalObjectPool():
	_resourceBuffer(OBJECT_MEMBER_TOTAL),
	_rawStoneBuffer(OBJECT_MEMBER_TOTAL),
	_rawWoodBuffer(OBJECT_MEMBER_TOTAL),
	_unitBuffer(OBJECT_MEMBER_TOTAL),
	_warriorBuffer(OBJECT_MEMBER_TOTAL),
	_rangerBuffer(OBJECT_MEMBER_TOTAL),
	_actionMenuBuffer(OBJECT_MEMBER_TOTAL),
	_statMenuBuffer(OBJECT_MEMBER_TOTAL)
{
	resetAllObjectBuffers();
}

GlobalObjectPool::~GlobalObjectPool()
{

}

void GlobalObjectPool::update(int offsetX, int offsetY)
{
	resetAllObjectBuffers();
	updatePool(gResourcePool, _resourceBuffer, offsetX, offsetY);
	updatePool(gRawStonePool, _rawStoneBuffer, offsetX, offsetY);
	updatePool(gRawWoodPool, _rawWoodBuffer, offsetX, offsetY);
	updatePool(gUnitPool, _unitBuffer, offsetX, offsetY);
	updatePool(gWarriorPool, _warriorBuffer, offsetX, offsetY);
	updatePool(gRangerPool, _rangerBuffer, offsetX, offsetY);
	updatePool(gActionMenuPool, _actionMenuBuffer, offsetX, offsetY);
	updatePool(gStatMenuPool, _statMenuBuffer, offsetX, offsetY);
}

void GlobalObjectPool::render()
{
	int resourceIndex = gResourcePool.size() - 1;
	int rawStoneIndex = gRawStonePool.size() - 1;
	int rawWoodIndex = gRawWoodPool.size() - 1;
	int unitIndex = gUnitPool.size() - 1;
	int warriorIndex = gWarriorPool.size() - 1;
	int rangerIndex = gRangerPool.size() - 1;

	for(int y = 0; y < GRID_Y; y++)
	{
		renderPool(gResourcePool, y, &resourceIndex);
		renderPool(gRawStonePool, y, &rawStoneIndex);
		renderPool(gRawWoodPool, y, &rawWoodIndex);
		renderPool(gUnitPool, y, &unitIndex);
		renderPool(gWarriorPool, y, &warriorIndex);
		renderPool(gRangerPool, y, &rangerIndex);
	}

	// render menus
	for(size_t i = 0; i < gStatMenuPool.size(); i++)
	{
		gStatMenuPool[i]->render();
	}
	for(size_t i = 0; i < gActionMenuPool.size(); i++)
	{
		gActionMenuPool[i]->render();
	}
}

void GlobalObjectPool::deleteAllPools()
{
	deletePool(gResourcePool);
	deletePool(gRawStonePool);
	deletePool(gRawWoodPool);
	deletePool(gUnitPool);
	deletePool(gWarriorPool);
	deletePool(gRangerPool);
	deletePool(gActionMenuPool);
	deletePool(gStatMenuPool);
}

void GlobalObjectPool::resetAllObjectBuffers()
{
	for(int i = 0; i < OBJECT_MEMBER_TOTAL; i++)
	{
		_maxPriority[i] = 0;
		resetObjectBuffers(i);
	}
}

void GlobalObjectPool::resetObjectBuffers(int memberType)
{
	_resourceBuffer[memberType] = NULL;
	_rawStoneBuffer[memberType] = NULL;
	_rawWoodBuffer[memberType] = NULL;
	_unitBuffer[memberType] = NULL;
	_warriorBuffer[memberType] = NULL;
	_rangerBuffer[memberType] = NULL;
	_actionMenuBuffer[memberType] = NULL;
	_statMenuBuffer[memberType] = NULL;
}

void GlobalObjectPool::setObjectBuffersMember(int memberType, bool value)
{
	switch(memberType)
	{
	case OBJECT_MEMBER_SELECTED:
		setObjectMember(_resourceBuffer[OBJECT_MEMBER_SELECTED], &_resourceBuffer[OBJECT_MEMBER_SELECTED]->_selected, value);
		setObjectMember(_rawStoneBuffer[OBJECT_MEMBER_SELECTED], &_rawStoneBuffer[OBJECT_MEMBER_SELECTED]->_selected, value);
		setObjectMember(_rawWoodBuffer[OBJECT_MEMBER_SELECTED], &_rawWoodBuffer[OBJECT_MEMBER_SELECTED]->_selected, value);
		setObjectMember(_unitBuffer[OBJECT_MEMBER_SELECTED], &_unitBuffer[OBJECT_MEMBER_SELECTED]->_selected, value);
		setObjectMember(_warriorBuffer[OBJECT_MEMBER_SELECTED], &_warriorBuffer[OBJECT_MEMBER_SELECTED]->_selected, value);
		setObjectMember(_rangerBuffer[OBJECT_MEMBER_SELECTED], &_rangerBuffer[OBJECT_MEMBER_SELECTED]->_selected, value);
		setObjectMember(_actionMenuBuffer[OBJECT_MEMBER_SELECTED], &_actionMenuBuffer[OBJECT_MEMBER_SELECTED]->_selected, value);
		setObjectMember(_statMenuBuffer[OBJECT_MEMBER_SELECTED], &_statMenuBuffer[OBJECT_MEMBER_SELECTED]->_selected, value);
		break;
	case OBJECT_MEMBER_HOVERED:
		setObjectMember(_resourceBuffer[OBJECT_MEMBER_HOVERED], &_resourceBuffer[OBJECT_MEMBER_HOVERED]->_hovered, value);
		setObjectMember(_rawStoneBuffer[OBJECT_MEMBER_HOVERED], &_rawStoneBuffer[OBJECT_MEMBER_HOVERED]->_hovered, value);
		setObjectMember(_rawWoodBuffer[OBJECT_MEMBER_HOVERED], &_rawWoodBuffer[OBJECT_MEMBER_HOVERED]->_hovered, value);
		setObjectMember(_unitBuffer[OBJECT_MEMBER_HOVERED], &_unitBuffer[OBJECT_MEMBER_HOVERED]->_hovered, value);
		setObjectMember(_warriorBuffer[OBJECT_MEMBER_HOVERED], &_warriorBuffer[OBJECT_MEMBER_HOVERED]->_hovered, value);
		setObjectMember(_rangerBuffer[OBJECT_MEMBER_HOVERED], &_rangerBuffer[OBJECT_MEMBER_HOVERED]->_hovered, value);
		setObjectMember(_actionMenuBuffer[OBJECT_MEMBER_HOVERED], &_actionMenuBuffer[OBJECT_MEMBER_HOVERED]->_hovered, value);
		setObjectMember(_statMenuBuffer[OBJECT_MEMBER_HOVERED], &_statMenuBuffer[OBJECT_MEMBER_HOVERED]->_hovered, value);
		break;
	default:
		break;
	}
}

GlobalObjectPool gGlobalObjectPool;

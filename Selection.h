#pragma once

#include "GameObjectUnion.h"

template <class gbu_t>
class Selection
{
private:
    static gbu_t *selectedObject;
    static std::vector<gbu_t*> candidatePool;
    
public:
    Selection();
    ~Selection();
    
    void addCandidate(gbu_t *gameObjectUnion);
    
    void update();
    void render();
};

template <class gbu_t>
gbu_t *Selection<gbu_t>::selectedObject = 0;

template <class gbu_t>
std::vector<gbu_t*> Selection<gbu_t>::candidatePool(0);

template <class gbu_t>
Selection<gbu_t>::Selection()
{
}

template <class gbu_t>
Selection<gbu_t>::~Selection()
{
}

template <class gbu_t>
void Selection<gbu_t>::addCandidate(gbu_t *gameObjectUnion)
{
    candidatePool.push_back(gameObjectUnion);
}

template <class gbu_t>
void Selection<gbu_t>::update()
{
    int maxPriority = 0;
    
    for(size_t i = 0; i < candidatePool.size(); i++)
    {
        int priority = GameObjectUnionUtility::fastSendToGameObjectUnion<gbu_t, int, int>(candidatePool[i], MSG_GET_INPUT, MSG_DATA_INPUT_PRIORITY) +
                       GameObjectUnionUtility::fastSendToGameObjectUnion<gbu_t, int, int>(candidatePool[i], MSG_GET_PHYSICS, MSG_DATA_PHYSICS_Y_POS);

        if(priority > maxPriority)
        {
            if(selectedObject != 0)
            {
                GameObjectUnionUtility::sendToGameObjectUnion<gbu_t, bool, int>(selectedObject, MSG_SET_INPUT_SELECTED, false);
            }
            maxPriority = priority;
            selectedObject = candidatePool[i];
            if(selectedObject != 0)
            {
                GameObjectUnionUtility::sendToGameObjectUnion<gbu_t, bool, int>(selectedObject, MSG_SET_INPUT_SELECTED, true);
            }
        }
    }

    candidatePool.clear();
}
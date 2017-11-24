#pragma once

#include "GameObjectUnion.h"
#include "Texture.h"

template <class gbu_t>
class Selection
{
private:
    gbu_t *selectedObject;
    gbu_t *hoveredObject;
    std::vector<gbu_t*> hoveredPool;
    std::vector<gbu_t*> selectedPool;
    
    void prioritizeSelected();
    void prioritizeHovered();
    
public:
    Selection();
    ~Selection();
    
    void addSelectedCandidate(gbu_t *gameObjectUnion);
    void addHoveredCandidate(gbu_t *gameObjectUnion);
    
    void update();
    void render();
};

template <class gbu_t>
Selection<gbu_t>::Selection()
{
}

template <class gbu_t>
Selection<gbu_t>::~Selection()
{
}

template <class gbu_t>
void Selection<gbu_t>::addSelectedCandidate(gbu_t *gameObjectUnion)
{
    selectedPool.push_back(gameObjectUnion);
}

template <class gbu_t>
void Selection<gbu_t>::addHoveredCandidate(gbu_t *gameObjectUnion)
{
    hoveredPool.push_back(gameObjectUnion);
}

template <class gbu_t>
void Selection<gbu_t>::update()
{
    prioritizeSelected();
    prioritizeHovered();
}

template <class gbu_t>
void Selection<gbu_t>::render()
{
//    if(selectedObject != NULL)
//    {
//        gTextures[TEXTURE_OBJECT_SELECTION_MENU].render(SCREEN_WIDTH - gTextures[TEXTURE_OBJECT_SELECTION_MENU].getWidth() - 16,
//                                                        16, NULL, 0, NULL, SDL_FLIP_NONE, 1);
//        gTextures[GameObjectUnionUtility::fastSendToGameObjectUnion<gbu_t, int, int>(selectedObject, MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_TEXTURE_TYPE)].render(
//            SCREEN_WIDTH - (int)(gTextures[TEXTURE_OBJECT_SELECTION_MENU].getWidth() * 3 / 4) - 16, -(int)(gTextures[TEXTURE_OBJECT_SELECTION_MENU].getHeight() / 4) + 16, NULL, 0, NULL,
//            GameObjectUnionUtility::fastSendToGameObjectUnion<gbu_t, int, SDL_RendererFlip>(selectedObject, MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_FLIP), 1);
//    }

    int x, y;
    Input::getMousePos(&x, &y);
    gTextures[TEXTURE_CURSOR_DOT].render(x - (int)(gTextures[TEXTURE_CURSOR_DOT].getWidth() / 2), 
                                         y - (int)(gTextures[TEXTURE_CURSOR_DOT].getHeight() / 2), 
                                         NULL, 0, NULL, SDL_FLIP_NONE, 1);
}

template <class gbu_t>
void Selection<gbu_t>::prioritizeSelected()
{
    int maxPriority = 0;
    
    for(size_t i = 0; i < selectedPool.size(); i++)
    {
        int priority = GameObjectUnionUtility::fastSendToGameObjectUnion<gbu_t, int, int>(selectedPool[i], MSG_GET_INPUT, MSG_DATA_INPUT_PRIORITY);

        if(priority > maxPriority)
        {
            if(selectedObject != NULL)
            {
                GameObjectUnionUtility::sendToGameObjectUnion<gbu_t, bool, int>(selectedObject, MSG_SET_INPUT_SELECTED, false);
            }
            maxPriority = priority;
            selectedObject = selectedPool[i];
            GameObjectUnionUtility::sendToGameObjectUnion<gbu_t, bool, int>(selectedObject, MSG_SET_INPUT_SELECTED, true);
        }
        else
        {
            GameObjectUnionUtility::sendToGameObjectUnion<gbu_t, bool, int>(selectedPool[i], MSG_SET_INPUT_SELECTED, false);
        }
    }
    
    selectedPool.clear();
}

template <class gbu_t>
void Selection<gbu_t>::prioritizeHovered()
{
    int maxPriority = 0;
    
    for(size_t i = 0; i < hoveredPool.size(); i++)
    {
        int priority = GameObjectUnionUtility::fastSendToGameObjectUnion<gbu_t, int, int>(hoveredPool[i], MSG_GET_INPUT, MSG_DATA_INPUT_PRIORITY);
        
        if(priority >= maxPriority)
        {
            if(hoveredObject != NULL)
            {
                GameObjectUnionUtility::sendToGameObjectUnion<gbu_t, bool, int>(hoveredObject, MSG_SET_INPUT_HOVERED, false);
            }

            maxPriority = priority;
            hoveredObject = hoveredPool[i];
            GameObjectUnionUtility::sendToGameObjectUnion<gbu_t, bool, int>(hoveredObject, MSG_SET_INPUT_HOVERED, true);
        }
        else
        {
            GameObjectUnionUtility::sendToGameObjectUnion<gbu_t, bool, int>(hoveredPool[i], MSG_SET_INPUT_HOVERED, false);
        }
    }
    
    hoveredPool.clear();
}
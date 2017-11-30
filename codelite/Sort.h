#pragma once

#include <vector>
#include <algorithm>
#include "component_msg_types.h"

class Sort
{
private:

    template <class vec_t>
    static int partition(std::vector<vec_t> vec, int low, int high, int *unionTypes, int unionLength);
    
public:
    Sort();
    ~Sort();

    template <class vec_t>
    static void quickSort(std::vector<vec_t> vec, int low, int high, int *unionTypes, int unionLength);
};

template <class vec_t>
int Sort::partition(std::vector<vec_t> vec, int low, int high, int *unionTypes, int unionLength)
{
    int iScreenPosY, jScreenPosY, pivot, zPos;
    int i = low - 1;
    
    vec[high].tile.template send(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_Y, &pivot);
    
    for(int j = low; j < high - 1; j++)
    {
        vec[j].template send(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_Y, &jScreenPosY);
        vec[j].template send(MSG_GET_PHYSICS, MSG_DATA_PHYSICS_Z_POS, &zPos);
        
        if(jScreenPosY < pivot)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    
    vec[high]->template send(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_Y, &jScreenPosY);
    vec[i + 1]->template send(MSG_GET_GRAPHICS, MSG_DATA_GRAPHICS_SCREEN_POS_Y, &iScreenPosY);
    
    if(jScreenPosY < iScreenPosY)
    {
        std::swap(*vec[i + 1], *vec[high]);
    }
    return i + 1;
}

template <class vec_t>
void Sort::quickSort(std::vector<vec_t> vec, int low, int high, int *unionType, int unionLength)
{
    if(low < high)
    {
        int p = partition(vec, low, high);
        quickSort(vec, low, p - 1);
        quickSort(vec, p + 1, high);
    }
}



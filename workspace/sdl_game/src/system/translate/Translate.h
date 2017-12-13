#pragma once

#include <vector>
#include "config_types.h"

class Translate {
public:
    Translate();
    ~Translate();
    static void gridToScreenPos(int xPos, int yPos, int zPos, int w, int h, int *screenPosX, int *screenPosY);
    static void screenPosToGrid(int screenPosX, int screenPosY, int w, int h, int *xPos, int *yPos);
    template <class assetType>
    void insertionSort(std::vector<assetType> *asset);
};


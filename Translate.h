#pragma once

#include <vector>
#include "config_types.h"
#include "assets_structs.h"

class Translate {
public:
    Translate();
    ~Translate();
    static void gridToScreenPos(int xPos, int yPos, int w, int h, int *screenPosX, int *screenPosY);
    template <class assetType>
    void insertionSort(std::vector<assetType> *asset);
};


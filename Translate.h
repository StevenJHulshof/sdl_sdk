#pragma once

#include <vector>
#include "config_types.h"
#include "assets_structs.h"

class Translate {
public:
    Translate();
    ~Translate();
  //  static void toIsometric(ScreenPos *inPos, ScreenPos *outPos);
    template <class assetType>
    void insertionSort(std::vector<assetType> *asset);
};


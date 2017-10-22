#include "Translate.h"

Translate::Translate() {
}

Translate::~Translate() {
}

//void Translate::toIsometric(ScreenPos *inPos, ScreenPos *outPos) {
//
//}

template <class assetType>
void Translate::insertionSort(std::vector<assetType> *asset) {
   for(int i = 1; i < asset->size(); i++) {
    
      std::vector<assetType> index = *asset;
      int j = i;
      while (j > 0 && asset[j-1]->mScreenPos.x > index.mScreenPos.x)
      {
           asset[j] = asset[j-1];
           j--;
      }
      asset[j] = index;
    } 
}


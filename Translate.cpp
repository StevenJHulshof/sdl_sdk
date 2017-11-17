#include "Translate.h"

Translate::Translate() {
}

Translate::~Translate() {
}

void Translate::gridToScreenPos(int xPos, int yPos, int w, int h, int *screenPosX, int *screenPosY) {
     *screenPosX = xPos * w * 0.75;
     *screenPosY = (xPos % 2) * -1 * h * 0.25 + yPos * h * 0.5;
}

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


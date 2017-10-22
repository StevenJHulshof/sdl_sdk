#include "GraphicalUserInterface.h"

GraphicalUserInterface::GraphicalUserInterface(Map *map) {
    mMap = map;
}

GraphicalUserInterface::~GraphicalUserInterface() {
}

void GraphicalUserInterface::update() {
    mResourceInterface.woodQuantity = 0;
    mResourceInterface.stoneQuantity = 0;
    for(unsigned int i = 0; i < mMap->mStockPiles.size(); i++) {
        if(mMap->mStockPiles[i].mTextureConfig.type == RESOURCE_WOOD)
            mResourceInterface.woodQuantity += mMap->mStockPiles[i].mQuantity;
    }
}

void GraphicalUserInterface::render() {
    
}

#pragma once

#include "Map.h"

struct ResourceInterface {
    int woodQuantity;
    int stoneQuantity;
};

class GraphicalUserInterface {
public:
    GraphicalUserInterface(Map *map);
    ~GraphicalUserInterface();
    void update();
    void render();
private:
    Map *mMap;
    ResourceInterface mResourceInterface;
};


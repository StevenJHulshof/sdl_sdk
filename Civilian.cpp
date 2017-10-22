#include "Civilian.h"

Civilian::Civilian(int x, int y, int velocity):
    GameObject<Civilian>() {
                
    addComponent(this, &inputComponent);
    addComponent(this, &physicsComponent);
    addComponent(this, &graphicsComponent);
    
    send(MSG_CIVILIAN_POS_X, x);
    send(MSG_CIVILIAN_POS_Y, y);
    send(MSG_CIVILIAN_VELOCITY, velocity);
}

Civilian::~Civilian() {
}


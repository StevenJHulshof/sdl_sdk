#pragma once

#include "GameObject.h"
#include "CivilianInputComponent.h"
#include "CivilianPhysicsComponent.h"
#include "CivilianGraphicsComponent.h"

class Civilian: public GameObject<Civilian>
{
private:
    
public:

    Civilian(int x, int y, int velocity);
    ~Civilian();
    
    CivilianInputComponent<Civilian> inputComponent;
    CivilianPhysicsComponent<Civilian> physicsComponent;
    CivilianGraphicsComponent<Civilian> graphicsComponent;
};


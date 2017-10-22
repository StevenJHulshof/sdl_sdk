#include "Component.h"

template <class obj_t>
class PhysicsComponent: public Component<obj_t> {
    
public:
    PhysicsComponent();
    int xPos, yPos, velocity;
};

template <class obj_t>
PhysicsComponent<obj_t>::PhysicsComponent():
    Component<obj_t>() {
    xPos = 0;
    yPos = 0;
    velocity = 0;
}
#include "Component.h"

template <class obj_t>
class PhysicsComponent: public Component<obj_t> 
{
public:
    PhysicsComponent();
    ~PhysicsComponent();
    int velocity;
};

template <class obj_t>
PhysicsComponent<obj_t>::PhysicsComponent():
    Component<obj_t>(),
    velocity(0)
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
PhysicsComponent<obj_t>::~PhysicsComponent() {
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}
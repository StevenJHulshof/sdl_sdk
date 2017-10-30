#pragma once

#include <vector>
#include "Component.h"

enum {
    MSG_GET_PHYSICS = -1,
    MSG_GET_GRAPHICS = -2,
    MSG_GET_INPUT = -3
};

template <class obj_t>
class GameObject {

private:
    std::vector<Component<obj_t>*> _components;
protected:

public:

    GameObject();
    int send(int message, int data);
    void update();
    void render();
    
    void addComponent(obj_t *gameObject, Component<obj_t> *component);
};

template <class obj_t>
GameObject<obj_t>::GameObject() {

}

template <class obj_t>
int GameObject<obj_t>::send(int message, int data) {
    
    int response = 0;
    std::cout << "SEND: msg: " << message << " data: " << data << " | " << __PRETTY_FUNCTION__ << std::endl;
    for(Component<obj_t> *component : _components) {
        component->receive(message, data, &response);
    }
    
    return response;
}

template <class obj_t>
void GameObject<obj_t>::update() {
    
    for(Component<obj_t> *component : _components) {
        component->update();
    }
}

template <class obj_t>
void GameObject<obj_t>::render() {
    
    for(Component<obj_t> *component : _components) {
        component->render();
    }
}

template <class obj_t>
void GameObject<obj_t>::addComponent(obj_t *gameObject, Component<obj_t> *component) {
    
    _components.push_back(component);
    component->setGameObject(gameObject);
}
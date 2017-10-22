#pragma once

#include <iostream>

template <class obj_t>
class Component { 
    
private:

    obj_t *_gameObject;

public:

    virtual void receive(int message, int data, int *response);
    virtual void update();
    virtual void render();
    
    void setGameObject(obj_t *gameObject);
    obj_t *getGameObject();
};

template <class obj_t>
void Component<obj_t>::receive(int message, int data, int *response) {

}

template <class obj_t>
void Component<obj_t>::update() {
 
}

template <class obj_t>
void Component<obj_t>::render() {

}

template <class obj_t>
void Component<obj_t>::setGameObject(obj_t *gameObject) {
    _gameObject = gameObject;
}

template <class obj_t>
obj_t *Component<obj_t>::getGameObject() {
    return _gameObject;
}
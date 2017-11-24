#pragma once

#include <iostream>
#include "sdl_includes.h"
#include "component_msg_types.h"

template <class obj_t>
class Component 
{ 
private:

    obj_t *_gameObject;

public:
    Component();
    virtual ~Component();

    virtual void update();
    virtual void render();

    virtual void receive(int message, int data, int *response);
    
    virtual void receive(int message, unsigned long int data, int *response);
    virtual void receive(int message, int data, unsigned long int *response);

    virtual void receive(int message, SDL_RendererFlip data, int *response);
    virtual void receive(int message, int data, SDL_RendererFlip *response);

    virtual void receive(int message, float data, int *response);
    virtual void receive(int message, int data, float *response);
    
    virtual void receive(int message, bool data, int *response);
    virtual void receive(int message, int data, bool *response);
    
    void setGameObject(obj_t *gameObject);
    obj_t *getGameObject();
};

template <class obj_t>
Component<obj_t>::Component() {
 
}

template <class obj_t>
Component<obj_t>::~Component() {
 
}

template <class obj_t>
void Component<obj_t>::update() {
 
}

template <class obj_t>
void Component<obj_t>::render() {

}

template <class obj_t>
void Component<obj_t>::receive(int message, int data, int *response) {

}

template <class obj_t>
void Component<obj_t>::receive(int message, unsigned long int data, int *response) {

}

template <class obj_t>
void Component<obj_t>::receive(int message, int data, unsigned long int *response) {

}

template <class obj_t>
void Component<obj_t>::receive(int message, SDL_RendererFlip data, int *response) {

}

template <class obj_t>
void Component<obj_t>::receive(int message, int data, SDL_RendererFlip *response) {

}

template <class obj_t>
void Component<obj_t>::receive(int message, float data, int *response) {

}

template <class obj_t>
void Component<obj_t>::receive(int message, int data, float *response) {

}

template <class obj_t>
void Component<obj_t>::receive(int message, bool data, int *response) {

}

template <class obj_t>
void Component<obj_t>::receive(int message, int data, bool *response) {

}

template <class obj_t>
void Component<obj_t>::setGameObject(obj_t *gameObject) {
    _gameObject = gameObject;
}

template <class obj_t>
obj_t *Component<obj_t>::getGameObject() {
    return _gameObject;
}
#pragma once

#include <vector>
#include "Debug.h"
#include "Component.h"
#include "Container.h"

template <class obj_t, class con_t>
class GameObject 
{
protected:
    std::vector<Component<obj_t>*> _components;
    con_t *_container;
    
public:

    GameObject();
    virtual ~GameObject();
    
    template <class data_t, class response_t>
    void send(int message, data_t data, response_t *response = NULL);

    void update();
    void render();
    
    void addComponent(obj_t *gameObject, Component<obj_t> *component);
    void setContainer(con_t *container);
    con_t *getContainer();
};

template <class obj_t, class con_t>
GameObject<obj_t, con_t>::GameObject() 
{

}

template <class obj_t, class con_t>
GameObject<obj_t, con_t>::~GameObject() 
{

}

template <class obj_t, class con_t>
template <class data_t, class response_t>
void GameObject<obj_t, con_t>::send(int message, data_t data, response_t *response) 
{    
    for(Component<obj_t> *component : _components) 
    {
        component->receive(message, data, response);
    }
}

template <class obj_t, class con_t>
void GameObject<obj_t, con_t>::update() 
{
    for(Component<obj_t> *component : _components) 
    {
        component->update();
    }
}

template <class obj_t, class con_t>
void GameObject<obj_t, con_t>::render() 
{
    for(Component<obj_t> *component : _components) 
    {
        component->render();
    }
}

template <class obj_t, class con_t>
void GameObject<obj_t, con_t>::addComponent(obj_t *gameObject, Component<obj_t> *component) 
{
    _components.push_back(component);
    component->setGameObject(gameObject);
}

template <class obj_t, class con_t>
void GameObject<obj_t, con_t>::setContainer(con_t *container) 
{
    _container = container;
}

template <class obj_t, class con_t>
con_t *GameObject<obj_t, con_t>::getContainer()
{
    return _container;
}
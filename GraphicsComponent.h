#pragma once

#include "sdl_includes.h"
#include "Debug.h"
#include "Component.h"
#include "Texture.h"

template <class obj_t>
class GraphicsComponent: public Component<obj_t> 
{    
    
protected:
    SDL_RendererFlip flip;
    int textureType, screenPosX, screenPosY;
public:

 

    GraphicsComponent();
    ~GraphicsComponent();
};

template <class obj_t>
GraphicsComponent<obj_t>::GraphicsComponent():
    Component<obj_t>(),
    flip(SDL_FLIP_NONE),
    textureType(0),
    screenPosX(0),
    screenPosY(0)
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

template <class obj_t>
GraphicsComponent<obj_t>::~GraphicsComponent()
{
#if (1 == DEBUG_ALLOC_COMP_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

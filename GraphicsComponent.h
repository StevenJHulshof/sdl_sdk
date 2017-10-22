#pragma once

#include "sdl_includes.h"
#include "Component.h"
#include "Texture.h"

template <class obj_t>
class GraphicsComponent: public Component<obj_t> {
    
private:

protected:
    SDL_RendererFlip flip;
    int textureType;
public:

    GraphicsComponent();
};

template <class obj_t>
GraphicsComponent<obj_t>::GraphicsComponent():
    Component<obj_t>() {
    
    flip = SDL_FLIP_NONE;
    textureType = 0;
}
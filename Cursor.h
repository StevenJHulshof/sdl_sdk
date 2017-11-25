#pragma once

#include "GameObject.h"
#include "CursorInputComponent.h"
#include "CursorGraphicsComponent.h"

template <class con_t>
class Cursor: public GameObject<Cursor<con_t>, con_t>
{
private:
    CursorInputComponent<Cursor<con_t>> cursorInputComponent;
    CursorGraphicsComponent<Cursor<con_t>> cursorGraphicsComponent;
    
public:
    Cursor();
    virtual ~Cursor();
};

template <class con_t>
Cursor<con_t>::Cursor():
    GameObject<Cursor<con_t>, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
        
    this->addComponent(this, &cursorInputComponent);
    this->addComponent(this, &cursorGraphicsComponent);
    
    this->template send<int, int>(MSG_SET_GRAPHICS_TEXTURE_TYPE, TEXTURE_CURSOR_ARROW);
}

template <class con_t>
Cursor<con_t>::~Cursor()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif

}

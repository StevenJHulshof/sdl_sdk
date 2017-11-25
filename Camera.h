#pragma once

#include "GameObject.h"
#include "CameraInputComponent.h"
#include "CameraPhysicsComponent.h"
#include "CameraGraphicsComponent.h"

enum
{
    CAMERA_VELOCITY = 16
};

template <class con_t>
class Camera: public GameObject<Camera<con_t>, con_t>
{
private:
    CameraInputComponent<Camera<con_t>> cameraInputComponent;
    CameraPhysicsComponent<Camera<con_t>> cameraPhysicsComponent;
    CameraGraphicsComponent<Camera<con_t>> cameraGraphicsComponent;
    
public:
    
    Camera(int x, int y);
    virtual ~Camera();
};

template <class con_t>
Camera<con_t>::Camera(int x, int y):
    GameObject<Camera<con_t>, con_t>()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Allocate   | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
        
    this->addComponent(this, &cameraInputComponent);
    this->addComponent(this, &cameraPhysicsComponent);
    this->addComponent(this, &cameraGraphicsComponent);
    
    this->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_X, x);
    this->template send<int, int>(MSG_SET_GRAPHICS_OFFSET_Y, y);
    this->template send<int, int>(MSG_SET_PHYSICS_VELOCITY, CAMERA_VELOCITY);
}

template <class con_t>
Camera<con_t>::~Camera()
{
#if (1 == DEBUG_ALLOC_GAME_OBJECT_ENABLE)
    DEBUG_ALLOC("Deallocate | %p | %s\n", this, __PRETTY_FUNCTION__);
#endif
}

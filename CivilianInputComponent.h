//#pragma once
//
//#include "sdl_includes.h"
//#include "time_user.h"
//#include "civilian_types.h"
//#include "InputComponent.h"
//#include "GameObject.h"
//#include "windows.h"
//
//template <class obj_t>
//class CivilianInputComponent: public InputComponent<obj_t>
//{
//private:
//    bool _delayFlag;
//    uint64_t _startTime;
//    int _direction;
//    int _direction2;
//    
//public:
//    CivilianInputComponent();
//    ~CivilianInputComponent();
//
//    virtual void update();
//};
//
//template <class obj_t>
//CivilianInputComponent<obj_t>::CivilianInputComponent():
//    InputComponent<obj_t>() {
//        _delayFlag = true;
//        _startTime = 0;
//        _direction = 0;
//         _direction2 = 0;
//}
//
//template <class obj_t>
//CivilianInputComponent<obj_t>::~CivilianInputComponent() {
//    
//}
//
//template <class obj_t>
//void CivilianInputComponent<obj_t>::update() {
//        
//    if(_delayFlag) {
//        _direction = rand() % 4;
//        _direction2 = rand() % 4;
//        _startTime = getTimeMilliSec();
//        _delayFlag = false;
//    }
//    if(getTimeMilliSec() - _startTime >= (uint64_t) (700 + rand() % 400)) {
//        _delayFlag = true;
//    } 
//
//
//     this->getGameObject()->send(MSG_CIVILIAN_MOVE, _direction);

//}
//
//
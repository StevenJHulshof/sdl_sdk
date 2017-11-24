#pragma once

#include "Tile.h"
#include "RawWood.h"
#include "RawStone.h"
#include "Warrior.h"

enum {
    GAME_OBJECT_RESOURCE,
    GAME_OBJECT_RAW_WOOD,
    GAME_OBJECT_RAW_STONE,
    GAME_OBJECT_UNIT,
    GAME_OBJECT_WARRIOR,
    GAME_OBJECT_TOTAL
};

template <class con_t>
struct GameObjectUnion{
    int tag;
    union {
        Resource<con_t> *resource;
        RawWood<con_t> *rawWood;
        RawStone<con_t> *rawStone;
        Unit<con_t> *unit;
        Warrior<con_t> *warrior;
    };
};

class GameObjectUnionUtility
{
public:
    GameObjectUnionUtility();
    ~GameObjectUnionUtility();

    template <class obj_t>
    static void renderGameObjectUnion(obj_t *object);
    template <class obj_t>
    static void updateGameObjectUnion(obj_t *object);
    template <class obj_t, class con_t>
    static void setGameObjectUnion(obj_t *gameObjectUnion, int tag, con_t *container);
    template <class obj_t, class data_t, class response_t>
    static void sendToGameObjectUnion(obj_t *object, int message, data_t data, response_t *response = NULL);
    template <class obj_t, class data_t, class response_t>
    static response_t fastSendToGameObjectUnion(obj_t *object, int message, data_t data);
};

template <class obj_t>
void GameObjectUnionUtility::updateGameObjectUnion(obj_t *object)
{
    switch(object->tag)
    {        
        case GAME_OBJECT_RESOURCE:
        object->resource->update();
        break;
        
        case GAME_OBJECT_RAW_WOOD:
        object->rawWood->update();
        break;
        
        case GAME_OBJECT_RAW_STONE:
        object->rawStone->update();
        break;
        
        case GAME_OBJECT_UNIT:
        object->unit->update();
        break;
        
        case GAME_OBJECT_WARRIOR:
        object->warrior->update();
        break;
        
        default:
        break;
    }
}

template <class obj_t, class con_t>
void GameObjectUnionUtility::setGameObjectUnion(obj_t *gameObjectUnion, int tag, con_t *container)
{    
    gameObjectUnion->tag = tag;
    
    switch(gameObjectUnion->tag)
    {        
        case GAME_OBJECT_RESOURCE:
        gameObjectUnion->resource->setContainer(container);
        break;       
        
        case GAME_OBJECT_RAW_WOOD:
        gameObjectUnion->rawWood->setContainer(container);
        break;       
        
        case GAME_OBJECT_RAW_STONE:
        gameObjectUnion->rawStone->setContainer(container);
        break;
        
        case GAME_OBJECT_UNIT:
        gameObjectUnion->unit->setContainer(container);
        break;

        case GAME_OBJECT_WARRIOR:
        gameObjectUnion->warrior->setContainer(container);
        break;
        
        default:
        break;
    }  
}

template <class obj_t>
void GameObjectUnionUtility::renderGameObjectUnion(obj_t *object)
{
    switch(object->tag)
    {        
        case GAME_OBJECT_RESOURCE:
        object->resource->render();
        break;
        
        case GAME_OBJECT_RAW_WOOD:
        object->rawWood->render();
        break;
        
        case GAME_OBJECT_RAW_STONE:
        object->rawStone->render();
        break;
        
        case GAME_OBJECT_UNIT:
        object->unit->render();
        break;

        case GAME_OBJECT_WARRIOR:
        object->warrior->render();
        break;
        
        default:
        break;
    }
}

template <class obj_t, class data_t, class response_t>
void GameObjectUnionUtility::sendToGameObjectUnion(obj_t *object, int message, data_t data, response_t *response)
{
    switch(object->tag)
    {
        case GAME_OBJECT_RESOURCE:
        object->resource->template send<data_t, response_t>(message, data, response);
        break;

        case GAME_OBJECT_RAW_WOOD:
        object->rawWood->template send<data_t, response_t>(message, data, response);
        break;

        case GAME_OBJECT_RAW_STONE:
        object->rawStone->template send<data_t, response_t>(message, data, response);
        break;

        case GAME_OBJECT_UNIT:
        object->unit->template send<data_t, response_t>(message, data, response);
        break;

        case GAME_OBJECT_WARRIOR:
        object->warrior->template send<data_t, response_t>(message, data, response);
        break;
        
        default:
        break;
    }
}

template <class obj_t, class data_t, class response_t>
response_t GameObjectUnionUtility::fastSendToGameObjectUnion(obj_t *object, int message, data_t data)
{
    response_t response = (response_t) 0;
    sendToGameObjectUnion<obj_t, data_t, response_t>(object, message, data, &response);
    return response;
}


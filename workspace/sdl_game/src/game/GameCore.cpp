#include "GameCore.h"

GameCore::GameCore():
	container()
{
    
}

void GameCore::update() 
{
	container.update();
}

void GameCore::render() 
{
	container.render();
}

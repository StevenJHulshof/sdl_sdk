#include "StatMenu.h"

StatMenu::StatMenu(int xPos, int yPos):
	Menu(xPos, yPos, TYPE_OBJECT_MENU_STAT),
	_statTextures(0),
	_statValue(0),
	_statStringTex(0)
{

}

StatMenu::~StatMenu()
{
	deleteStats();
}

void StatMenu::updateGraphics()
{
	Menu::updateGraphics();

	_screenPosX -= 32;
	_screenPosY += 128;
}

void StatMenu::renderGraphics()
{
	Menu::renderGraphics();

	int symbolScreenPosX = _screenPosX + _offsetX + 6;
	int symbolScreenPosY = _screenPosY + _offsetY + 6;
	int statMiddleScreenPosX = _screenPosX + _offsetX;
	int statMiddleScreenPosY = _screenPosY + _offsetY + 6;

	for(size_t i = 0; i < _statTextures.size(); i++)
	{
		if(i % 3 == 0)
		{
			gTextures[TEXTURE_OBJECT_MENU_STAT_MIDDLE].render(statMiddleScreenPosX, statMiddleScreenPosY, NULL, 0, NULL, SDL_FLIP_NONE, 1.0);
			symbolScreenPosX = _screenPosX + _offsetX + 6;
			if(i != 0)
			{
				symbolScreenPosY += 10;
			}
			statMiddleScreenPosY += 10;
		}
		gTextures[_statTextures[i]].render(symbolScreenPosX, symbolScreenPosY, NULL, 0, NULL, SDL_FLIP_NONE, 1.0);
		_statStringTex[i]->render(symbolScreenPosX + 10, symbolScreenPosY, NULL, 0, NULL, SDL_FLIP_NONE, 1.0);

		symbolScreenPosX += 40;
	}

	gTextures[TEXTURE_OBJECT_MENU_STAT_BOTTOM].render(statMiddleScreenPosX, statMiddleScreenPosY, NULL, 0, NULL, SDL_FLIP_NONE, 1.0);
}

void StatMenu::addStat(int type, int *stat)
{
	switch(type)
	{
	case STAT_TYPE_HEALTH:
		_statTextures.push_back(TEXTURE_STAT_HEALTH);
		break;
	case STAT_TYPE_DEFENSE:
		_statTextures.push_back(TEXTURE_STAT_DEFENSE);
		break;
	case STAT_TYPE_MOVEMENT_SPEED:
		_statTextures.push_back(TEXTURE_STAT_MOVEMENT_SPEED);
		break;
	case STAT_TYPE_ATTACK_MELEE:
		_statTextures.push_back(TEXTURE_STAT_ATTACK_MELEE);
		break;
	case STAT_TYPE_ATTACK_RANGED:
		_statTextures.push_back(TEXTURE_STAT_ATTACK_RANGED);
		break;
	default:
		std::cout << "Statistic type invalid" << std::endl;
		break;
	}
	_statValue.push_back(stat);
	_statStringTex.push_back(new Texture());
	updateStats();
}

void StatMenu::updateStats()
{
    SDL_Color textColor = { 0, 0, 0 };
	for(size_t i = 0; i < _statStringTex.size(); i++)
	{
        _statStringTex[i]->loadFromRenderedText(std::to_string(*_statValue[i]), textColor);
	}
}

void StatMenu::deleteStats()
{
	for(size_t i = 0; i < _statStringTex.size(); i++)
	{
		_statStringTex[i]->deleteSelf();
	}
	_statValue.clear();
	_statTextures.clear();
}

std::vector<StatMenu*> gStatMenuPool;

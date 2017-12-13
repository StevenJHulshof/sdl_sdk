#pragma once

#include "stat_types.h"
#include "Menu.h"

class StatMenu: public Menu
{
public:
	StatMenu(int xPos, int yPos, int zPos);
	virtual ~StatMenu();

	std::vector<int> _statTextures;
	std::vector<int*> _statValue;
	std::vector<Texture*> _statStringTex;

	virtual void updateGraphics();
	virtual void renderGraphics();

	void addStat(int type, int *stat);
	void updateStats();
	void deleteStats();
};

extern std::vector<StatMenu*> gStatMenuPool;

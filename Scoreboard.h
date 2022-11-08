#pragma once
#include "Game.h"
#include "mini/ini.h"
#include <string>
#include "Floor.h"

class Scoreboard
{
private:
	
	sf::RenderWindow* window;

	sf::Event evnt;

	sf::Font font,namefont;

	sf::Text nametitle, scoretitle, ranktitle, stitle;

	sf::Text name[5],score[5],rank[5],noscore;

	sf::RectangleShape bg;

	sf::Texture background;

	Floor* floor;

	int size;

	mINI::INIFile* file;
	mINI::INIStructure ini;

	mINI::INIMap<std::string> namelist, scorelist;

	void update();
	void render();

	void getInput();


public:

	Scoreboard(sf::RenderWindow* window);

};


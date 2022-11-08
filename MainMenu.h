#include "Game.h"
#include "SFML/Audio.hpp"
#include "Floor.h"
#pragma once

class MainMenu
{
private:
	sf::RenderWindow* window;
	sf::Texture background;
	
	Floor* floor;

	sf::RectangleShape bg;

	sf::Font font;

	sf::Event evnt;

	sf::Music option;

	sf::Text play, hScore, quit,title;

	int mOption = 0;

	void fontDef();

	void fontOption();

	void getInput();

	void update();

	void render();

public:

	MainMenu(sf::RenderWindow* window);

	~MainMenu();

};


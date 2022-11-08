#pragma once
#include "Game.h"


class Floor
{
private:
	
	sf::Texture floortex;

	sf::Clock clock;

	float dT;

public:

	sf::RectangleShape floorshape;

	Floor();

	Floor(bool first);

	void update();

	void render(sf::RenderWindow* window);

};


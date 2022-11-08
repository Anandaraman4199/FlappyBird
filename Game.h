#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Game
{
private:

	sf::RenderWindow* window;

	sf::Music option;

public:

	Game();


	static int states;

	static float sWidth, sHeight;

	static bool running;

	void update();

};


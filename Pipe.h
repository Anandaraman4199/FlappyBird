#pragma once
#include "Game.h"
#include "SFML/Audio.hpp"

class Pipe
{
private:
	sf::RectangleShape rect1,rect1end;
	sf::RectangleShape rect2,rect2end;

	sf::Texture pipe1, pipe1end, pipe2end, pipe2;

	sf::Clock clock;

	bool gaveScore = false;

	float dT;

	const float PIPEGAP = Game::sHeight / 6;
	const float RECXSIZE = Game::sWidth / 22;

	const float SPEED = Game::sWidth / 6.4;

	void pCollision();

public:

	sf::Vector2f pipePos;
	Pipe();

	void update();

	void render(sf::RenderWindow* window);

};


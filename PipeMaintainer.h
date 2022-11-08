#pragma once
#include "Game.h"
#include "Pipe.h"
#include "Floor.h"

class PipeMaintainer
{

private:

	std::vector<Pipe*> listOfPipes;
	std::vector<Floor*> listOfFloor;

	sf::Vector2f playerPosition;

	

	void updatePlayerPos();

	void pipeCreate();

	void pipeDelete();


public:

	PipeMaintainer();

	void update();

	void render(sf::RenderWindow* window);

};


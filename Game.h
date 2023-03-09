#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

/*
* This class object will decide which game state should be initiated depends upon the player's input
*/

class Game
{
private:

	// SFML Window

	sf::RenderWindow* window;

	// This object will used for the sound that plays when the player choose any option in the main menu

	sf::Music option;

public:

	//Constructor which initialize the window creation

	Game();

	//This static variable is used to decide in which state the game is in.

	static int states;

/*
	These static variable store the current screen resolution of the computer.These values will be used for every calculation in the
	game to maintain the size and positions of the game to be same in every computer.
*/

	static float sWidth, sHeight;

	//This static variable is used in the main.cpp to main the loop.

	static bool running;

	//Update function that decides in which state the game will be.

	void update();

};


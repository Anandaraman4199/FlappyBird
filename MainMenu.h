#pragma once
#include "Game.h"
#include "SFML/Audio.hpp"
#include "Floor.h"

//This class member variables and functions will be used for MainMenu state.

class MainMenu
{
private:

	// This window pointer will store the window from Game object.
	sf::RenderWindow* window;
	sf::Event evnt;


	// These variables are used to create the background in the main menu.
	sf::Texture background;
	// Floor is a class which contains a rectangular shape and a texture object.
	Floor* floor;
	sf::RectangleShape bg;
	
	// This object will control the music that plays everytime the player presses up and down keys in the main menu.
	sf::Music option;

	// These text object will show all the text in mainmenu in the font style that stored in the font object.
	sf::Text play, hScore, quit, title;
	sf::Font font;

	// This variable is used to store the current option in the mainmenu. This will be used to change the colour of the text and states variable.

	int mOption = 0;

/* This function will be called everytime the player presses upand down keys in the main menu.
   This will change the colour of all the fonts to white.
*/

	void fontDef();

/* This function will be called everytime the player presses upand down keys in the main menu after fontDef().
   This will change the colour of the current option's font to red.
*/
	void fontOption();

// This function is used to get the player input and change the values of the variables according to the player's input.

	void update();

// This function is used to render all the fonts and background elements everyframe using sfml functions.

	void render();

public:

// Constructor will initialize all the text and background elements and keeps the update and render function in loop.

	MainMenu(sf::RenderWindow* window);

// Destructor is used to delete the floor object everytime as it is initialized using heap allocation.

	~MainMenu();

};


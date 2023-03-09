#include "Game.h"
#include "MainMenu.h"
#include "Scoreboard.h"
#include "GameState.h"

// Initializing the static variables

bool Game::running = true;
float Game::sWidth = 0;
float Game::sHeight = 0;
int Game::states = 0;

//Constructor which initialize the window creation and get the screen resolution of the computer and store it in the static variable.

Game::Game()
{
	sWidth = sf::VideoMode::getDesktopMode().width;
	sHeight = sf::VideoMode::getDesktopMode().height;
	this->window = new sf::RenderWindow(sf::VideoMode(sWidth, sHeight), "Flappy Bird", sf::Style::Fullscreen);
	this->window->setMouseCursorVisible(false);
}

/* Update function that decides in which state the game will be.Depends on the value in the states static variable, this function will create an object of a game state.
   When the value of the states static variable changes, from the MainMenu's member function,
	 this update function deletes the mainmenu object and create the necessary game state object,
*/

void Game::update()
{
	if (states == 0)
	{
		// This value initializes mainmenu state (which is the default state of the game).

		this->option.openFromFile("option.wav");
		this->option.play();
		MainMenu* menu = new MainMenu(this->window);
		delete menu;
	}
	if (states == 1)
	{
		// This value initializes the gameplay state.

		this->option.openFromFile("option.wav");
		this->option.play();
		GameState* gState = new GameState(this->window);
		delete gState;
	}
	if (states == 2)
	{
		// This value initializes the Scoreboard state.

		this->option.openFromFile("option.wav");
		this->option.play();
		Scoreboard* sBoard = new Scoreboard(this->window);
		delete sBoard;
	}
	if (states == 3)
	{
		// This value closes the game by changing the running static variable to false.

		this->option.openFromFile("option.wav");
		this->option.play();
		running = false;
	}
	if (states == 4)
	{
		//This value is used for restarting the game from gameplay state by changing the value to 4. This will delete the objects of exisiting gameplay and sets it again to 1.

		states = 1;
	}


}

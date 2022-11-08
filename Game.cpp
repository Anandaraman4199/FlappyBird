#include "Game.h"
#include "MainMenu.h"
#include "Scoreboard.h"
#include "GameState.h"


bool Game::running = true;
float Game::sWidth = 0;
float Game::sHeight = 0;
int Game::states = 0;


Game::Game()
{
	sWidth = sf::VideoMode::getDesktopMode().width;
	sHeight = sf::VideoMode::getDesktopMode().height;
	this->window = new sf::RenderWindow(sf::VideoMode(sWidth, sHeight), "Flappy Bird", sf::Style::Fullscreen);
	this->window->setMouseCursorVisible(false);
}

void Game::update()
{
	if (states == 0)
	{
		this->option.openFromFile("option.wav");
		this->option.play();
		MainMenu* menu = new MainMenu(this->window);
		delete menu;
	}
	if (states == 1)
	{

		this->option.openFromFile("option.wav");
		this->option.play();
		GameState* gState = new GameState(this->window);
		delete gState;
	}
	if (states == 2)
	{

		this->option.openFromFile("option.wav");
		this->option.play();
		Scoreboard* sBoard = new Scoreboard(this->window);
		delete sBoard;
	}
	if (states == 3)
	{

		this->option.openFromFile("option.wav");
		this->option.play();
		running = false;
	}
	if (states == 4)
	{
		states = 1;
	}


}

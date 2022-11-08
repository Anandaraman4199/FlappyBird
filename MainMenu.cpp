#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow* window)
{
	this->window = window;
	this->background.loadFromFile("background.png");
	this->bg.setSize(sf::Vector2f(Game::sWidth, Game::sHeight));
	this->bg.setTexture(&this->background);
	this->bg.setPosition(0, 0);

	this->font.loadFromFile("gamefont.ttf");
	this->play.setFont(this->font);
	this->hScore.setFont(this->font); 
	this->quit.setFont(this->font);
	this->title.setFont(this->font);

	this->play.setCharacterSize(Game::sWidth / 19.2);
	this->hScore.setCharacterSize(Game::sWidth /19.2);
	this->quit.setCharacterSize(Game::sWidth / 19.2);
	this->title.setCharacterSize(Game::sWidth / 12);

	this->play.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight *4/ 10));
	this->hScore.setPosition(Game::sWidth / 2, Game::sHeight * 5 / 10);
	this->quit.setPosition(Game::sWidth / 2, Game::sHeight * 6/ 10);
	this->title.setPosition(Game::sWidth / 2, Game::sHeight  / 9);

	this->play.setString("Play");
	this->hScore.setString("High Score");
	this->quit.setString("Quit");
	this->title.setString("Flappy Bird");

	this->play.setOutlineThickness(Game::sWidth/960);
	this->hScore.setOutlineThickness(Game::sWidth / 960);
	this->quit.setOutlineThickness(Game::sWidth / 960);
	this->title.setOutlineThickness(Game::sWidth / 850);

	this->play.setOutlineColor(sf::Color::Black);
	this->hScore.setOutlineColor(sf::Color::Black);
	this->quit.setOutlineColor(sf::Color::Black);
	this->title.setOutlineColor(sf::Color::Black);
	

	this->play.setOrigin(this->play.getGlobalBounds().width / 2, this->play.getGlobalBounds().height / 2);
	this->hScore.setOrigin(this->hScore.getGlobalBounds().width / 2, this->hScore.getGlobalBounds().height / 2);
	this->quit.setOrigin(this->quit.getGlobalBounds().width / 2, this->quit.getGlobalBounds().height / 2);
	this->title.setOrigin(this->title.getGlobalBounds().width / 2, this->title.getGlobalBounds().height / 2);

	this->floor = new Floor(true);


	while (Game::states == 0)
	{
		this->update();
		this->render();
	}
	
}

void MainMenu::getInput()
{
	while (this->window->pollEvent(this->evnt))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			this->option.openFromFile("option.wav");
			this->option.play();
			this->mOption--;
			if(this->mOption < 0)
			{
				this->mOption = 2;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			this->option.openFromFile("option.wav");
			this->option.play();
			this->mOption++;
			if (this->mOption > 2)
			{
				this->mOption = 0;
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			Game::states = this->mOption + 1;
		}
	}

}

void MainMenu::fontDef()
{
	this->play.setFillColor(sf::Color::White);
	this->hScore.setFillColor(sf::Color::White);
	this->quit.setFillColor(sf::Color::White);
}

void MainMenu::fontOption()
{

	switch (this->mOption)
	{
	case 0: this->play.setFillColor(sf::Color::Red);
		break;
	case 1: this->hScore.setFillColor(sf::Color::Red);
		break;
	case 2: this->quit.setFillColor(sf::Color::Red);
		break;
	}

}

void MainMenu::update()
{
	this->fontDef();
	this->getInput();
	this->fontOption();
}

void MainMenu::render()
{
	this->window->clear();
	this->window->draw(this->bg);
	this->window->draw(this->title);
	this->window->draw(this->play);
	this->window->draw(this->hScore);
	this->window->draw(this->quit);
	this->floor->render(this->window);
	this->window->display();
}

MainMenu::~MainMenu()
{
	delete this->floor;
}
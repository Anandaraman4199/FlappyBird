#include "MainMenu.h"

// Constructor will initialize all the text and background elements and keeps the update and render function in loop.

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

	// This loop goes until the value of states static variable is 0. When the values changes, the mainmenu object will get deleted.

	while (Game::states == 0)
	{
		this->update();
		this->render();
	}
	
}

/* This function will be called everytime the player presses upand down keys in the main menu.
   This will change the colour of all the fonts to white.
*/

void MainMenu::fontDef()
{
	this->play.setFillColor(sf::Color::White);
	this->hScore.setFillColor(sf::Color::White);
	this->quit.setFillColor(sf::Color::White);
}

/* This function will be called everytime the player presses upand down keys in the main menu after fontDef().
   This will change the colour of the current option's font to red.
*/

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

// This function is used to get the player input and change the values of the variables according to the player's input.

void MainMenu::update()
{
	while (this->window->pollEvent(this->evnt))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			this->fontDef();
			this->option.openFromFile("option.wav");
			this->option.play();
			this->mOption--;
			if (this->mOption < 0)
			{
				this->mOption = 2;
				this->fontOption();
			}
			this->fontOption();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			this->fontDef();
			this->option.openFromFile("option.wav");
			this->option.play();
			this->mOption++;
			if (this->mOption > 2)
			{
				this->mOption = 0;
				this->fontOption();
			}
			this->fontOption();

		}

		// When the enter key is pressed the value of the states static variable will be changed and this will delete the main menu object.

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			Game::states = this->mOption + 1;
		}
	}
}

// This function is used to render all the fonts and background elements everyframe using sfml functions.

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

/* When the value of the states static variable changes, the destructor will be called.
   Destructor is used to delete the floor object everytime as it is initialized using heap allocation.
*/

MainMenu::~MainMenu()
{
	delete this->floor;
}
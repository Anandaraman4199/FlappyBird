#include "Scoreboard.h"
#include <iostream>



Scoreboard::Scoreboard(sf::RenderWindow* window)
{
	this->window = window;
	this->floor = new Floor(true);
	this->background.loadFromFile("background.png");
	this->bg.setSize(sf::Vector2f(Game::sWidth, Game::sHeight));
	this->bg.setTexture(&this->background);
	this->bg.setPosition(0, 0);
	this->font.loadFromFile("score.ttf");
	this->namefont.loadFromFile("gamefont.ttf");
	this->file = new mINI::INIFile("highscore.ini");
	this->file->read(this->ini);
	this->ini.begin()->second;
	this->namelist = this->ini["name"];
	this->scorelist = this->ini["score"];
	this->size = this->namelist.size();

	this->nametitle.setFont(this->namefont);
	this->scoretitle.setFont(this->namefont);
	this->ranktitle.setFont(this->namefont);
	this->stitle.setFont(this->namefont);

	this->nametitle.setCharacterSize(Game::sWidth / 19.2);
	this->scoretitle.setCharacterSize(Game::sWidth / 19.2);
	this->ranktitle.setCharacterSize(Game::sWidth / 19.2);
	this->stitle.setCharacterSize(Game::sWidth / 19.2);

	this->nametitle.setString("Name");
	this->scoretitle.setString("Score");
	this->ranktitle.setString("Rank");
	this->stitle.setString("Scoreboard");

	this->nametitle.setOrigin(sf::Vector2f(this->nametitle.getGlobalBounds().width / 2, this->nametitle.getGlobalBounds().height));
	this->scoretitle.setOrigin(sf::Vector2f(this->scoretitle.getGlobalBounds().width / 2, this->scoretitle.getGlobalBounds().height));
	this->ranktitle.setOrigin(sf::Vector2f(this->ranktitle.getGlobalBounds().width / 2, this->ranktitle.getGlobalBounds().height));
	this->stitle.setOrigin(sf::Vector2f(this->stitle.getGlobalBounds().width / 2, this->stitle.getGlobalBounds().height));

	this->nametitle.setOutlineThickness(Game::sWidth / 850);
	this->scoretitle.setOutlineThickness(Game::sWidth / 850);
	this->ranktitle.setOutlineThickness(Game::sWidth / 850);
	this->stitle.setOutlineThickness(Game::sWidth / 850);

	this->stitle.setFillColor(sf::Color::Red);

	this->nametitle.setOutlineColor(sf::Color::Black);
	this->scoretitle.setOutlineColor(sf::Color::Black);
	this->ranktitle.setOutlineColor(sf::Color::Black);
	this->stitle.setOutlineColor(sf::Color::Black);

	this->nametitle.setPosition(Game::sWidth * 2 / 4, Game::sHeight*2/ 8);
	this->scoretitle.setPosition(Game::sWidth * 3 / 4, Game::sHeight * 2 / 8);
	this->ranktitle.setPosition(Game::sWidth / 4, Game::sHeight * 2 / 8);
	this->stitle.setPosition(Game::sWidth * 2 / 4, Game::sHeight / 8);

	if (this->size)
	{
		for (int i = 0; i < this->size; i++)
		{
		
			this->name[i].setFont(this->namefont);
			this->score[i].setFont(this->font);
			this->rank[i].setFont(this->font);

			this->rank[i].setCharacterSize(Game::sWidth/23);
			this->name[i].setCharacterSize(Game::sWidth / 15);
			this->score[i].setCharacterSize(Game::sWidth / 23);

			this->rank[i].setString(std::to_string(i+1));
			this->name[i].setString((this->namelist.begin() + i)->second);
			this->score[i].setString((this->scorelist.begin() + i)->second);

			this->rank[i].setOrigin(sf::Vector2f(this->rank[i].getGlobalBounds().width/10 , this->rank[i].getGlobalBounds().height/2 ));
			this->name[i].setOrigin(sf::Vector2f(this->name[i].getGlobalBounds().width / 2, this->name[i].getGlobalBounds().height ));
			this->score[i].setOrigin(sf::Vector2f(this->score[i].getGlobalBounds().width/10 , this->score[i].getGlobalBounds().height/2));

			this->rank[i].setPosition(Game::sWidth / 4, Game::sHeight * (i + 3) / 8);
			this->name[i].setPosition(Game::sWidth * 2/ 4, Game::sHeight * (i + 3) / 8);
			this->score[i].setPosition(Game::sWidth * 3 / 4, Game::sHeight * (i + 3) / 8);

			this->rank[i].setOutlineThickness(Game::sWidth / 960);
			this->name[i].setOutlineThickness(Game::sWidth / 960);
			this->score[i].setOutlineThickness(Game::sWidth / 960);

			this->rank[i].setOutlineColor(sf::Color::Black);
			this->name[i].setOutlineColor(sf::Color::Black);
			this->score[i].setOutlineColor(sf::Color::Black);
		}
	}
	else
	{
		this->noscore.setFont(this->namefont);
		this->noscore.setCharacterSize(Game::sWidth / 19.2);
		this->noscore.setString("No HighScore Yet");
		this->noscore.setPosition(Game::sWidth / 2, Game::sHeight / 2);
		this->noscore.setOrigin(this->noscore.getGlobalBounds().width / 2, this->noscore.getGlobalBounds().height);
		
		this->noscore.setOutlineThickness(Game::sWidth / 960);
		this->noscore.setOutlineColor(sf::Color::Black);
	}
	while (Game::states == 2)
	{
		this->update();
		this->render();
	}

}

void Scoreboard::getInput()
{
	while (this->window->pollEvent(this->evnt))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			Game::states = 0;
		}
	}
}

void Scoreboard::update()
{
	this->getInput();
}

void Scoreboard::render()
{
	this->window->clear();
	this->window->draw(this->bg);
	this->floor->render(this->window);
	this->window->draw(this->stitle);
	this->size = this->namelist.size();

	if (this->size)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->window->draw(this->name[i]);
			this->window->draw(this->score[i]);
			this->window->draw(this->rank[i]);
		}
		this->window->draw(this->nametitle);
		this->window->draw(this->scoretitle);
		this->window->draw(this->ranktitle);
	
	}
	else
	{
		this->window->draw(this->noscore);
	}
	this->window->display();
}
#include "GameOver.h"
#include "Game.h"
#include "GameState.h"
#include <iostream>

GameOver::GameOver()
{
	this->fontInitialise();
}

void GameOver::initialize()
{
	this->file = new mINI::INIFile("highscore.ini");
	this->file->read(this->ini);
	this->namelist = this->ini["name"];
	this->scorelist = this->ini["score"];
	this->size = this->scorelist.size();
	if (GameState::Score > 0)
	{
		if (this->size)
		{
			for (int i = 0; i < this->size; i++)
			{
				this->list[i].rank = i + 1;
				this->list[i].name = (this->namelist.begin() + i)->second;
				this->list[i].score = std::stoi((this->scorelist.begin() + i)->second, nullptr, 10);
			}
			for (int i = 0; i < this->size; i++)
			{
				if (GameState::Score > this->list[i].score)
				{
					this->pos = i;
					break;
				}
				else
				{
					this->pos++;
				}
			}
			if (this->pos < 5)
			{
				this->highscoreb = true;
			}
			
		}
		else
		{
			this->highscoreb = true;
		}
	}
	std::cout << this->pos;
}

void GameOver::fontInitialise()
{
	this->name = new std::string(5, 'X');
	this->font.loadFromFile("gamefont.ttf");
	this->highscore.setFont(this->font);
	this->enter.setFont(this->font);
	this->namet.setFont(this->font);

	this->highscore.setCharacterSize(Game::sWidth / 19.2);
	this->enter.setCharacterSize(Game::sWidth / 19.2);
	this->namet.setCharacterSize(Game::sWidth / 19.2);

	this->highscore.setString("NEW HIGHSCORE");
	this->enter.setString("ENTER YOUR NAME");
	this->namet.setString(*this->name);

	this->highscore.setOrigin(this->highscore.getGlobalBounds().width / 2, this->highscore.getGlobalBounds().height / 2);
	this->enter.setOrigin(this->enter.getGlobalBounds().width / 2, this->enter.getGlobalBounds().height / 2);
	this->namet.setOrigin(this->namet.getGlobalBounds().width / 2, this->namet.getGlobalBounds().height / 2);

	this->highscore.setOutlineColor(sf::Color::Black);
	this->enter.setOutlineColor(sf::Color::Black);
	this->namet.setOutlineColor(sf::Color::Black);

	this->highscore.setOutlineThickness(Game::sWidth / 768);
	this->enter.setOutlineThickness(Game::sWidth / 768);
	this->namet.setOutlineThickness(Game::sWidth / 768);

	this->retry.setFont(this->font);
	this->yes.setFont(this->font);
	this->no.setFont(this->font);

	this->retry.setCharacterSize(Game::sWidth / 19.2);
	this->yes.setCharacterSize(Game::sWidth / 19.2);
	this->no.setCharacterSize(Game::sWidth / 19.2);

	this->retry.setString("RETRY");
	this->yes.setString("YES");
	this->no.setString("NO");

	this->retry.setOrigin(this->retry.getGlobalBounds().width / 2, this->retry.getGlobalBounds().height / 2);
	this->yes.setOrigin(this->yes.getGlobalBounds().width / 2, this->yes.getGlobalBounds().height / 2);
	this->no.setOrigin(this->no.getGlobalBounds().width / 2, this->no.getGlobalBounds().height / 2);

	this->retry.setOutlineColor(sf::Color::Black);
	this->yes.setOutlineColor(sf::Color::Black);
	this->no.setOutlineColor(sf::Color::Black);

	this->retry.setOutlineThickness(Game::sWidth / 768);
	this->yes.setOutlineThickness(Game::sWidth / 768);
	this->no.setOutlineThickness(Game::sWidth / 768);

	this->retry.setPosition(Game::sWidth / 2, Game::sHeight / 4);
	this->yes.setPosition(Game::sWidth / 4, Game::sHeight / 2);
	this->no.setPosition(Game::sWidth * 3 / 4, Game::sHeight / 2);

	this->highscore.setPosition(Game::sWidth / 2, Game::sHeight / 4);
	this->enter.setPosition(Game::sWidth / 4, Game::sHeight / 2);
	this->namet.setPosition(Game::sWidth * 3 / 4, Game::sHeight / 2);

}

void GameOver::getInput(sf::RenderWindow* window)
{
	while (window->pollEvent(this->evnt))
	{
		if (this->highscoreb)
		{
			if (this->charpos < 5)
			{
				if (this->evnt.type == sf::Event::TextEntered)
				{

					if (this->evnt.text.unicode < 128)
					{
						this->musicoption.openFromFile("option.wav");
						this->musicoption.play();
						(*this->name)[this->charpos] = std::toupper((char)(this->evnt.text.unicode));
						this->charpos++;
					}
				}
			}
			else
			{
				this->highscoreb = false;
				if (this->size > 0)
				{
					if (this->size > 4)
					{
						this->size = 4;
					}
					for (int i = this->size; i > this->pos; i--)
					{
						this->list[i] = this->list[i - 1];
					}
					this->list[this->pos].rank = this->pos + 1;
					this->list[this->pos].name = *this->name;
					this->list[this->pos].score = GameState::Score;
					this->ini.clear();
					for (int i = 0; i <= this->size; i++)
					{
						this->ini["name"][std::to_string(i + 1)] = this->list[i].name;
						this->ini["score"][std::to_string(i + 1)] = std::to_string(this->list[i].score);
					}
				}
				else
				{
					this->ini["name"]["1"] = *this->name;
					this->ini["score"]["1"] = std::to_string(GameState::Score);
				}
					this->file->generate(this->ini);

			}

		}
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{

				this->musicoption.openFromFile("option.wav");
				this->musicoption.play();
				this->option--;
				if (this->option < 0)
				{
					this->option = 1;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{

				this->musicoption.openFromFile("option.wav");
				this->musicoption.play();
				this->option++;
				if (this->option > 1)
				{
					this->option = 0;
				}

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				if (this->option)
				{
					Game::states = 4;
				}
				else
				{
					Game::states = 0;
				}
			}
		}
	}
}


void GameOver::update(sf::RenderWindow* window)
{
	this->yes.setFillColor(sf::Color::White);
	this->no.setFillColor(sf::Color::White);
	this->getInput(window);
	if (this->option)
	{
		this->yes.setFillColor(sf::Color::Red);
	}
	else
	{
		this->no.setFillColor(sf::Color::Red);
	}
	this->namet.setString(*this->name);
}

void GameOver::render(sf::RenderWindow* window)
{
	if (this->highscoreb)
	{
		window->draw(this->highscore);
		window->draw(this->enter);
		window->draw(this->namet);
	}
	else
	{
		window->draw(this->retry);
		window->draw(this->yes);
		window->draw(this->no);
	}
	
}

GameOver::~GameOver()
{
	delete this->file;
	delete this->name;

}
#include "Pipe.h"
#include "GameState.h"
#include <cstdlib>
#include <iostream>

Pipe::Pipe()
{
	std::srand(static_cast<unsigned int>(time(0)));
	this->pipePos.y = ((std::rand()*std::rand()+std::rand()) % (int)(Game::sHeight - Game::sHeight / 8 - this->PIPEGAP)) + (this->PIPEGAP / 2);
	this->pipePos.x = GameState::player->getPosition().x + Game::sWidth;
	this->rect1end.setSize(sf::Vector2f(this->RECXSIZE, this->RECXSIZE));
	this->rect2end.setSize(sf::Vector2f(this->RECXSIZE, this->RECXSIZE));
	this->rect1end.setOrigin(this->rect1end.getSize().x / 2, this->rect1end.getSize().y / 2);
	this->rect2end.setOrigin(this->rect2end.getSize().x / 2, this->rect2end.getSize().y / 2);
	this->rect1end.setPosition(this->pipePos.x, this->pipePos.y - (this->PIPEGAP / 2) - (this->rect1end.getSize().y / 2));
	this->rect2end.setPosition(this->pipePos.x, this->pipePos.y + (this->PIPEGAP / 2) + (this->rect1end.getSize().y / 2));

	this->rect1.setSize(sf::Vector2f(this->RECXSIZE, (this->pipePos.y - (this->PIPEGAP/2)-this->RECXSIZE)));
	this->rect2.setSize(sf::Vector2f(this->RECXSIZE, (Game::sHeight - (this->rect2end.getPosition().y) + (this->RECXSIZE/ 2))));

	this->rect1.setOrigin(this->rect1.getSize().x / 2, this->rect1.getSize().y / 2);
	this->rect2.setOrigin(this->rect2.getSize().x / 2, this->rect2.getSize().y / 2);

	this->rect1.setPosition(this->pipePos.x, this->rect1end.getPosition().y - this->RECXSIZE/2 - this->rect1.getSize().y/2);
	this->rect2.setPosition(this->pipePos.x, this->rect2end.getPosition().y + this->RECXSIZE/2 + this->rect2.getSize().y/2);

	this->pipe1.loadFromFile("pipe1.png");
	this->pipe2.loadFromFile("pipe2.png");
	this->pipe1end.loadFromFile("pipe1end.png");
	this->pipe2end.loadFromFile("pipe2end.png");

	this->rect1end.setTexture(&this->pipe1end);
	this->rect2end.setTexture(&this->pipe2end);
	this->rect1.setTexture(&this->pipe1);
	this->rect2.setTexture(&this->pipe2);

/*	this->rect1.setOutlineColor(sf::Color::Black);
	this->rect2.setOutlineColor(sf::Color::Black);

	this->rect1.setOutlineThickness(Game::sWidth / 384);
	this->rect2.setOutlineThickness(Game::sWidth / 384);*/
}

void Pipe::pCollision()
{
	if (abs(this->pipePos.x - GameState::player->getPosition().x) - ((this->RECXSIZE / 2) + GameState::player->getRadius())<1)
	{
		if (abs(GameState::player->getPosition().y - this->rect1.getPosition().y) - ((this->rect1.getSize().y / 2) + GameState::player->getRadius()) < 1)
		{
			GameState::pPipeCollision = true;
		}
		else if (abs(GameState::player->getPosition().y - this->rect2.getPosition().y) - ((this->rect2.getSize().y / 2) + GameState::player->getRadius()) < 1)
		{
			GameState::pPipeCollision = true;
		}
		if (abs(GameState::player->getPosition().y - this->rect1end.getPosition().y) - ((this->rect1end.getSize().y / 2) + GameState::player->getRadius()) < 1)
		{
			GameState::pPipeCollision = true;
		}
		else if (abs(GameState::player->getPosition().y - this->rect2end.getPosition().y) - ((this->rect2end.getSize().y / 2) + GameState::player->getRadius()) < 1)
		{
			GameState::pPipeCollision = true;
		}

	}

}

void Pipe::update()
{
	this->dT = this->clock.restart().asSeconds();
	this->pCollision();
	if (this->pipePos.x < GameState::player->getPosition().x)
	{
		if (!this->gaveScore)
		{
			GameState::Score = GameState::Score + 1;
			this->gaveScore = true;
			GameState::playPoint();

		}
	}
	this->rect1.move(-this->dT * this->SPEED, 0);
	this->rect2.move(-this->dT * this->SPEED, 0);
	this->rect1end.move(-this->dT * this->SPEED, 0);
	this->rect2end.move(-this->dT * this->SPEED, 0);
	this->pipePos.x = this->rect1.getPosition().x;

}

void Pipe::render(sf::RenderWindow* window)
{
	if (GameState::pbtCollision())
	{
		this->rect1.setFillColor(sf::Color(50, 205, 50, 50));
		this->rect2.setFillColor(sf::Color(50, 205, 50, 50));
		this->rect1end.setFillColor(sf::Color(50, 205, 50, 50));
		this->rect2end.setFillColor(sf::Color(50, 205, 50, 50));
	}
	window->draw(this->rect1end);
	window->draw(this->rect2end);
	window->draw(this->rect1);
	window->draw(this->rect2);
}
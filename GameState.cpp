#include "GameState.h"
#include <iostream>
#include <string>

sf::CircleShape* GameState::player = new sf::CircleShape();
bool GameState::pPipeCollision = false;
int GameState::Score = 0;
sf::Music* GameState::point = new sf::Music();



GameState::GameState(sf::RenderWindow* window)
{
	this->window = window;

	this->background.loadFromFile("background.png");
	this->bg.setSize(sf::Vector2f(Game::sWidth,Game::sHeight));
	this->bg.setTexture(&this->background);
	this->bg.setPosition(0, 0);

	this->bg1.setSize(sf::Vector2f(Game::sWidth, Game::sHeight));

	this->bg1.setFillColor(sf::Color(255, 255, 255, 50));
	this->bg1.setPosition(0, 0);

	this->font.loadFromFile("score.ttf");
	this->ScoreT.setFont(this->font);
	this->ScoreT.setCharacterSize(Game::sWidth / 19.2);
	this->ScoreT.setString(std::to_string(Score));
	this->ScoreT.setPosition(Game::sWidth / 2, Game::sHeight / 10);
	this->ScoreT.setOrigin(this->ScoreT.getGlobalBounds().width / 2, this->ScoreT.getGlobalBounds().height / 2);
	this->ScoreT.setOutlineColor(sf::Color::Black);
	this->ScoreT.setOutlineThickness(Game::sWidth / 800);
	this->playerTexidle.loadFromFile("playeridle.png");
	this->playerTexup.loadFromFile("playerup.png");
	this->playerTexdown.loadFromFile("playerdown.png");

	player->setRadius(Game::sWidth/80);
	player->setPointCount(20);
	player->setPosition(Game::sWidth / 4, Game::sHeight / 2);
	player->setOrigin(player->getGlobalBounds().width / 2, player->getGlobalBounds().height / 2);
	player->setTexture(&this->playerTexidle);
	this->finda();

	this->floor = new Floor(true);

	while (Game::states == 1)
	{
		this->update();
		this->render();
	}

}

void GameState::playPoint()
{
	point->openFromFile("point.wav");
	point->setVolume(75);
	point->play();
}

void GameState::finda()
{
	this->a = 1/(Game::sHeight/4.05);
	this->dX = (Game::sHeight * 2 / 4.05) / (this->jT / this->dT);
	this->dX = this->dX/(this->dT* ((1 / this->dT) / 4));
}

void GameState::getInput()
{
	while (this->window->pollEvent(this->evnt))
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (this->dE > 0.1)
			{
				this->wing.openFromFile("wing.wav");
				this->wing.setVolume(10);
				this->wing.setPitch(1.25);
				this->wing.play();
				this->swoosh.openFromFile("swooshing.wav");
				this->swoosh.setVolume(10);
				this->swoosh.setPitch(1.5);
				this->swoosh.play();
				this->dY = 0;
				this->jumpV = 0;
				this->jX = -Game::sHeight / 4.05;
				this->jumped = true;
				this->dE = 0;

			}
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{

		}


	}

}

void GameState::jump()
{

	if (((this->jX <= Game::sHeight / 4.05)&&(this->jX >= -Game::sHeight / 4.05))&&(!this->ptpCollision()))
	{
			
			this->jumpV = (this->a) * (this->jX * this->jX) - Game::sHeight / 4.05;
			this->jumpV = this->jumpV - this->dY;
			this->dY = this->dY + this->jumpV;
			this->jX = this->jX + this->dX;
			this->jumpV = this->jumpV;
	}
	else
	{
		this->dY = 0;
		this->jumpV = 0;
		this->jX = -Game::sHeight / 4.05;
		this->jumped = false;
	}
}

void GameState::updateAnim(bool direction)
{	
	if (direction)
	{
		if (this->aT > 0.2)
		{
			if (this->animChange)
			{
				this->animChange = false;
				this->aT = 0;
				this->finalAnim = this->playerTexup;
			}
			else
			{
				this->animChange = true;
				this->aT = 0;
				this->finalAnim = this->playerTexidle;
			}

		}
		else
		{
			this->finalAnim = *player->getTexture();
		}
	}
	else
	{
		if (this->aT > 0.2)
		{
			if (this->animChange)
			{
				this->animChange = false;
				this->aT = 0;
				this->finalAnim = this->playerTexdown;
			}
			else
			{
				this->animChange = true;
				this->aT = 0;
				this->finalAnim = this->playerTexidle;
			}

		}
		else
		{
			this->finalAnim = *player->getTexture();
		}
	}
}


void GameState::playerUpdate()
{
	if (this->jumped)
	{
		this->jump();
	}
	if (this->jumpV < 0)
	{
		player->move(0, this->speed + this->jumpV);
		this->updateAnim(true);
		player->setTexture(&this->finalAnim);
		if (this->iT > -30)
		{
			player->setRotation(this->iT = this->iT - (this->dT * 250));
		}
		else
		{
			player->setRotation(this->iT);
		}
	}
	else
	{
		player->move(0, this->speed);
		this->updateAnim(false);
		player->setTexture(&this->finalAnim);
			if (this->iT < 45)
			{
				player->setRotation(this->iT = this->iT + (this->dT*100));
			}
			else
			{
				player->setRotation(this->iT);
			}
	}
}

bool GameState::pbtCollision()
{
	if((Game::sHeight - Game::sHeight / 8 - player->getPosition().y <= player->getRadius())||(pPipeCollision))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GameState::ptpCollision()
{
	if (player->getPosition().y <= player->getRadius())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameState::update()
{
	
	this->dT = this->clock.restart().asSeconds();
	this->dE = this->dE + this->dT;
	this->aT = this->aT + this->dT;
	this->cT = this->cT + this->dT;
	this->speed = this->dT * Game::sHeight / 2.5;
	this->finda();
	if (!this->pbtCollision())
	{
		this->floor->update();
		this->getInput();
		this->playerUpdate();
		this->pMain.update();
	}
	else
	{

		if (this->goobj)
		{
			this->gameover.initialize();
			this->goobj = false;
		}

		if (this->play)
		{
			this->die.openFromFile("die.wav");
			this->die.setVolume(75);
			this->die.play();
			this->hit.openFromFile("hit.wav");
			this->hit.setVolume(50);
			this->hit.play();
			this->play = false;
		}

		this->gameover.update(this->window);
		
	}
	this->ScoreT.setString(std::to_string(Score));

}

void GameState::render()
{
	this->window->clear();
	this->window->draw(this->bg);
	if (this->pbtCollision())
	{
		this->window->draw(this->bg1);
	}

	this->window->draw(*player);
	this->pMain.render(this->window);
	if (this->pbtCollision())
	{
		player->setFillColor(sf::Color(255, 255, 255, 50));
		player->setOutlineColor(sf::Color(0, 0, 0, 50));
		this->gameover.render(this->window);
	}
	this->window->draw(this->ScoreT);
	this->floor->render(this->window);
	this->window->display();
}

GameState::~GameState()
{
	player->setFillColor(sf::Color(255, 255, 255, 255));
	player->setOutlineColor(sf::Color(0, 0, 0, 255));
	Score = 0;
	pPipeCollision = false;
	delete this->floor;
}
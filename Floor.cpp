#include "Floor.h"

Floor::Floor()
{
	this->floorshape.setSize(sf::Vector2f(Game::sWidth, Game::sHeight / 8));
	this->floorshape.setOrigin(this->floorshape.getSize().x / 2, this->floorshape.getSize().y / 2);
	this->floorshape.setPosition(Game::sWidth / 2+Game::sWidth, Game::sHeight - this->floorshape.getSize().y / 2);
	this->floortex.loadFromFile("floor.png");
	this->floorshape.setTexture(&this->floortex);
}

Floor::Floor(bool first)
{
	this->floorshape.setSize(sf::Vector2f(Game::sWidth, Game::sHeight / 8));
	this->floorshape.setOrigin(this->floorshape.getSize().x / 2, this->floorshape.getSize().y / 2);
	this->floorshape.setPosition(Game::sWidth / 2, Game::sHeight - this->floorshape.getSize().y / 2);
	this->floortex.loadFromFile("floor.png");
	this->floorshape.setTexture(&this->floortex);
}

void Floor::update()
{
	this->dT = this->clock.restart().asSeconds();
	this->floorshape.move(-this->dT * Game::sWidth / 6.4, 0);
}

void Floor::render(sf::RenderWindow* window)
{
	window->draw(this->floorshape);
}
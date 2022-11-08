#include "PipeMaintainer.h"
#include "GameState.h"
#include <iterator>



PipeMaintainer::PipeMaintainer()
{
	
	this->playerPosition = GameState::player->getPosition();
	Pipe* pipe = new Pipe();
	Floor* floor = new Floor();
	this->listOfPipes.push_back(pipe);
	this->listOfFloor.push_back(floor);
}

void PipeMaintainer::updatePlayerPos()
{
	this->playerPosition = GameState::player->getPosition();
}

void PipeMaintainer::pipeCreate()
{
	std::vector<Pipe*>::iterator ptr;
	
	ptr = this->listOfPipes.end() - 1;
	if ((*ptr)->pipePos.x + Game::sWidth / 3 < Game::sWidth + this->playerPosition.x)
	{
		Pipe* pipe = new Pipe();
		this->listOfPipes.push_back(pipe);
	}

	std::vector<Floor*>::iterator fptr;

	fptr = this->listOfFloor.end() - 1;
	if ((*fptr)->floorshape.getPosition().x <= Game::sWidth / 2)
	{
		Floor* floor = new Floor();
		this->listOfFloor.push_back(floor);
	}
}


void PipeMaintainer::pipeDelete()
{
	std::vector<Pipe*>::iterator ptr;
	ptr = this->listOfPipes.begin();
	if ((*ptr)->pipePos.x < -Game::sWidth/9.6)
	{
		delete *ptr;
		this->listOfPipes.erase(ptr);
	}

	std::vector<Floor*>::iterator fptr;
	fptr = this->listOfFloor.begin();

	if ((*fptr)->floorshape.getPosition().x < -Game::sWidth / 2)
	{
		delete* fptr;
		this->listOfFloor.erase(fptr);
	}
}


void PipeMaintainer::update()
{
	this->updatePlayerPos();
	this->pipeCreate();
	this->pipeDelete();
	std::vector<Pipe*>::iterator ptr;
	for (ptr = this->listOfPipes.begin(); ptr < this->listOfPipes.end(); ptr++)
	{
		(*ptr)->update();
	}
	std::vector<Floor*>::iterator fptr;
	for (fptr = this->listOfFloor.begin(); fptr < this->listOfFloor.end(); fptr++)
	{
		(*fptr)->update();
	}
}

void PipeMaintainer::render(sf::RenderWindow* window)
{
	std::vector<Pipe*>::iterator ptr;
	for (ptr = this->listOfPipes.begin(); ptr < this->listOfPipes.end(); ptr++)
	{
		(*ptr)->render(window);
	}
	std::vector<Floor*>::iterator fptr;
	for (fptr = this->listOfFloor.begin(); fptr < this->listOfFloor.end(); fptr++)
	{
		(*fptr)->render(window);
	}
}




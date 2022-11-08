#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "mini/ini.h"
#include "SFML/Audio.hpp"

struct highscorelist
{
	int rank;
	std::string name;
	int score;
};

class GameOver
{
private:

	highscorelist list[5];

	sf::Clock clock;
	sf::Font font;

	sf::Event evnt;

	sf::Music musicoption;

	sf::Text retry, yes, no,highscore,enter,namet;

	mINI::INIFile* file;
	mINI::INIStructure ini;
	mINI::INIMap<std::string> namelist, scorelist;
	
	bool highscoreb=false;

	int size, pos=0 ,charpos = 0;

	std::string* name;

	int option = 0;

	float dE;

	void getInput(sf::RenderWindow* window);

	void fontInitialise();

public:

	GameOver();

	~GameOver();

	void initialize();

	void update(sf::RenderWindow* window);

	void render(sf::RenderWindow* window);
	
};


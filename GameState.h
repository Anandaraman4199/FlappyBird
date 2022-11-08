#pragma once
#include "Game.h"
#include "PipeMaintainer.h"
#include "GameOver.h"
#include "SFML/Audio.hpp"

class GameState
{
private:

	sf::RenderWindow* window;
	sf::Texture background;

	sf::Music hit, die, wing,swoosh;

	sf::RectangleShape bg,bg1;
	GameOver gameover;

	sf::Event evnt;

	Floor* floor;

	sf::Clock clock;

	sf::Font font;
	sf::Text ScoreT;

	sf::Texture playerTexidle, playerTexup, playerTexdown, finalAnim;

	PipeMaintainer pMain;

	bool goobj=true;

	bool jumped = false;

	float a = 0, jumpV = 0, dY = 0;
	float jX = -Game::sHeight / 4.05;
	float dT = 0, speed = 0, jT = 4, nF = 0, dX = 0 ,dE=0,aT=0,cT=0,iT=0;

	bool animChange = false;

	void finda();

	void jump();

	void getInput();
	void playerUpdate();
	
	void updateAnim(bool direction);

	bool play = true;

	bool ptpCollision();

	void update();

	void render();

public:

	static sf::Music* point;

	static void playPoint();

	static bool pbtCollision();

	static int Score;

	static sf::CircleShape* player;

	static bool pPipeCollision;

	GameState(sf::RenderWindow* window);

	~GameState();


};


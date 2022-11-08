#include "SFML/Graphics.hpp"
#include "Game.h"

int main()
{
	Game game;
	while (Game::running)
	{
		game.update();
	
	}
	return 0;
}
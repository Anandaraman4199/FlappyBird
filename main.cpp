#include "Game.h"

int main()
{
	
	//Creating a game object which controls the game and making the program alive till the static boo variable is true.

	Game game;

	while (Game::running)
	{
		game.update();
	
	}
	return 0;
}
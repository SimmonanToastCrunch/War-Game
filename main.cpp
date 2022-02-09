#include "Game.h"

int main(int argc, char* args[])
{
	
	Game game("War Game", 1080, 720, 0);

	while (game.is_running())
	{
		game.handle();
	}
	





	return 0;
}
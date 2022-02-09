#include "Game.h"

Game::Game(const char* title, int ww, int wh, Uint32 flags)
{
	using namespace std;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "SDL failed to init! Error: " << SDL_GetError() << "\n";
	}
	window = SDL_CreateWindow
	(
		title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		ww,
		wh,
		flags
	);

	if (!window)
	{
		cout << "Window failed to create! Error: " << SDL_GetError() << "\n";
	}

	renderer = SDL_CreateRenderer
	(
		window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!renderer)
	{
		cout << "Renderer failed to create! Error: " << SDL_GetError() << endl;
	}

	running = true;
	SDL_SetRenderDrawColor(renderer, 235, 235, 235, 255);
}

Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handle()
{
	SDL_RenderClear(renderer);
	while (SDL_PollEvent(&sdlevent))
	{
		if (sdlevent.type == SDL_QUIT)
		{
			running = false;
		}


	}
	SDL_RenderPresent(renderer);
}
#include "Game.h"

Game::Game(const char* title, int ww, int wh, Uint32 flags)
{
	using namespace std;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "SDL failed to init! Error: " << SDL_GetError() << "\n";
	}
	if (IMG_Init(IMG_INIT_PNG) == NULL)
	{
		cout << "SDL_img failed to init! Error: " << SDL_GetError() << "\n";
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
	city_texture = IMG_LoadTexture(renderer, "assets/art/circle.png");
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
	SDL_Rect dst{};
	dst.w = 38;
	dst.h = 38;
	if (!city_vec.empty())
		for (int i = 0; i != city_vec.size(); i++)
		{
			city_vec[i].get_position(dst.x, dst.y);
			
			SDL_RenderCopy(renderer, city_texture, NULL, &dst);
		}
	

	SDL_RenderPresent(renderer);
}
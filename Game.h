#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class Game
{
public:
	Game(const char* title, int ww, int wh, Uint32 flags);
	~Game();

	void handle();


	inline bool is_running() const { return running; }
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event sdlevent{};

	bool running{ 0 };

};

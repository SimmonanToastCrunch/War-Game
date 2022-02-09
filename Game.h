#pragma once
#include <SDL_image.h>
#include <vector>
#include <iostream>

#include "City.h"


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

	SDL_Texture* city_texture = nullptr;

	std::vector<City> city_vec = { City(320, 320) };

	bool running{ 0 };

};

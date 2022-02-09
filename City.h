#pragma once
#include <SDL.h>

#include "Vec2.h"

class City
{
public:
	City(int px, int py);

	inline Vec2 get_position() const { return Vec2(x, y); }
	inline void get_position( int& px, int& py) const { px = x; py = y; }

	inline unsigned char get_citizens() const { return citizens; }

private:
	int x, y;
	unsigned char citizens;
	



};


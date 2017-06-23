#pragma once
#include "Console.h"
#include "Vector.h"

class Pixel {
public:
	char ascii;
	Color background;
	Color color;
	unsigned char tag;
	
	Pixel();
	Pixel(char, Color, Color);
	~Pixel();

	static const Pixel blank;						// equivalent to null

	Pixel & operator=(const Pixel &);

	void put(Vector);
};

bool operator==(const Pixel&, const Pixel&);
bool operator!=(const Pixel&, const Pixel&);
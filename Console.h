 #pragma once

#include <Windows.h>
#include "Vector.h"
#include <string>
using namespace std;

enum Color {
	black = 0x00,
	darkBlue = 0x01,
	darkGreen = 0x02,
	darkCyan = 0x03,
	darkRed = 0x04,
	darkPurple = 0x05,
	darkYellow = 0x06,
	lightGray = 0x07,
	darkGray = 0x08,
	blue = 0x09,
	green = 0x0A,
	cyan = 0x0B,
	red = 0x0C,
	purple = 0x0D,
	yellow = 0x0E,
	white = 0x0F
};

class Console {
private:
	static HANDLE hStdout, hStdin;
	static int consoleWidth, consoleHeigh;
public:
	Console();
	~Console();

	static void setPosition(Vector);
	static void setTitle(string);
	static void setConsoleDimension(Vector, Vector);
	static void setFullScreen();
	static void setCharacter(Vector);
	static void setColor(Color, Color);
};


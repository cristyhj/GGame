#include "Console.h"
#include "Log.h"

HANDLE Console::hStdout, Console::hStdin;
int Console::consoleHeigh, Console::consoleWidth;

Console::Console() {
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE || hStdout == INVALID_HANDLE_VALUE) {
		//Log("There is no console opened!");
	}
	_CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hStdout, &info);
	consoleWidth = info.dwMaximumWindowSize.X;
	consoleHeigh = info.dwMaximumWindowSize.Y;
	_CONSOLE_CURSOR_INFO curs;
	curs.dwSize = 1;
	curs.bVisible = 0;
	SetConsoleCursorInfo(hStdout, &curs);
}


Console::~Console() {
}


void Console::setPosition(Vector position) {
	if (position.x > consoleHeigh || position.y > consoleWidth) {
		//Log("You tried to print out of the console buffer!");
	}
	COORD point;
	point.X = position.x;
	point.Y = position.y;
	SetConsoleCursorPosition(hStdout, point);
}

void Console::setTitle(string title) {
	SetConsoleTitle(title.data());
}

void Console::setConsoleDimension(Vector position, Vector size) {
	SMALL_RECT rect;
	rect.Left = position.x;
	rect.Top = position.y;
	rect.Right = size.x;
	rect.Bottom = size.y;
	SetConsoleWindowInfo(hStdout, true, &rect);
}

void Console::setFullScreen() {
	SetConsoleDisplayMode(hStdout, CONSOLE_FULLSCREEN_MODE, 0);
	_CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hStdout, &info);
	consoleWidth = info.dwMaximumWindowSize.X;
	consoleHeigh = info.dwMaximumWindowSize.Y;
	SetConsoleScreenBufferSize(hStdout, info.dwMaximumWindowSize);

	_CONSOLE_CURSOR_INFO curs;
	curs.dwSize = 1;
	curs.bVisible = 0;
	SetConsoleCursorInfo(hStdout, &curs);
}

void Console::setCharacter(Vector dimension) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = dimension.x;
	cfi.dwFontSize.Y = dimension.y;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(hStdout, false, &cfi);
}

void Console::setColor(Color bk, Color color) {
	WORD bb = bk << 4;
	WORD col = (bk << 4) | color;
	SetConsoleTextAttribute(hStdout, col);
}


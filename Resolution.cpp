#include "Resolution.h"
#include "Console.h"


Resolution::Resolution() {
}


Resolution::~Resolution() {
}

Resolution Resolution::getApplicationResolution() {
	_CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	Resolution aux;
	aux.x = info.dwMaximumWindowSize.X;
	aux.y = info.dwMaximumWindowSize.Y;
	return aux;
}

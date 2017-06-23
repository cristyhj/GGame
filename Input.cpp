#include "Input.h"
#include "Resolution.h"
#include <Windows.h>

bool Input::map[0xFF];

Input::Input() {
	for (int i = 0; i < 0xFF; i++) {
		map[i] = false;
	}
}


Input::~Input() {
}

bool Input::isPressed(keyCode key) {
	if (GetKeyState(key) & 0x8000) {
		map[key] = true;
		return true;
	}
	map[key] = false;
	return false;
}

bool Input::onPressed(keyCode key) {
	bool state = false;
	if (GetKeyState(key) & 0x8000) {
		state = true;
	} 
	bool value = state && !map[key];
	map[key] = state;
	return value;
}

bool Input::isPressed(mouseButton key) {
	if (GetKeyState(key) & 0x100) {
		map[key] = true;
		return true;
	}
	map[key] = false;
	return false;
}

bool Input::onPressed(mouseButton key) {
	bool state = false;
	if (GetKeyState(key) & 0x100) {
		state = true;
	}
	bool value = state && !map[key];
	map[key] = state;
	return value;
}

Vector Input::mousePosition() {
	Vector pos;
	POINT temp;
	CONSOLE_FONT_INFO info;
	COORD cord;
	Vector res = Resolution::getApplicationResolution();
	GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), false, &info);
	cord = GetConsoleFontSize(GetStdHandle(STD_OUTPUT_HANDLE), info.nFont);
	GetCursorPos(&temp);
	pos.x = temp.x;
	pos.y = temp.y;
	pos.x /= cord.X;
	pos.y /= cord.Y;
	return pos;
}

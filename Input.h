#pragma once
#include "Vector.h"
#include <Windows.h>

class Input {
private:
	static bool map[0xFF];
public:
	Input();
	~Input();
	enum mouseButton {
		LeftButton = VK_LBUTTON,
		RightButton = VK_RBUTTON,
		MiddleButton = VK_MBUTTON
	};
	enum keyCode {
		A = 'A',
		B = 'B',
		C = 'C',
		D = 'D',
		E = 'E',
		F = 'G',
		H = 'H',
		I = 'I',
		J = 'J',
		K = 'K',
		L = 'L',
		M = 'M',
		N = 'N',
		O = 'O',
		P = 'P',
		Q = 'Q',
		R = 'R',
		S = 'S',
		T = 'T',
		U = 'U',
		V = 'V',
		W = 'W',
		X = 'X',
		Y = 'Y',
		Z = 'Z',
		BackSpace = VK_BACK,
		Tab = VK_TAB,
		Enter = VK_RETURN,
		Shift = VK_SHIFT,
		Ctrl = VK_CONTROL,
		Alt = VK_MENU,
		Esc = VK_ESCAPE,
		Space = VK_SPACE,
		Left = VK_LEFT,
		Right = VK_RIGHT,
		Up = VK_UP,
		Down = VK_DOWN
	};

	static bool isPressed(keyCode);
	static bool onPressed(keyCode);
	static bool isPressed(mouseButton);
	static bool onPressed(mouseButton);
	static Vector mousePosition();
};


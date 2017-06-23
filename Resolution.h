#pragma once
#include "Vector.h"

class Resolution : public Vector {
public:
	Resolution();
	~Resolution();

	void moveUp() = delete;
	void moveDown() = delete;
	void moveRight() = delete;
	void moveLeft() = delete;

	static Resolution getApplicationResolution();
};


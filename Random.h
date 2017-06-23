#pragma once
#include "Vector.h"
#include <stdlib.h>
#include <time.h>

class Random {
public:
	Random();
	~Random();

	static int randomInt(int max);
	static Vector randomVector(Vector max);
};


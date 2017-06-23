#include "Random.h"



Random::Random() {
	srand(time(0));
}


Random::~Random() {
}

int Random::randomInt(int max) {
	return rand() % max;
}

Vector Random::randomVector(Vector max) {
	return Vector(rand() % max.x, rand() % max.y);
}

#pragma once
#include "StandardObject.h"
#include "LayerManager.h"
#include "Random.h"
#include <vector>
using namespace std;

class GGame {
private:
	int fps;
	static bool gameOver;
	static GGame *mInstance;

public:
	static int actualFps;

public:
	GGame(int);
	~GGame();
	GGame();

	void callRoutines();
	void callInitialize();

	static void callGraphicsUpdate();
	static void callOnCollision(unsigned char, unsigned char);

	void setFPS(int fps);

	void start();
	static void end();

	template<typename T>
	static T* instantiateObject(unsigned char, Vector);
};

template<typename T>
inline T * GGame::instantiateObject(unsigned char tag, Vector pos) {
	T *item = new T(tag, pos);
	return item;
}

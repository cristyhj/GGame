#include "GGame.h"
#include "Console.h"
#include <chrono>
#include <thread>
#include "UI.h"
using namespace std::chrono;

bool GGame::gameOver;
GGame* GGame::mInstance = nullptr;
int GGame::actualFps = 0;

GGame::GGame() {
	if (mInstance == nullptr) {
		mInstance = this;
		Console();
	}
}

//GGame & GGame::operator=(const GGame &) {
//	// TODO: insert return statement here
//}


GGame::GGame(int fps) {
	if (mInstance == nullptr) {
		mInstance = this;
		this->fps = fps;
		Console();
	} else {
		mInstance->fps = fps;
	}
}

GGame::~GGame() {
}

void GGame::start() {
	if (!mInstance) return;
	mInstance->gameOver = false;
	steady_clock::time_point moment;
	int time = 0;
	//UI::instance()->addUpdatedInt(&time, Vector(Resolution::getApplicationResolution().x - 20, 10));

	mInstance->callInitialize();
	//std::thread t1(callGraphicsUpdate);
	//t1.join();
	while (!mInstance->gameOver) {
		moment = steady_clock::now();
		mInstance->callRoutines();
		callGraphicsUpdate();
		time = duration_cast<milliseconds>(steady_clock::now() - moment).count();
		if (time < fps) {								// this is for debug with VS
			int difference = 1000 / fps - time;
			if (difference > 0) Sleep(difference);
		}
		time = duration_cast<milliseconds>(steady_clock::now() - moment).count();
		actualFps = 1000 / time;
	}
}

void GGame::end() {
	if (!mInstance) return;
	mInstance->gameOver = true;
}

#pragma once
#include <vector>
#include "GGame.h"
using namespace std;


class StandardObject {
private:
	static vector<StandardObject*> instancesRegister;
public:
	unsigned char tag;
public:
	StandardObject();
	~StandardObject();
	friend class GGame;

	virtual void start() {};				// used to initilize an object; it's called oce at the begining
	virtual void preUpdate() {};			// used to compute its propreties
	virtual void update() {};				// used to move through visual space
	virtual void lateUpdate() {};			// used to do final computations and get ready for next update

	virtual void onCollision(unsigned char) {};		// overload to manipulte collisions
};


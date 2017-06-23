#include "Body.h"
#include <math.h>



void Body::preUpdate() {
	steady_clock::time_point thisMoment = steady_clock::now();
	int time;
	float diagonalForce;
	time = duration_cast<microseconds>(thisMoment - moment).count();				// first get the timelapse
	moment = steady_clock::now();													// get the time each loop
	diagonalForce = force.magnitude();
	diagonalForce -= friction();
	if (diagonalForce < 0) diagonalForce = 0;
	acceleration = diagonalForce / mass();
	velocity = acceleration * (static_cast<float>(time) / 1000000);
	if (velocity != velocity) velocity = 0;
}

void Body::update() {
	Vector temp = position;
	Vector newPos = temp;
	if (gravity) {
		force.y += 1 * mass();
	}
	newPos.x += force.x * velocity;
	newPos.y += force.y * velocity;
	unsigned char tag = layer->checkPrintable(map, position, newPos, dimension);
	if (tag == 0) {
		isColliding = false;
		position = newPos;
	} else {
		isColliding = true;
		GGame::callOnCollision(this->tag, tag);
	}
	force -= newPos - temp;
}

void Body::lateUpdate() {
	if (gravity && !isColliding) {
		addForce(Vector::down);
	}
}

void Body::moveRight() {
	Vector temp = position;
	Vector newPos = temp;

	newPos.moveRight();
	unsigned char tag = layer->checkPrintable(map, position, newPos, dimension);
	if (tag == 0) {
		isColliding = false;
		position = newPos;
	} else {
		isColliding = true;
		GGame::callOnCollision(this->tag, tag);
	}
}

void Body::moveLeft() {
	Vector temp = position;
	Vector newPos = temp;

	newPos.moveLeft();
	unsigned char tag = layer->checkPrintable(map, position, newPos, dimension);
	if (tag == 0) {
		isColliding = false;
		position = newPos;
	} else {
		isColliding = true;
		GGame::callOnCollision(this->tag, tag);
	}
}

void Body::moveUp() {
	Vector temp = position;
	Vector newPos = temp;

	newPos.moveUp();
	unsigned char tag = layer->checkPrintable(map, position, newPos, dimension);
	if (tag == 0) {
		isColliding = false;
		position = newPos;
	} else {
		isColliding = true;
		GGame::callOnCollision(this->tag, tag);
	}
}

void Body::moveDown() {
	Vector temp = position;
	Vector newPos = temp;

	newPos.moveDown();
	unsigned char tag = layer->checkPrintable(map, position, newPos, dimension);
	if (tag == 0) {
		isColliding = false;
		position = newPos;
	} else {
		isColliding = true;
		GGame::callOnCollision(this->tag, tag);
	}
}

Body::Body() {
	gravity = false;
	isColliding = false;
	moment = steady_clock::now();
}


Body::~Body() {
}

void Body::addForce(Vector force) {
	this->force += force;
}

void Body::useGravity() {
	gravity = true;
}


#pragma once
#include "Sprite.h"
#include "Vector.h"
#include "RigidBody.h"
#include "StandardObject.h"
#include <chrono>
using namespace std::chrono;

class Body : public Sprite, public RigidBody, public StandardObject {
private:
	steady_clock::time_point moment;
protected:
	Vector force;
	bool gravity;
	bool isColliding;
public:
	Body();
	~Body();

	void preUpdate() override;
	void update() override;
	void lateUpdate() override;

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	void addForce(Vector);
	void useGravity();
};


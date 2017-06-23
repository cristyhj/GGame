#pragma once
#include "Vector.h"

class RigidBody {
private:		// protected?
	float _mass;
	float _friction;
public:
	float velocity;
	float acceleration;
	

	float mass() const { return _mass; }
	float friction() const { return _friction; }

	void setMass(float mass) { _mass = mass; }
	void setFriction(float friction) { _friction = friction; }

	RigidBody();
	RigidBody(float, float);
	~RigidBody();
};
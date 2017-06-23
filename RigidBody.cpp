#include "RigidBody.h"




RigidBody::RigidBody() {
	_friction = 0.3;
	_mass = 2;
	velocity = 0;
	acceleration = 0;
}

RigidBody::RigidBody(float mass, float friction) {
	this->_mass = mass;
	this->_friction = friction;
	this->velocity = 0;
	acceleration = 0;
}

RigidBody::~RigidBody() {
}

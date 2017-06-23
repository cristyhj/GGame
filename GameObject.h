#pragma once
#include "StandardObject.h"
#include "Body.h"

class GameObject : public StandardObject {
public:
	Body body;
public:
	GameObject(unsigned char);
	GameObject(unsigned char, Vector);
	~GameObject();
};


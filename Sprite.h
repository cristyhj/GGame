#pragma once
#pragma once
#include "Vector.h"
#include "Layer.h"
#include "Console.h"

class Sprite {
protected:
	Vector dimension;
	Layer *layer;
	Pixel **map;
	Vector lastPosition;
	Vector position;
public:
	Sprite();
	~Sprite();

	void updatePosition();

	void load(string);			//loads sprite from file
	void load(Vector, Color = cyan);

	void setLayer(Layer* layer) { this->layer = layer; }
	void setPosition(Vector position) { this->position = position; this->lastPosition = position; }

	void setTag(unsigned char tag);

	void flipHorizontally();
	void flipVerically();
	void rotate();

	Layer* getLayer() const { return layer; }
};


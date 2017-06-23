#pragma once
#include "Resolution.h"
#include "Pixel.h"


class Layer {
protected:
	Resolution resolution;
	Pixel **map;
	Pixel **printableMap; 
public:
	Layer();
	Layer(Layer&);
	~Layer();

	friend class GGame;

	Layer& operator=(const Layer&);

	void print(Pixel**, Vector, Vector);
	void clear(Pixel**, Vector, Vector);
	void clear();
	void update();

	unsigned char checkPrintable(Pixel**, Vector, Vector, Vector);
};

void updateGraphics(Vector *, Pixel***, Pixel***);


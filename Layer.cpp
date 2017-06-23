#include "Layer.h"
#include "LayerManager.h"

using namespace std;

Layer::Layer() {
	resolution = Resolution::getApplicationResolution();
	map = new Pixel*[resolution.x];
	printableMap = new Pixel*[resolution.x];
	for (int i = 0; i < resolution.x; i++) {
		map[i] = new Pixel[resolution.y];
		printableMap[i] = new Pixel[resolution.y];
		for (int j = 0; j < resolution.y; j++) {
			map[i][j] = Pixel::blank;
			printableMap[i][j] = Pixel::blank;
		}
	}
}

Layer::Layer(Layer &lay) {
	resolution = Resolution::getApplicationResolution();
	map = new Pixel*[resolution.x];
	printableMap = new Pixel*[resolution.x];
	for (int i = 0; i < resolution.x; i++) {
		map[i] = new Pixel[resolution.y];
		printableMap[i] = new Pixel[resolution.y];
	}
	for (int i = 0; i < resolution.x; i++) {
		for (int j = 0; j < resolution.y; j++) {
			map[i][j] = lay.map[i][j];
			printableMap[i][j] = lay.printableMap[i][j];
		}
	}
}


Layer::~Layer() {
	for (int i = 0; i < resolution.x; i++) {
		delete[] map[i];
		delete[] printableMap[i];
	}
	delete[] map;
	delete[] printableMap;
}

Layer & Layer::operator=(const Layer &lay) {
	for (int i = 0; i < resolution.x; i++) {
		for (int j = 0; j < resolution.y; j++) {
			map[i][j] = lay.map[i][j];
			printableMap[i][j] = lay.printableMap[i][j];
		}
	}
	return *this;
}

void Layer::print(Pixel **map, Vector position, Vector dimension) {
	for (int i = position.x; i < position.x + dimension.x && i < resolution.x; i++) {
		for (int j = position.y; j < position.y + dimension.y && j < resolution.y; j++) {
			if (map[i - position.x][j - position.y] != Pixel::blank) {
				this->printableMap[i][j] = map[i - position.x][j - position.y];
			}
		}
	}
}

void Layer::clear(Pixel **map, Vector position, Vector dimension) {
	for (int i = position.x; i < position.x + dimension.x && i < resolution.x; i++) {
		for (int j = position.y; j < position.y + dimension.y && j < resolution.y; j++) {
			if (map[i - position.x][j - position.y] != Pixel::blank) {
				this->printableMap[i][j] = Pixel::blank;
			}
		}
	}
}

void Layer::clear() {
	for (int i = 0;i < resolution.x; i++) {
		for (int j = 0; j < resolution.y; j++) {
			this->printableMap[i][j] = Pixel::blank;
		}
	}
}

void Layer::update() {
	for (int i = 0; i < resolution.x; i++) {
		for (int j = 0; j < resolution.y; j++) {
			if (map[i][j] != printableMap[i][j]) {
				map[i][j] = printableMap[i][j];
				map[i][j].put(Vector(i, j));
			}
		}
	}
}

unsigned char Layer::checkPrintable(Pixel **map, Vector lastPosition, Vector position, Vector dimension) {
	for (int i = 0; i < dimension.x && i + position.x < resolution.x; i++) {
		for (int j = 0; j < dimension.y && j + position.y < resolution.y; j++) {
			if (this->map[position.x + i][position.y + j] != Pixel::blank && 
				this->map[position.x + i][position.y + j] != this->map[lastPosition.x + i][lastPosition.y + j] && 
				map[i][j] != Pixel::blank) 
			{
				return this->map[position.x + i][position.y + j].tag;
			}
		}
	}
	return 0;
}

//void updateGraphics(Vector *resolution, Pixel *** map, Pixel *** printableMap) {
//	while (true)
//	for (int i = 0; i < resolution->x; i++) {
//		for (int j = 0; j < resolution->y; j++) {
//			if ((*map)[i][j] != (*printableMap)[i][j]) {
//				(*map)[i][j] = (*printableMap)[i][j];
//				(*map)[i][j].put(Vector(i, j));
//			}
//		}
//	}
//}

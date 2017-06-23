#include "Log.h"
#include "Sprite.h"
#include <fstream>
using namespace std;


void Sprite::updatePosition() {
	layer->clear(this->map, lastPosition, dimension);
	layer->print(this->map, position, dimension);
	lastPosition = position;
}

void Sprite::setTag(unsigned char tag) {
	for (int i = 0; i < dimension.x; i++) {
		for (int j = 0; j < dimension.y; j++) {
			map[i][j].tag = tag;
		}
	}
}

void Sprite::flipHorizontally() {
	Pixel aux;
	layer->clear(this->map, lastPosition, dimension);
	for (int i = 0; i < dimension.x; i++) {
		for (int j = 0; j < dimension.y / 2; j++) {
			aux = map[i][j];
			map[i][j] = map[i][dimension.y - 1 - j];
			map[i][dimension.y - 1 - j] = aux;
		}
	}
	layer->print(this->map, lastPosition, dimension);
}

void Sprite::flipVerically() {
	Pixel aux;
	layer->clear(this->map, lastPosition, dimension);
	for (int i = 0; i < dimension.x / 2; i++) {
		for (int j = 0; j < dimension.y; j++) {
			aux = map[i][j];
			map[i][j] = map[dimension.x - 1 - i][j];
			map[dimension.x - 1 - i][j] = aux;
		}
	}
	layer->print(this->map, lastPosition, dimension);
}

void Sprite::rotate() {
	Pixel **rot;
	int aux;
	layer->clear(this->map, lastPosition, dimension);
	rot = new Pixel*[dimension.y];
	for (int i = 0; i < dimension.y; i++) {
		rot[i] = new Pixel[dimension.x];
	}
	for (int i = 0; i < dimension.x; i++) {
		for (int j = 0; j < dimension.y; j++) {
			rot[j][i] = map[i][j];
		}
	}
	for (int i = 0; i < dimension.x; i++) {
		if (map[i]) delete[] map[i];
	}
	if (map) delete[] map;
	map = rot;
	aux = dimension.x;
	dimension.x = dimension.y;
	dimension.y = aux;
	layer->print(this->map, lastPosition, dimension);
}


Sprite::Sprite() {
	position = Vector(10, 10);
}


Sprite::~Sprite() {
	layer->clear(map, position, dimension);
	for (int i = 0; i < dimension.x; i++) {
		if (map[i]) delete[] map[i];
	}
	if (map) delete[] map;
}


void Sprite::load(string fileName) {
	ifstream file(fileName, ifstream::binary);
	if (!file) {
		Log::instance()->log("Eroare la incarcare sprite: " + fileName + "! Application exit with code 1!");
		exit(1);
	}
	file.read((char*)&dimension.x, sizeof(dimension.x));
	file.read((char*)&dimension.y, sizeof(dimension.y));
	map = new Pixel*[dimension.x];
	for (int i = 0; i < dimension.x; i++) {
		map[i] = new Pixel[dimension.y];
	}
	for (int i = 0; i < dimension.x; i++) {
		for (int j = 0; j < dimension.y; j++) {
			file.read(&map[i][j].ascii, sizeof(char));
			file.read((char*)&map[i][j].background, sizeof(unsigned char));
			file.read((char*)&map[i][j].color, sizeof(unsigned char));
		}
	}
	file.close();
}

void Sprite::load(Vector dimension, Color color) {
	this->dimension = dimension;
	map = new Pixel*[dimension.x];
	for (int i = 0; i < dimension.x; i++) {
		map[i] = new Pixel[dimension.y];
	}
	int midx = dimension.x / 2;
	int midy = dimension.y / 2;
	for (int i = 0; i < dimension.x; i++) {
		for (int j = 0; j < dimension.y; j++) {
			map[i][j] = Pixel(219, black, color);
		}
	}
}
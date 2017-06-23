#include "Pixel.h"
#include <iostream>
using namespace std;


const Pixel Pixel::blank = Pixel(32, Color::black, Color::black);

Pixel::Pixel() {
	ascii = 32;
	color = Color::black;
	background = Color::black;
	tag = 0;
}

Pixel::Pixel(char ascii, Color background, Color color) {
	this->ascii = ascii;
	this->background = background;
	this->color = color;
	tag = 0;
}

Pixel::~Pixel() {
}

Pixel & Pixel::operator=(const Pixel &op) {
	this->tag = op.tag;
	this->ascii = op.ascii;
	this->background = op.background;
	this->color = op.color;
	return *this;
}

void Pixel::put(Vector pos) {
	Console::setPosition(pos);
	Console::setColor(background, color);
	printf("%c", ascii);
}

bool operator==(const Pixel &lop, const Pixel &rop) {
	if ((lop.ascii == 32 && lop.background == 0 && lop.color == 0) ||
		(rop.ascii == 32 && rop.background == 0 && rop.color == 0))
	{
		return (lop.ascii == rop.ascii) && (lop.color == rop.color) && (lop.background == rop.background);
	} else {
		return (lop.ascii == rop.ascii) && (lop.color == rop.color) && (lop.background == rop.background) && (lop.tag == rop.tag);
	}
}

bool operator!=(const Pixel &lop, const Pixel &rop) {
	return !(rop == lop);
}

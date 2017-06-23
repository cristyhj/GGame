#include "Vector.h"
#include <math.h>

const Vector Vector::unit = Vector(1, 1);
const Vector Vector::left = Vector(-1, 0);
const Vector Vector::right = Vector(1, 0);
const Vector Vector::up = Vector(0, -1);
const Vector Vector::down = Vector(0, 1);


Vector & operator+(const Vector & lvec, const Vector & vec) {
	Vector *mem = new Vector(0, 0);
	mem->x = lvec.x + vec.x;
	mem->y = lvec.y + vec.y;
	return *mem;
}

Vector & Vector::operator+=(const Vector & vec) {
	this->x = this->x + vec.x;
	this->y = this->y + vec.y;
	return *this;
}

Vector & operator-(const Vector & lvec, const Vector & vec) {
	Vector *mem = new Vector(0, 0);
	mem->x = lvec.x - vec.x;
	mem->y = lvec.y - vec.y;
	return *mem;
}

Vector & Vector::operator-=(const Vector & vec) {
	this->x = this->x - vec.x;
	this->y = this->y - vec.y;
	return *this;
}

Vector & operator*(const Vector & lvec, const Vector & vec) {
	Vector *mem = new Vector(0, 0);
	mem->x = lvec.x * vec.x;
	mem->y = lvec.y * vec.y;
	return *mem;
}

Vector & Vector::operator*=(const Vector &vec) {
	this->x = this->x * vec.x;
	this->y = this->y * vec.y;
	return *this;
}

Vector & operator*(const Vector & vec, const int value) {
	Vector *mem = new Vector(0, 0);
	mem->x = vec.x * value;
	mem->y = vec.y * value;
	return *mem;
}

Vector & Vector::operator*=(const int &value) {
	this->x = this->x * value;
	this->y = this->y * value;
	return *this;
}

Vector & Vector::operator++() {
	this->x++;
	this->y++;
	return *this;
}

Vector Vector::operator++(int) {
	Vector temp = *this;
	this->x++;
	this->y++;
	return temp;
}

Vector & Vector::operator--() {
	Vector temp = *this;
	this->x--;
	this->y--;
	return temp;
}

Vector Vector::operator--(int) {
	return Vector();
}

float Vector::magnitude() {
	return sqrt(x * x + y * y);
}

void Vector::moveUp() {
	this->y--;
}

void Vector::moveDown() {
	this->y++;
}

void Vector::moveRight() {
	this->x++;
}

void Vector::moveLeft() {
	this->x--;
}

string Vector::toString() {
	return "(" + to_string(x) + ", " + to_string(y) + ")";
}

Vector::Vector() {
	x = 0;
	y = 0;
}

Vector::Vector(int x, int y) {
	this->x = x;
	this->y = y;
}


Vector::~Vector() {
}

std::ostream & operator<<(std::ostream &os, Vector vec) {
	os << "(" << vec.x << ", " << vec.y << ")";
	return os;
}

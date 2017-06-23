#pragma once
#include <iostream>
#include <string>
using namespace std;

//		┌─────────────────>x
//		│
//		│
//		│
//		│
//		│
//	  y	v
//		
	
class Vector {
public:
	int x, y;

	Vector &operator+=(const Vector &);
	Vector &operator-=(const Vector &);
	Vector &operator*=(const Vector &);
	Vector &operator*=(const int &);
	Vector &operator++();
	Vector operator++(int);
	Vector &operator--();
	Vector operator--(int);


	float magnitude();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	static const Vector unit;
	static const Vector left;
	static const Vector right;
	static const Vector up;
	static const Vector down;

	friend std::ostream & operator<<(std::ostream &os, Vector vec);
	string toString();

	Vector();
	Vector(int, int);
	~Vector();
};


Vector &operator+(const Vector &, const Vector &);
Vector &operator-(const Vector &, const Vector &);
Vector &operator*(const Vector &, const Vector &);
Vector &operator*(const Vector &, const int);
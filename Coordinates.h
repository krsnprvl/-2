#pragma once 
#include <iostream> 
class Coordinates { 
private:
	float x;
	float y; 
	float z;
public:
	// basic constructor
	// protects against unexpected implicit conversions
	explicit Coordinates(float X = 0, float Y = 0, float Z = 0) : x(X), y(Y), z(Z) {}
	// copy constructor
	// not necesary
	Coordinates(const Coordinates& obj);
	// postfix ++
	Coordinates operator++(int);
	// postfix --
	Coordinates operator--(int);
	// prefix ++
	friend float operator++(Coordinates& crd_1);
	// prefix --
	Coordinates operator--();
	// extra overloads
	bool operator!=(Coordinates& second); 
	bool operator==(Coordinates& second);
	// get data 
	float getX() {
	return x;
}
float getY() {
	return y;
}
float getZ() {
	return z;
}
void setCoord(float x, float y, float z) {
	this->x = x;
	this->y = y; this->z = z;
}
// destructor
~Coordinates() {
	x = 0;
	y = 0;
	z = 0;
}
};


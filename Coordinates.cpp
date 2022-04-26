#include "Coordinates.h"
// prototype
float operator++(Coordinates& crd_1);
// overloads operators 
Coordinates::Coordinates(const Coordinates& obj) {
	this->x = obj.x;
	this->y = obj.y;
	this->z = obj.z;
}
Coordinates Coordinates::operator++(int) {
	this->x += 1.5;
	this->y += 1.5;
	this->z += 1.5;
	// call copy construstor
	return Coordinates(*this);
}
Coordinates Coordinates::operator--(int) {
	this->x -= 5.9;
	this->y -= 5.9;
	this->z -= 5.9;
	// call copy construstor
	return Coordinates(*this);
}
Coordinates Coordinates::operator--() {
	float tmp_x = this->x,
		tmp_y = this->y, tmp_z = this->z;
	this->x -= tmp_y; this->y -= tmp_z; this->z -= tmp_x;
	// call copy construstor 
	return Coordinates(*this);
}
// friend func
float operator++(Coordinates& crd_1) {
	return (crd_1.x + crd_1.y + crd_1.z);
}
// extra overload operator
bool Coordinates::operator!=(Coordinates& second) {
	// x1 != x2 || y1 != y2 || z1 != z2
	if ((this->getX() != second.getX()) || (this->getY() != second.getY()) || (this -> getZ() != second.getZ()))
	return true;
	return false;
}
bool Coordinates::operator==(Coordinates& second) {
	// x1 == x2 && y1 == y2 && z1 == z2
	if ((this->getX() == second.getX()) && (this->getY() == second.getY()) && (this -> getZ() == second.getZ()))
	return true;
	return false;
}

#include "Space.h"

Space::Space()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Space::Space(double X, double Y, double Z) :x{ X }, y{ Y }, z{ Z }
{
}

Space& Space::operator=(const Space& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}
	return *this;
}

Space Space::operator+(const Space& other)
{
	return Space(this->x + other.x, this->y + other.y, this->z + other.z);
}

Space& Space::operator+=(const Space& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

void Space::setSpace(double X, double Y, double Z)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

double Space::getX() { return this->x; }
double Space::getY() { return this->y; }
double Space::getZ() { return this->z; }

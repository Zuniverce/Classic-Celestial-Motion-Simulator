#include "Space.h"
#include "Global.h"
Space::Space()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Space::Space(double X, double Y, double Z) :x{ X }, y{ Y }, z{ Z } {}

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
	double X = this->x + other.x;
	double Y = this->y + other.y;
	double Z = this->z + other.z;
	return Space(X, Y, Z);
}

Space& Space::operator+=(const Space& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

Space Space::operator-(const Space& other)
{
	double X = this->x - other.x;
	double Y = this->y - other.y;
	double Z = this->z - other.z;
	return Space(X, Y, Z);
}

void Space::setSpace(double X, double Y, double Z)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

double Space::getX()const { return this->x; }
double Space::getY()const { return this->y; }
double Space::getZ()const { return this->z; }

void Space::print()
{
	cout << "("
		<< this->getX() << ", "
		<< this->getY() << ", "
		<< this->getZ() <<
		")" << endl;
}

void Space::printToShow()
{
	int diveder = 1e+6;
	cout << "["
		<< this->getX() / diveder << ", "
		<< this->getY() / diveder << ", "
		<< this->getZ() / diveder <<
		"]" << ", ";
}

double Space::getDistance(const Space A, const Space B)
{
	double X = SQR(A.getX() - B.getX());
	double Y = SQR(A.getY() - B.getY());
	double Z = SQR(A.getZ() - B.getZ());
	return sqrt(X + Y + Z);
}

double Space::getSquareDistance(const Space A, const Space B)
{
	double X = SQR(A.getX() - B.getX());
	double Y = SQR(A.getY() - B.getY());
	double Z = SQR(A.getZ() - B.getZ());
	return X + Y + Z;
}
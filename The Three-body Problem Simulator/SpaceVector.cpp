#include "SpaceVector.h"
#include "Global.h"

SpaceVector::SpaceVector(void)
{
	this->x = ZERO;
	this->y = ZERO;
	this->z = ZERO;
}

SpaceVector::SpaceVector(const SpaceVector& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

SpaceVector::SpaceVector(double X, double Y, double Z)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

SpaceVector& SpaceVector::setSpaceVector(const SpaceVector& origin, double modulus)
{
	SpaceVector unitVector(origin.getUnitVector());
	this->x = modulus * unitVector.x;
	this->y = modulus * unitVector.y;
	this->z = modulus * unitVector.z;
	return *this;
}

SpaceVector& SpaceVector::operator=(const SpaceVector& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

SpaceVector SpaceVector::operator*(const double scalarMultiplier)
{
	return SpaceVector(
		this->x * scalarMultiplier,
		this->y * scalarMultiplier,
		this->z * scalarMultiplier);
}

SpaceVector SpaceVector::operator/(const double scalarDivisor)
{
	return SpaceVector(
		this->x / scalarDivisor,
		this->y / scalarDivisor,
		this->z / scalarDivisor);
}

SpaceVector SpaceVector::operator+(const SpaceVector& vectorAddend)
{
	return SpaceVector(
		this->x + vectorAddend.x,
		this->y + vectorAddend.y,
		this->z + vectorAddend.z);
}

SpaceVector SpaceVector::operator-(const SpaceVector& vectorSubtrahend)
{
	return SpaceVector(
		this->x - vectorSubtrahend.x,
		this->y - vectorSubtrahend.y,
		this->z - vectorSubtrahend.z);
}

SpaceVector SpaceVector::operator/(const SpaceVector& vectorDivisor)
{
	return SpaceVector(
		this->x - vectorDivisor.x,
		this->y - vectorDivisor.y,
		this->z - vectorDivisor.z);
}

double SpaceVector::getModulus() const
{
	return sqrt(
		SQR(this->x)
		+ SQR(this->y)
		+ SQR(this->z));
}

double SpaceVector::getSquareModulus() const
{
	return SQR(this->x)
		+ SQR(this->y)
		+ SQR(this->z);
}

SpaceVector SpaceVector::getUnitVector() const
{
	int modulus = this->getModulus();
	return SpaceVector(
		this->x / modulus,
		this->y / modulus,
		this->z / modulus);
}

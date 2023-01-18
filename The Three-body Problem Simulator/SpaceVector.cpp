#include "SpaceVector.h"
#include "Space.h"
#include "Global.h"
SpaceVector::SpaceVector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

SpaceVector::SpaceVector(double X, double Y, double Z)
{
    this->x = X;
    this->y = Y;
    this->z = Z;
}

void SpaceVector::setSpaceVector(Space other)
{
    this->x = other.getX();
    this->y = other.getY();
    this->z = other.getZ();
}

void SpaceVector::setSpaceVector(SpaceVector S, double K)
{
    this->x = S.getDirection().getX();
    this->y = S.getDirection().getY();
    this->z = S.getDirection().getZ();
}

SpaceVector& SpaceVector::operator=(const Space& other)
{
    this->x = other.getX();
    this->y = other.getY();
    this->z = other.getZ();
    return *this;
}

SpaceVector SpaceVector::operator/(const double K)
{
    double X = this->x / K;
    double Y = this->y / K;
    double Z = this->z / K;
    return SpaceVector(X, Y, Z);
}

SpaceVector SpaceVector::operator*(const double K)
{
    double X = this->x * K;
    double Y = this->y * K;
    double Z = this->z * K;
    return SpaceVector(X, Y, Z);
}

SpaceVector SpaceVector::operator+(const SpaceVector& other)
{
    double X = this->x + other.x;
    double Y = this->y + other.y;
    double Z = this->z + other.z;
    return SpaceVector(X, Y, Z);
}

SpaceVector SpaceVector::operator/(const SpaceVector& other)
{
    double X = this->x / other.x;
    double Y = this->y / other.y;
    double Z = this->z / other.z;
    return SpaceVector(X, Y, Z);
}

double SpaceVector::getModulus()
{
    double X = SQR(this->x);
    double Y = SQR(this->y);
    double Z = SQR(this->z);
    return sqrt(X + Y + Z);
}

Space SpaceVector::getDirection()
{
    double Modulus = this->getModulus();
    double X = this->x / this->getModulus();
    double Y = this->y / this->getModulus();
    double Z = this->z / this->getModulus();
    return Space(X, Y, Z);
}

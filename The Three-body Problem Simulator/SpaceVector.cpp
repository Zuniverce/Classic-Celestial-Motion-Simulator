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

void SpaceVector::setSpaceVector(const SpaceVector D, double K)
{
    SpaceVector direction;
    direction.setSpaceVector(D.getDirection());
    this->x = K * direction.getX();
    this->y = K * direction.getY();
    this->z = K * direction.getZ();
}

SpaceVector& SpaceVector::operator=(const Space& other)
{
    this->x = other.getX();
    this->y = other.getY();
    this->z = other.getZ();
    return *this;
}

SpaceVector& SpaceVector::operator=(const SpaceVector& other)
{
    this->x = other.getX();
    this->y = other.getY();
    this->z = other.getZ();
    return *this;
}

SpaceVector::SpaceVector(const SpaceVector& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
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

double SpaceVector::getModulus()const
{
    double X = SQR(this->x);
    double Y = SQR(this->y);
    double Z = SQR(this->z);
    return sqrt(X + Y + Z);
}

double SpaceVector::getSquareModulus()const
{
    double X = SQR(this->x);
    double Y = SQR(this->y);
    double Z = SQR(this->z);
    return X + Y + Z;
}

Space SpaceVector::getDirection()const
{
    double Modulus = this->getModulus();
    double X = this->x / Modulus;
    double Y = this->y / Modulus;
    double Z = this->z / Modulus;
    return Space(X, Y, Z);
}

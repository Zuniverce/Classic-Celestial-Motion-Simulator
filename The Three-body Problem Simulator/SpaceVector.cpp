#include "SpaceVector.h"
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

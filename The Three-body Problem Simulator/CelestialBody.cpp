#include "Global.h"
#include "CelestialBody.h"


int CelestialBody::quantity = 0;

//构造函数
CelestialBody::CelestialBody()
{
	this->coordinate = Space();
	this->velocity = SpaceVector();
	quantity++;
}

CelestialBody::CelestialBody(double M, Space C, SpaceVector V)
{
	this->mass = M;
	this->coordinate = C;
	this->velocity = V;
}

// 析构函数
CelestialBody::~CelestialBody()
{
	quantity--;
}

void CelestialBody::set(double M, Space C, SpaceVector V)
{
	this->mass = M;
	this->coordinate = C;
	this->velocity = V;
}

//getPrivate
double CelestialBody::getMass() { return this->mass; }

Space CelestialBody::getCoordinate() { return Space(this->coordinate); }

SpaceVector CelestialBody::getForce() { return SpaceVector(this->force); }

SpaceVector CelestialBody::getAcceleration() { return SpaceVector(this->acceleration); }

SpaceVector CelestialBody::getVelocity() { return SpaceVector(this->velocity); }


//setting
void CelestialBody::setCoordinate(Space C) { this->coordinate = C; }

void CelestialBody::setForce(SpaceVector F) { this->force = F; }

void CelestialBody::setAcceleration(SpaceVector A) { this->acceleration = A; }

void CelestialBody::setVelocity(SpaceVector V) { this->velocity = V; }

void CelestialBody::setMass(double M)
{
	this->mass = M;
}

//other
double CelestialBody::getKineticEnergy()
{
	double KE = 0.5 * this->mass * SQR(this->velocity.getModulus());
	return KE;
}

SpaceVector CelestialBody::getMomentum()
{
	double X = this->mass * this->velocity.getX();
	double Y = this->mass * this->velocity.getY();
	double Z = this->mass * this->velocity.getZ();
	return SpaceVector(X, Y, Z);
}

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
double CelestialBody::getMass()const { return this->mass; }

Space CelestialBody::getCoordinate()const { return Space(this->coordinate); }

SpaceVector CelestialBody::getForce()const { return SpaceVector(this->force); }

SpaceVector CelestialBody::getAcceleration()const { return SpaceVector(this->acceleration); }

SpaceVector CelestialBody::getVelocity()const { return SpaceVector(this->velocity); }

CelestialBody CelestialBody::operator+=(const CelestialBody& other)
{
	// 将位置改为两星重心
	double cX = (other.coordinate.getX() - this->coordinate.getX()) 
		* (other.mass / (this->mass + other.mass));
	double cY = (other.coordinate.getY() - this->coordinate.getY())
		* (other.mass / (this->mass + other.mass));
	double cZ = (other.coordinate.getZ() - this->coordinate.getZ())
		* (other.mass / (this->mass + other.mass));
	this->coordinate = Space(cX, cY, cZ);

	// 由动量球速度
	SpaceVector M = this->getMomentum() + other.getMomentum();
	this->velocity = M / (this->mass + other.mass);

	// 最后在合并质量, 因为动量要用原质量
	this->mass += other.mass;
	return *this;
}

//setting

void CelestialBody::setMass(double M) { this->mass = M; }

void CelestialBody::setCoordinate(Space C) { this->coordinate = C; }

void CelestialBody::setForce(SpaceVector F) { this->force = F; }

void CelestialBody::setAcceleration(SpaceVector A) { this->acceleration = A; }

void CelestialBody::setVelocity(SpaceVector V) { this->velocity = V; }

SpaceVector CelestialBody::getMomentum()const
{
	double X = this->mass * this->velocity.getX();
	double Y = this->mass * this->velocity.getY();
	double Z = this->mass * this->velocity.getZ();
	return SpaceVector(X, Y, Z);
}

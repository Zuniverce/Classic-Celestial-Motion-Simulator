#include "Global.h"
#include "CelestialBody.h"


int CelestialBody::quantity = ZERO;

//构造函数
CelestialBody::CelestialBody(void) {
	this->mass = ZERO;
	this->position = SpaceVector();
	this->velocity = SpaceVector();
	quantity++;
}
CelestialBody::CelestialBody(double M, SpaceVector& P, SpaceVector& V) {
	this->mass = M;
	this->position = P;
	this->velocity = V;
	quantity++;
}
// 析构函数
CelestialBody::~CelestialBody(void) {
	quantity--;
}

//settintgs
void CelestialBody::setMass(const double M) { this->mass = M; }
void CelestialBody::setPosition(const SpaceVector& P) { this->position = P; }
void CelestialBody::setForce(const SpaceVector& F) { this->force = F; }
void CelestialBody::setAcceleration(const SpaceVector& A) { this->acceleration = A; }
void CelestialBody::setVelocity(const SpaceVector& V) { this->velocity = V; }
void CelestialBody::setDisplacement(const SpaceVector& D) { this->velocity = D; }
void CelestialBody::set(const double M, const SpaceVector& P, const SpaceVector& V) {
	this->mass = M;
	this->position = P;
	this->velocity = V;
}

//gettings
double CelestialBody::getMass()const { return this->mass; }
SpaceVector CelestialBody::getPosition()const { return SpaceVector(this->position); }
SpaceVector CelestialBody::getForce()const { return SpaceVector(this->force); }
SpaceVector CelestialBody::getAcceleration()const { return SpaceVector(this->acceleration); }
SpaceVector CelestialBody::getVelocity()const { return SpaceVector(this->velocity); }
SpaceVector CelestialBody::getDisplacement()const { return SpaceVector(this->displacement); }
SpaceVector CelestialBody::getMomentum()const {
	return this->velocity * this->mass;
}

CelestialBody CelestialBody::operator+=(const CelestialBody& other) {
	// 将位置改为两星重心
	this->position = (other.position - this->position)
		* (other.mass / (this->mass + other.mass));
	// 由动量球速度
	this->velocity = (this->getMomentum() + other.getMomentum())
		/ (this->mass + other.mass);
	// 最后再合并质量, 因为动量要用原质量
	this->mass += other.mass;
	return *this;
}

#include "CelestialBody.h"
//构造函数
CelestialBody::CelestialBody(void) {
	this->mass = ZERO;
	this->position = MultidimensionalVector();
	this->velocity = MultidimensionalVector();
	quantity++;
}
CelestialBody::CelestialBody(const CelestialBody& other) {
	this->mass = other.mass;
	this->position = other.position;
	this->velocity = other.velocity;
	quantity++;
}
CelestialBody::CelestialBody(const double M, const MultidimensionalVector& P, const MultidimensionalVector& V) {
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
void CelestialBody::setPosition(const MultidimensionalVector& P) { this->position = P; }
void CelestialBody::setForce(const MultidimensionalVector& F) { this->force = F; }
void CelestialBody::setAcceleration(const MultidimensionalVector& A) { this->acceleration = A; }
void CelestialBody::setVelocity(const MultidimensionalVector& V) { this->velocity = V; }
void CelestialBody::setDisplacement(const MultidimensionalVector& D) { this->velocity = D; }
void CelestialBody::set(const double M, const MultidimensionalVector& P, const MultidimensionalVector& V) {
	this->mass = M;
	this->position = P;
	this->velocity = V;
}
//gettings
double CelestialBody::getMass()const { return this->mass; }
MultidimensionalVector CelestialBody::getPosition()const { return MultidimensionalVector(this->position); }
MultidimensionalVector CelestialBody::getForce()const { return MultidimensionalVector(this->force); }
MultidimensionalVector CelestialBody::getAcceleration()const { return MultidimensionalVector(this->acceleration); }
MultidimensionalVector CelestialBody::getVelocity()const { return MultidimensionalVector(this->velocity); }
MultidimensionalVector CelestialBody::getMomentum()const {
	return this->velocity * this->mass;
}
CelestialBody& CelestialBody::operator+=(const CelestialBody& other) {
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
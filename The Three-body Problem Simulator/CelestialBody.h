#pragma once
#include "Space.h"
#include "SpaceVector.h"

class CelestialBody // 天体类
{
private:
	double mass; // 质量
	Space coordinate; // 坐标
	SpaceVector force; // 受力
	SpaceVector acceleration; // 加速度
	SpaceVector velocity; //速度

public:
	static int quantity;

	CelestialBody();
	CelestialBody(double, Space, SpaceVector);
	~CelestialBody();

	CelestialBody operator+=(const CelestialBody&);

	void set(double, Space, SpaceVector); // 坐标, 速度

	double getMass()const; // 质量
	Space getCoordinate()const; // 坐标
	SpaceVector getForce()const; // 受力
	SpaceVector getAcceleration()const; // 加速度
	SpaceVector getVelocity()const; //速度

	void setMass(double); // 质量
	void setCoordinate(Space); // 坐标
	void setForce(SpaceVector); // 受力
	void setAcceleration(SpaceVector); // 加速度
	void setVelocity(SpaceVector); //速度

	SpaceVector getMomentum()const; // 动量
};


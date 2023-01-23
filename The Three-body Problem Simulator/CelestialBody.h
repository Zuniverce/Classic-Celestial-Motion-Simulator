#pragma once
#include "SpaceVector.h"

class CelestialBody // 天体类
{
private:
	double mass; // 质量
	SpaceVector position; // 坐标
	SpaceVector force; // 受力
	SpaceVector acceleration; // 加速度
	SpaceVector velocity; //速度
	SpaceVector displacement; // 位移
public:
	static int quantity;

	// 构造函数
	CelestialBody(void); // 空构造函数
	CelestialBody(const CelestialBody& other); // 拷贝构造函数
	CelestialBody(const double M, const SpaceVector& P, const SpaceVector& V); // 初始化构造函数
	~CelestialBody(void); // 构造函数

	// 运算符重载
	CelestialBody operator+=(const CelestialBody& other);

	double getMass(void)const; // 质量
	SpaceVector getPosition(void)const; // 坐标
	SpaceVector getForce(void)const; // 受力
	SpaceVector getAcceleration(void)const; // 加速度
	SpaceVector getVelocity(void)const; //速度

	SpaceVector getDisplacement(void)const; // 位移
	SpaceVector getMomentum(void)const; // 动量

	void setMass(const double M); // 质量
	void setPosition(const SpaceVector& P); // 坐标
	void setForce(const SpaceVector& F); // 受力
	void setAcceleration(const SpaceVector& A); // 加速度
	void setVelocity(const SpaceVector& V); // 速度
	void setDisplacement(const SpaceVector& D); // 位移
	void set(const double M, const SpaceVector& P, const SpaceVector& V);
};


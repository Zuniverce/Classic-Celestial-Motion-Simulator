#pragma once
#include "MultidimensionalVector.h"

class CelestialBody // 天体类
{
private:
	double mass; // 质量
	MultidimensionalVector position; // 坐标
	MultidimensionalVector force; // 受力
	MultidimensionalVector acceleration; // 加速度
	MultidimensionalVector velocity; //速度
	MultidimensionalVector displacement; // 位移
public:
	static int quantity;

	// 构造函数
	CelestialBody(void); // 空构造函数
	CelestialBody(const CelestialBody& other); // 拷贝构造函数
	CelestialBody(const double M, const MultidimensionalVector& P, const MultidimensionalVector& V); // 初始化构造函数
	~CelestialBody(void); // 构造函数

	CelestialBody operator+=(const CelestialBody& other); // 运算符重载

	double getMass(void)const; // 质量
	MultidimensionalVector getPosition(void)const; // 坐标
	MultidimensionalVector getForce(void)const; // 受力
	MultidimensionalVector getAcceleration(void)const; // 加速度
	MultidimensionalVector getVelocity(void)const; //速度

	MultidimensionalVector getDisplacement(void)const; // 位移
	MultidimensionalVector getMomentum(void)const; // 动量

	void setMass(const double M); // 质量
	void setPosition(const MultidimensionalVector& P); // 坐标
	void setForce(const MultidimensionalVector& F); // 受力
	void setAcceleration(const MultidimensionalVector& A); // 加速度
	void setVelocity(const MultidimensionalVector& V); // 速度
	void setDisplacement(const MultidimensionalVector& D); // 位移
	void set(const double M, const MultidimensionalVector& P, const MultidimensionalVector& V);
};

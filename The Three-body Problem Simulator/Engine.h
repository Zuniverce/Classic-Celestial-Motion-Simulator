﻿#pragma once
#include "Global.h"
#include "CelestialBody.h"
#include "MultidimensionalVector.h"

class Engine
{
private:
	vector<CelestialBody>star;
public:
	static inline const double GravitationalConstant = 6.674e-11; // 引力常量
	static inline const double CrashJudgingSquareDistance = 1e-2; // 碰撞界限的平方
	Engine(); // 构造函数
	int run(const double& TimeLimit); // 运行模块

	void check(const int situation);
};


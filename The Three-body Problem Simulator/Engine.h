#pragma once
#include "Global.h"
#include "CelestialBody.h"
#include "Space.h"
#include "SpaceVector.h"

class Engine
{
private:
	vector<CelestialBody> star;
public:
	// 引力常量
	const static double GravitationalConstant;

	// 输入
	void initialize();

	// 运行模块
	int run(int TimeLimit);

};


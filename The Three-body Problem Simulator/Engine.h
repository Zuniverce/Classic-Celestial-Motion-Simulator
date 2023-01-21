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
	static const double GravitationalConstant;

	static const double CrashJudgingDistance;

	// 构造函数
	Engine();

	// 运行模块
	int run(double TimeLimit);

};


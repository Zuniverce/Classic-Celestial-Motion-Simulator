#pragma once
#include "Global.h"
#include "CelestialBody.h"
#include "MultidimensionalVector.h"
class Engine
{
private:
	vector<CelestialBody>star;
	static inline double GravitationalConstant = 6.674e-11; // 引力常量
	static inline const double CrashJudgingSquareDistance = 1e-2; // 碰撞界限的平方
public:
	explicit Engine(); // 构造函数
	int run(); // 运行模块
	bool collisionDetection();
	void writeFile(); // 写入文件
	void GravitationalFieldCalculate(const int& depth);
	//gravitational
};
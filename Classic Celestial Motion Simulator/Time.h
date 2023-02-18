﻿#pragma once
#include "Global.h"
class Time
{
public:
	const static inline double DT = ONE; // 迭代间隔
	// 单位换算
	const static inline double DAYTOHOUR = 12;
	const static inline double HOURTOMINUTE = 60;
	const static inline double MINUTETOSECOND = 60;
	static double minute(double M = ONE);
	static double hour(double H = ONE);
	static double day(double D = ONE);
	// 控制
	static inline double showInterval = DT; // 输出间隔
	static inline double totalTime = ZERO; // 总时间
	Time();
};
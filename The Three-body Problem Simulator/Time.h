#pragma once
#include "Global.h"
class Time
{
public:
	const static inline double DT = 1; // 迭代间隔

	const static inline double DAYTOHOUR = 12;
	const static inline double HOURTOMINUTE = 60;
	const static inline double MINUTETOSECOND = 60;

	static double minute(double M = 1);
	static double hour(double H = 1);
	static double day(double D = 1);

	static inline double showInterval = DT; // 输出间隔
	static void setShowInterval();
};

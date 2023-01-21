#pragma once
class Time
{
public:
	const static double DT;

	const static int DAYTOHOUR;
	const static int HOURTOMINUTE;
	const static int MINUTETOSECOND;

	static int minute(int M = 1);
	static int hour(int H = 1);
	static int day(int D = 1);
};


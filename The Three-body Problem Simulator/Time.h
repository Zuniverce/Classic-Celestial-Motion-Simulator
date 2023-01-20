#pragma once
class Time
{
public:
	const static double DT;

	const static int DAYTOHOUR;
	const static int HOURTOMINUTE;
	const static int MINUTETOSECOND;

	static int minute(int);
	static int hour(int);
	static int day(int);
};


// The Three-body Problem Simulator.cpp

#include "Global.h"
#include "CelestialBody.h"
#include "Engine.h"
#include "Time.h"

//string FILENAME = "The Three-body Problem Simulator";

int main()
{
	Engine instance;
	instance.run(Time::day(1 * 365));
	system("pause");

	return 0;
}

// The Three-body Problem Simulator.cpp

#include "Global.h"
#include "CelestialBody.h"
#include "Engine.h"
#include "Time.h"


int main()
{
	Engine instance;
	instance.check(instance.run(Time::day(1 * 365)));
	system("pause");

	return 0;
}

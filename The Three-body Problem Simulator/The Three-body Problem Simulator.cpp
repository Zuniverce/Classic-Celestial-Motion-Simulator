// The Three-body Problem Simulator.cpp

#include "Global.h"
#include "CelestialBody.h"
#include "Engine.h"
#include "Time.h"

int main()
{
	Engine instance;
	instance.Run(1 * 60);
	return 0;
}

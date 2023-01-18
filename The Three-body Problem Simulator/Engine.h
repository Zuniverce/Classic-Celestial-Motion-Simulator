#pragma once
#include "Global.h"
#include "CelestialBody.h"
#include "Space.h"
#include "SpaceVector.h"

class Engine
{
private:
	CelestialBody star[QUANTITY];
public:
	int Run(int);
};


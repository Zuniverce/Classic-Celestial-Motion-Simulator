// The Three-body Problem Simulator.cpp

#include "Global.h"
#include "CelestialBody.h"
#include "Engine.h"
#include "Time.h"
#include "MultidimensionalVector.h"
#include "FileOperator.h"
int main()
{
	Time timeInstance;
	MultidimensionalVector::setDimension();
	Engine engineInstance;
	engineInstance.run();
	system("pause");
	return 0;
}
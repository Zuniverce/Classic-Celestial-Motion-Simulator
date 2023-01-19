#pragma once
#include "Global.h"
#include "CelestialBody.h"
#include "Space.h"
#include "SpaceVector.h"

class Engine
{
private:
	vector<CelestialBody> star;
public:
	// ��������
	const static double GravitationalConstant;

	// ����ģ��
	int Run(int TimeLimit);

};


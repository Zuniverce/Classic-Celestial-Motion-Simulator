#pragma once
#include "Space.h"
#include "SpaceVector.h"

class CelestialBody // ������
{
private:
	double mass; // ����
	Space coordinate; // ����
	SpaceVector force; // ����
	SpaceVector acceleration; // ���ٶ�
	SpaceVector velocity; //�ٶ�

public:
	CelestialBody();
	CelestialBody(Space, SpaceVector); // ����, �ٶ�

	double getMass(); // ����
	Space getCoordinate(); // ����
	SpaceVector getForce(); // ����
	SpaceVector getAcceleration(); // ���ٶ�
	SpaceVector getVelocity(); //�ٶ�

	void setCoordinate(Space); // ����
	void setForce(SpaceVector); // ����
	void setAcceleration(SpaceVector); // ���ٶ�
	void setVelocity(SpaceVector); //�ٶ�

	double getKineticEnergy(); // ����
	SpaceVector getMomentum(); // ����
};

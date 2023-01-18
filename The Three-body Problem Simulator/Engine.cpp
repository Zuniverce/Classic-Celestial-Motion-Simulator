#include "Engine.h"
#include "Global.h"
#include "Time.h"
#include "CelestialBody.h"
#include "Space.h"
#include "SpaceVector.h"
void Engine::Run(int TimeLimit)
{
	for (int presentTime = 0; presentTime < TimeLimit; presentTime += DT)
	{
		for (int i = 0; i < QUANTITY; i++)
		{
			SpaceVector R[QUANTITY - 1];
			SpaceVector F[QUANTITY - 1];
			SpaceVector resultantForce;
			for (int j = 0; j < QUANTITY - 2; j++)
			{
				R[j].setSpaceVector(this->star[(i + j + 1) % QUANTITY].getCoordinate()
					- this->star[i].getCoordinate());
				F[j].setSpaceVector(R[j], GravitationalConstant
					* (star[i].getMass() * star[(i + j + 1) % QUANTITY].getMass()
						/ SQR(R[j].getModulus())));
				resultantForce += F[j];
			}
			star[i].setForce(resultantForce);
			star[i].setAcceleration(star[i].getForce() / star[i].getMass());
			star[i].setVelocity(star[i].getVelocity() + star[i].getAcceleration() * DT);
			star[i].setCoordinate(star[i].getCoordinate() + star[i].getVelocity() * DT);
		}
	}
}

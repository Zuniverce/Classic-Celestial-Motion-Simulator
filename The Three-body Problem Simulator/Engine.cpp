#include "Engine.h"
#include "Global.h"
#include "Time.h"
#include "CelestialBody.h"
#include "Space.h"
#include "SpaceVector.h"

const double Engine::GravitationalConstant = 6.674e-11;

const double Engine::CrashJudgingSquareDistance = 1e-2;

Engine::Engine()
{
	int quantity = 0;
	while (quantity == 0) {
		cout << "天体个数: " << endl;
		cin >> quantity;
	}

	for (int i = 0; i < quantity; i++) {
		cout << endl << "设置天体 No." << i << endl;
		CelestialBody initializer;

		cout << "质量; " << endl;
		double mass;
		cin >> mass;
		initializer.setMass(mass);

		cout << "坐标 x y z : " << endl;
		double coordinateX, coordinateY, coordinateZ;
		cin >> coordinateX >> coordinateY >> coordinateZ;
		initializer.setCoordinate(Space(coordinateX, coordinateY, coordinateZ));
		for (int j = 0; j < i; j++) {
			if (Space::getSquareDistance(initializer.getCoordinate(), star[j].getCoordinate())
				<= Engine::CrashJudgingSquareDistance) {
				cout << "天体的初始位置不能相同." << endl;
				// "The initial position of the celestial body cannot be the same."
				i--;
				continue;
			}
		}

		cout << "速度 x y z : " << endl;
		double velocityX, velocityY, velocityZ;
		cin >> velocityX >> velocityY >> velocityZ;
		initializer.setVelocity(SpaceVector(velocityX, velocityY, velocityZ));

		star.push_back(initializer);
       	}
}

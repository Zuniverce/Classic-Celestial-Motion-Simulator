#include "Engine.h"
#include "Time.h"

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
		initializer.setPosition(SpaceVector(coordinateX, coordinateY, coordinateZ));
		for (int j = 0; j < i; j++) {
			if (SpaceVector::getSquareModulus(initializer.getPosition(), star[j].getPosition())
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
		initializer.setVelocity(velocityX, velocityY, velocityZ);

		star.push_back(initializer);
       	}
}

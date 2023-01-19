#include "Engine.h"
#include "Global.h"
#include "Time.h"
#include "CelestialBody.h"
#include "Space.h"
#include "SpaceVector.h"

const double Engine::GravitationalConstant = 6.67259e-11;


void Engine::initialize()
{
	int quantity = 0;
	while (quantity == 0) {
	cout << "天体个数: " << endl;
	cin >> quantity;
	}
	for (int i = 0; i < quantity; i++) {
		cout << endl << "设置天体 No." << i << endl;
		star.push_back(CelestialBody());

		cout << "质量; " << endl;
		double mass;
		cin >> mass;
		star[i].setMass(mass);

		cout << "坐标(x, y, z): " << endl;
		double coordinateX, coordinateY, coordinateZ;
		cin >> coordinateX >> coordinateY >> coordinateZ;
		star[i].setCoordinate(Space(coordinateX, coordinateY, coordinateZ));
		for (int j = 0; j < i; j++) {
			if (Space::getDistance(star[i].getCoordinate(), star[j].getCoordinate())) {
				cout << "天体的初始位置不能相同." << endl;
				i--;
				continue;
			}
		}


		cout << "速度(x, y, z): " << endl;
		double velocityX, velocityY, velocityZ;
		cin >> velocityX >> velocityY >> velocityZ;
		star[i].setVelocity(SpaceVector(velocityX, velocityY, velocityZ));		
	}
}

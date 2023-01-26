#include "Engine.h"
#include "Time.h"
void Engine::setGravitationalConstant() {
	cin >> GravitationalConstant;
}
Engine::Engine()
{
	int quantity = ZERO;
	while (quantity == ZERO) {
		cout << "天体个数:" << endl;
		cin >> quantity;
	}
	for (int i = ZERO; i < quantity; i++) {
	again:
		cout << endl << "设置天体 No." << i << endl;
		CelestialBody initializer;
		cout << "质量 (kg):" << endl;
		double mass;
		cin >> mass;
		initializer.setMass(mass);
		cout << "坐标 (m)(以空格分隔):" << endl;
		vector<double>coordinate(MultidimensionalVector::dimension);
		for (int i = ZERO; i < MultidimensionalVector::dimension; i++) {
			cin >> coordinate[i];
		}
		initializer.setPosition(MultidimensionalVector(coordinate));
		for (int j = ZERO; j < i; j++) {
			if (MultidimensionalVector::getSquareModulus(initializer.getPosition(), star[j].getPosition())
				<= Engine::CrashJudgingSquareDistance) {
				cout << "天体的初始位置不能相同." << endl;
				// "The initial position of the celestial body cannot be the same."
				i--;
				goto again;
			}
		}
		cout << "速度 (m/s)(以空格分隔):" << endl;
		vector<double>velocity(MultidimensionalVector::dimension);
		for (int i = ZERO; i < MultidimensionalVector::dimension; i++) {
			cin >> velocity[i];
		}
		initializer.setVelocity(MultidimensionalVector(velocity));
		star.push_back(initializer);
	}
}
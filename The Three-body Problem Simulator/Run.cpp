#include "Engine.h"
#include "Global.h"
#include "Time.h"
// 运行模块
int Engine::run(double TimeLimit)
{
	/*for (int i = 0; i < CelestialBody::quantity; i++) {
		star[i].getCoordinate().print();
	}*/

	int timePercentCounter = 0;

	for (int presentTime = 0; presentTime < TimeLimit; presentTime += Time::DT)
	{
		for (int i = 0; i < CelestialBody::quantity; i++)
		{
			SpaceVector R; // 到star[j]的距离
			SpaceVector F; // 由star[j]提供的力
			SpaceVector resultantForce; // 合力

			for (int j = i + 1; j % CelestialBody::quantity != i; j++) // 循环下标防止溢出；
			{
				R.setSpaceVector(star[j % CelestialBody::quantity].getCoordinate()
					- star[i].getCoordinate());
				F.setSpaceVector(R, GravitationalConstant
					* (star[i].getMass() * star[j % CelestialBody::quantity].getMass()
						/ SQR(R.getModulus())));
				resultantForce += F; // 合力与当前受力合成

				/*cout << "天体" << i << "到" << j << "距: " << R.getModulus() << endl;
				cout << "天体" << j << "对" << i << "力: " << F.getModulus() << endl;*/
			}
			star[i].setForce(resultantForce);
			star[i].setAcceleration(star[i].getForce() / star[i].getMass());
			star[i].setVelocity(star[i].getVelocity() + star[i].getAcceleration() * Time::DT);
			star[i].setCoordinate(star[i].getCoordinate() + star[i].getVelocity() * Time::DT);

			// Debug
			/*cout << "天体" << i << endl;
			cout << star[i].getForce().getModulus() << endl;
			cout << star[i].getAcceleration().getModulus() << endl;
			cout << star[i].getVelocity().getModulus() << endl;
			star[i].getCoordinate().print();*/
		}

		// 碰撞检测
		for (int i = 0; i < CelestialBody::quantity; i++) {
			for (int j = i + 1; j < CelestialBody::quantity; j++) {
				if (Space::getDistance(star[i].getCoordinate(), star[j].getCoordinate())
					<= Engine::CrashJudgingDistance) {
					star[i] += star[j];
					star.erase(star.begin() + j);
					return 1;
				}
			}
		}

		if (presentTime >= timePercentCounter * TimeLimit / ONEHUNDRED) {
			cout << timePercentCounter << "%" << endl;
			timePercentCounter++;
		}
		// cout << ".";
	}

	cout << Space::getDistance(Space(), star[1].getCoordinate()) << endl;
	return 0;
}


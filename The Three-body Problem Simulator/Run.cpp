#include "Engine.h"
#include "Global.h"
#include "Time.h"
int Engine::run(const double& TimeLimit)
{

	int timePercentCounter = ZERO;
	for (double presentTime = ZERO; presentTime < TimeLimit; presentTime += Time::DT)
	{
		for (int i = ZERO; i < CelestialBody::quantity; i++)
		{
			MultidimensionalVector R; // 到star[j]的距离
			MultidimensionalVector F; // 由star[j]提供的力
			MultidimensionalVector resultantForce; // 合力
			for (int j = i + ONE; j % CelestialBody::quantity != i; j++) // 循环下标防止溢出；
			{
				R = star[j % CelestialBody::quantity].getPosition()
					- star[i].getPosition();
				F.setSpaceVector(R, GravitationalConstant
					* (star[i].getMass() * star[j % CelestialBody::quantity].getMass()
						/ R.getSquareModulus()));
				resultantForce += F; // 合力与当前受力合成
			}
			star[i].setForce(resultantForce);
			star[i].setAcceleration(star[i].getForce() / star[i].getMass());
			star[i].setVelocity(star[i].getVelocity() + star[i].getAcceleration() * Time::DT);
			star[i].setPosition(star[i].getPosition() + star[i].getVelocity() * Time::DT);
		}
		// 碰撞检测
		for (int i = ZERO; i < CelestialBody::quantity; i++) {
			for (int j = i + ONE; j < CelestialBody::quantity; j++) {
				if (MultidimensionalVector::getSquareModulus(star[i].getPosition(), star[j].getPosition())
					<= Engine::CrashJudgingSquareDistance) {
					cout << "天体" << i << "天体" << j << "合并." << endl;
					star[i] += star[j];
					star.erase(star.begin() + j);
					j--;
				}
			}
		}
		if (int(presentTime) % int(Time::showInterval) <= ONE) {
			star[ZERO].getPosition().print();
			for (int i = ONE; i < CelestialBody::quantity; i++) {
				fout << ", ";
				star[i].getPosition().print();
			}
			fout << endl;
		}
		if (presentTime >= timePercentCounter * TimeLimit / ONEHUNDRED) {
			int tens = timePercentCounter / 10;
			int ones = timePercentCounter - tens * 10;
			cout << "\b\b\b" << tens << ones << "%";
			timePercentCounter++;
		}
	}
	cout << "\b\b\b" << "done." << endl;
	return ZERO;
}
#include "Engine.h"
#include "Time.h"
int Engine::run()
{
	int timePercentCounter = ZERO;
	MultidimensionalVector R; // 到star[j]的距离
	MultidimensionalVector F; // 由star[j]提供的力
	for (double presentTime = ZERO; presentTime < Time::totalTime; presentTime += Time::DT)
	{
		for (int i = ZERO; i < CelestialBody::quantity; i++)
		{
			MultidimensionalVector resultantForce; // 合力
			for (int j = i + ONE; j % CelestialBody::quantity != i; j++) // 循环下标防止溢出
			{
				R = star[j % CelestialBody::quantity].getPosition()
					- star[i].getPosition();
				F.setSpaceVector(R, GravitationalConstant
					* (star[i].getMass() * star[j % CelestialBody::quantity].getMass()
						/ R.getInvolutionalModulus(MultidimensionalVector::dimension - ONE)));
				resultantForce += F; // 合力与当前受力合成
			}
			star[i].setForce(resultantForce);
			star[i].setAcceleration(star[i].getForce() / star[i].getMass());
			star[i].setVelocity(star[i].getVelocity() + star[i].getAcceleration() * Time::DT);
			star[i].setPosition(star[i].getPosition() + star[i].getVelocity() * Time::DT);
		}
		collisionDetection(); // 碰撞检测
		if (int(presentTime) % int(Time::showInterval) <= ONE)
		{
			writeFile();
		}
		// 显示进度
		if (presentTime >= timePercentCounter * Time::totalTime / ONEHUNDRED)
		{
			int tens = timePercentCounter / 10;
			int ones = timePercentCounter - tens * 10;
			cout << "\b\b\b" << tens << ones << "%";
			timePercentCounter++;
		}
	}
	cout << "\b\b\b" << "done." << endl;
	return ZERO;
}
bool Engine::collisionDetection() // 碰撞检测
{
	bool flag = false;
	for (int i = ZERO; i < CelestialBody::quantity; i++)
	{
		for (int j = i + ONE; j < CelestialBody::quantity; j++)
		{
			if (MultidimensionalVector::getSquareModulus(star[i].getPosition(), star[j].getPosition())
				<= Engine::CrashJudgingSquareDistance)
			{
				cout << "天体" << i << "天体" << j << "合并." << endl;
				star[i] += star[j];
				star.erase(star.begin() + j);
				j--;
				flag = true;
			}
		}
	}
	return false;
}
void Engine::writeFile() // 写入文件
{
	star[ZERO].getPosition().print();
	for (int i = ONE; i < CelestialBody::quantity; i++)
	{
		fout << ", ";
		star[i].getPosition().print();
	}
	fout << endl;
}
void Engine::GravitationalFieldCalculate(const int& depth)
{
	int lim = 0;//随便写的用来过语法
	if (depth != ZERO)
	{
		for (int i = ZERO; i < lim; i++)
		{
			GravitationalFieldCalculate(depth - ONE);
		}
	}
	else
	{

	}

}
Engine::Engine()
{
	while (MultidimensionalVector::dimension <= ZERO)
	{
		cout << "维度: " << endl;
		cin >> MultidimensionalVector::dimension;
	}
	if (MultidimensionalVector::dimension != THREE)
	{
		cout << "引力常量: " << endl;
		cin >> GravitationalConstant;
	}
	int quantity = ZERO;
	while (quantity == ZERO)
	{
		cout << "天体个数:" << endl;
		cin >> quantity;
	}
	for (int i = ZERO; i < quantity; i++)
	{
	again:
		cout << endl << "设置天体 No." << i << endl;
		CelestialBody initializer;
		cout << "质量 (kg):" << endl;
		double mass;
		cin >> mass;
		initializer.setMass(mass);
		cout << "坐标 (m)(以空格分隔):" << endl;
		vector<double>coordinate(MultidimensionalVector::dimension);
		for (int i = ZERO; i < MultidimensionalVector::dimension; i++)
		{
			cin >> coordinate[i];
		}
		initializer.setPosition(MultidimensionalVector(coordinate));
		for (int j = ZERO; j < i; j++)
		{
			if (MultidimensionalVector::getSquareModulus(initializer.getPosition(), star[j].getPosition())
				<= Engine::CrashJudgingSquareDistance)
			{
				cout << "天体的初始位置不能相同." << endl;
				// "The initial position of the celestial body cannot be the same."
				i--;
				goto again;
			}
		}
		cout << "速度 (m/s)(以空格分隔):" << endl;
		vector<double>velocity(MultidimensionalVector::dimension);
		for (int i = ZERO; i < MultidimensionalVector::dimension; i++)
		{
			cin >> velocity[i];
		}
		initializer.setVelocity(MultidimensionalVector(velocity));
		star.push_back(initializer);
	}
}
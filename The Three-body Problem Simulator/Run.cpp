#include "Engine.h"
#include "Global.h"
#include "Time.h"
// 运行模块


int Engine::run(const double& TimeLimit)
{
	ifstream fin("in.txt"); // 输入文件
	ofstream fout("out.txt"); //输出文件
	streambuf* cinbackup = cin.rdbuf(fin.rdbuf()); //用 rdbuf() 重新定向，返回旧缓冲区指针;
	streambuf* coutbackup = cout.rdbuf(fout.rdbuf()); //用 rdbuf() 重新定向，返回旧缓冲区指针


	// Debug
	/*for (int i = ZERO; i < CelestialBody::quantity; i++) {
		star[i].getCoordinate().print();
	}*/

	int timePercentCounter = ZERO;

	for (double presentTime = ZERO; presentTime < TimeLimit; presentTime += Time::DT)
	{
		for (int i = ZERO; i < CelestialBody::quantity; i++)
		{
			MultidimensionalVector R; // 到star[j]的距离
			MultidimensionalVector F; // 由star[j]提供的力
			MultidimensionalVector resultantForce; // 合力

			for (int j = i + 1; j % CelestialBody::quantity != i; j++) // 循环下标防止溢出；
			{
				R = star[j % CelestialBody::quantity].getPosition()
					- star[i].getPosition();
				F.setSpaceVector(R, GravitationalConstant
					* (star[i].getMass() * star[j % CelestialBody::quantity].getMass()
						/ R.getSquareModulus()));
				resultantForce += F; // 合力与当前受力合成

				/*cout << "天体" << i << "到" << j << "距: " << R.getModulus() << endl;
				cout << "天体" << j << "对" << i << "力: " << F.getModulus() << endl;*/
			}
			star[i].setForce(resultantForce);
			star[i].setAcceleration(star[i].getForce() / star[i].getMass());
			star[i].setVelocity(star[i].getVelocity() + star[i].getAcceleration() * Time::DT);
			star[i].setPosition(star[i].getPosition() + star[i].getVelocity() * Time::DT);

			// Debug
			/*cout << "天体" << i << endl;
			cout << star[i].getForce().getModulus() << endl;
			cout << star[i].getAcceleration().getModulus() << endl;
			cout << star[i].getVelocity().getModulus() << endl;
			star[i].getCoordinate().print();*/
		}

		// 碰撞检测
		for (int i = ZERO; i < CelestialBody::quantity; i++) {
			for (int j = i + 1; j < CelestialBody::quantity; j++) {
				if (MultidimensionalVector::getSquareModulus(star[i].getPosition(), star[j].getPosition())
					<= Engine::CrashJudgingSquareDistance) {
					cout << "天体" << i << "天体" << j << "合并." << endl;
					star[i] += star[j];
					star.erase(star.begin() + j);
					j--;
					return 1;
				}
			}
		}

		
		if (presentTime >= timePercentCounter * TimeLimit / ONEHUNDRED) {
			/*int tens = timePercentCounter / 10;
			int ones = timePercentCounter - tens * 10;
			cout << "\b\b\b" << tens << ones << "%";*/
			timePercentCounter++;

			star[1].getPosition().print();
			//cout << "\b\b";
		}
		// cout << ".";
	}

	cout << endl;

	/*for (int i = ZERO; i < CelestialBody::quantity; i++)
	{
		cout << "天体" << i << "的位置: ";
		star[i].getCoordinate().print();
	}*/

	fin.close();//随手关闭
	fout.close();//是好习惯

	return ZERO;
}

void Engine::check(const int situation)
{
}


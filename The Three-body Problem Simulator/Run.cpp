#include "Engine.h"
#include "Global.h"
#include "Time.h"
// 运行模块


int Engine::run(double TimeLimit)
{

	ifstream fin("in.txt"); // 输入文件
	ofstream fout("out.txt"); //输出文件
	streambuf* cinbackup = cin.rdbuf(fin.rdbuf()); //用 rdbuf() 重新定向，返回旧缓冲区指针;
	streambuf* coutbackup = cout.rdbuf(fout.rdbuf()); //用 rdbuf() 重新定向，返回旧缓冲区指针


	// Debug
	/*for (int i = 0; i < CelestialBody::quantity; i++) {
		star[i].getCoordinate().print();
	}*/

	int timePercentCounter = 0;
	cout << "   " << endl;

	for (double presentTime = 0; presentTime < TimeLimit; presentTime += Time::DT)
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
					cout << "天体" << i << "天体" << j << "合并." << endl;
					star[i] += star[j];
					star.erase(star.begin() + j);
					return 1;
				}
			}
		}

		
		if (presentTime >= timePercentCounter * TimeLimit / ONEHUNDRED) {
			/*int tens = timePercentCounter / 10;
			int ones = timePercentCounter - tens * 10;
			cout << "\b\b\b" << tens << ones << "%";*/
			timePercentCounter++;

			star[1].getCoordinate().printToShow();
			//cout << "\b\b";
		}
		// cout << ".";
	}

	cout << endl;

	/*for (int i = 0; i < CelestialBody::quantity; i++)
	{
		cout << "天体" << i << "的位置: ";
		star[i].getCoordinate().print();
	}*/

	fin.close();//随手关闭
	fout.close();//是好习惯

	return 0;
}

void Engine::check(int situation)
{
}


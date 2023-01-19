// The Three-body Problem Simulator.cpp

#include "Global.h"
#include "CelestialBody.h"
#include "Engine.h"
#include "Time.h"
//#pragma warning(disable:4996)

string FILENAME = "The Three-body Problem Simulator";

int main()
{
	/*freopen((FILENAME + ".in").c_str(), "r", stdin);
	freopen((FILENAME + ".out").c_str(), "w", stdout);*/

	Engine instance;
	instance.run(1);
	system("pause");

	//fclose(stdin);//关闭重定向输入
	//fclose(stdout);//关闭重定向输出 
	return 0;
}

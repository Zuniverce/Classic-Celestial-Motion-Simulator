// The Three-body Problem Simulator.cpp

#include "Global.h"
#include "CelestialBody.h"
#include "Engine.h"
#include "Time.h"
#include "MultidimensionalVector.h"
int main()
{
	fin.open("in.txt"); // 输入文件
	fout.open("out.txt"); //输出文件
	//cinbackup = cin.rdbuf(fin.rdbuf()); //用 rdbuf() 重新定向，返回旧缓冲区指针
	//coutbackup = cout.rdbuf(fout.rdbuf()); //用 rdbuf() 重新定向，返回旧缓冲区指针
	MultidimensionalVector::setDimension();
	Time::setShowInterval();
	Engine instance;
	instance.run();
	system("pause");
	fin.close();
	fout.close();
	return 0;
}
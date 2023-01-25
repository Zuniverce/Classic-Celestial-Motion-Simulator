#pragma once

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <vector>
#include <fstream>

using namespace std;

template<typename T>
constexpr auto SQR(T a) { return ((a)*(a)); }

constexpr int ONEHUNDRED = 100;
constexpr int ZERO = 0;
constexpr int ONE = 1;
constexpr int THREE = 3;

extern const string FILENAME;
extern streambuf* cinbackup;
extern streambuf* coutbackup;
extern ifstream fin; // 输入文件
extern ofstream fout; //输出文件
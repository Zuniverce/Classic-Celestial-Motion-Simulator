﻿#pragma once

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

extern const string FILENAME;
extern streambuf* cinbackup;
extern streambuf* coutbackup;

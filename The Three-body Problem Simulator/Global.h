#pragma once

#include <iostream>
#include <math.h>
#include <time.h>
#include <Windows.h>

using namespace std;

template<typename T>
constexpr auto SQR(T a) { return ((a)*(a)); }

constexpr auto GravitationalConstant = 6.67259e-11;

constexpr auto QUANTITY = 3;

constexpr auto DT = 1;

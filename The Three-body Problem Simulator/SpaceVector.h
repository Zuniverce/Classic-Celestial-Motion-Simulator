#pragma once
#include "Space.h"
class SpaceVector : // 空间向量坐标类
    public Space
{
public:
    SpaceVector(); // 默认构造函数
    SpaceVector(double, double, double); // 构造函数

    double getModulus(); // 向量的模
    Space getDirection(); // 单位向量
};


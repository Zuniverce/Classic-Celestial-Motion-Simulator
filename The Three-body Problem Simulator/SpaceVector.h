#pragma once
#include "Space.h"
class SpaceVector : // 空间向量坐标类
    public Space
{
public:
    SpaceVector(); // 默认构造函数
    SpaceVector(double, double, double); // 构造函数

    void setSpaceVector(Space);
    void setSpaceVector(SpaceVector, double);

    SpaceVector& operator=(const Space&);
    SpaceVector& operator=(const SpaceVector&);
    SpaceVector(const SpaceVector&);
    SpaceVector operator/(const double);
    SpaceVector operator*(const double);
    SpaceVector operator+(const SpaceVector&);
    SpaceVector operator/(const SpaceVector&);

    double getModulus()const; // 向量的模
    double getSquareModulus()const; // 模的平方
    Space getDirection()const; // 单位向量
};


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
    SpaceVector operator/(const double);
    SpaceVector operator*(const double);
    SpaceVector operator+(const SpaceVector&);
    SpaceVector operator/(const SpaceVector&);

    double getModulus(); // 向量的模
    Space getDirection(); // 单位向量
};


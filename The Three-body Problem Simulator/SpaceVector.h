#pragma once
class SpaceVector // 空间向量坐标类
{
private:
    // 坐标(x, y, z)
    double x;
    double y;
    double z;
public:
    // 构造函数
    SpaceVector(void); // 默认构造函数
    SpaceVector(const SpaceVector& other); // 拷贝构造函数
    SpaceVector(double X, double Y, double Z); // 初始化构造函数

    SpaceVector& setSpaceVector(const SpaceVector& origin, double modulus);
    // 根据给定向量的方向和给定的模设置向量

    // 运算符重载
    SpaceVector& operator=(const SpaceVector& other); // 赋值运算符
    SpaceVector operator*(const double scalarMultiplier)const; // 向量乘标量
    SpaceVector operator/(const double scalarDivisor)const; // 向量除以标量
    SpaceVector operator+(const SpaceVector& vectorAddend)const; // 向量加法
    SpaceVector operator-(const SpaceVector& vectorSubtrahend)const; // 向量减法
    SpaceVector operator/(const SpaceVector& vectorDivisor)const; // 向量除法

    double getModulus(void)const; // 向量的模
    double getSquareModulus(void)const; // 向量的模的平方
    SpaceVector getUnitVector(void)const; // 向量对应的单位向量
};

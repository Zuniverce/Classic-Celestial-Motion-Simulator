#pragma once
#include "Global.h"
class MultidimensionalVector // 多维向量坐标类
{
private:
    // 坐标
    vector<double>coordinate;
public:
    static inline int dimension = 0; // 维度
    static void setDimension(); // 设置维度

    MultidimensionalVector(void); // 默认构造函数
    MultidimensionalVector(const MultidimensionalVector& other); // 拷贝构造函数
    MultidimensionalVector(const vector<double>&origin); // 初始化构造函数

    MultidimensionalVector& setSpaceVector(const MultidimensionalVector& origin, const double& modulus); // 根据给定向量的方向和给定的模设置向量
    
    MultidimensionalVector& operator=(const MultidimensionalVector& other); // 赋值运算符
    MultidimensionalVector operator*(const double& scalarMultiplier)const; // 向量乘标量
    MultidimensionalVector operator/(const double& scalarDivisor)const; // 向量除以标量
    MultidimensionalVector operator+(const MultidimensionalVector& vectorAddend)const; // 向量加法
    MultidimensionalVector operator-(const MultidimensionalVector& vectorSubtrahend)const; // 向量减法
    //MultidimensionalVector operator/(const MultidimensionalVector& vectorDivisor)const; // 向量除法
    MultidimensionalVector& operator+=(const MultidimensionalVector& vectorAddend);
    
    double getModulus(void)const; // 向量的模
    double getSquareModulus(void)const; // 向量的模的平方
    MultidimensionalVector getUnitVector(void)const; // 向量对应的单位向量
    static double getSquareModulus(const MultidimensionalVector& A, const MultidimensionalVector& B); // 两个向量的差向量的模的平方

    void print(void); // 打印\n
};
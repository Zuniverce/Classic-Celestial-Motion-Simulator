#pragma once
class SpaceVector // 空间向量坐标类
{
private:
    // 坐标
    vector<double>coordinate;
public:
    static int dimension; // 维度
    void setDimension(); // 设置维度

    SpaceVector(void); // 默认构造函数
    SpaceVector(const SpaceVector& other); // 拷贝构造函数
    SpaceVector(const vector<double>& origin); // 初始化构造函数
    SpaceVector& setSpaceVector(const SpaceVector& origin, const double& modulus); // 根据给定向量的方向和给定的模设置向量
    
    // 运算符重载
    SpaceVector& operator=(const SpaceVector& other); // 赋值运算符
    SpaceVector operator*(const double& scalarMultiplier)const; // 向量乘标量
    SpaceVector operator/(const double& scalarDivisor)const; // 向量除以标量
    SpaceVector operator+(const SpaceVector& vectorAddend)const; // 向量加法
    SpaceVector operator-(const SpaceVector& vectorSubtrahend)const; // 向量减法
    SpaceVector& operator+=(const SpaceVector& vectorAddend);
    
    double getModulus(void)const; // 向量的模
    double getSquareModulus(void)const; // 向量的模的平方
    SpaceVector getUnitVector(void)const; // 向量对应的单位向量

    static double getSquareModulus(const SpaceVector& A, const SpaceVector& B); // 两个向量的差向量的模的平方

    void print(void); // 打印\n
};

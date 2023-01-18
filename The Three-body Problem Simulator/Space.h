#pragma once
class Space // 空间标量坐标类
{
protected:
	double x;
	double y;
	double z;

public:
	Space();
	Space(double, double, double);

	Space& operator=(const Space& other);
	Space operator+(const Space& other);
	Space& operator+=(const Space& other);
	Space operator-(const Space& other);

	void setSpace(double, double, double);
	double getX()const;
	double getY()const;
	double getZ()const;
};


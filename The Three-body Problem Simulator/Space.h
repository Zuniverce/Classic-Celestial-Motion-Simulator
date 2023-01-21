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
	void setSpace(double, double, double);

	Space& operator=(const Space& other);
	Space operator+(const Space& other);
	Space& operator+=(const Space& other);
	Space operator-(const Space& other);

	double getX()const;
	double getY()const;
	double getZ()const;

	static double getDistance(const Space, const Space);
	static double getSquareDistance(const Space A, const Space B);

	void print();
	void printToShow();
};


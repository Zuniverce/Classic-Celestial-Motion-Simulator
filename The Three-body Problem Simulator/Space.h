#pragma once
class Space // �ռ����������
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


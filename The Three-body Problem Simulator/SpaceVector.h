#pragma once
#include "Space.h"
class SpaceVector : // �ռ�����������
    public Space
{
public:
    SpaceVector(); // Ĭ�Ϲ��캯��
    SpaceVector(double, double, double); // ���캯��

    void setSpaceVector(Space);
    void setSpaceVector(SpaceVector, double);

    SpaceVector& operator=(const Space&);
    SpaceVector& operator=(const SpaceVector&);
    SpaceVector(const SpaceVector&);
    SpaceVector operator/(const double);
    SpaceVector operator*(const double);
    SpaceVector operator+(const SpaceVector&);
    SpaceVector operator/(const SpaceVector&);

    double getModulus()const; // ������ģ
    double getSquareModulus()const; // ģ��ƽ��
    Space getDirection()const; // ��λ����
};


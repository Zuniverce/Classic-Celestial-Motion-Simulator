#pragma once
#include "Space.h"
class SpaceVector : // �ռ�����������
    public Space
{
public:
    SpaceVector(); // Ĭ�Ϲ��캯��
    SpaceVector(double, double, double); // ���캯��

    double getModulus(); // ������ģ
    Space getDirection(); // ��λ����
};


#pragma once
#include "System_of_equations.h"

// ��������� �� ��������� ���� Algebraic_equation, �� � �������� ����� System_of_equations. ��� ���� �� ����� ��� ����������
// ������� ������� � ����� �� ����������� �������
class Algebraic_equation : public System_of_equations
{
private:
	double a1, b1, a2, b2, c1, c2, n1, n2, n3, n4; // ����������� �������
public:
	Algebraic_equation(double, double, double, double, double, double, double, double, double, double); // ����������� � ����������� ��� ����������� �����������
	void values_of_equations(double, double, double*) override; // ���������� ������� ������� � ����� (�, �)
};
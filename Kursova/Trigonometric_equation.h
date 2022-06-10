#pragma once
#include "System_of_equations.h"

// ��������� �� ��������� ���� Trigonometric_equation, �� � �������� ����� System_of_equations. ��� ���� �� ����� ��� ����������
// ������� ������� � ����� �� ����������� �������
class Trigonometric_equation : public System_of_equations
{
private:
	double a1, b1, a2, b2, c1, c2; // ����������� �������
public:
	Trigonometric_equation(double, double, double, double, double, double); // ����������� � ����������� ��� ����������� �����������
	void values_of_equations(double, double, double*) override; // ���������� ������� ������� � ����� (�, �)
};
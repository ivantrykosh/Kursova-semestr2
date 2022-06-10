#include "Transcendental_equation.h"

// ����������� ��� ����������� ����������� (a1, b1, a2, b2), ������ ����� (c1, c2) �� ����� ��������� (n1, n2) ������� ��������������� ������
Transcendental_equation::Transcendental_equation(double a1, double b1, double a2, double b2, double c1, double c2, double n1, double n2) : System_of_equations::System_of_equations()
{
	this->a1 = a1;
	this->b1 = b1;
	this->a2 = a2;
	this->b2 = b2;
	this->c1 = c1;
	this->c2 = c2;
	this->n1 = n1;
	this->n2 = n2;
}

// ��������� �������� ���������������� ������� � ����� (�, �)
void Transcendental_equation::values_of_equations(double x, double y, double* p) // (�, �) - �����, � - �������� �� ����� �������
{
	*(p) = a1 * mathpow(M_E, x) + b1 * mathpow(M_E, -y) - c1; // ��������� ����� �������� �������
	*(p + 1) = a2 * logarithm(n1, x) + b2 * logarithm(n2, y) - c2; // ��������� ����� �������� �������
}
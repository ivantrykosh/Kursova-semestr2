#include "Algebraic_equation.h"

// ����������� ��� ����������� ����������� (a1, b1, a2, b2), ������ ����� (c1, c2) �� ������� "�" (n1, n3) � "y" (n2, n4) ������� ����������� ������
Algebraic_equation::Algebraic_equation(double a1, double b1, double a2, double b2, double c1, double c2, double n1, double n2, double n3, double n4) : System_of_equations::System_of_equations()
{
	this->a1 = a1;
	this->b1 = b1;
	this->a2 = a2;
	this->b2 = b2;
	this->c1 = c1;
	this->c2 = c2;
	this->n1 = n1;
	this->n2 = n2;
	this->n3 = n3;
	this->n4 = n4;
}

// ��������� �������� ����������� ������� � ����� (�, �)
void Algebraic_equation::values_of_equations(double x, double y, double* p) // (�, �) - �����, � - �������� �� ����� �������
{
	*(p) = a1 * mathpow(x, n1) + b1 * mathpow(y, n2) - c1; // ��������� ����� �������� �������
	*(p + 1) = a2 * mathpow(x, n3) + b2 * mathpow(y, n4) - c2; // ��������� ����� �������� �������
}
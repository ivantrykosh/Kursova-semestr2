#include "Algebraic_equation.h"

// Конструктор для ініціалізації коефіцієнтів (a1, b1, a2, b2), вільних членів (c1, c2) та степенів "х" (n1, n3) й "y" (n2, n4) системи алгебраїчних рівнянь
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

// Знаходимо значення алгебраїчних функцій у точці (х, у)
void Algebraic_equation::values_of_equations(double x, double y, double* p) // (х, у) - точка, р - покажчик на масив значень
{
	*(p) = a1 * mathpow(x, n1) + b1 * mathpow(y, n2) - c1; // Знаходимо перше значення функції
	*(p + 1) = a2 * mathpow(x, n3) + b2 * mathpow(y, n4) - c2; // Знаходимо друге значення функції
}
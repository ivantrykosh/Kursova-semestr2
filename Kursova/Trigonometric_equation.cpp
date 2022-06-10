#include "Trigonometric_equation.h"

// Конструктор для ініціалізації коефіцієнтів (a1, b1, a2, b2), вільних членів (c1, c2) системи тригонометричних рівнянь
Trigonometric_equation::Trigonometric_equation(double a1, double b1, double a2, double b2, double c1, double c2) : System_of_equations::System_of_equations()
{
	this->a1 = a1;
	this->b1 = b1;
	this->a2 = a2;
	this->b2 = b2;
	this->c1 = c1;
	this->c2 = c2;
}

// Знаходимо значення тригонометричних функцій у точці (х, у)
void Trigonometric_equation::values_of_equations(double x, double y, double* p) // (х, у) - точка, р - покажчик на масив значень
{
	*(p) = a1 * sin(x) + b1 * cos(y) - c1; // Знаходимо перше значення функції
	*(p + 1) = a2 * tangens(x) + b2 * cotangens(y) - c2; // Знаходимо друге значення функції
}
#pragma once
#include "System_of_equations.h"

// Оголошуємо та визначаємо клас Trigonometric_equation, що є нащадком класу System_of_equations. Цей клас має метод для обчислення
// значень функцій у точці та коефіцієнти системи
class Trigonometric_equation : public System_of_equations
{
private:
	double a1, b1, a2, b2, c1, c2; // Коефіцієнти системи
public:
	Trigonometric_equation(double, double, double, double, double, double); // Конструктор з параметрами для ініціалізації коефіцієнтів
	void values_of_equations(double, double, double*) override; // Обчислення значень функцій в точці (х, у)
};
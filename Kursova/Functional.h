#pragma once
//#define _USE_MATH_DEFINES // Для математичних констант
//#include <cmath> // Для обчислення математичних функцій
//#include <string> // Для використання рядків
//#include <vector> // Для збереження масиву значень "x" та "y"
//
//using namespace std;
//
//// Оголошуємо та визначаємо клас "System_of_equations", який є абстрактим та має методи Ньютона, січних, чисто віртуальний метод для обчислення
//// значень функцій у точці (х, у), методи для обчислення логарифма, степеня, тангенса, котангенса, сеттер для встановлення точності обчислень
//class System_of_equations
//{
//public:
//	System_of_equations(); // Пустий конструктор
//	void set_epsylon(double); // Встановлення точності обчислень
//	void Matrix_W(double, double, double*); // Обчислення матриці Якобі в точці (х, у)
//	virtual void values_of_equations(double, double, double*) = 0; // Обчислення значень функцій в точці (х, у)
//	vector<vector<double>> newton(double&, double&); // Метод Ньютона
//	vector<vector<double>> sichna(double&, double&); // Метод січних
//protected:
//	double eps; // Точність обчислень
//	double mathpow(double, double); // Знаходження степеня "у" числа "х"
//	double tangens(double); // Знаходження tg(х)
//	double cotangens(double); // Знаходження ctg(х)
//	double logarithm(double, double); // Знаходження log(x) за основою "base"
//};
//
//// Оголошуємо та визначаємо клас Algebraic_equation, що є нащадком класу System_of_equations. Цей клас має метод для обчислення
//// значень функцій у точці та коефіцієнти системи
//class Algebraic_equation : public System_of_equations
//{
//private:
//	double a1, b1, a2, b2, c1, c2, n1, n2, n3, n4; // Коефіцієнти системи
//public:
//	Algebraic_equation(double, double, double, double, double, double, double, double, double, double); // Конструктор з параметрами для ініціалізації коефіцієнтів
//	void values_of_equations(double, double, double*) override; // Обчислення значень функцій в точці (х, у)
//};
//
//// Оголошуємо та визначаємо клас Trigonometric_equation, що є нащадком класу System_of_equations. Цей клас має метод для обчислення
//// значень функцій у точці та коефіцієнти системи
//class Trigonometric_equation : public System_of_equations
//{
//private:
//	double a1, b1, a2, b2, c1, c2; // Коефіцієнти системи
//public:
//	Trigonometric_equation(double, double, double, double, double, double); // Конструктор з параметрами для ініціалізації коефіцієнтів
//	void values_of_equations(double, double, double*) override; // Обчислення значень функцій в точці (х, у)
//};
//
//// Оголошуємо та визначаємо клас Transcendental_equation, що є нащадком класу System_of_equations. Цей клас має метод для обчислення
//// значень функцій у точці та коефіцієнти системи
//class Transcendental_equation : public System_of_equations
//{
//private:
//	double a1, b1, a2, b2, c1, c2, n1, n2; // Коефіцієнти системи
//public:
//	Transcendental_equation(double, double, double, double, double, double, double, double); // Конструктор з параметрами для ініціалізації коефіцієнтів
//	void values_of_equations(double, double, double*) override; // Обчислення значень функцій в точці (х, у)
//};
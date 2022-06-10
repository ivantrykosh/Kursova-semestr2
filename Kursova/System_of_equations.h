#pragma once
#define _USE_MATH_DEFINES // Для математичних констант
#include <cmath> // Для обчислення математичних функцій
#include <vector> // Для збереження масиву значень "x" та "y"

using namespace std;

// Оголошуємо та визначаємо клас "System_of_equations", який є абстрактим та має методи Ньютона, січних, чисто віртуальний метод для обчислення
// значень функцій у точці (х, у), методи для обчислення логарифма, степеня, тангенса, котангенса, сеттер для встановлення точності обчислень
class System_of_equations
{
public:
	System_of_equations(); // Пустий конструктор
	void set_epsylon(double); // Встановлення точності обчислень
	void Matrix_W(double, double, double*); // Обчислення матриці Якобі в точці (х, у)
	virtual void values_of_equations(double, double, double*) = 0; // Обчислення значень функцій в точці (х, у)
	vector<vector<double>> newton(double&, double&); // Метод Ньютона
	vector<vector<double>> sichna(double&, double&); // Метод січних
protected:
	double eps; // Точність обчислень
	double mathpow(double, double); // Знаходження степеня "у" числа "х"
	double tangens(double); // Знаходження tg(х)
	double cotangens(double); // Знаходження ctg(х)
	double logarithm(double, double); // Знаходження log(x) за основою "base"	
};
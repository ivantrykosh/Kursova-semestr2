#pragma once
//#define _USE_MATH_DEFINES // ��� ������������ ��������
//#include <cmath> // ��� ���������� ������������ �������
//#include <string> // ��� ������������ �����
//#include <vector> // ��� ���������� ������ ������� "x" �� "y"
//
//using namespace std;
//
//// ��������� �� ��������� ���� "System_of_equations", ���� � ���������� �� �� ������ �������, �����, ����� ���������� ����� ��� ����������
//// ������� ������� � ����� (�, �), ������ ��� ���������� ���������, �������, ��������, ����������, ������ ��� ������������ ������� ���������
//class System_of_equations
//{
//public:
//	System_of_equations(); // ������ �����������
//	void set_epsylon(double); // ������������ ������� ���������
//	void Matrix_W(double, double, double*); // ���������� ������� ���� � ����� (�, �)
//	virtual void values_of_equations(double, double, double*) = 0; // ���������� ������� ������� � ����� (�, �)
//	vector<vector<double>> newton(double&, double&); // ����� �������
//	vector<vector<double>> sichna(double&, double&); // ����� �����
//protected:
//	double eps; // ������� ���������
//	double mathpow(double, double); // ����������� ������� "�" ����� "�"
//	double tangens(double); // ����������� tg(�)
//	double cotangens(double); // ����������� ctg(�)
//	double logarithm(double, double); // ����������� log(x) �� ������� "base"
//};
//
//// ��������� �� ��������� ���� Algebraic_equation, �� � �������� ����� System_of_equations. ��� ���� �� ����� ��� ����������
//// ������� ������� � ����� �� ����������� �������
//class Algebraic_equation : public System_of_equations
//{
//private:
//	double a1, b1, a2, b2, c1, c2, n1, n2, n3, n4; // ����������� �������
//public:
//	Algebraic_equation(double, double, double, double, double, double, double, double, double, double); // ����������� � ����������� ��� ����������� �����������
//	void values_of_equations(double, double, double*) override; // ���������� ������� ������� � ����� (�, �)
//};
//
//// ��������� �� ��������� ���� Trigonometric_equation, �� � �������� ����� System_of_equations. ��� ���� �� ����� ��� ����������
//// ������� ������� � ����� �� ����������� �������
//class Trigonometric_equation : public System_of_equations
//{
//private:
//	double a1, b1, a2, b2, c1, c2; // ����������� �������
//public:
//	Trigonometric_equation(double, double, double, double, double, double); // ����������� � ����������� ��� ����������� �����������
//	void values_of_equations(double, double, double*) override; // ���������� ������� ������� � ����� (�, �)
//};
//
//// ��������� �� ��������� ���� Transcendental_equation, �� � �������� ����� System_of_equations. ��� ���� �� ����� ��� ����������
//// ������� ������� � ����� �� ����������� �������
//class Transcendental_equation : public System_of_equations
//{
//private:
//	double a1, b1, a2, b2, c1, c2, n1, n2; // ����������� �������
//public:
//	Transcendental_equation(double, double, double, double, double, double, double, double); // ����������� � ����������� ��� ����������� �����������
//	void values_of_equations(double, double, double*) override; // ���������� ������� ������� � ����� (�, �)
//};
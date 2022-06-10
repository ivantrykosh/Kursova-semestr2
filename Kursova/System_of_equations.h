#pragma once
#define _USE_MATH_DEFINES // ��� ������������ ��������
#include <cmath> // ��� ���������� ������������ �������
#include <vector> // ��� ���������� ������ ������� "x" �� "y"

using namespace std;

// ��������� �� ��������� ���� "System_of_equations", ���� � ���������� �� �� ������ �������, �����, ����� ���������� ����� ��� ����������
// ������� ������� � ����� (�, �), ������ ��� ���������� ���������, �������, ��������, ����������, ������ ��� ������������ ������� ���������
class System_of_equations
{
public:
	System_of_equations(); // ������ �����������
	void set_epsylon(double); // ������������ ������� ���������
	void Matrix_W(double, double, double*); // ���������� ������� ���� � ����� (�, �)
	virtual void values_of_equations(double, double, double*) = 0; // ���������� ������� ������� � ����� (�, �)
	vector<vector<double>> newton(double&, double&); // ����� �������
	vector<vector<double>> sichna(double&, double&); // ����� �����
protected:
	double eps; // ������� ���������
	double mathpow(double, double); // ����������� ������� "�" ����� "�"
	double tangens(double); // ����������� tg(�)
	double cotangens(double); // ����������� ctg(�)
	double logarithm(double, double); // ����������� log(x) �� ������� "base"	
};
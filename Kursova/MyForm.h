#pragma once
#include <string> // Для використання рядків
#include "Algebraic_equation.h" // Підключаємо клас Algebraic_equation
#include "Trigonometric_equation.h" // Підключаємо клас Trigonometric_equation
#include "Transcendental_equation.h" // Підключаємо клас Transcendental_equation
// Клас System_of_equations уже підключений до вище підключених класів, тому його підключати уже не потрібно

namespace Kursova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void); // Конструктор, що ініціалізує компоненти
	protected:
		~MyForm(); // Деструктор, що видалаяє компоненти
	private: System_of_equations* system = nullptr; // Оголошуємо покажчик на систему рівнянь

	// Виводимо результат
	private: void printresult(vector<vector<double>>, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&);

	// Записуємо систему
	private: string printsystem(double&, double&, double&, double&, double&, double&, double&, double&, double&, double&);

	// Перевірка введених даних на правильність
	private: void check(double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&, double&);

	// Оголошуємо компоненти форми
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ проПрограмуToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ якКористуватисяToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вийтиToolStripMenuItem;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TextBox^ textBox13;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		// Створюємо компоненти форми
		void InitializeComponent(void);	
#pragma endregion
	// Оброблюємо натискання на кпопки
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void якКористуватисяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void вийтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
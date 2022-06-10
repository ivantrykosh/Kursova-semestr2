#include "MyForm.h"

// Конструктор, що ініціалізує компоненти
Kursova::MyForm::MyForm(void)
{
	InitializeComponent();
}

// Деструктор, що видалаяє компоненти
Kursova::MyForm::~MyForm()
{
	if (components)
	{
		delete components;
	}
}

// Виводимо результат
void Kursova::MyForm::printresult(vector<vector<double>> values, double& x, double& y, double& eps, double& a1, double& b1, double& a2, double& b2, double& n1, double& n2, double& n3, double& n4, double& c1, double& c2) // values - вектор точок (х, у)
{
	string temp = printsystem(a1, b1, a2, b2, n1, n2, n3, n4, c1, c2); // Записуємо введену систему рівнянь

	// Записуємо обраний метод розв'язування
	temp += "\nМетод розв'язування:    ";
	temp += this->radioButton4->Checked ? "Ньютона\n" : "січних\n";

	// Записуємо введене початкове приближення та точність обчислень
	temp += "Початкове приближення:   " + to_string(values[0][0]) + " ; " + to_string(values[0][1]) + "\n";
	temp += "Точність обчислень:   " + to_string(eps) + "\n\n";

	temp += "Коротка відповідь: " + to_string(values[values.size() - 1][0]) + " ; " + to_string(values[values.size() - 1][1]) + "\n\nЗначення \"х\" та \"у\" на кожній ітерації:\n"; // Записуємо роз'язок системи (х, у)

	// Проходимо по масиву точок
	for (int i = 0; i < values.size(); i++)
	{
		temp += to_string(i + 1) + ": " + to_string(values[i][0]) + " ; " + to_string(values[i][1]); // Додаємо точку до рядка
		if ((i + 1) % 4 == 0)
		{
			temp += "\n";
		}
		else if (i != values.size() - 1)
		{
			temp += "  |  ";
		}
	}
	this->label15->Text = gcnew System::String(temp.c_str()); // Записуємо рядок у поле label
	MessageBox::Show(gcnew System::String(("Відповідь: " + to_string(values[values.size() - 1][0]) + " ; " + to_string(values[values.size() - 1][1])).c_str()), L"Результат", MessageBoxButtons::OK, MessageBoxIcon::Information); // Виводимо результат на екран з відповідними атрибутами
}

// Записуємо систему
string Kursova::MyForm::printsystem(double& a1, double& b1, double& a2, double& b2, double& n1, double& n2, double& n3, double& n4, double& c1, double& c2)
{
	string temp = "Система рівнянь:\n"; // Рядок для запису

	// Записуємо систему алгебраїчних рівнянь із заданими коефіцієнтами
	if (this->radioButton1->Checked)
	{
		// Записуємо перше рівняння системи у форматі a1 * x^(n1) + b1 * y^(n2) = c1
		temp += "    " + to_string(a1) + " * x^(" + to_string(n1) + ") ";
		if (b1 < 0)
		{
			temp += "- " + to_string(fabs(b1));
		}
		else
		{
			temp += "+ " + to_string(b1);
		}
		temp += " * y^(" + to_string(n2) + ") = " + to_string(c1) + "\n";

		// Записуємо друге рівняння системи у форматі a2 * x^(n3) + b2 * y^(n4) = c2
		temp += "    " + to_string(a2) + " * x^(" + to_string(n3) + ") ";
		if (b2 < 0)
		{
			temp += "- " + to_string(fabs(b2));
		}
		else
		{
			temp += "+ " + to_string(b2);
		}
		temp += " * y^(" + to_string(n4) + ") = " + to_string(c2) + "\n";
	}

	// Записуємо систему тригонометричних рівнянь із заданими коефіцієнтами
	else if (this->radioButton2->Checked)
	{
		// Записуємо перше рівняння системи у форматі a1 * sin(x) + b1 * cos(y) = c1
		temp += "    " + to_string(a1) + " * sin(x) ";
		if (b1 < 0)
		{
			temp += "- " + to_string(fabs(b1));
		}
		else
		{
			temp += "+ " + to_string(b1);
		}
		temp += " * cos(y) = " + to_string(c1) + "\n";

		// Записуємо друге рівняння системи у форматі a2 * tg(x) + b2 * ctg(y) = c2
		temp += "    " + to_string(a2) + " * tg(x) ";
		if (b2 < 0)
		{
			temp += "- " + to_string(fabs(b2));
		}
		else
		{
			temp += "+ " + to_string(b2);
		}
		temp += " * ctg(y) = " + to_string(c2) + "\n";
	}

	// Записуємо систему трансцендентних рівнянь із заданими коефіцієнтами
	else
	{
		// Записуємо перше рівняння системи у форматі a1 * e^(x) + b1 * e^(-y) = c1
		temp += "    " + to_string(a1) + " * e^(x) ";
		if (b1 < 0)
		{
			temp += "- " + to_string(fabs(b1));
		}
		else
		{
			temp += "+ " + to_string(b1);
		}
		temp += " * e^(-y) = " + to_string(c1) + "\n";

		// Записуємо друге рівняння системи у форматі a2 * log(n1)x + b2 * log(n2)y = c2
		temp += "    " + to_string(a2) + " * log(" + to_string(n1) + ")x ";
		if (b2 < 0)
		{
			temp += "- " + to_string(fabs(b2));
		}
		else
		{
			temp += "+ " + to_string(b2);
		}
		temp += " * log(" + to_string(n2) + ")y = " + to_string(c2) + "\n";
	}
	return temp;
}

// Перевірка введених даних на правильність
void Kursova::MyForm::check(double& x, double& y, double& eps, double& a1, double& b1, double& a2, double& b2, double& n1, double& n2, double& n3, double& n4, double& c1, double& c2)
{
	// Перевіряємо, чи обрано тип системи
	if (!(this->radioButton1->Checked || this->radioButton2->Checked || this->radioButton3->Checked))
	{
		throw "Ви не обрали вид системи рівнянь!";
	}

	// Перевіряємо, чи обрано метод розв'язування системи
	if (!(this->radioButton4->Checked || this->radioButton5->Checked))
	{
		throw "Ви не обрали метод розв'язування!";
	}
	
	// Перевіряємо на правильність введення початкове приближення
	if (!(Double::TryParse(this->textBox11->Text, x) && Double::TryParse(this->textBox12->Text, y)))
	{
		throw "Ви некоректно ввели початкове приближення!";
	}

	// Перевірямо на правильність введення точність обчислень
	if (!(Double::TryParse(this->textBox13->Text, eps) && eps > 0 && eps < 1))
	{
		throw "Ви некоректно ввели точність обчислень!";
	}

	// Перевіряємо на правильність введення коефіцієнти системи алгебраїчних рівнянь
	if (Double::TryParse(this->textBox1->Text, a1) && Double::TryParse(this->textBox2->Text, b1) && Double::TryParse(this->textBox3->Text, a2) &&
		Double::TryParse(this->textBox4->Text, b2) && Double::TryParse(this->textBox5->Text, n1) && Double::TryParse(this->textBox6->Text, n2) &&
		Double::TryParse(this->textBox7->Text, n3) && Double::TryParse(this->textBox8->Text, n4) && Double::TryParse(this->textBox9->Text, c1) &&
		Double::TryParse(this->textBox10->Text, c2) && this->radioButton1->Checked)
	{
		system = new Algebraic_equation(a1, b1, a2, b2, c1, c2, n1, n2, n3, n4);
	}

	// Перевіряємо на правильність введення коефіцієнти системи трансцендентних рівнянь
	else if (Double::TryParse(this->textBox1->Text, a1) && Double::TryParse(this->textBox2->Text, b1) && Double::TryParse(this->textBox3->Text, a2) &&
		Double::TryParse(this->textBox4->Text, b2) && Double::TryParse(this->textBox5->Text, n1) && Double::TryParse(this->textBox6->Text, n2) &&
		this->textBox7->Text == L"-" && this->textBox8->Text == L"-" && Double::TryParse(this->textBox9->Text, c1) &&
		Double::TryParse(this->textBox10->Text, c2) && this->radioButton3->Checked)
	{
		system = new Transcendental_equation(a1, b1, a2, b2, c1, c2, n1, n2);
	}

	// Перевіряємо на правильність введення коефіцієнти системи тригонометричних рівнянь
	else if (Double::TryParse(this->textBox1->Text, a1) && Double::TryParse(this->textBox2->Text, b1) && Double::TryParse(this->textBox3->Text, a2) &&
		Double::TryParse(this->textBox4->Text, b2) && this->textBox5->Text == L"-" && this->textBox6->Text == L"-" &&
		this->textBox7->Text == L"-" && this->textBox8->Text == L"-" && Double::TryParse(this->textBox9->Text, c1) &&
		Double::TryParse(this->textBox10->Text, c2) && this->radioButton2->Checked)
	{
		system = new Trigonometric_equation(a1, b1, a2, b2, c1, c2);
	}

	// Інакше виводимо помилку
	else
	{
		throw "Ви некоректно ввели коефіцієнти!";
	}
}

// Створюємо компоненти форми
void Kursova::MyForm::InitializeComponent(void)
{
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->label2 = (gcnew System::Windows::Forms::Label());
	this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
	this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
	this->label3 = (gcnew System::Windows::Forms::Label());
	this->label4 = (gcnew System::Windows::Forms::Label());
	this->label5 = (gcnew System::Windows::Forms::Label());
	this->label6 = (gcnew System::Windows::Forms::Label());
	this->label7 = (gcnew System::Windows::Forms::Label());
	this->label8 = (gcnew System::Windows::Forms::Label());
	this->label9 = (gcnew System::Windows::Forms::Label());
	this->label10 = (gcnew System::Windows::Forms::Label());
	this->label11 = (gcnew System::Windows::Forms::Label());
	this->label12 = (gcnew System::Windows::Forms::Label());
	this->label13 = (gcnew System::Windows::Forms::Label());
	this->textBox1 = (gcnew System::Windows::Forms::TextBox());
	this->textBox2 = (gcnew System::Windows::Forms::TextBox());
	this->textBox3 = (gcnew System::Windows::Forms::TextBox());
	this->textBox4 = (gcnew System::Windows::Forms::TextBox());
	this->textBox5 = (gcnew System::Windows::Forms::TextBox());
	this->textBox6 = (gcnew System::Windows::Forms::TextBox());
	this->textBox7 = (gcnew System::Windows::Forms::TextBox());
	this->textBox8 = (gcnew System::Windows::Forms::TextBox());
	this->textBox9 = (gcnew System::Windows::Forms::TextBox());
	this->textBox10 = (gcnew System::Windows::Forms::TextBox());
	this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
	this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
	this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
	this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
	this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
	this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
	this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
	this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
	this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->label14 = (gcnew System::Windows::Forms::Label());
	this->label15 = (gcnew System::Windows::Forms::Label());
	this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
	this->textBox12 = (gcnew System::Windows::Forms::TextBox());
	this->textBox11 = (gcnew System::Windows::Forms::TextBox());
	this->label18 = (gcnew System::Windows::Forms::Label());
	this->label17 = (gcnew System::Windows::Forms::Label());
	this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
	this->проПрограмуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->якКористуватисяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->вийтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->label16 = (gcnew System::Windows::Forms::Label());
	this->button2 = (gcnew System::Windows::Forms::Button());
	this->label19 = (gcnew System::Windows::Forms::Label());
	this->label20 = (gcnew System::Windows::Forms::Label());
	this->textBox13 = (gcnew System::Windows::Forms::TextBox());
	this->groupBox1->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
	this->groupBox2->SuspendLayout();
	this->groupBox3->SuspendLayout();
	this->groupBox4->SuspendLayout();
	this->menuStrip1->SuspendLayout();
	this->SuspendLayout();
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->Enabled = false;
	this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label1->ForeColor = System::Drawing::SystemColors::Desktop;
	this->label1->Location = System::Drawing::Point(50, 24);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(285, 25);
	this->label1->TabIndex = 0;
	this->label1->Text = L"Оберіть тип системи рівнянь";
	this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
	// 
	// label2
	// 
	this->label2->AutoSize = true;
	this->label2->BackColor = System::Drawing::SystemColors::Control;
	this->label2->Enabled = false;
	this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label2->ForeColor = System::Drawing::SystemColors::Desktop;
	this->label2->Location = System::Drawing::Point(344, 24);
	this->label2->Name = L"label2";
	this->label2->Size = System::Drawing::Size(154, 50);
	this->label2->TabIndex = 7;
	this->label2->Text = L"Оберіть метод\r\nрозв\'язування";
	this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	// 
	// radioButton4
	// 
	this->radioButton4->AutoSize = true;
	this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->radioButton4->Location = System::Drawing::Point(14, 18);
	this->radioButton4->Name = L"radioButton4";
	this->radioButton4->Size = System::Drawing::Size(166, 26);
	this->radioButton4->TabIndex = 8;
	this->radioButton4->Text = L"Метод Ньютона";
	this->radioButton4->UseVisualStyleBackColor = true;
	// 
	// radioButton5
	// 
	this->radioButton5->AutoSize = true;
	this->radioButton5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->radioButton5->Location = System::Drawing::Point(14, 68);
	this->radioButton5->Name = L"radioButton5";
	this->radioButton5->Size = System::Drawing::Size(145, 26);
	this->radioButton5->TabIndex = 9;
	this->radioButton5->TabStop = true;
	this->radioButton5->Text = L"Метод січних";
	this->radioButton5->UseVisualStyleBackColor = true;
	// 
	// label3
	// 
	this->label3->AutoSize = true;
	this->label3->Enabled = false;
	this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label3->ForeColor = System::Drawing::SystemColors::Desktop;
	this->label3->Location = System::Drawing::Point(417, 220);
	this->label3->Name = L"label3";
	this->label3->Size = System::Drawing::Size(203, 25);
	this->label3->TabIndex = 10;
	this->label3->Text = L"Введіть коефіцієнти";
	this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	// 
	// label4
	// 
	this->label4->AutoSize = true;
	this->label4->Enabled = false;
	this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label4->Location = System::Drawing::Point(7, 23);
	this->label4->Name = L"label4";
	this->label4->Size = System::Drawing::Size(51, 22);
	this->label4->TabIndex = 11;
	this->label4->Text = L"a1 = ";
	// 
	// label5
	// 
	this->label5->AutoSize = true;
	this->label5->Enabled = false;
	this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label5->Location = System::Drawing::Point(7, 59);
	this->label5->Name = L"label5";
	this->label5->Size = System::Drawing::Size(46, 22);
	this->label5->TabIndex = 12;
	this->label5->Text = L"b1 =";
	// 
	// label6
	// 
	this->label6->AutoSize = true;
	this->label6->Enabled = false;
	this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label6->Location = System::Drawing::Point(7, 92);
	this->label6->Name = L"label6";
	this->label6->Size = System::Drawing::Size(46, 22);
	this->label6->TabIndex = 13;
	this->label6->Text = L"a2 =";
	// 
	// label7
	// 
	this->label7->AutoSize = true;
	this->label7->Enabled = false;
	this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label7->Location = System::Drawing::Point(7, 127);
	this->label7->Name = L"label7";
	this->label7->Size = System::Drawing::Size(46, 22);
	this->label7->TabIndex = 14;
	this->label7->Text = L"b2 =";
	// 
	// label8
	// 
	this->label8->AutoSize = true;
	this->label8->Enabled = false;
	this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label8->Location = System::Drawing::Point(128, 23);
	this->label8->Name = L"label8";
	this->label8->Size = System::Drawing::Size(46, 22);
	this->label8->TabIndex = 15;
	this->label8->Text = L"n1 =";
	// 
	// label9
	// 
	this->label9->AutoSize = true;
	this->label9->Enabled = false;
	this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label9->Location = System::Drawing::Point(128, 58);
	this->label9->Name = L"label9";
	this->label9->Size = System::Drawing::Size(46, 22);
	this->label9->TabIndex = 16;
	this->label9->Text = L"n2 =";
	// 
	// label10
	// 
	this->label10->AutoSize = true;
	this->label10->Enabled = false;
	this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label10->Location = System::Drawing::Point(128, 92);
	this->label10->Name = L"label10";
	this->label10->Size = System::Drawing::Size(51, 22);
	this->label10->TabIndex = 17;
	this->label10->Text = L"n3 = ";
	// 
	// label11
	// 
	this->label11->AutoSize = true;
	this->label11->Enabled = false;
	this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label11->Location = System::Drawing::Point(128, 127);
	this->label11->Name = L"label11";
	this->label11->Size = System::Drawing::Size(51, 22);
	this->label11->TabIndex = 18;
	this->label11->Text = L"n4 = ";
	// 
	// label12
	// 
	this->label12->AutoSize = true;
	this->label12->Enabled = false;
	this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label12->Location = System::Drawing::Point(247, 61);
	this->label12->Name = L"label12";
	this->label12->Size = System::Drawing::Size(50, 22);
	this->label12->TabIndex = 19;
	this->label12->Text = L"c1 = ";
	// 
	// label13
	// 
	this->label13->AutoSize = true;
	this->label13->Enabled = false;
	this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label13->Location = System::Drawing::Point(247, 95);
	this->label13->Name = L"label13";
	this->label13->Size = System::Drawing::Size(50, 22);
	this->label13->TabIndex = 20;
	this->label13->Text = L"c2 = ";
	// 
	// textBox1
	// 
	this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox1->Location = System::Drawing::Point(40, 19);
	this->textBox1->Name = L"textBox1";
	this->textBox1->Size = System::Drawing::Size(82, 28);
	this->textBox1->TabIndex = 21;
	this->textBox1->Text = L"-";
	// 
	// textBox2
	// 
	this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox2->Location = System::Drawing::Point(40, 55);
	this->textBox2->Name = L"textBox2";
	this->textBox2->Size = System::Drawing::Size(82, 28);
	this->textBox2->TabIndex = 22;
	this->textBox2->Text = L"-";
	// 
	// textBox3
	// 
	this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox3->Location = System::Drawing::Point(40, 89);
	this->textBox3->Name = L"textBox3";
	this->textBox3->Size = System::Drawing::Size(82, 28);
	this->textBox3->TabIndex = 23;
	this->textBox3->Text = L"-";
	// 
	// textBox4
	// 
	this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox4->Location = System::Drawing::Point(40, 124);
	this->textBox4->Name = L"textBox4";
	this->textBox4->Size = System::Drawing::Size(82, 28);
	this->textBox4->TabIndex = 24;
	this->textBox4->Text = L"-";
	// 
	// textBox5
	// 
	this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox5->Location = System::Drawing::Point(161, 19);
	this->textBox5->Name = L"textBox5";
	this->textBox5->Size = System::Drawing::Size(82, 28);
	this->textBox5->TabIndex = 25;
	this->textBox5->Text = L"-";
	// 
	// textBox6
	// 
	this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox6->Location = System::Drawing::Point(161, 55);
	this->textBox6->Name = L"textBox6";
	this->textBox6->Size = System::Drawing::Size(82, 28);
	this->textBox6->TabIndex = 26;
	this->textBox6->Text = L"-";
	// 
	// textBox7
	// 
	this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox7->Location = System::Drawing::Point(161, 91);
	this->textBox7->Name = L"textBox7";
	this->textBox7->Size = System::Drawing::Size(82, 28);
	this->textBox7->TabIndex = 27;
	this->textBox7->Text = L"-";
	// 
	// textBox8
	// 
	this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox8->Location = System::Drawing::Point(161, 124);
	this->textBox8->Name = L"textBox8";
	this->textBox8->Size = System::Drawing::Size(82, 28);
	this->textBox8->TabIndex = 28;
	this->textBox8->Text = L"-";
	// 
	// textBox9
	// 
	this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox9->Location = System::Drawing::Point(276, 58);
	this->textBox9->Name = L"textBox9";
	this->textBox9->Size = System::Drawing::Size(82, 28);
	this->textBox9->TabIndex = 29;
	this->textBox9->Text = L"-";
	// 
	// textBox10
	// 
	this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->textBox10->Location = System::Drawing::Point(276, 92);
	this->textBox10->Name = L"textBox10";
	this->textBox10->Size = System::Drawing::Size(82, 28);
	this->textBox10->TabIndex = 30;
	this->textBox10->Text = L"-";
	// 
	// groupBox1
	// 
	this->groupBox1->Controls->Add(this->pictureBox3);
	this->groupBox1->Controls->Add(this->pictureBox2);
	this->groupBox1->Controls->Add(this->pictureBox1);
	this->groupBox1->Controls->Add(this->radioButton3);
	this->groupBox1->Controls->Add(this->radioButton2);
	this->groupBox1->Controls->Add(this->radioButton1);
	this->groupBox1->Location = System::Drawing::Point(6, 44);
	this->groupBox1->Name = L"groupBox1";
	this->groupBox1->Size = System::Drawing::Size(285, 261);
	this->groupBox1->TabIndex = 31;
	this->groupBox1->TabStop = false;
	// 
	// pictureBox3
	// 
	this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
	this->pictureBox3->Location = System::Drawing::Point(26, 181);
	this->pictureBox3->Name = L"pictureBox3";
	this->pictureBox3->Size = System::Drawing::Size(247, 60);
	this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	this->pictureBox3->TabIndex = 39;
	this->pictureBox3->TabStop = false;
	// 
	// pictureBox2
	// 
	this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
	this->pictureBox2->Location = System::Drawing::Point(26, 102);
	this->pictureBox2->Name = L"pictureBox2";
	this->pictureBox2->Size = System::Drawing::Size(247, 60);
	this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	this->pictureBox2->TabIndex = 38;
	this->pictureBox2->TabStop = false;
	// 
	// pictureBox1
	// 
	this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
	this->pictureBox1->Location = System::Drawing::Point(26, 23);
	this->pictureBox1->Name = L"pictureBox1";
	this->pictureBox1->Size = System::Drawing::Size(247, 60);
	this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	this->pictureBox1->TabIndex = 37;
	this->pictureBox1->TabStop = false;
	// 
	// radioButton3
	// 
	this->radioButton3->AutoSize = true;
	this->radioButton3->Location = System::Drawing::Point(6, 204);
	this->radioButton3->Name = L"radioButton3";
	this->radioButton3->Size = System::Drawing::Size(21, 20);
	this->radioButton3->TabIndex = 2;
	this->radioButton3->UseVisualStyleBackColor = true;
	// 
	// radioButton2
	// 
	this->radioButton2->AutoSize = true;
	this->radioButton2->Location = System::Drawing::Point(6, 127);
	this->radioButton2->Name = L"radioButton2";
	this->radioButton2->Size = System::Drawing::Size(21, 20);
	this->radioButton2->TabIndex = 1;
	this->radioButton2->UseVisualStyleBackColor = true;
	// 
	// radioButton1
	// 
	this->radioButton1->AutoSize = true;
	this->radioButton1->Checked = true;
	this->radioButton1->Location = System::Drawing::Point(6, 47);
	this->radioButton1->Name = L"radioButton1";
	this->radioButton1->Size = System::Drawing::Size(21, 20);
	this->radioButton1->TabIndex = 0;
	this->radioButton1->TabStop = true;
	this->radioButton1->UseVisualStyleBackColor = true;
	// 
	// groupBox2
	// 
	this->groupBox2->Controls->Add(this->radioButton4);
	this->groupBox2->Controls->Add(this->radioButton5);
	this->groupBox2->Location = System::Drawing::Point(320, 61);
	this->groupBox2->Name = L"groupBox2";
	this->groupBox2->Size = System::Drawing::Size(151, 100);
	this->groupBox2->TabIndex = 32;
	this->groupBox2->TabStop = false;
	// 
	// groupBox3
	// 
	this->groupBox3->Controls->Add(this->textBox1);
	this->groupBox3->Controls->Add(this->label4);
	this->groupBox3->Controls->Add(this->label5);
	this->groupBox3->Controls->Add(this->textBox10);
	this->groupBox3->Controls->Add(this->label6);
	this->groupBox3->Controls->Add(this->textBox9);
	this->groupBox3->Controls->Add(this->label7);
	this->groupBox3->Controls->Add(this->textBox8);
	this->groupBox3->Controls->Add(this->label8);
	this->groupBox3->Controls->Add(this->textBox7);
	this->groupBox3->Controls->Add(this->label9);
	this->groupBox3->Controls->Add(this->textBox6);
	this->groupBox3->Controls->Add(this->label10);
	this->groupBox3->Controls->Add(this->textBox5);
	this->groupBox3->Controls->Add(this->label11);
	this->groupBox3->Controls->Add(this->textBox4);
	this->groupBox3->Controls->Add(this->label12);
	this->groupBox3->Controls->Add(this->textBox3);
	this->groupBox3->Controls->Add(this->label13);
	this->groupBox3->Controls->Add(this->textBox2);
	this->groupBox3->Location = System::Drawing::Point(307, 236);
	this->groupBox3->Name = L"groupBox3";
	this->groupBox3->Size = System::Drawing::Size(370, 154);
	this->groupBox3->TabIndex = 33;
	this->groupBox3->TabStop = false;
	// 
	// button1
	// 
	this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->button1->Location = System::Drawing::Point(6, 325);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(135, 65);
	this->button1->TabIndex = 34;
	this->button1->Text = L"Знайти розв\'язок";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
	// 
	// label14
	// 
	this->label14->AutoSize = true;
	this->label14->BackColor = System::Drawing::SystemColors::ControlDark;
	this->label14->Enabled = false;
	this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label14->ForeColor = System::Drawing::SystemColors::Control;
	this->label14->Location = System::Drawing::Point(307, 391);
	this->label14->MaximumSize = System::Drawing::Size(278, 66);
	this->label14->Name = L"label14";
	this->label14->Size = System::Drawing::Size(111, 25);
	this->label14->TabIndex = 35;
	this->label14->Text = L"Результат";
	this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	// 
	// label15
	// 
	this->label15->AutoSize = true;
	this->label15->BackColor = System::Drawing::SystemColors::ControlDark;
	this->label15->Enabled = false;
	this->label15->ForeColor = System::Drawing::SystemColors::Control;
	this->label15->Location = System::Drawing::Point(3, 413);
	this->label15->MaximumSize = System::Drawing::Size(1000, 100000);
	this->label15->Name = L"label15";
	this->label15->Size = System::Drawing::Size(0, 22);
	this->label15->TabIndex = 36;
	// 
	// groupBox4
	// 
	this->groupBox4->Controls->Add(this->textBox12);
	this->groupBox4->Controls->Add(this->textBox11);
	this->groupBox4->Controls->Add(this->label18);
	this->groupBox4->Controls->Add(this->label17);
	this->groupBox4->Location = System::Drawing::Point(507, 61);
	this->groupBox4->Name = L"groupBox4";
	this->groupBox4->Size = System::Drawing::Size(152, 100);
	this->groupBox4->TabIndex = 38;
	this->groupBox4->TabStop = false;
	// 
	// textBox12
	// 
	this->textBox12->Location = System::Drawing::Point(32, 55);
	this->textBox12->Name = L"textBox12";
	this->textBox12->Size = System::Drawing::Size(100, 28);
	this->textBox12->TabIndex = 3;
	this->textBox12->Text = L"-";
	// 
	// textBox11
	// 
	this->textBox11->Location = System::Drawing::Point(32, 24);
	this->textBox11->Name = L"textBox11";
	this->textBox11->Size = System::Drawing::Size(100, 28);
	this->textBox11->TabIndex = 2;
	this->textBox11->Text = L"-";
	// 
	// label18
	// 
	this->label18->AutoSize = true;
	this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label18->Location = System::Drawing::Point(10, 58);
	this->label18->Name = L"label18";
	this->label18->Size = System::Drawing::Size(44, 25);
	this->label18->TabIndex = 1;
	this->label18->Text = L"y = ";
	// 
	// label17
	// 
	this->label17->AutoSize = true;
	this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label17->Location = System::Drawing::Point(10, 24);
	this->label17->Name = L"label17";
	this->label17->Size = System::Drawing::Size(44, 25);
	this->label17->TabIndex = 0;
	this->label17->Text = L"x = ";
	// 
	// menuStrip1
	// 
	this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
	this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
	this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
		this->проПрограмуToolStripMenuItem,
			this->якКористуватисяToolStripMenuItem, this->вийтиToolStripMenuItem
	});
	this->menuStrip1->Location = System::Drawing::Point(0, 0);
	this->menuStrip1->Name = L"menuStrip1";
	this->menuStrip1->Size = System::Drawing::Size(705, 33);
	this->menuStrip1->TabIndex = 39;
	this->menuStrip1->Text = L"menuStrip1";
	// 
	// проПрограмуToolStripMenuItem
	// 
	this->проПрограмуToolStripMenuItem->Name = L"проПрограмуToolStripMenuItem";
	this->проПрограмуToolStripMenuItem->Size = System::Drawing::Size(149, 29);
	this->проПрограмуToolStripMenuItem->Text = L"Про програму";
	this->проПрограмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::проПрограмуToolStripMenuItem_Click);
	// 
	// якКористуватисяToolStripMenuItem
	// 
	this->якКористуватисяToolStripMenuItem->Name = L"якКористуватисяToolStripMenuItem";
	this->якКористуватисяToolStripMenuItem->Size = System::Drawing::Size(171, 29);
	this->якКористуватисяToolStripMenuItem->Text = L"Як користуватися";
	this->якКористуватисяToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::якКористуватисяToolStripMenuItem_Click);
	// 
	// вийтиToolStripMenuItem
	// 
	this->вийтиToolStripMenuItem->Name = L"вийтиToolStripMenuItem";
	this->вийтиToolStripMenuItem->Size = System::Drawing::Size(75, 29);
	this->вийтиToolStripMenuItem->Text = L"Вийти";
	this->вийтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::вийтиToolStripMenuItem_Click);
	// 
	// label16
	// 
	this->label16->AutoSize = true;
	this->label16->Enabled = false;
	this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label16->ForeColor = System::Drawing::SystemColors::Desktop;
	this->label16->Location = System::Drawing::Point(517, 24);
	this->label16->Name = L"label16";
	this->label16->Size = System::Drawing::Size(188, 50);
	this->label16->TabIndex = 40;
	this->label16->Text = L"Оберіть початкове\r\nприближення";
	this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	// 
	// button2
	// 
	this->button2->Location = System::Drawing::Point(156, 325);
	this->button2->Name = L"button2";
	this->button2->Size = System::Drawing::Size(135, 65);
	this->button2->TabIndex = 42;
	this->button2->Text = L"Зберегти\r\nрезультат";
	this->button2->UseVisualStyleBackColor = true;
	this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
	// 
	// label19
	// 
	this->label19->AutoSize = true;
	this->label19->ForeColor = System::Drawing::SystemColors::ButtonShadow;
	this->label19->Location = System::Drawing::Point(418, 191);
	this->label19->Name = L"label19";
	this->label19->Size = System::Drawing::Size(40, 22);
	this->label19->TabIndex = 43;
	this->label19->Text = L"ε = ";
	// 
	// label20
	// 
	this->label20->AutoSize = true;
	this->label20->BackColor = System::Drawing::SystemColors::Control;
	this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->label20->ForeColor = System::Drawing::SystemColors::ButtonShadow;
	this->label20->Location = System::Drawing::Point(398, 170);
	this->label20->Name = L"label20";
	this->label20->Size = System::Drawing::Size(272, 25);
	this->label20->TabIndex = 44;
	this->label20->Text = L"Введіть точність обчислень";
	// 
	// textBox13
	// 
	this->textBox13->Location = System::Drawing::Point(442, 189);
	this->textBox13->Name = L"textBox13";
	this->textBox13->Size = System::Drawing::Size(100, 28);
	this->textBox13->TabIndex = 45;
	this->textBox13->Text = L"-";
	// 
	// MyForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->AutoScroll = true;
	this->ClientSize = System::Drawing::Size(703, 448);
	this->Controls->Add(this->textBox13);
	this->Controls->Add(this->label20);
	this->Controls->Add(this->label19);
	this->Controls->Add(this->button2);
	this->Controls->Add(this->label16);
	this->Controls->Add(this->groupBox4);
	this->Controls->Add(this->label15);
	this->Controls->Add(this->label14);
	this->Controls->Add(this->button1);
	this->Controls->Add(this->groupBox3);
	this->Controls->Add(this->groupBox2);
	this->Controls->Add(this->groupBox1);
	this->Controls->Add(this->label3);
	this->Controls->Add(this->label2);
	this->Controls->Add(this->label1);
	this->Controls->Add(this->menuStrip1);
	this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->ForeColor = System::Drawing::SystemColors::ControlText;
	this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
	this->Name = L"MyForm";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"Розв\'язання систем нелінійних рівнянь";
	this->groupBox1->ResumeLayout(false);
	this->groupBox1->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
	this->groupBox2->ResumeLayout(false);
	this->groupBox2->PerformLayout();
	this->groupBox3->ResumeLayout(false);
	this->groupBox3->PerformLayout();
	this->groupBox4->ResumeLayout(false);
	this->groupBox4->PerformLayout();
	this->menuStrip1->ResumeLayout(false);
	this->menuStrip1->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();

}

// Оброблюємо натискання на кпопку button1
System::Void Kursova::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->label15->Text = L""; // Очищуємо текст поля label15

	try
	{
		double x, y, // Початкове приближення
			eps, // Точність обчислень
			a1, b1, a2, b2, n1, n2, n3, n4, c1, c2; // Коефіцієнти системи
		this->check(x, y, eps, a1, b1, a2, b2, n1, n2, n3, n4, c1, c2); // Перевіряємо на правильність введеня дані
		system->set_epsylon(eps); // Встановлюємо точність
		vector <vector<double>> values; // Вектор точок (х, у)

		// Розв'язуємо рівняння методом Ньютона або січних
		if (this->radioButton4->Checked)
		{
			values = system->newton(x, y);
		}
		else
		{
			values = system->sichna(x, y);
		}
		this->printresult(values, x, y, eps, a1, b1, a2, b2, n1, n2, n3, n4, c1, c2); // Виводимо результат
	}
	catch (const char* e)
	{
		MessageBox::Show(gcnew System::String(e), L"Результат не знайдено", MessageBoxButtons::OK, MessageBoxIcon::Error); // Виводимо повідомлення про помилку
	}
	delete system;
	system = nullptr;
}

// Оброблюємо натискання на кпопку проПрограмуToolStripMenuItem та виводимо інформацію про програму
System::Void Kursova::MyForm::проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show(L"Програма дозволяє розв'язувати алгебраїчні, тригонометричні та трансцендентні системи рівнянь з двома змінними", L"Про програму", MessageBoxButtons::OK, MessageBoxIcon::Question);
}

// Оброблюємо натискання на кпопку якКористуватисяToolStripMenuItem та виводимо посібник користувача
System::Void Kursova::MyForm::якКористуватисяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show(L"1. Оберіть тип системи рівнянь (алгебраїчна, тригонометрична, трансцендентна)\n2. Оберіть метод розв'язування системи (метод Ньютона або січних)\n3. Задайте початкове приближення\n4. Задайте точність обчислень. ЇЇ межі: 0 < ε < 1. (Наприклад: 0,001)\n5. Задайте коефіцієнти системи рівнянь (якщо коефіцієнт відсутній, то впишіть туди \"-\")\n\nВведені числа задавайте у форматі з плаваючою комою, розділяючи чисельник та знаменник комою (Наприклад: -17,032)", L"Як користуватися", MessageBoxButtons::OK, MessageBoxIcon::Question);
}

// Оброблюємо натискання на кпопку вийтиToolStripMenuItem та закриваємо форму
System::Void Kursova::MyForm::вийтиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close(); // Закриваємо форму
}

// Оброблюємо натискання на кпопку button2 записуємо у файл результат
System::Void Kursova::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->label15->Text == L"")
	{
		MessageBox::Show(L"Поле з результатами пусте!", "Розв'язання систем нелінійних рівнянь", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else
	{
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Тектові файли (*.txt)|*.txt";
		saveFileDialog1->FilterIndex = 1;
		saveFileDialog1->RestoreDirectory = true;
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK
			&& saveFileDialog1->FileName->Length > 0)
		{
			IO::File::WriteAllText(saveFileDialog1->FileName, this->label15->Text); // Записуємо у файл текст з label15
		}
	}
}
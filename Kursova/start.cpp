#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
// ��������� ��������
void main(cli::array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Kursova::MyForm form;
    Application::Run(% form);
}
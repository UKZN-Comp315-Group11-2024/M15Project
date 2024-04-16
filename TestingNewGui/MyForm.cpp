#include "pch.h"
#include "MyForm.h"
#include "Form2.h"
#include "MyForm.h"


using namespace System;
using namespace TestingNewGui;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Form2 form2;
	Application::Run(% form2);
}

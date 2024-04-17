#include "pch.h"
#include "MyForm.h"


using namespace System;
using namespace TestingNewGui;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm form;
	Application::Run(% form);
}

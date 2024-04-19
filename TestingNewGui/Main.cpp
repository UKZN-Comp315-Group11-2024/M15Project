#include "pch.h"
#include "BootForm.h"
#include "LoginForm.h"


using namespace System;
using namespace TestingNewGui;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	BootForm form;
	Application::Run(% form);

	//LoginForm loginForm;
	//Application::Run(% loginForm);

}

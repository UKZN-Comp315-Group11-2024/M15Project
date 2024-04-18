#include "pch.h"
#include "MyForm.h"
#include "LoginForm.h"


using namespace System;
using namespace TestingNewGui;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MyForm form;
	//LoginForm^ loginForm = gcnew LoginForm();

	Application::Run(% form);
	//if (!form->userClosed)
	//{
	//	Application::Run(loginForm);
	//}

	//delete form;
	//delete loginForm;
}

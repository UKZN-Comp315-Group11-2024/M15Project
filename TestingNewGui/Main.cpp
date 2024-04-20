#include "pch.h"
#include "BootForm.h"
#include "LoginForm.h"
#include "lvl1Form.h"
#include "PlayerInfo.h"
using namespace System;
using namespace TestingNewGui;
using namespace System::Windows::Forms;


void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//BootForm form;
	//Application::Run(% form);

	//LoginForm loginForm;
	//Application::Run(% loginForm);

	lvl1Form lvl1form;
	Application::Run(% lvl1form);


}

#include "pch.h"
#include "BootForm.h"
#include "LoginForm.h"
#include "lvl1Form.h"
#include "PlayerInfo.h"
#include "popup.h"
//#include "LoadQuestion.h"
#include "Leaderboard.h"

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

	//Leaderboard leaderboard;
	//Application::Run(% leaderboard);
	//lvl1Form lvl1form;
	//Application::Run(% lvl1form);
	
	//popup P("Lorem Ipsum is simply dummy text of the printing and typesetting industry, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages.", 0, 0);
	//Application::Run(% P);




}

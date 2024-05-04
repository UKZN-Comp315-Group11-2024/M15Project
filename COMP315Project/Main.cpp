#include "pch.h"

#include "BootForm.h"
#include "LoginForm.h"
#include "TutorialForm.h"
#include "Leaderboard.h"

#include "MusicAndSFX.h"
#include "PlayerInfo.h"
#include "popup.h"
#include "LoadQuestion.h"

#include "lvl1Form.h"
#include "lvl2Form.h"
#include "lvl3Form.h"
#include "lvl4Form.h"

#include "BonusLevelOne.h"
#include "BonusLevelTwo.h"
#include "BonusLevelThree.h"
#include "BonusLevelFour.h"

using namespace System;
using namespace M15Namespace;
using namespace System::Windows::Forms;


int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//BootForm form;
	//Application::Run(% form);

	//LoginForm loginForm;
	//Application::Run(% loginForm);

	//lvl1Form lvl1form;
	//Application::Run(% lvl1form);

	//lvl2Form lvl2;
	//Application::Run(% lvl2);

	//lvl3Form lvl3;
	//Application::Run(% lvl3);

	lvl4Form lvl4;
	Application::Run(% lvl4);

	//BonusLevelOne bonusLevelOne;
	//Application::Run(% bonusLevelOne);

	//BonusLevelTwo bnt;
	//Application::Run(% bnt);

	//BonusLevelThree bonusLevelThree;
	//Application::Run(% bonusLevelThree);

	//BonusLevelFour BNTT;
	//Application::Run(% BNTT);

	//FaceRecognition fr;
	//Application::Run(% fr);

}

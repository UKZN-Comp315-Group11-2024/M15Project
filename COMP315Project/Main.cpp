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
	//PlayerInfo PlayerStats;
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//BootForm form;
	//Application::Run(% form);

	//LoginForm loginForm;
	//Application::Run(% loginForm);
	lvl1Form lvl1form;
	Application::Run(% lvl1form);

	//MusicAndSFX *m = new MusicAndSFX();
	//m->LevelOneMusic();

	//lvl1Form lvl1form;
	//Application::Run(% lvl1form);

	//Leaderboard leaderboard("yes");
	//Application::Run(% leaderboard);

	//TutorialForm tut;
	//Application::Run(% tut);
	//lvl1Form lvl1form;
	//Application::Run(% lvl1form);

	/*popup P("Lorem Ipsum is simply dummy text of the printing and typesetting industry, "
		+   "but also the leap into electronic typesetting, remaining essentially unchanged. "
		+   "It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages.", 0, 0);*/
		//Application::Run(% P);

		//BonusLevelOne bonusLevelOne;
	    //Application::Run(% bonusLevelOne);

		//BonusLevelThree bonusLevelThree;
		//Application::Run(% bonusLevelThree);


		//BonusLevelTwo bnt;
		//Application::Run(% bnt);

		//BonusLevelFour BNTT;
		//Application::Run(% BNTT);

		lvl3Form lvl3;
		Application::Run(% lvl3);

		//lvl2Form lvl2;
		//Application::Run(% lvl2);
		//lvl4Form lvl4;
		//Application::Run(% lvl4);

	//FaceRecognition fr;
	//Application::Run(% fr);

}

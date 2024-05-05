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


[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    try {
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false);

        BootForm form;
        Application::Run(% form);

        return 0;
    }
    catch (Exception^ ex) {
        // Handle any uncaught exceptions here
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return -1;
    }
}

#pragma once
//#include "PlayerInfo.h"
#include <string>
#include "LoadQuestion.h"
#include <windows.h>

//Co-Ordinates of the bullet apon collision
/*ref struct BulletInfo {

	int CoOrdX, CoOrdY;

};*/
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::Drawing;
using namespace System::IO;


public ref class LevelMethods : public System::Windows::Forms::NativeWindow
	{
	public:
		int QuestionsCompleted;  
		int QuestionsAnswered; 
		int lvlNum;
		bool DisableControls;
		int CorrectOptionInt = -1;
		bool Correct = false;
		bool AnswerGiven = true;
		bool canChange = true;
	
		System::Windows::Forms::Form^ LevelFormInstance;

		System::Windows::Forms::TextBox^ Question;
		System::Windows::Forms::TextBox^ Option1;
		System::Windows::Forms::TextBox^ Option2;
		System::Windows::Forms::TextBox^ Option3;
		System::Windows::Forms::TextBox^ Option4;
		System::Windows::Forms::TextBox^ TFOption1;
		System::Windows::Forms::TextBox^ TFOption2;

		System::Windows::Forms::PictureBox^ PlayerImage;

		System::Windows::Forms::Button^ ContinueButton;

		System::Windows::Forms::ProgressBar^ ProgressBar;
		System::Windows::Forms::Timer^ ProgressBarTimer;

		System::Windows::Forms::Panel^ Panel;

		LoadQuestion^ QuestionLoader;
		List<LoadQuestion::Question^>^ QuestionQueue;

		System::String^ QuestionType = "";
		System::String^ question = "";
		System::String^ OptionA = "";
		System::String^ OptionB = "";
		System::String^ OptionC = "";
		System::String^ OptionD = "";
		System::String^ CorrectOption = "";
		
		playerInfo^ PlayerStats;

		//LevelMethods(Form^ form, int lvlNum);
		LevelMethods(int lvlno);

		//void TransitionIn();

		//void SetTransLabel(String^ label, Control^ item);

		//void ShuffelQuestionSets();

		void ExtractQuestionSet();

		void DisplayNextQuestionSet();

		// call this method if a question has been answered, so call this function when you detect a bullet collision with an answer's hit box
		//increments QuestionsAnswered
		//calls ProcessAnswer();
		//if(T/F){} else{}
		void QuestionAnswered(int option);

		void QuestionCompleted();

		//Determins which answer was selected by the player
		//needs to take in x and y co ordinate of bullet
		//determines if the answer selected was correct
		//void ProcessingAnswer();

		//returns true if they match
		//bool CheckAnswerCorrect(System::String^ AnswerSelected, System::String^ CorrectAnswer);

		void SetQuestionComponents(System::Windows::Forms::TextBox^ lblQuestion, System::Windows::Forms::TextBox^ lblOption1, System::Windows::Forms::TextBox^ lblOption2, System::Windows::Forms::TextBox^ lblOption3, System::Windows::Forms::TextBox^ lblOption4, System::Windows::Forms::TextBox^ lblTFOption1, System::Windows::Forms::TextBox^ lblTFOption2);

		void SetPlayerComponent(System::Windows::Forms::PictureBox^ plyr);

		void SetProgressBarComponent(System::Windows::Forms::ProgressBar^ PB);
		void SetProgressBarTimerComponent(System::Windows::Forms::Timer^ PBtmr);

		void SetPanelComponant(System::Windows::Forms::Panel^ Pnl);

		void SetLevelFormInstance(System::Windows::Forms::Form^ lvlFrmInst);

		void SetButtonComponenets(System::Windows::Forms::Button^ btn);

		//void ResetLoadingBar();

		void ResetPlayerPos();

		void calculateTime();

		//check if 10 questions have been answered, if so call end of level
		bool CheckLevelEnd();

		//end the level
		void EndLevel();

		void RecordPlayerStats();

		void DetermCorrectOptionInt();
	};
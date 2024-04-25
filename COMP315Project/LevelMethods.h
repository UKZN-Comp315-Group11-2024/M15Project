#pragma once
#include"PlayerInfo.h"
#include<string>
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

public ref class LevelMethods : public System::Windows::Forms::NativeWindow
	{
	public:
		int QuestionsCompleted;
		int QuestionsAnswered;
		int CorrectAnswers;
		int Time;
		int lvlNum;
		//bool DisplayNextQuestionSet;
	
		System::Windows::Forms::Form^ LevelFormInstance;

		System::Windows::Forms::Label^ Question;
		System::Windows::Forms::Label^ Option1;
		System::Windows::Forms::Label^ Option2;
		System::Windows::Forms::Label^ Option3;
		System::Windows::Forms::Label^ Option4;
		System::Windows::Forms::Label^ TFOption1;
		System::Windows::Forms::Label^ TFOption2;

		System::Windows::Forms::PictureBox^ PlayerImage;

		System::Windows::Forms::Timer^ ProgressBarTimer;

		System::Windows::Forms::Panel^ Panel;

		LoadQuestion^ QuestionLoader;
		Queue<LoadQuestion::Question^>^ QuestionQueue;

		System::String^ QuestionType = "";
		System::String^ question = "";
		System::String^ OptionA = "";
		System::String^ OptionB = "";
		System::String^ OptionC = "";
		System::String^ OptionD = "";
		System::String^ CorrectOption = "";
		
		//PlayerInfo PlayerStats;

		//LevelMethods(Form^ form, int lvlNum);
		LevelMethods(int lvlno);

		//void TransitionIn();

		//void SetTransLabel(String^ label, Control^ item);

		void ShuffelQuestionSets();

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

		void SetQuestionComponents(System::Windows::Forms::Label^ lblQuestion, System::Windows::Forms::Label^ lblOption1, System::Windows::Forms::Label^ lblOption2, System::Windows::Forms::Label^ lblOption3, System::Windows::Forms::Label^ lblOption4, System::Windows::Forms::Label^ lblTFOption1, System::Windows::Forms::Label^ lblTFOption2, int lvlNumber);

		void SetPlayerComponent(System::Windows::Forms::PictureBox^ plyr);

		void SetLoadingBarComponent(System::Windows::Forms::Timer^ PBtmr);

		void SetPanelComponant(System::Windows::Forms::Panel^ Pnl);

		void SetLevelFormInstance(System::Windows::Forms::Form^ lvlFrmInst);

		//void ResetLoadingBar();

		void ResetPlayerPos();

		void calculateTime();

		//check if 10 questions have been answered, if so call end of level
		bool CheckLevelEnd();

		//end the level
		void EndLevel();
	};
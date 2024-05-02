#pragma once
#include "LoadQuestion.h"
#include <windows.h>

public ref class LevelMethods 
{
public:
	//Question tracking variables
	int QuestionsCompleted;
	int QuestionsAnswered;
	int CorrectOptionInt = -1;
	
	//Number representing the level
	int lvlNum;
	
	//Set true to disable player input
	bool DisableControls;
	
	//determines wether to increment CorrectOptionInt or not
	bool Correct = false;

	//Label handles 
	System::Windows::Forms::Label^ Question;
	System::Windows::Forms::Label^ Option1;
	System::Windows::Forms::Label^ Option2;
	System::Windows::Forms::Label^ Option3;
	System::Windows::Forms::Label^ Option4;
	System::Windows::Forms::Label^ TFOption1;
	System::Windows::Forms::Label^ TFOption2;

	//Progress bar and its timer handles
	System::Windows::Forms::ProgressBar^ ProgressBar;
	System::Windows::Forms::Timer^ ProgressBarTimer;

	//List storing Question struct objects
	List<LoadQuestion::Question^>^ QuestionList;

	//Strings containing the question and its options
	System::String^ QuestionType = "";
	System::String^ question = "";
	System::String^ OptionA = "";
	System::String^ OptionB = "";
	System::String^ OptionC = "";
	System::String^ OptionD = "";
	System::String^ CorrectOption = "";

	//Instance of a struct used to track player statistics during a level
	playerInfo^ PlayerStats;

	//constructor
	LevelMethods(int lvlno);

	//Methods for displaying questions
	void DisplayNextQuestionSet();
	void ExtractQuestionSet();
	void DetermCorrectOptionInt();
	
	//Methods for handeling when a question is answered 
	void QuestionAnswered(int option);
	void QuestionCompleted();

	//Sets variouse components that need to be accessed from LevelMethods
	void SetQuestionComponents(System::Windows::Forms::Label^ lblQuestion, System::Windows::Forms::Label^ lblOption1, System::Windows::Forms::Label^ lblOption2, System::Windows::Forms::Label^ lblOption3, System::Windows::Forms::Label^ lblOption4, System::Windows::Forms::Label^ lblTFOption1, System::Windows::Forms::Label^ lblTFOption2);
	void SetProgressBarComponent(System::Windows::Forms::ProgressBar^ PB);
	void SetProgressBarTimerComponent(System::Windows::Forms::Timer^ PBtmr);

};
#pragma once
//#include <Windows.ui.xaml.h>
#include"PlayerInfo.h"
#include<string>
#include "LoadQuestion.h"
#include"lvl1Form.h"

//using namespace M15Namespace;
//using namespace std;

//using namespace Windows::UI::Xaml;

//Co-Ordinates of the bullet apon collision
/*ref struct BulletInfo {

	int CoOrdX, CoOrdY;

};*/
//namespace M15Namespace {
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

	public ref class LevelMethods
	{
	public:
		int QuestionsAnswered;
		int CorrectAnswers;
		//bool DisplayNextQuestionSet;
		Form^ LevelFormInstance;
		int lvlNum;
		//LoadQuestion^ QuestionLoader;
		//PlayerInfo plyr;

		//LevelMethods(Form^ form, int lvlNum);

		// call this method if a question has been answered, so call this function when you detect a bullet collision with an answer's hit box
		//increments QuestionsAnswered
		// 
		//calls ProcessAnswer();
		//if(T/F){} else{}
		//void QuestionAnswered();

		//Determins which answer was selected by the player
		//needs to take in x and y co ordinate of bullet
		//calls a function to determine if the answer selected was correct
		//void ProcessingAnswer();

		//returns true if they match
		//bool CheckAnswerCorrect(System::String^ AnswerSelected, System::String^ CorrectAnswer);

		//if answer was correct, call correct answer method
		//increment CorrectAnswers
		//set DisplayNextQuestionSet to true and/or call DisplayNextQuestionSet
		//Display message telling the player it was correct
		//void CorrectAnswer();

		//if the answer was incorrect
		//set DisplayNextQuestionSet to true and/or call DisplayNextQuestionSet
		//Display message telling the player it was wrong
		//void IncorrectAnswer();

		//calls LoadQuestion function to get the next question set
		//specifically records the correct answer as a variable CorrectAnswer for thee use of CheckAnswerCorrect()
		//first checks if the level is over : if(QuestionsAnswered == 10){ EndLevel() } else { actual method}
		//void DisplayNextQuestionSet();
		// add answers score to total

		//check if 10 questions have been answered, if so call end of level

		//end the level
	};


//}


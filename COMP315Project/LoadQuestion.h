#pragma once     //ORIGINAL
#include "pch.h"
#include "customAlgs.h"

using namespace System;
using namespace System::IO;

public ref class LoadQuestion {
public:

	//constructer
	LoadQuestion(int levelNum);
	
	//struct for storing question sets
	ref struct Question {
		String^ QuestionType = "- 1";
		String^ question = "";
		String^ OptionA = "";
		String^ OptionB = "";
		String^ OptionC = "";
		String^ OptionD = "";
		String^ CorrectOption = "";

	};

	int levelNum = 0;

	// stores the 10 questions for the current level, ready to be displayed
	List<Question^>^ levelQuestions = gcnew List<Question^>;
	
	//pre-rendomization data structures containing questions:
	System::Collections::Generic::Queue<Question^>^ QuestionQueue = gcnew System::Collections::Generic::Queue<Question^>;
	List<Question^>^ tfQuestions = gcnew List<Question^>;
	List<Question^>^ mcqQuestions = gcnew List<Question^>;
	
	//used to randomize questions :
	//temp vector, just to combine into main question vector(levelQuestions)
	List<Question^>^ tempTFvector = gcnew List<Question^>;
	//List(vector) stores options to be shuffled
	List<String^>^ optionsShuffle = gcnew List<String^>;

	//used for debugging:
	System::Collections::Generic::Queue<Question^>^ displayQuestions = gcnew System::Collections::Generic::Queue<Question^>;
	void printQuestions();

};
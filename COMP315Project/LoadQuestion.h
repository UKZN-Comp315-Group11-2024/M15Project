#pragma once     //ORIGINAL
#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <string>
#include "customAlgs.h"

using namespace System;
using namespace System::Collections::Generic;

//@Daniel: had to convert this class to ref class and place it in the two name spaces below otherwise this class cant be used.
//Cant have a non-managed member of a managed class. That means you cant create an instance of LoadQuestion in ref classes and all forms are ref classes
//also had to place this class in the two name spaces below because the compiler cant find the class otherwise
	public ref class LoadQuestion {   // outer class
	public:
		LoadQuestion(int levelNum);
		ref struct Question { // inner struct
			//@Daniel: replaced std::string with System::String^
			System::String^ QuestionType = "- 1";
			System::String^ question = "";
			System::String^ OptionA = "";
			System::String^ OptionB = "";
			System::String^ OptionC = "";
			System::String^ OptionD = "";
			System::String^ CorrectOption = "";

		};
		//@Daniel: swapped std::queue<Question> for managed class version
		System::Collections::Generic::Queue<Question^>^ QuestionQueue = gcnew System::Collections::Generic::Queue<Question^>;
		List<Question^>^ tfQuestions = gcnew List<Question^>;
		List<Question^>^ mcqQuestions = gcnew List<Question^>;
		//temp vector, just to combine into main question vector(levelQuestions)
		List<Question^>^ tempTFvector = gcnew List<Question^>;
		// stores the 10 questions for the current level
		List<Question^>^ levelQuestions = gcnew List<Question^>;
		//Queue
		System::Collections::Generic::Queue<Question^>^ displayQuestions = gcnew System::Collections::Generic::Queue<Question^>;
		//vector stores options to be shuffled
		List<System::String^>^ optionsShuffle = gcnew List<System::String^>;
		int levelNum = 0;

		void printQuestions();

	};
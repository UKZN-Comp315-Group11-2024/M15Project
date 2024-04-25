/*#pragma once     //ORIGINAL
#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <cstdlib>
#include <queue>


class LoadQuestion {   // outer class
public:
	LoadQuestion(int levelNum);
	~LoadQuestion();



	struct Question { // inner struct


		std::string QuestionType = "";
		std::string question = "";
		std::string OptionA = "";
		std::string OptionB = "";
		std::string OptionC = "";
		std::string OptionD = "";
		std::string CorrectOption = "";



	};

private:
	std::queue<Question> QuestionQueue;


};*/
#pragma once     //ORIGINAL
#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <string>

//@Daniel: had to convert this class to ref class and place it in the two name spaces below otherwise this class cant be used.
//Cant have a non-managed member of a managed class. That means you cant create an instance of LoadQuestion in ref classes and all forms are ref classes
//also had to place this class in the two name spaces below because the compiler cant find the class otherwise
	ref class LoadQuestion {   // outer class
	public:
		LoadQuestion(int levelNum);
		//~LoadQuestion();



		ref struct Question { // inner struct

			//@Daniel: replaced std::string with System::String^

			System::String^ QuestionType = "";
			System::String^ question = "";
			System::String^ OptionA = "";
			System::String^ OptionB = "";
			System::String^ OptionC = "";
			System::String^ OptionD = "";
			System::String^ CorrectOption = "";






		};

		//private:
			//@Daniel: swapped std::queue<Question> for managed class version
			//std::queue<Question> QuestionQueue;
			//System::Collections::Generic::Queue <Question^>  QuestionQueue;
		System::Collections::Generic::Queue<Question^>^ QuestionQueue;

	};
// our code

/*#pragma once     //ORIGINAL
#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <cstdlib>
#include <queue>
//#include <stack>



	ref class LoadQuestion {   // outer class
	public:
		LoadQuestion(int levelNum);
		~LoadQuestion();

		ref struct Question { // inner struct


			System::String^ QuestionType = "";
			System::String^ question = "";
			System::String^ OptionA = "";
			System::String^ OptionB = "";
			System::String^ OptionC = "";
			System::String^ OptionD = "";
			System::String^ CorrectOption = "";

		};

	private:
		//std::queue<Question> QuestionQueue;
		std::vector<Question> QuestionStack;
		//vectors to store Questions type, Elements: mcq = 16, tf = 4
		std::vector<Question> tfQuestions;
		std::vector<Question> mcqQuestions;
		//temp vector, just to combine into main question vector(levelQuestions)
		std::vector<Question> tempTFvector;
		// stores the 10 questions for the current level
		std::vector<Question> levelQuestions;
		//Queue
		std::queue<Question> displayQuestions;
		//vector stores options to be shuffled
		std::vector<std::string> optionsShuffle;

	};
	*/
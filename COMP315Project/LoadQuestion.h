#pragma once     //ORIGINAL
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


};
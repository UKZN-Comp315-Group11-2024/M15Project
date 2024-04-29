#include "pch.h"      //ORIGINAL
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "customAlgs.h"
#include "LoadQuestion.h"

//Source Code: @Vashin, @Archan
//De-Standardizing: @Daniel
//Debugging: @Jaedon

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

LoadQuestion::LoadQuestion(int levelNum) {
    customAlgs<System::String^>::srandom();

    this->levelNum = levelNum;
	System::String^ LevelFile = "textfiles\\level" + levelNum + "QuestionBank.txt";
	System::IO::StreamReader^ myfile = gcnew System::IO::StreamReader(LevelFile);
	System::String^ sline;

    while ((sline = myfile->ReadLine()) != nullptr) {
        int pos = sline->IndexOf("$");
        if (pos == 1) {         //only do all this if it's actually a question and not some other line in the textfile
            Question^ currentQuestion = gcnew Question;
            currentQuestion->QuestionType = sline->Substring(0, pos);
            sline = sline->Remove(0, pos + 1);
            if (currentQuestion->QuestionType == "0") {
                pos = sline->IndexOf('$');
                currentQuestion->question = sline->Substring(0, pos);   // stores the question
                sline = sline->Remove(0, pos + 1); // erase(0, pos + 1) equivalent

                pos = sline->IndexOf('$');
                currentQuestion->CorrectOption = sline->Substring(0, pos);  // stores option A
                currentQuestion->OptionA = sline->Substring(0, pos);
                sline = sline->Remove(0, pos + 1); // erase(0, pos + 1) equivalent

                pos = sline->IndexOf('$');
                currentQuestion->OptionB = sline->Substring(0, pos);  // stores option B
                sline = sline->Remove(0, pos + 1); // erase(0, pos + 1) equivalent

                pos = sline->IndexOf('$');
                currentQuestion->OptionC = sline->Substring(0, pos); // stores option C
                sline = sline->Remove(0, pos + 1); // erase(0, pos + 1) equivalent

                //The remaining bit is the last option, pos would be -1 here, gives an error when doing substring with negative length
                //pos = sline->IndexOf('$');
                currentQuestion->OptionD = sline;  // stores option D
                
                mcqQuestions->Add(currentQuestion);

                optionsShuffle->Clear();
                optionsShuffle->Add(currentQuestion->OptionA);
                optionsShuffle->Add(currentQuestion->OptionB);
                optionsShuffle->Add(currentQuestion->OptionC);
                optionsShuffle->Add(currentQuestion->OptionD);

                optionsShuffle = customAlgs<System::String^>::shuffle(optionsShuffle);

                currentQuestion->OptionA = optionsShuffle[0];
                currentQuestion->OptionB = optionsShuffle[1];
                currentQuestion->OptionC = optionsShuffle[2];
                currentQuestion->OptionD = optionsShuffle[3];
                
            }
            else {
                pos = sline->IndexOf('$');
                currentQuestion->question = sline->Substring(0, pos);   // stores the question
                sline = sline->Remove(0, pos + 1); // erase(0, pos + 1) equivalent

                pos = sline->IndexOf('$');
                currentQuestion->CorrectOption = sline->Substring(0, pos);  // stores option A
                currentQuestion->OptionA = sline->Substring(0, pos);
                sline = sline->Remove(0, pos + 1); // erase(0, pos + 1) equivalent

                //The remaining bit is the last option, pos would be -1 here, gives an error when doing subtring with negative length
                //pos = sline->IndexOf('$');
                currentQuestion->OptionB = sline;  // stores option B

                //storing into Vector
                tfQuestions->Add(currentQuestion);

                //Shuffling Options T&F
                optionsShuffle->Clear();
                optionsShuffle->Add(currentQuestion->OptionA);
                optionsShuffle->Add(currentQuestion->OptionB);

                optionsShuffle = customAlgs<System::String^>::shuffle(optionsShuffle);
                currentQuestion->OptionA = optionsShuffle[0];
                currentQuestion->OptionB = optionsShuffle[1];
            }

            this->QuestionQueue->Enqueue(currentQuestion);
           
        }      
    }

    myfile->Close();

    levelQuestions = customAlgs<Question^>::chooseRandomMfromN(mcqQuestions, 8);
    tempTFvector = customAlgs<Question^>::chooseRandomMfromN(tfQuestions, 2);

    //Randomized Questions are now Combined
    levelQuestions->AddRange(tempTFvector);

    for each (Question ^ q in levelQuestions) {
        displayQuestions->Enqueue(q);
    }

    printQuestions();
}

//@Jaedon: method that's useful for debugging
void LoadQuestion::printQuestions() {
    std::cout << "LEVEL " << levelNum << " QUESTIONS: " << "\n\n";
    for each (Question ^ q in displayQuestions) {
        msclr::interop::marshal_context context;
        std::string stdString = "QUESTION: " + context.marshal_as<std::string>(q->question) + "\n";
        stdString += "OPTIONS: " + context.marshal_as<std::string>(q->OptionA) + "\n";
        stdString += context.marshal_as<std::string>(q->OptionB) + "\n";
        stdString += context.marshal_as<std::string>(q->OptionC) + "\n";
        stdString += context.marshal_as<std::string>(q->OptionD) + "\n";
        stdString += "CORRECT OPTION: " + context.marshal_as<std::string>(q->CorrectOption) + "\n";
        std::cout << stdString << "\n\n";
    }
    
}

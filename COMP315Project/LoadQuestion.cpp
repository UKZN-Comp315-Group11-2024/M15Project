/*#include "pch.h"      //ORIGINAL
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "LoadQuestion.h"
using namespace std;

LoadQuestion::LoadQuestion(int levelNum) {

    std::queue<Question> QuestionQueue;

    std::string LevelFile = "level" + std::to_string(levelNum) + "QuestionBank.txt"; // textfile name
   // string LevelFile = "level3QuestionBank.txt"; //selects approprate question depending on the level

    fstream myfile;

    myfile.open(LevelFile, ios::in);
    if (myfile.is_open()) {
        std::string sline;
        while (getline(myfile, sline)) { //goes through each line

            LoadQuestion::Question currentQuestion; //creates object  
            //addQuestion.QuestionType = 0;

            //size_t alias for unsigned long long, used for positive indexes
            size_t pos = sline.find("$");
            // cout << sline + \n;

            currentQuestion.QuestionType = sline.substr(0, pos); // string to int

            sline.erase(0, 2);


            ////instantiates class depending on question type  
            if (currentQuestion.QuestionType == "0") // MCQ
            {

                pos = sline.find('$');
                currentQuestion.question = sline.substr(0, pos);   // stores the question
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                currentQuestion.CorrectOption = sline.substr(0, pos);  // stores option A
                currentQuestion.OptionA = sline.substr(0, pos);
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                currentQuestion.OptionB = sline.substr(0, pos);  // stores option B
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                currentQuestion.OptionC = sline.substr(0, pos); // stores option C
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                currentQuestion.OptionD = sline.substr(0, pos);  // stores option D
                sline.erase(0, pos + 1);

            }
            else if (currentQuestion.QuestionType == "1") { // T&F
                pos = sline.find('$');
                currentQuestion.question = sline.substr(0, pos);   // stores the question
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                currentQuestion.CorrectOption = sline.substr(0, pos);  // stores option A
                currentQuestion.OptionA = sline.substr(0, pos);
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                currentQuestion.OptionB = sline.substr(0, pos);  // stores option B
                sline.erase(0, pos + 1);
            }
            else
            {
                cout << "Unkown Question type";
            }

            QuestionQueue.push(currentQuestion); // adds "addQuestion" to the queue
            std::cout << QuestionQueue.front().question << endl;


        }

    }
    myfile.close();

}*/
#include "pch.h"      //ORIGINAL
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "LoadQuestion.h"
//where ever you see an @Daniel is where I replaced std methods with .Net versions
//using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
//using namespace M15Namespace;

LoadQuestion::LoadQuestion(int levelNum) {

    //@Daniel: std::queue<Question> QuestionQueue;
    QuestionQueue = gcnew Queue<Question^>();
    System::String^ LevelFile = "level" + levelNum + "QuestionBank.txt";
    //std::string LevelFile = "level" + std::to_string(levelNum) + "QuestionBank.txt"; // textfile name
    // string LevelFile = "level3QuestionBank.txt"; //selects approprate question depending on the level

    //@Daniel: fstream myfile;
    System::IO::StreamReader^ myfile = gcnew System::IO::StreamReader(LevelFile);

    //myfile.open(LevelFile, ios::in);
     //if (myfile.is_open()) {
         //@Daniel: replaced std::string with managed equivalent for declaration of sline 
    System::String^ sline;
    //@Daniel: replaced while (getline(myfile, sline)) with managed equivalent also added stream reader declaration
    while ((sline = myfile->ReadLine()) != nullptr) { //goes through each line
        
        LoadQuestion::Question^ currentQuestion; //creates object  
        //addQuestion.QuestionType = 0;

        //size_t alias for unsigned long long, used for positive indexes
        //@Daniel:  replaced size_t pos = sline.find("$"); with managed version              
        int pos = sline->IndexOf("$");
        // cout << sline + \n;

        


        //@Daniel: replaced sline.erase(0, 2);
        
        if (pos == 1) {
            //@Daniel replaced sline.substr(0, pos)
            currentQuestion->QuestionType = sline->Substring(0, pos); // string to int
            sline = sline->Remove(0, 2);
            ////instantiates class depending on question type  
            if (currentQuestion->QuestionType == "0") // MCQ
            {

                /* pos = sline.find('$');
                 currentQuestion.question = sline.substr(0, pos);   // stores the question
                 sline.erase(0, pos + 1);

                 pos = sline.find('$');
                 currentQuestion.CorrectOption = sline.substr(0, pos);  // stores option A
                 currentQuestion.OptionA = sline.substr(0, pos);
                 sline.erase(0, pos + 1);

                 pos = sline.find('$');
                 currentQuestion.OptionB = sline.substr(0, pos);  // stores option B
                 sline.erase(0, pos + 1);

                 pos = sline.find('$');
                 currentQuestion.OptionC = sline.substr(0, pos); // stores option C
                 sline.erase(0, pos + 1);

                 pos = sline.find('$');
                 currentQuestion.OptionD = sline.substr(0, pos);  // stores option D
                 sline.erase(0, pos + 1);
                 */

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

                pos = sline->IndexOf('$');
                currentQuestion->OptionD = sline->Substring(0, pos);  // stores option D

            }
            else if (currentQuestion->QuestionType == "1") { // T&F
                /*pos = sline.find('$');
                currentQuestion.question = sline.substr(0, pos);   // stores the question
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                currentQuestion.CorrectOption = sline.substr(0, pos);  // stores option A
                currentQuestion.OptionA = sline.substr(0, pos);
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                currentQuestion.OptionB = sline.substr(0, pos);  // stores option B
                sline.erase(0, pos + 1);
                */

                pos = sline->IndexOf('$');
                currentQuestion->question = sline->Substring(0, pos);   // stores the question
                sline = sline->Remove(0, pos + 1); // erase(0, pos + 1) equivalent

                pos = sline->IndexOf('$');
                currentQuestion->CorrectOption = sline->Substring(0, pos);  // stores option A
                currentQuestion->OptionA = sline->Substring(0, pos);
                sline = sline->Remove(0, pos + 1); // erase(0, pos + 1) equivalent

                pos = sline->IndexOf('$');
                currentQuestion->OptionB = sline->Substring(0, pos);  // stores option B
            }
            else
            {
                // cout << "Unkown Question type";
            }

            //QuestionQueue.push(currentQuestion); // adds "addQuestion" to the queue
            //std::cout << QuestionQueue.front().question << endl;
            QuestionQueue->Enqueue(currentQuestion);
        }
    }

    //}
    //@Daniel: myfile.close();
    myfile->Close();
}

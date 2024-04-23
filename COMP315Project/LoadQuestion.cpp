#include "pch.h"      //ORIGINAL
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "LoadQuestion.h"
using namespace std;

LoadQuestion::LoadQuestion() {


    std::queue<Question> QuestionQueue;
    string LevelFile = "level3QuestionBank.txt"; //selects approprate question depending on the level



    fstream myfile;

    myfile.open(LevelFile, ios::in);
    if (myfile.is_open()) {
        std::string sline;
        while (getline(myfile, sline)) { //goes through each line

            LoadQuestion::Question currentQuestion; //creates object  
            //addQuestion.QuestionType = 0;

            int pos = sline.find("$");
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

}

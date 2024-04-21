#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "LoadQuestion.h"
using namespace std;

//@Vashin@Archan@Avesh 
LoadQuestion::LoadQuestion() {


    std::queue<Question> QuestionQueue;
    string LevelFile = "level3QuestionBank.txt"; //selects approprate question depending on the level

    //std::string textfileName = "level" + std::to_string(levelNum) + "QuestionBank.txt"; // textfile 


    fstream myfile;

    myfile.open(LevelFile, ios::in);
    if (myfile.is_open()) {
        std::string sline;
        while (getline(myfile, sline)) { //goes through each line

            LoadQuestion::Question addQuestion; //creates object  
            //addQuestion.QuestionType = 0;

            int pos = sline.find("$");
            // cout << sline + \n;

            addQuestion.QuestionType = sline.substr(0, pos); // string to int

            sline.erase(0, 2);


            ////instantiates class depending on question type  
            if (addQuestion.QuestionType == "0") // MCQ
            {

                pos = sline.find('$');
                addQuestion.question = sline.substr(0, pos);   // stores the question
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                addQuestion.CorrectOption = sline.substr(0, pos);  // stores option A
                addQuestion.OptionA = sline.substr(0, pos);
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                addQuestion.OptionB = sline.substr(0, pos);  // stores option B
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                addQuestion.OptionC = sline.substr(0, pos); // stores option C
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                addQuestion.OptionD = sline.substr(0, pos);  // stores option D
                sline.erase(0, pos + 1);

            }
            else if (addQuestion.QuestionType == "1") { // T&F
                pos = sline.find('$');
                addQuestion.question = sline.substr(0, pos);   // stores the question
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                addQuestion.CorrectOption = sline.substr(0, pos);  // stores option A
                addQuestion.OptionA = sline.substr(0, pos);
                sline.erase(0, pos + 1);

                pos = sline.find('$');
                addQuestion.OptionB = sline.substr(0, pos);  // stores option B
                sline.erase(0, pos + 1);
            }
            else
            {
                cout << "Unkown Question type";
            }

            QuestionQueue.push(addQuestion); // adds "addQuestion" to the queue
            std::cout << QuestionQueue.front().question << endl;


        }

    }
    myfile.close();

}
  








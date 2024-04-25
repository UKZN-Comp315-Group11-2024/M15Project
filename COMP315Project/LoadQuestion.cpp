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

        LoadQuestion::Question^ currentQuestion = gcnew Question; //creates object  
        //addQuestion.QuestionType = 0;

        //size_t alias for unsigned long long, used for positive indexes
        //@Daniel:  replaced size_t pos = sline.find("$"); with managed version              
        int pos = sline->IndexOf("$");
        // cout << sline + \n;

        


        //@Daniel: replaced sline.erase(0, 2);
        
        if (pos == 1) {
            //@Daniel replaced sline.substr(0, pos)
            msclr::interop::marshal_context context;
            std::string stdString = context.marshal_as<std::string>(sline);
            std::cout << stdString<<" ";
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




// our code



/*
#include "pch.h"      //ORIGINAL
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
    //#include <stack>;
#include "customAlgs.h"
#include "LoadQuestion.h"
    using namespace std;

    LoadQuestion::LoadQuestion(int levelNum) {

        std::queue<Question> QuestionQueue;

        std::string LevelFile = "level" + std::to_string(levelNum) + "QuestionBank.txt"; // textfile name

        fstream myfile;

        myfile.open(LevelFile, ios::in);
        if (myfile.is_open()) {
            std::string sline;
            while (getline(myfile, sline)) { //goes through each line

                LoadQuestion::Question currentQuestion; //creates object

                //size_t alias for unsigned long long, used for positive indexes
                size_t pos = sline.find("$");

                currentQuestion.QuestionType = sline.substr(0, pos); // string to int

                sline.erase(0, 2);
                ////instantiates class depending on question type
                if (currentQuestion.QuestionType == "0") // MCQ
                {

                    pos = sline.find('$');
                    currentQuestion.question = sline.substr(0, pos);   // stores the question
                    sline.erase(0, pos + 1);

                    pos = sline.find('$');
                    currentQuestion.CorrectOption = sline.substr(0, pos);  // stores option correct option
                    currentQuestion.OptionA = sline.substr(0, pos); //stores option A
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

                    mcqQuestions.push_back(currentQuestion);  //storing MCQ Question


                    //code to shuffle options


                    optionsShuffle.push_back(currentQuestion.OptionA);
                    optionsShuffle.push_back(currentQuestion.OptionB);
                    optionsShuffle.push_back(currentQuestion.OptionC);
                    optionsShuffle.push_back(currentQuestion.OptionD);

                    vector <string> optionsShuffle = customAlgs<std::string>::shuffle(optionsShuffle);

                    currentQuestion.OptionA = optionsShuffle[0];
                    currentQuestion.OptionB = optionsShuffle[1];
                    currentQuestion.OptionC = optionsShuffle[2];
                    currentQuestion.OptionD = optionsShuffle[3];

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

                    tfQuestions.push_back(currentQuestion);


                    optionsShuffle.push_back(currentQuestion.OptionA);
                    optionsShuffle.push_back(currentQuestion.OptionB);

                    vector <string> optionsShuffle = customAlgs<std::string>::shuffle(optionsShuffle);

                    currentQuestion.OptionA = optionsShuffle[0];
                    currentQuestion.OptionB = optionsShuffle[1];

                }
                else
                {
                    cout << "Unkown Question type";
                }
                QuestionStack.push_back(currentQuestion);  // populating stack with questions
                //QuestionQueue.push(currentQuestion); // adds "addQuestion" to the queue
                //std::cout << QuestionQueue.front().question << endl;  //need to change this to a stack
            }

        }
        myfile.close();

        std::vector<Question> levelQuestions = customAlgs<Question>::chooseRandomMfromN(mcqQuestions, 16);
        std::vector<Question> tempTFvector = customAlgs<Question>::chooseRandomMfromN(tfQuestions, 4);

        //Randomized Questions are now combined
        levelQuestions.insert(levelQuestions.end(), tempTFvector.begin(), tempTFvector.end());
        std::cout << levelQuestions.front().question << endl;  //final question

        for (int i = 0; i < levelQuestions.size(); i++) {
            displayQuestions.push(levelQuestions.at(i));
        }

    }*/
#pragma once
#include <iostream>
#include <string>

//include opencv core
#include "opencv2/core/core.hpp"
#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/opencv.hpp"
#include <direct.h>

//file handling
#include <fstream>
#include <sstream>


/* Original source code from : https://github.com/ssj-ali/Face-Detection-Recognition/blob/master/Project1c%2B%2B/main.cpp */
/*Adapted: The original file was console based. Additionally, it was only able to identify a user based on a number.
Also, it would infinite loop since that was the only thing in the program. All of these have been changed to fit this project.
The program is now graphical, can identify the user based on their username, and will count the user as successfully recognized when
the model has had over 1000 confidence that the user is some fixed existing user, for at least 3 seconds. At this point, the loop will break.
Thereafter, functionality was added to return to the original form. The object oriented functionality was also added.*/


class facerec {
public:
	cv::CascadeClassifier face_cascade;
	std::string filename;
	std::string name;
	int filenumber = 0;

	void detectAndDisplay(cv::Mat frame);
	int addFace(std::string s);
	void dbread(std::vector<cv::Mat>& images, std::vector<int>& labels);
	void eigenFaceTrainer();
	std::string FaceRecognitionNew();
	std::string facerec::InttoName(int num);
};


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


class facerec {
public:
	cv::CascadeClassifier face_cascade;
	std::string filename;
	std::string name;
	int filenumber = 0;

	void detectAndDisplay(cv::Mat frame);
	void addFace();
	void dbread(std::vector<cv::Mat>& images, std::vector<int>& labels);
	void eigenFaceTrainer();
	void  FaceRecognitionNew();
		
};


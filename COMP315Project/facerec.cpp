#include "pch.h"
#include <iostream>
#include <string>

#include "opencv2/core/core.hpp"
#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/opencv.hpp"
#include<direct.h>

#include <fstream>
#include <sstream>
#include <chrono>

#include "facerec.h"
#include "FaceRecognition.h"

/*Original source code from: https://github.com/ssj-ali/Face-Detection-Recognition/blob/master/Project1c%2B%2B/main.cpp */
/*Adapted: The original file was console based. Additionally, it was only able to identify a user based on a number.
Also, it would infinite loop since that was the only thing in the program. All of these have been changed to fit this project.
The program is now graphical, can identify the user based on their username, and will count the user as successfully recognized when
the model has had over 1000 confidence that the user is some fixed existing user, for at least 3 seconds. At this point, the loop will break.
Thereafter, functionality was added to return to the original form*/

void facerec::detectAndDisplay(cv::Mat frame)
{
	std::vector<cv::Rect> faces;
	cv::Mat frame_gray;
	cv::Mat crop;
	cv::Mat res;
	cv::Mat gray;
	std::string text;
	std::stringstream sstm;

	cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

	cv::Rect roi_b;
	cv::Rect roi_c;

	size_t ic = 0;
	int ac = 0;

	size_t ib = 0;
	int ab = 0;

	for (ic = 0; ic < faces.size(); ic++)

	{
		roi_c.x = faces[ic].x;
		roi_c.y = faces[ic].y;
		roi_c.width = (faces[ic].width);
		roi_c.height = (faces[ic].height);

		ac = roi_c.width * roi_c.height;

		roi_b.x = faces[ib].x;
		roi_b.y = faces[ib].y;
		roi_b.width = (faces[ib].width);
		roi_b.height = (faces[ib].height);


		crop = frame(roi_b);
		resize(crop, res, cv::Size(128, 128), 0, 0, cv::INTER_LINEAR);
		cvtColor(crop, gray, cv::COLOR_BGR2GRAY);
		std::stringstream ssfn;
		filename = "Faces\\";
		ssfn << filename.c_str() << name << filenumber << ".jpg";
		filename = ssfn.str();
		imwrite(filename, res);
		filenumber++;


		cv::Point pt1(faces[ic].x, faces[ic].y);
		cv::Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
		rectangle(frame, pt1, pt2, cv::Scalar(0, 255, 0), 2, 8, 0);
	}


	sstm << "Crop area size: " << roi_b.width << "x" << roi_b.height << " Filename: " << filename;
	text = sstm.str();

	if (!crop.empty())
	{
		imshow("detected", crop);
	}
	else
		cv::destroyWindow("detected");

}

void facerec::addFace(std::string s)
{
	name = s;

	cv::VideoCapture capture(0);

	if (!capture.isOpened())
		return;

	if (!face_cascade.load("OpenCV\\build\\install\\etc\\haarcascades\\haarcascade_frontalface_alt.xml"))
	{
		std::cout << "error" << std::endl;
		return;
	};

	cv::Mat frame;
	std::cout << "\nCapturing your face 10 times, Press 'C' 10 times keeping your face front of the camera";
	char key;
	int i = 0;

	for (;;)
	{
		capture >> frame;

		detectAndDisplay(frame);
		i++;
		if (i == 10)
		{
			std::cout << "Face Added";
			break;
		}

		int c = cv::waitKey(10);

		if (27 == char(c))
		{
			break;
		}
	}

	return;
}


void facerec::dbread(std::vector<cv::Mat>& images, std::vector<int>& labels) {
	std::vector<cv::String> fn;
	filename = "Faces\\";;
	cv::glob(filename, fn, false);

	size_t count = fn.size();

	for (size_t i = 0; i < count; i++)
	{
		std::string itsname = "";
		char sep = '\\';
		size_t j = fn[i].rfind(sep, fn[i].length());
		if (j != std::string::npos)
		{
			itsname = (fn[i].substr(j + 1, fn[i].length() - j - 6));
		}
		images.push_back(cv::imread(fn[i], 0));
		labels.push_back(atoi(itsname.c_str()));
	}
}

void facerec::eigenFaceTrainer() {
	std::vector<cv::Mat> images;
	std::vector<int> labels;
	dbread(images, labels);
	std::cout << "size of the images is " << images.size() << std::endl;
	std::cout << "size of the labels is " << labels.size() << std::endl;
	std::cout << "Training begins...." << std::endl;

	//create algorithm eigenface recognizer
	cv::Ptr<cv::face::EigenFaceRecognizer> model = cv::face::EigenFaceRecognizer::create();

	//train data
	model->train(images, labels);
	model->save("YML\\eigenface.yml");

	std::cout << "Training finished...." << std::endl;
	cv::waitKey(10000);
}

bool facerec::FaceRecognitionNew() {

	//load pre-trained data sets
	cv::Ptr<cv::face::FaceRecognizer>  model = cv::face::FisherFaceRecognizer::create();
	model->read("YML/eigenface.yml");

	cv::Mat testSample = cv::imread("0.jpg", 0);

	int img_width = testSample.cols;
	int img_height = testSample.rows;

	std::string window = "Face recognition AI";

	if (!face_cascade.load("OpenCV\\build\\install\\etc\\haarcascades\\haarcascade_frontalface_alt.xml")) {
		std::cout << " Error loading file" << std::endl;
		return false;
	}

	cv::VideoCapture cap(0);

	if (!cap.isOpened())
	{
		std::cout << "exit" << std::endl;
		return false;
	}

	cv::namedWindow(window, 1);
	long count = 0;
	std::string Pname = "";
	int conf = 0;
	auto timeStartStart = std::chrono::high_resolution_clock::now();
	auto timeStart = std::chrono::high_resolution_clock::now();
	auto timeNow = std::chrono::high_resolution_clock::now();
	while (std::chrono::duration_cast<std::chrono::seconds>(timeNow - timeStartStart).count() < 10)
	{
		std::vector<cv::Rect> faces;
		cv::Mat frame;
		cv::Mat graySacleFrame;
		cv::Mat original;

		cap >> frame;
	
		count = count + 1;

		if (!frame.empty()) {

			//clone from original frame
			original = frame.clone();

			//convert image to gray scale and equalize
			cv::cvtColor(original, graySacleFrame, cv::COLOR_BGR2GRAY);

			//detect face in gray image
			face_cascade.detectMultiScale(graySacleFrame, faces, 1.1, 3, 0, cv::Size(90, 90));

			//number of faces detected
			std::string frameset = std::to_string(count);
			std::string faceset = std::to_string(faces.size());

			int width = 0, height = 0;

			for (int i = 0; i < faces.size(); i++)
			{
				//region of interest
				cv::Rect face_i = faces[i];

				//crop the roi from grya image
				cv::Mat face = graySacleFrame(face_i);

				//resizing the cropped image to suit to database image sizes
				cv::Mat face_resized;
				cv::resize(face, face_resized, cv::Size(img_width, img_height), 1.0, 1.0, cv::INTER_CUBIC);

				//recognizing what faces detected
				int label = -1; double confidence = 0;
				model->predict(face_resized, label, confidence);

				if (confidence < 1000 || label == 0) {
					timeStart = std::chrono::high_resolution_clock::now();
				}

				std::cout << " confidence " << confidence << " Label: " << label << std::endl;
				conf = confidence;
				Pname = InttoName(label);

				//drawing green rectagle in recognize face
				rectangle(original, face_i, CV_RGB(0, 255, 0), 1);
				std::string text = Pname;

				int pos_x = std::max(face_i.tl().x - 10, 0);
				int pos_y = std::max(face_i.tl().y - 10, 0);

				//name the person who is in the image
				putText(original, text, cv::Point(pos_x, pos_y), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);

			}


			putText(original, "Frames: " + frameset, cv::Point(30, 60), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
			putText(original, "No. of Persons detected: " + std::to_string(faces.size()), cv::Point(30, 90), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
			putText(original, "Confidence: " + std::to_string(conf), cv::Point(30, 120), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
			//display to the winodw
			cv::imshow(window, original);


		}

		timeNow = std::chrono::high_resolution_clock::now();
		if (std::chrono::duration_cast<std::chrono::seconds>(timeNow - timeStart).count() > 2.5) {
			cv::destroyAllWindows();
			return true;
		}

		if (cv::waitKey(30) >= 0) break;
	}
	cv::destroyAllWindows();
	return false;
}

std::string facerec::InttoName(int num) {
	std::string line;
	std::ifstream file("textfiles/usernameFaceNum.txt");

	if (file.is_open())
	{
		getline(file, line);
		while (getline(file, line))
		{
			int pos = line.find("$");
			int i = std::stoi(line.substr(0, pos));
			line.erase(0, pos + 1);
			if (i == num) {
				file.close();
				return line;
			}
		}

	}
	file.close();
}

void facerec::goToLogin() {

}
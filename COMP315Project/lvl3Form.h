#pragma once
#include "PlayerInfo.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include "popup.h"
#include <set>
#include <cstdlib>
#include "customAlgs.h"
#include "LevelMethods.h"
#include "Destructible.h"
#include "PictureBox.h"
#include "MusicAndSFX.h"
#include "BonusLevelThree.h"

namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class lvl3Form : public System::Windows::Forms::Form
	{

	private: System::Windows::Forms::Timer^ BulletTimer;
	private: System::Windows::Forms::Timer^ QuestionTransitionTimerShow;

	private: System::Windows::Forms::Timer^ QuestionTransitionTimerHide;
	private: System::Windows::Forms::PictureBox^ playerlevel1;
	private: System::Windows::Forms::PictureBox^ Barrier;






	private: System::Windows::Forms::Label^ textBoxQuestion;
	private: System::Windows::Forms::Timer^ timerfinal;
	private: System::Windows::Forms::PictureBox^ pbstart;
	private: System::Windows::Forms::PictureBox^ Barrier2;
	private: System::Windows::Forms::Label^ DigitalStopWatch;
	private: System::Windows::Forms::Label^ MissLabel;
	private: System::Windows::Forms::Timer^ missTimer;
	private: System::Windows::Forms::PictureBox^ pbObstacle1;
	private: System::Windows::Forms::PictureBox^ pbObstacle2;
	private: System::Windows::Forms::PictureBox^ pbObstacle3;
	private: System::Windows::Forms::PictureBox^ pbObstacle4;
	private: System::Windows::Forms::PictureBox^ pbObstacle5;
	private: System::Windows::Forms::PictureBox^ pbObstacle6;





	private: System::Windows::Forms::Label^ textBoxTFB;
	private: System::Windows::Forms::Label^ textBoxTFA;
	private: System::Windows::Forms::Label^ textBoxD;
	private: System::Windows::Forms::Label^ textBoxC;
	private: System::Windows::Forms::Label^ textBoxB;
	private: System::Windows::Forms::Label^ textBoxA;
	private: System::Windows::Forms::Label^ lvl1Brief;
	private: System::Windows::Forms::Button^ btnsafety;


	public:

		lvl3Form()
		{
			InitializeComponent();

			this->KeyPreview = true;

			this->LvlMethods = gcnew LevelMethods(3);
			this->LvlMethods->SetQuestionComponents(textBoxQuestion, textBoxA, textBoxB, textBoxC, textBoxD, textBoxTFA, textBoxTFB);
			this->LvlMethods->SetProgressBarComponent(progressBarLevel1);
			this->LvlMethods->SetProgressBarTimerComponent(timerProgress);

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		}

	protected:
		~lvl3Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ Transition1;
	private: System::Windows::Forms::PictureBox^ pbGeneralMilitary;
	private: System::Windows::Forms::Panel^ panelLogin;
	private: System::Windows::Forms::Timer^ Transition2;
	private: System::Windows::Forms::Label^ lblMessage1;
	private: System::Windows::Forms::ProgressBar^ progressBarLevel1;
	private: System::Windows::Forms::Timer^ timerProgress;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Timer^ movePlayerTimer;
	private: System::Windows::Forms::Timer^ timeranimation;
	private: System::Windows::Forms::PictureBox^ wasd;
	private: System::Windows::Forms::PictureBox^ space;
	private: System::Windows::Forms::Timer^ shootTimer;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(lvl3Form::typeid));
			   this->lblMessage1 = (gcnew System::Windows::Forms::Label());
			   this->Transition1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pbGeneralMilitary = (gcnew System::Windows::Forms::PictureBox());
			   this->panelLogin = (gcnew System::Windows::Forms::Panel());
			   this->lvl1Brief = (gcnew System::Windows::Forms::Label());
			   this->pbObstacle6 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbObstacle4 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbObstacle5 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbObstacle3 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbObstacle2 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbObstacle1 = (gcnew System::Windows::Forms::PictureBox());
			   this->textBoxTFB = (gcnew System::Windows::Forms::Label());
			   this->textBoxTFA = (gcnew System::Windows::Forms::Label());
			   this->textBoxD = (gcnew System::Windows::Forms::Label());
			   this->textBoxC = (gcnew System::Windows::Forms::Label());
			   this->textBoxB = (gcnew System::Windows::Forms::Label());
			   this->textBoxA = (gcnew System::Windows::Forms::Label());
			   this->MissLabel = (gcnew System::Windows::Forms::Label());
			   this->DigitalStopWatch = (gcnew System::Windows::Forms::Label());
			   this->btnsafety = (gcnew System::Windows::Forms::Button());
			   this->pbstart = (gcnew System::Windows::Forms::PictureBox());
			   this->textBoxQuestion = (gcnew System::Windows::Forms::Label());
			   this->playerlevel1 = (gcnew System::Windows::Forms::PictureBox());
			   this->space = (gcnew System::Windows::Forms::PictureBox());
			   this->wasd = (gcnew System::Windows::Forms::PictureBox());
			   this->progressBarLevel1 = (gcnew System::Windows::Forms::ProgressBar());
			   this->Barrier2 = (gcnew System::Windows::Forms::PictureBox());
			   this->Barrier = (gcnew System::Windows::Forms::PictureBox());
			   this->Transition2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timerProgress = (gcnew System::Windows::Forms::Timer(this->components));
			   this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			   this->movePlayerTimer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timeranimation = (gcnew System::Windows::Forms::Timer(this->components));
			   this->shootTimer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->BulletTimer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->QuestionTransitionTimerShow = (gcnew System::Windows::Forms::Timer(this->components));
			   this->QuestionTransitionTimerHide = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timerfinal = (gcnew System::Windows::Forms::Timer(this->components));
			   this->missTimer = (gcnew System::Windows::Forms::Timer(this->components));
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->BeginInit();
			   this->panelLogin->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle6))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle4))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle5))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle3))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbstart))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playerlevel1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->space))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wasd))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Barrier2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Barrier))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // lblMessage1
			   // 
			   this->lblMessage1->AutoSize = true;
			   this->lblMessage1->Font = (gcnew System::Drawing::Font(L"Courier New", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblMessage1->Location = System::Drawing::Point(330, 900);
			   this->lblMessage1->Name = L"lblMessage1";
			   this->lblMessage1->Size = System::Drawing::Size(0, 90);
			   this->lblMessage1->TabIndex = 1;
			   this->lblMessage1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			   // 
			   // Transition1
			   // 
			   this->Transition1->Interval = 1;
			   this->Transition1->Tick += gcnew System::EventHandler(this, &lvl3Form::Transition1_Tick);
			   // 
			   // pbGeneralMilitary
			   // 
			   this->pbGeneralMilitary->BackColor = System::Drawing::Color::Transparent;
			   this->pbGeneralMilitary->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			   this->pbGeneralMilitary->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbGeneralMilitary.Image")));
			   this->pbGeneralMilitary->Location = System::Drawing::Point(-325, 288);
			   this->pbGeneralMilitary->Margin = System::Windows::Forms::Padding(0);
			   this->pbGeneralMilitary->Name = L"pbGeneralMilitary";
			   this->pbGeneralMilitary->Size = System::Drawing::Size(372, 560);
			   this->pbGeneralMilitary->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pbGeneralMilitary->TabIndex = 11;
			   this->pbGeneralMilitary->TabStop = false;
			   // 
			   // panelLogin
			   // 
			   this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			   this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));
			   this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panelLogin->Controls->Add(this->lvl1Brief);
			   this->panelLogin->Controls->Add(this->pbObstacle6);
			   this->panelLogin->Controls->Add(this->pbObstacle4);
			   this->panelLogin->Controls->Add(this->pbObstacle5);
			   this->panelLogin->Controls->Add(this->pbObstacle3);
			   this->panelLogin->Controls->Add(this->pbObstacle2);
			   this->panelLogin->Controls->Add(this->pbObstacle1);
			   this->panelLogin->Controls->Add(this->textBoxTFB);
			   this->panelLogin->Controls->Add(this->textBoxTFA);
			   this->panelLogin->Controls->Add(this->textBoxD);
			   this->panelLogin->Controls->Add(this->textBoxC);
			   this->panelLogin->Controls->Add(this->textBoxB);
			   this->panelLogin->Controls->Add(this->textBoxA);
			   this->panelLogin->Controls->Add(this->MissLabel);
			   this->panelLogin->Controls->Add(this->DigitalStopWatch);
			   this->panelLogin->Controls->Add(this->btnsafety);
			   this->panelLogin->Controls->Add(this->pbstart);
			   this->panelLogin->Controls->Add(this->textBoxQuestion);
			   this->panelLogin->Controls->Add(this->playerlevel1);
			   this->panelLogin->Controls->Add(this->space);
			   this->panelLogin->Controls->Add(this->wasd);
			   this->panelLogin->Controls->Add(this->progressBarLevel1);
			   this->panelLogin->Controls->Add(this->lblMessage1);
			   this->panelLogin->Controls->Add(this->pbGeneralMilitary);
			   this->panelLogin->Controls->Add(this->Barrier2);
			   this->panelLogin->Controls->Add(this->Barrier);
			   this->panelLogin->ForeColor = System::Drawing::Color::White;
			   this->panelLogin->Location = System::Drawing::Point(0, 0);
			   this->panelLogin->Name = L"panelLogin";
			   this->panelLogin->Size = System::Drawing::Size(1540, 852);
			   this->panelLogin->TabIndex = 12;
			   // 
			   // lvl1Brief
			   // 
			   this->lvl1Brief->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lvl1Brief->ForeColor = System::Drawing::Color::Black;
			   this->lvl1Brief->Location = System::Drawing::Point(1650, 264);
			   this->lvl1Brief->Name = L"lvl1Brief";
			   this->lvl1Brief->Size = System::Drawing::Size(300, 593);
			   this->lvl1Brief->TabIndex = 60;
			   // 
			   // pbObstacle6
			   // 
			   this->pbObstacle6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbObstacle6.Image")));
			   this->pbObstacle6->Location = System::Drawing::Point(426, 626);
			   this->pbObstacle6->Name = L"pbObstacle6";
			   this->pbObstacle6->Size = System::Drawing::Size(191, 169);
			   this->pbObstacle6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbObstacle6->TabIndex = 55;
			   this->pbObstacle6->TabStop = false;
			   this->pbObstacle6->Visible = false;
			   // 
			   // pbObstacle4
			   // 
			   this->pbObstacle4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbObstacle4.Image")));
			   this->pbObstacle4->Location = System::Drawing::Point(705, 568);
			   this->pbObstacle4->Name = L"pbObstacle4";
			   this->pbObstacle4->Size = System::Drawing::Size(92, 125);
			   this->pbObstacle4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbObstacle4->TabIndex = 54;
			   this->pbObstacle4->TabStop = false;
			   this->pbObstacle4->Visible = false;
			   // 
			   // pbObstacle5
			   // 
			   this->pbObstacle5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbObstacle5.Image")));
			   this->pbObstacle5->Location = System::Drawing::Point(797, 492);
			   this->pbObstacle5->Name = L"pbObstacle5";
			   this->pbObstacle5->Size = System::Drawing::Size(128, 82);
			   this->pbObstacle5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbObstacle5->TabIndex = 53;
			   this->pbObstacle5->TabStop = false;
			   this->pbObstacle5->Visible = false;
			   // 
			   // pbObstacle3
			   // 
			   this->pbObstacle3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbObstacle3.Image")));
			   this->pbObstacle3->Location = System::Drawing::Point(797, 334);
			   this->pbObstacle3->Name = L"pbObstacle3";
			   this->pbObstacle3->Size = System::Drawing::Size(92, 125);
			   this->pbObstacle3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbObstacle3->TabIndex = 52;
			   this->pbObstacle3->TabStop = false;
			   this->pbObstacle3->Visible = false;
			   // 
			   // pbObstacle2
			   // 
			   this->pbObstacle2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbObstacle2.Image")));
			   this->pbObstacle2->Location = System::Drawing::Point(567, 454);
			   this->pbObstacle2->Name = L"pbObstacle2";
			   this->pbObstacle2->Size = System::Drawing::Size(126, 61);
			   this->pbObstacle2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbObstacle2->TabIndex = 51;
			   this->pbObstacle2->TabStop = false;
			   this->pbObstacle2->Visible = false;
			   // 
			   // pbObstacle1
			   // 
			   this->pbObstacle1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbObstacle1.Image")));
			   this->pbObstacle1->Location = System::Drawing::Point(663, 249);
			   this->pbObstacle1->Name = L"pbObstacle1";
			   this->pbObstacle1->Size = System::Drawing::Size(92, 125);
			   this->pbObstacle1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbObstacle1->TabIndex = 50;
			   this->pbObstacle1->TabStop = false;
			   this->pbObstacle1->Visible = false;
			   // 
			   // textBoxTFB
			   // 
			   this->textBoxTFB->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBoxTFB->ForeColor = System::Drawing::Color::Black;
			   this->textBoxTFB->Location = System::Drawing::Point(1272, 618);
			   this->textBoxTFB->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->textBoxTFB->Name = L"textBoxTFB";
			   this->textBoxTFB->Size = System::Drawing::Size(241, 88);
			   this->textBoxTFB->TabIndex = 59;
			   this->textBoxTFB->Text = L"TF2";
			   this->textBoxTFB->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->textBoxTFB->Visible = false;
			   // 
			   // textBoxTFA
			   // 
			   this->textBoxTFA->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBoxTFA->ForeColor = System::Drawing::Color::Black;
			   this->textBoxTFA->Location = System::Drawing::Point(1272, 348);
			   this->textBoxTFA->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->textBoxTFA->Name = L"textBoxTFA";
			   this->textBoxTFA->Size = System::Drawing::Size(238, 81);
			   this->textBoxTFA->TabIndex = 58;
			   this->textBoxTFA->Text = L"TF1";
			   this->textBoxTFA->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->textBoxTFA->Visible = false;
			   // 
			   // textBoxD
			   // 
			   this->textBoxD->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBoxD->ForeColor = System::Drawing::Color::Black;
			   this->textBoxD->Location = System::Drawing::Point(1235, 706);
			   this->textBoxD->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->textBoxD->Name = L"textBoxD";
			   this->textBoxD->Size = System::Drawing::Size(300, 120);
			   this->textBoxD->TabIndex = 57;
			   this->textBoxD->Text = L"Option D";
			   this->textBoxD->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->textBoxD->Visible = false;
			   // 
			   // textBoxC
			   // 
			   this->textBoxC->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBoxC->ForeColor = System::Drawing::Color::Black;
			   this->textBoxC->Location = System::Drawing::Point(1240, 533);
			   this->textBoxC->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->textBoxC->Name = L"textBoxC";
			   this->textBoxC->Size = System::Drawing::Size(300, 120);
			   this->textBoxC->TabIndex = 56;
			   this->textBoxC->Text = L"Option C";
			   this->textBoxC->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->textBoxC->Visible = false;
			   // 
			   // textBoxB
			   // 
			   this->textBoxB->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBoxB->ForeColor = System::Drawing::Color::Black;
			   this->textBoxB->Location = System::Drawing::Point(1235, 413);
			   this->textBoxB->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->textBoxB->Name = L"textBoxB";
			   this->textBoxB->Size = System::Drawing::Size(300, 120);
			   this->textBoxB->TabIndex = 55;
			   this->textBoxB->Text = L"Option B";
			   this->textBoxB->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->textBoxB->Visible = false;
			   // 
			   // textBoxA
			   // 
			   this->textBoxA->BackColor = System::Drawing::Color::Transparent;
			   this->textBoxA->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBoxA->ForeColor = System::Drawing::Color::Black;
			   this->textBoxA->Location = System::Drawing::Point(1235, 248);
			   this->textBoxA->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->textBoxA->Name = L"textBoxA";
			   this->textBoxA->Size = System::Drawing::Size(300, 120);
			   this->textBoxA->TabIndex = 54;
			   this->textBoxA->Text = L"Option A";
			   this->textBoxA->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->textBoxA->Visible = false;
			   // 
			   // MissLabel
			   // 
			   this->MissLabel->AutoSize = true;
			   this->MissLabel->BackColor = System::Drawing::Color::Black;
			   this->MissLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->MissLabel->ForeColor = System::Drawing::Color::Red;
			   this->MissLabel->Location = System::Drawing::Point(1200, 175);
			   this->MissLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->MissLabel->Name = L"MissLabel";
			   this->MissLabel->Size = System::Drawing::Size(313, 29);
			   this->MissLabel->TabIndex = 49;
			   this->MissLabel->Text = L"Missed!! +10 seconds";
			   this->MissLabel->Visible = false;
			   // 
			   // DigitalStopWatch
			   // 
			   this->DigitalStopWatch->AutoSize = true;
			   this->DigitalStopWatch->BackColor = System::Drawing::Color::Black;
			   this->DigitalStopWatch->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->DigitalStopWatch->ForeColor = System::Drawing::Color::Red;
			   this->DigitalStopWatch->Location = System::Drawing::Point(904, 174);
			   this->DigitalStopWatch->Name = L"DigitalStopWatch";
			   this->DigitalStopWatch->Size = System::Drawing::Size(116, 31);
			   this->DigitalStopWatch->TabIndex = 48;
			   this->DigitalStopWatch->Text = L"label1";
			   this->DigitalStopWatch->Visible = false;
			   // 
			   // btnsafety
			   // 
			   this->btnsafety->ForeColor = System::Drawing::Color::Transparent;
			   this->btnsafety->Location = System::Drawing::Point(1548, 3);
			   this->btnsafety->Name = L"btnsafety";
			   this->btnsafety->Size = System::Drawing::Size(145, 823);
			   this->btnsafety->TabIndex = 45;
			   this->btnsafety->Text = L"button1";
			   this->btnsafety->UseVisualStyleBackColor = true;
			   this->btnsafety->Visible = false;
			   // 
			   // pbstart
			   // 
			   this->pbstart->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbstart.Image")));
			   this->pbstart->Location = System::Drawing::Point(500, 875);
			   this->pbstart->Name = L"pbstart";
			   this->pbstart->Size = System::Drawing::Size(312, 312);
			   this->pbstart->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbstart->TabIndex = 44;
			   this->pbstart->TabStop = false;
			   this->pbstart->Click += gcnew System::EventHandler(this, &lvl3Form::pbstart_Click);
			   // 
			   // textBoxQuestion
			   // 
			   this->textBoxQuestion->Font = (gcnew System::Drawing::Font(L"Courier New", 16.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->textBoxQuestion->ForeColor = System::Drawing::Color::White;
			   this->textBoxQuestion->Location = System::Drawing::Point(0, 0);
			   this->textBoxQuestion->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->textBoxQuestion->Name = L"textBoxQuestion";
			   this->textBoxQuestion->Padding = System::Windows::Forms::Padding(70, 0, 70, 0);
			   this->textBoxQuestion->Size = System::Drawing::Size(813, 236);
			   this->textBoxQuestion->TabIndex = 43;
			   this->textBoxQuestion->Text = L"label1";
			   this->textBoxQuestion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->textBoxQuestion->Visible = false;
			   // 
			   // playerlevel1
			   // 
			   this->playerlevel1->ImageLocation = L"assets/PlayerMove/idle.gif";
			   this->playerlevel1->Location = System::Drawing::Point(62, 492);
			   this->playerlevel1->Name = L"playerlevel1";
			   this->playerlevel1->Size = System::Drawing::Size(188, 105);
			   this->playerlevel1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->playerlevel1->TabIndex = 35;
			   this->playerlevel1->TabStop = false;
			   this->playerlevel1->Visible = false;
			   // 
			   // space
			   // 
			   this->space->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"space.Image")));
			   this->space->Location = System::Drawing::Point(775, 778);
			   this->space->Margin = System::Windows::Forms::Padding(2);
			   this->space->Name = L"space";
			   this->space->Size = System::Drawing::Size(38, 48);
			   this->space->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->space->TabIndex = 16;
			   this->space->TabStop = false;
			   this->space->Visible = false;
			   // 
			   // wasd
			   // 
			   this->wasd->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wasd.Image")));
			   this->wasd->Location = System::Drawing::Point(651, 751);
			   this->wasd->Margin = System::Windows::Forms::Padding(2);
			   this->wasd->Name = L"wasd";
			   this->wasd->Size = System::Drawing::Size(120, 90);
			   this->wasd->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->wasd->TabIndex = 15;
			   this->wasd->TabStop = false;
			   this->wasd->Visible = false;
			   // 
			   // progressBarLevel1
			   // 
			   this->progressBarLevel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->progressBarLevel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->progressBarLevel1->ForeColor = System::Drawing::Color::DarkOrange;
			   this->progressBarLevel1->Location = System::Drawing::Point(904, 30);
			   this->progressBarLevel1->Maximum = 1500;
			   this->progressBarLevel1->Name = L"progressBarLevel1";
			   this->progressBarLevel1->Size = System::Drawing::Size(562, 62);
			   this->progressBarLevel1->TabIndex = 12;
			   this->progressBarLevel1->Visible = false;
			   // 
			   // Barrier2
			   // 
			   this->Barrier2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Barrier2.Image")));
			   this->Barrier2->Location = System::Drawing::Point(278, 238);
			   this->Barrier2->Margin = System::Windows::Forms::Padding(2);
			   this->Barrier2->Name = L"Barrier2";
			   this->Barrier2->Size = System::Drawing::Size(90, 323);
			   this->Barrier2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->Barrier2->TabIndex = 46;
			   this->Barrier2->TabStop = false;
			   this->Barrier2->Visible = false;
			   // 
			   // Barrier
			   // 
			   this->Barrier->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Barrier.Image")));
			   this->Barrier->Location = System::Drawing::Point(270, 558);
			   this->Barrier->Name = L"Barrier";
			   this->Barrier->Size = System::Drawing::Size(90, 323);
			   this->Barrier->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->Barrier->TabIndex = 36;
			   this->Barrier->TabStop = false;
			   this->Barrier->Visible = false;
			   // 
			   // Transition2
			   // 
			   this->Transition2->Interval = 1;
			   this->Transition2->Tick += gcnew System::EventHandler(this, &lvl3Form::Transition2_Tick);
			   // 
			   // timerProgress
			   // 
			   this->timerProgress->Interval = 1;
			   this->timerProgress->Tick += gcnew System::EventHandler(this, &lvl3Form::timerProgress_Tick);
			   // 
			   // movePlayerTimer
			   // 
			   this->movePlayerTimer->Enabled = true;
			   this->movePlayerTimer->Interval = 1;
			   this->movePlayerTimer->Tick += gcnew System::EventHandler(this, &lvl3Form::movePlayerTimer_Tick);
			   // 
			   // timeranimation
			   // 
			   this->timeranimation->Enabled = true;
			   this->timeranimation->Interval = 1;
			   // 
			   // shootTimer
			   // 
			   this->shootTimer->Interval = 200;
			   this->shootTimer->Tick += gcnew System::EventHandler(this, &lvl3Form::shootTimer_Tick);
			   // 
			   // BulletTimer
			   // 
			   this->BulletTimer->Interval = 1;
			   this->BulletTimer->Tick += gcnew System::EventHandler(this, &lvl3Form::BulletTimer_Tick);
			   // 
			   // QuestionTransitionTimerShow
			   // 
			   this->QuestionTransitionTimerShow->Interval = 1;
			   this->QuestionTransitionTimerShow->Tick += gcnew System::EventHandler(this, &lvl3Form::QuestionTransitionTimerShow_Tick);
			   // 
			   // QuestionTransitionTimerHide
			   // 
			   this->QuestionTransitionTimerHide->Interval = 1000;
			   this->QuestionTransitionTimerHide->Tick += gcnew System::EventHandler(this, &lvl3Form::QuestionTransitionTimerHide_Tick);
			   // 
			   // timerfinal
			   // 
			   this->timerfinal->Interval = 2000;
			   this->timerfinal->Tick += gcnew System::EventHandler(this, &lvl3Form::timerfinal_Tick);
			   // 
			   // missTimer
			   // 
			   this->missTimer->Interval = 500;
			   this->missTimer->Tick += gcnew System::EventHandler(this, &lvl3Form::missTimer_Tick);
			   // 
			   // lvl3Form
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			   this->ClientSize = System::Drawing::Size(1580, 852);
			   this->Controls->Add(this->panelLogin);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MaximizeBox = false;
			   this->Name = L"lvl3Form";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Level 3 of 4";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &lvl3Form::lvl3Form_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &lvl3Form::lvl3Form_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &lvl3Form::lvl3Form_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &lvl3Form::lvl3Form_KeyUp);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->EndInit();
			   this->panelLogin->ResumeLayout(false);
			   this->panelLogin->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle6))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle4))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle5))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle3))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbObstacle1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbstart))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playerlevel1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->space))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wasd))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Barrier2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Barrier))->EndInit();
			   this->ResumeLayout(false);

		   }

#pragma endregion


	private:
		// Player object
		playerInfo^ player;

		LevelMethods^ LvlMethods;

		// Music objects
		MusicAndSFX* soundAnswer = new MusicAndSFX();
		MusicAndSFX* soundImpact = new MusicAndSFX();
		MusicAndSFX* ambience = new MusicAndSFX();
		MusicAndSFX* music = new MusicAndSFX();

		array<definedPictureBox^>^ pictureBoxArray;

		Destructible^ des = gcnew Destructible;
		Destructible::DestroyFunction^ destroyFuncA = gcnew Destructible::DestroyFunction(this, &lvl3Form::destroyA);
		Destructible::DestroyFunction^ destroyFuncB = gcnew Destructible::DestroyFunction(this, &lvl3Form::destroyB);
		Destructible::DestroyFunction^ destroyFuncC = gcnew Destructible::DestroyFunction(this, &lvl3Form::destroyC);
		Destructible::DestroyFunction^ destroyFuncD = gcnew Destructible::DestroyFunction(this, &lvl3Form::destroyD);
		Destructible::DestroyFunction^ destroyFuncTF1 = gcnew Destructible::DestroyFunction(this, &lvl3Form::destroyTF1);
		Destructible::DestroyFunction^ destroyFuncTF2 = gcnew Destructible::DestroyFunction(this, &lvl3Form::destroyTF2);
		Destructible::DestroyFunction^ destroyFuncSafety = gcnew Destructible::DestroyFunction(this, &lvl3Form::destroySafety);
		Destructible::DestroyFunction^ destroyFuncObstacle = gcnew Destructible::DestroyFunction(this, &lvl3Form::destroyObstacle);

		definedPictureBox^ bullet;

		definedPictureBox^ pictureBoxA;
		definedPictureBox^ pictureBoxB;
		definedPictureBox^ pictureBoxC;
		definedPictureBox^ pictureBoxD;
		definedPictureBox^ pictureBoxTF1;
		definedPictureBox^ pictureBoxTF2;
		definedPictureBox^ openedDoor;

		definedPictureBox^ pbSafety;

		String^ projectDirectory = Application::StartupPath;
		String^ playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\idle.gif");

		String^ playerRunRightGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\run.gif");
		String^ playerRunLeftGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\runleft.gif");
		String^ playerShootGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\shoot.gif");

		bool isleft;
		bool canshoot = false;
		bool levelcomplete = false;


		bool move_up = false;
		bool move_left = false;
		bool move_down = false;
		bool move_right = false;

		bool is_w_up = true;
		bool is_a_up = true;
		bool is_s_up = true;
		bool is_d_up = true;

		long long ticks = 0;

		int countSpacePress = 0;

		int currentFeedbackLogoNum = 0;

		int countMissTimer = 0;

	private:
		/*
			Loads/instantiates certain UI elements
			Creates and displays the "Welcome to level 1" pop up,
			Initalizes the player info object with info from PlayerInfo.txt
			Plays the levels' (background) music
		*/
		System::Void lvl3Form_Load(System::Object^ sender, System::EventArgs^ e) {
			this->ClientSize = System::Drawing::Size(1232, 682);


			lvl1Brief->Text = "Level 3 Brief:\n\n• You will be required to answer 10 questions.\n• These consist of multiple choice and true/false questions.\n• Shoot the bunker you wish to select.\n• If a bunker is obstructed, destroy its obstructions.\n• You will be granted 15 seconds per question.\n• Feedback on a question will be provided immediately after.\n\nAll The Best Soldier!!\n\n<Click Start To Begin>";


			std::ifstream file("textfiles/PlayerInfo.txt");
			std::string line;
			std::vector<std::string> v;
			if (file.is_open())
			{
				while (getline(file, line))
				{
					v.push_back(line);
				}

			}
			file.close();

			playerInfo^ p = gcnew playerInfo;
			for (int i = 0; i < 3; i++) {
				std::string s = v[i];
				if (i == 0) {
					p->username = gcnew String(s.c_str());

				}

				else if (i == 1) {
					p->score = std::stoi(s);
				}
				else {
					p->timeTaken = std::stoi(s);
				}

			}

			this->player = p;

			msclr::interop::marshal_context context;
			std::string windowPrompt = "Welcome to the third level of the simulation, " + context.marshal_as<std::string>(this->player->username) + ". This level takes place in the M15 jungle. \nSo... try not to get eaten by a lion or something. \nOh yeah and y'know... \n\nTry not to die in any other way too;)";
			String^ unwrapped = gcnew String(windowPrompt.c_str());
			popup^ window = gcnew popup(unwrapped, 0, 0, "assets/level_transition_background.png");
			window->Visible = false;
			this->Hide();
			window->ShowDialog();

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			System::String^ recruitname = this->player->username;

			Transition1->Start();

			playerlevel1->ImageLocation = "assets/PlayerMove/idle.gif";

			bullet = gcnew definedPictureBox(panelLogin, 8, 4, playerlevel1->Location.X, playerlevel1->Location.Y, "assets/Bullets/9.png", false);
			bullet->Hide();

			pictureBoxArray = gcnew array<definedPictureBox^>(10);
			int pbWidth = 45;
			int pbHeight = 45;


			System::String^ imagePath = "assets/Logos/logo_default.png";
			Image^ image = Image::FromFile(imagePath);
			for (int i = 0; i < 10; i++) {

				pictureBoxArray[i] = gcnew definedPictureBox(panelLogin, pbWidth, pbHeight, 723 + (i * pbWidth), 84, imagePath, false);

			}

			openedDoor = gcnew definedPictureBox();

			textBoxQuestion->BackgroundImage = Image::FromFile("assets/Backgrounds/im.png");
			textBoxQuestion->BackgroundImageLayout = ImageLayout::Stretch;

			des->addObject(this->btnsafety, destroyFuncSafety);
			//Obstacles
			//destructable objects(they're all barrels for, will change later)
			des->addObject(this->pbObstacle1, destroyFuncObstacle);
			des->addObject(this->pbObstacle2, destroyFuncObstacle);
			des->addObject(this->pbObstacle3, destroyFuncObstacle);
			des->addObject(this->pbObstacle4, destroyFuncObstacle);
			des->addObject(this->pbObstacle5, destroyFuncObstacle);
			des->addObject(this->pbObstacle6, destroyFuncObstacle);
			
			ambience->NightForest();
			music->LevelThreeMusic();
		}

		/*
			Moves the military general and start button onto the screen
		*/
		System::Void Transition1_Tick(System::Object^ sender, System::EventArgs^ e) {
			Point p1 = pbGeneralMilitary->Location;
			Point p2 = lblMessage1->Location;
			Point p3 = pbstart->Location;
			Point p4 = lvl1Brief->Location;
			int x1 = p1.X, y1 = p2.Y, y2 = p3.Y, x2 = p4.X;

			if (x1 <= 40)
			{
				x1 += 10;
			}
			if (y1 >= 400)
			{
				y1 -= 10;
			}
			if (y2 >= 470)
			{
				y2 -= 10;
			}
			if (x2 >= 1000)
			{
				x2 -= 10;
			}

			pbGeneralMilitary->Location = Point(x1, 230);
			lblMessage1->Location = Point(395, y1);
			pbstart->Location = Point(500, y2);
			lvl1Brief->Location = Point(x2, 195);
		}

		/*
			Moves the military general and start button out of the screen
			Enables/sets all elements required for the level
		*/
		System::Void Transition2_Tick(System::Object^ sender, System::EventArgs^ e) {
			Point p1 = pbGeneralMilitary->Location;
			Point p2 = lblMessage1->Location;
			Point p3 = pbstart->Location;
			Point p4 = lvl1Brief->Location;
			int x1 = p1.X, y1 = p2.Y, y2 = p3.Y, x2 = p4.X;

			if (x1 >= -325)
			{
				x1 -= 10;
			}
			if (y1 <= 900)
			{
				y1 += 10;
			}
			if (y2 <= 1000)
			{
				y2 += 10;
			}
			if (x2 <= 1650)
			{
				x2 += 10;
			}

			if (!(x1 >= -325) && !(y1 <= 900) && !(y2 <= 1000) && !(x2 <= 1650))
			{
				this->Barrier2->Visible = true;
				this->Barrier->Visible = true;
				this->progressBarLevel1->Visible = true;
				this->playerlevel1->Visible = true;
				this->playerlevel1->BringToFront();
				this->pbstart->Enabled = false;
				this->DigitalStopWatch->Visible = true;
				this->wasd->Visible = true;
				this->space->Visible = true;
				movePlayerTimer->Start();
				Transition2->Enabled = false;
				canshoot = true;

				pictureBoxA = gcnew definedPictureBox(panelLogin, 90, 80, 850, 215, "assets/Doors/bunker_closed.png", false);
				pictureBoxA->Show();
				pictureBoxB = gcnew definedPictureBox(panelLogin, 90, 80, 850, 335, "assets/Doors/bunker_closed.png", false);
				pictureBoxB->Show();
				pictureBoxC = gcnew definedPictureBox(panelLogin, 90, 80, 850, 455, "assets/Doors/bunker_closed.png", false);
				pictureBoxC->Show();
				pictureBoxD = gcnew definedPictureBox(panelLogin, 90, 80, 850, 575, "assets/Doors/bunker_closed.png", false);
				pictureBoxD->Show();

				des->addObject(pictureBoxA, destroyFuncA);
				des->addObject(pictureBoxB, destroyFuncB);
				des->addObject(pictureBoxC, destroyFuncC);
				des->addObject(pictureBoxD, destroyFuncD);

				for (int i = 0; i < 10; i++) {
					pictureBoxArray[i]->setVisible(true);

				}

				//displaying obstacles
				pbObstacle1->Visible = true;
				pbObstacle2->Visible = true;
				pbObstacle3->Visible = true;
				pbObstacle4->Visible = true;
				pbObstacle5->Visible = true;
				pbObstacle6->Visible = true;

				LvlMethods->DisplayNextQuestionSet();


			}
			pbGeneralMilitary->Location = Point(x1, 230);
			lblMessage1->Location = Point(395, y1);
			pbstart->Location = Point(500, y2);
			lvl1Brief->Location = Point(x2, 195);
		}

		/*
			Change from transition 1 to transition 2
		*/
		System::Void pbstart_Click(System::Object^ sender, System::EventArgs^ e) {
			Transition1->Enabled = false;
			Transition2->Start();
			this->timerProgress->Start();
		}


	private:
		/*
			All destroy functions below (except for destroySafety):
			Respawns the doors that the player shoot
			Displays an open door to signify a door has been shot
			Calls changeLabelColors() to change text of the options to indicate if their chosen answer is correct (green) or incorrect (red)
			Checks if the final question has been answered to which it will start the process of displaying the end of level screen
		*/
		void destroyTF1()
		{
			changeLabelColors();
			openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 740, 215, "assets/Doors/bunker_opened.png", false);
			openedDoor->setVisible(true);

			pictureBoxTF1 = gcnew definedPictureBox(panelLogin, 225, 200, 740, 215, "assets/Doors/bunker_closed.png", false);

			des->addObject(pictureBoxTF1, destroyFuncTF1);

			LvlMethods->QuestionAnswered(0);
			if (LvlMethods->QuestionsCompleted == 10)
			{
				doFinalCheck("T");
			}
			else
			{
				QuestionTransitionTimerShow->Start();
			}
		}
		void destroyTF2()
		{
			changeLabelColors();
			openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 740, 455, "assets/Doors/bunker_opened.png", false);
			openedDoor->setVisible(true);

			pictureBoxTF2 = gcnew definedPictureBox(panelLogin, 225, 200, 740, 455, "assets/Doors/bunker_closed.png", false);

			des->addObject(pictureBoxTF2, destroyFuncTF2);

			LvlMethods->QuestionAnswered(1);
			if (LvlMethods->QuestionsCompleted == 10)
			{
				doFinalCheck("F");
			}
			else
			{
				QuestionTransitionTimerShow->Start();
			}
		}
		void destroyA()
		{
			changeLabelColors();
			openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 215, "assets/Doors/bunker_opened.png", false);
			openedDoor->setVisible(true);


			pictureBoxA = gcnew definedPictureBox(panelLogin, 90, 80, 850, 215, "assets/Doors/bunker_closed.png", false);

			des->addObject(pictureBoxA, destroyFuncA);

			LvlMethods->QuestionAnswered(0);
			if (LvlMethods->QuestionsCompleted == 10)
			{
				doFinalCheck("A");
			}
			else
			{
				QuestionTransitionTimerShow->Start();
			}
		}
		void destroyB()
		{
			changeLabelColors();

			openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 335, "assets/Doors/bunker_opened.png", false);
			openedDoor->setVisible(true);

			pictureBoxB = gcnew definedPictureBox(panelLogin, 90, 80, 850, 335, "assets/Doors/bunker_closed.png", false);

			des->addObject(pictureBoxB, destroyFuncB);

			LvlMethods->QuestionAnswered(1);

			if (LvlMethods->QuestionsCompleted == 10)
			{
				doFinalCheck("B");
			}
			else
			{
				QuestionTransitionTimerShow->Start();
			}
		}
		void destroyC()
		{
			changeLabelColors();

			openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 455, "assets/Doors/bunker_opened.png", false);
			openedDoor->setVisible(true);

			pictureBoxC = gcnew definedPictureBox(panelLogin, 90, 80, 850, 455, "assets/Doors/bunker_closed.png", false);

			des->addObject(pictureBoxC, destroyFuncC);

			LvlMethods->QuestionAnswered(2);

			if (LvlMethods->QuestionsCompleted == 10)
			{
				doFinalCheck("C");
			}
			else
			{
				QuestionTransitionTimerShow->Start();
			}
		}
		void destroyD()
		{
			changeLabelColors();

			openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 575, "assets/Doors/bunker_opened.png", false);
			openedDoor->setVisible(true);

			pictureBoxD = gcnew definedPictureBox(panelLogin, 90, 80, 850, 575, "assets/Doors/bunker_closed.png", false);

			des->addObject(pictureBoxD, destroyFuncD);
			LvlMethods->QuestionAnswered(3);

			if (LvlMethods->QuestionsCompleted == 10)
			{
				doFinalCheck("D");
			}
			else
			{
				QuestionTransitionTimerShow->Start();
			}
		}

		/*
			Respawns the safety barrier beyond the questions if a bullet happens to get pass the doors
			Shows the player that 10 seconds has been added to their time
		*/
		void destroySafety() {
			MissLabel->Show();
			missTimer->Start();
			ticks += 1000;
			pbSafety = gcnew definedPictureBox(panelLogin, 116, 659, 1239, 3, "assets/Barrier.gif", false);
			pbSafety->Hide();
			des->addObject(pbSafety, destroyFuncSafety);
			ambience->playRandomSound("assets\\music\\ouch.wav", false);
		}

		void destroyObstacle(){


		}

		/*
			Hides the "+10 seconds" label 1 second after the player misses a target
		*/
		System::Void missTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (countMissTimer == 0)
			{
				countMissTimer++;
			}
			else
			{
				MissLabel->Hide();
				countMissTimer = 0;
				missTimer->Stop();
			}
		}
		/*
			Changes the text of the options to indicate if their chosen answer is correct (green) or incorrect (red)
		*/
		void changeLabelColors() {
			textBoxA->ForeColor = System::Drawing::Color::Red;
			textBoxB->ForeColor = System::Drawing::Color::Red;
			textBoxC->ForeColor = System::Drawing::Color::Red;
			textBoxD->ForeColor = System::Drawing::Color::Red;
			textBoxTFA->ForeColor = System::Drawing::Color::Red;
			textBoxTFB->ForeColor = System::Drawing::Color::Red;
			if (LvlMethods->CorrectOptionInt == 0) {
				textBoxA->ForeColor = System::Drawing::Color::Green;
				textBoxTFA->ForeColor = System::Drawing::Color::Green;
			}

			if (LvlMethods->CorrectOptionInt == 1) {
				textBoxB->ForeColor = System::Drawing::Color::Green;
				textBoxTFB->ForeColor = System::Drawing::Color::Green;
			}

			if (LvlMethods->CorrectOptionInt == 2) {
				textBoxC->ForeColor = System::Drawing::Color::Green;
			}

			if (LvlMethods->CorrectOptionInt == 3) {
				textBoxD->ForeColor = System::Drawing::Color::Green;
			}
		}

	private:
		/*
			Checks when the keys for moving and shooting are being pressed
			Sets the required player animations
		*/
		System::Void lvl3Form_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			e->SuppressKeyPress = true;
			if (LvlMethods->DisableControls != true) {

				if (e->KeyCode == Keys::Space && canshoot)
				{
					if (des->getBulletCount() == 0 && !isleft) {
						shootTimer->Start();
						soundAnswer->gunshot();
					}
				}
			}

			if (e->KeyCode == Keys::W)
			{
				move_up = true;
				is_w_up = false;
				soundImpact->playRandomSound("assets\\music\\ES_Footsteps Grass 2 - SFX Producer.wav", false);
			}
			if (e->KeyCode == Keys::A)
			{
				if (!isleft) {
					playerlevel1->ImageLocation = playerRunLeftGifPath;
				}
				isleft = true;
				move_left = true;
				is_a_up = false;
				soundImpact->playRandomSound("assets\\music\\ES_Footsteps Grass 2 - SFX Producer.wav", false);
			}
			if (e->KeyCode == Keys::S)
			{
				move_down = true;
				is_s_up = false;
				soundImpact->playRandomSound("assets\\music\\ES_Footsteps Grass 2 - SFX Producer.wav", false);
			}
			if (e->KeyCode == Keys::D)
			{
				if (isleft) {
					playerlevel1->ImageLocation = playerRunRightGifPath;
				}
				isleft = false;
				move_right = true;
				is_d_up = false;
				soundImpact->playRandomSound("assets\\music\\ES_Footsteps Grass 2 - SFX Producer.wav", false);
			}
		}

		/*
			Checks when the keys for moving aren't being pressed
			Sets the required player animations
		*/
		System::Void lvl3Form_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			e->SuppressKeyPress = true;

			switch (e->KeyCode)
			{
			case Keys::W:
				move_up = false;
				is_w_up = true;

				break;
			case Keys::A:
				move_left = false;
				is_a_up = true;

				break;
			case Keys::S:
				move_down = false;
				is_s_up = true;

				break;
			case Keys::D:
				move_right = false;
				is_d_up = true;

				break;

			default:
				break;
			}

			if (is_w_up && is_a_up && is_s_up && is_d_up)
			{
				if (isleft)
				{
					playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\idleleft.gif");
				}
				else
				{
					playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\idle.gif");
				}
				playerlevel1->ImageLocation = playerIdleGifPath;

				soundImpact->randomSound.stop();
			}
		}

		/*
			Updates the player location when the appropriate keys are being pressed
			Sets the required player animations
		*/
		System::Void movePlayerTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			Barrier->BringToFront();
			playerlevel1->SendToBack();
			if (!(is_w_up && is_a_up && is_s_up && is_d_up) &&
				(playerlevel1->ImageLocation != playerRunRightGifPath &&
					playerlevel1->ImageLocation != playerRunLeftGifPath))
			{

				if (isleft)
				{
					playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\runleft.gif");
				}
				else
				{
					playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\run.gif");
				}
				playerlevel1->ImageLocation = playerIdleGifPath;
			}

			if (move_up && playerlevel1->Top > 190)
			{
				playerlevel1->Top += -5;
			}
			if (move_left && playerlevel1->Left > -35)
			{
				playerlevel1->Left += -5;
			}
			if (move_down && playerlevel1->Top < 575)
			{
				playerlevel1->Top += 5;
			}
			if (move_right && playerlevel1->Left < 100)
			{
				playerlevel1->Left += 5;
			}
		}

	private:
		/*
			Only allows the bullet to spawn when it's in sync with the shoot animation
		*/
		System::Void shootTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (countSpacePress == 0) {
				playerlevel1->ImageLocation = playerShootGifPath;
				movePlayerTimer->Stop();
				countSpacePress++;
			}
			else {
				playerlevel1->ImageLocation = playerIdleGifPath;
				movePlayerTimer->Start();
				countSpacePress = 0;
				shootTimer->Stop();

				addBullet(10, 0, playerlevel1->Location.X + 80, playerlevel1->Location.Y + 19);
				BulletTimer->Start();
			}

		}

		/*
			Updates the location of the bullet and checks if it has collided with another object
		*/
		System::Void BulletTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			des->update();
		}

		/*
			Instantiates a new bullet (called when a bullet has been destroyed)
		*/
		void addBullet(double velocityX, double velocityY, int x_pos, int y_pos) {
			bullet = gcnew definedPictureBox(panelLogin, 8, 4, playerlevel1->Location.X, playerlevel1->Location.Y, "assets/Bullets/9.png", false);
			bullet->Show();
			des->addBullet(bullet, velocityX, velocityY, x_pos, y_pos);
		}

	private:
		/*
			Sets the current questions' feedback logo to correct (green) or incorrect (red)
			Plays an appropriate audio depending on whether they got the question correct or incorrect
		*/
		System::Void QuestionTransitionTimerShow_Tick(System::Object^ sender, System::EventArgs^ e) {

			LvlMethods->DisableControls = true;
			if (LvlMethods->Correct) {
				LvlMethods->Correct = false;
				QuestionTransitionTimerHide->Start();
				QuestionTransitionTimerShow->Stop();

				pictureBoxArray[currentFeedbackLogoNum]->Image = Image::FromFile("assets/Logos/logo_correctMK3.png");
				currentFeedbackLogoNum++;

				soundAnswer->CorrectAnswer();
				soundImpact->playRandomSound("assets\\music\\ES_Explosion Grenade 3 - SFX Producer.wav", false);

			}
			else {
				LvlMethods->Correct = false;
				QuestionTransitionTimerHide->Start();
				QuestionTransitionTimerShow->Stop();

				pictureBoxArray[currentFeedbackLogoNum]->Image = Image::FromFile("assets/Logos/logo_incorrect.png");
				currentFeedbackLogoNum++;

				soundAnswer->IncorrectAnswer();
				soundImpact->playRandomSound("assets\\music\\ES_Explosion Grenade 3 - SFX Producer.wav", false);
			}





		}

		/*
			Shows the objects that the player will be required to shoot to select their answer (in front of the options)
		*/
		System::Void QuestionTransitionTimerHide_Tick(System::Object^ sender, System::EventArgs^ e) {
			LvlMethods->DisplayNextQuestionSet();
			LvlMethods->DisableControls = false;
			QuestionTransitionTimerHide->Stop();

			openedDoor->Hide();

			if (LvlMethods->QuestionType == "0")
			{
				pictureBoxA->Show();
				pictureBoxB->Show();
				pictureBoxC->Show();
				pictureBoxD->Show();
			}
			else if (LvlMethods->QuestionType == "1")
			{
				pictureBoxA->setLocation(870, pictureBoxA->Location.Y);
				pictureBoxB->setLocation(870, pictureBoxA->Location.Y);
				pictureBoxC->setLocation(870, pictureBoxA->Location.Y);
				pictureBoxD->setLocation(870, pictureBoxA->Location.Y);
				pictureBoxA->Hide();
				pictureBoxB->Hide();
				pictureBoxC->Hide();
				pictureBoxD->Hide();

				pictureBoxTF1 = gcnew definedPictureBox(panelLogin, 225, 200, 740, 215, "assets/Doors/bunker_closed.png", false);
				pictureBoxTF1->Hide();
				pictureBoxTF2 = gcnew definedPictureBox(panelLogin, 225, 200, 740, 455, "assets/Doors/bunker_closed.png", false);
				pictureBoxTF2->Hide();

				des->addObject(pictureBoxTF1, destroyFuncTF1);
				des->addObject(pictureBoxTF2, destroyFuncTF2);
				pictureBoxTF1->Show();
				pictureBoxTF2->Show();
			}

			textBoxA->ForeColor = System::Drawing::Color::Black;
			textBoxB->ForeColor = System::Drawing::Color::Black;
			textBoxC->ForeColor = System::Drawing::Color::Black;
			textBoxD->ForeColor = System::Drawing::Color::Black;
			textBoxTFA->ForeColor = System::Drawing::Color::Black;
			textBoxTFB->ForeColor = System::Drawing::Color::Black;
		}

		/*
			Increments the progress bar as time progresses for each question
			If the progress bar reaches the end for a particular question then it marks that question as incorrectly answered
		*/
		System::Void timerProgress_Tick(System::Object^ sender, System::EventArgs^ e) {
			this->progressBarLevel1->Increment(1);
			LvlMethods->PlayerStats->timeTaken = ticks / 100;
			ticks++;

			DigitalStopWatch->Text = "Total time: " + System::Convert::ToString(LvlMethods->PlayerStats->timeTaken);
			if (this->progressBarLevel1->Value == this->progressBarLevel1->Maximum)
			{
				pictureBoxArray[currentFeedbackLogoNum]->Image = Image::FromFile("assets/Logos/logo_incorrect.png");

				if (LvlMethods->QuestionsCompleted == 9) {
					LvlMethods->Correct = false;
					doFinalCheck("");
				}
				else {
					currentFeedbackLogoNum++;
					LvlMethods->QuestionCompleted();
					if (LvlMethods->QuestionsCompleted == 8) {
						pictureBoxA->setLocation(870, pictureBoxA->Location.Y);
						pictureBoxB->setLocation(870, pictureBoxA->Location.Y);
						pictureBoxC->setLocation(870, pictureBoxA->Location.Y);
						pictureBoxD->setLocation(870, pictureBoxA->Location.Y);
						pictureBoxA->Hide();
						pictureBoxB->Hide();
						pictureBoxC->Hide();
						pictureBoxD->Hide();

						pictureBoxTF1 = gcnew definedPictureBox(panelLogin, 150, 240, 740, 195, "assets/Doors/bunker_closed.png", false);
						pictureBoxTF1->Hide();
						pictureBoxTF2 = gcnew definedPictureBox(panelLogin, 150, 240, 740, 435, "assets/Doors/bunker_closed.png", false);
						pictureBoxTF2->Hide();

						des->addObject(pictureBoxTF1, destroyFuncTF1);
						des->addObject(pictureBoxTF2, destroyFuncTF2);
						pictureBoxTF1->Show();
						pictureBoxTF2->Show();
					}
					soundAnswer->IncorrectAnswer();
				}

				LvlMethods->DisableControls = false;
			}

		}


	private:
		/*
			Starts the timer to go to the end of level screen
		*/
		System::Void timerfinal_Tick(System::Object^ sender, System::EventArgs^ e) {
			displayEndLvlScreen();
			timerfinal->Enabled = false;
			timerfinal->Stop();
		}

		/*
			Ensures that feedback is provided for the final question (question 10) before moving to the end of level screen
		*/
		void doFinalCheck(std::string str) {
			this->shootTimer->Enabled = false;
			this->timeranimation->Enabled = false;
			this->timerProgress->Enabled = false;
			this->movePlayerTimer->Enabled = false;
			this->QuestionTransitionTimerHide->Enabled = false;
			this->QuestionTransitionTimerShow->Enabled = false;
			this->Transition1->Enabled = false;
			this->Transition2->Enabled = false;
			this->BulletTimer->Enabled = false;

			if (LvlMethods->Correct)
			{
				LvlMethods->Correct = false;
				pictureBoxArray[currentFeedbackLogoNum]->Image = Image::FromFile("assets/Logos/logo_correctMK3.png");

				if (str != "") {
					soundImpact->BulletImpact();
				}
				soundAnswer->CorrectAnswer();

				currentFeedbackLogoNum++;

			}
			else
			{
				LvlMethods->Correct = false;
				pictureBoxArray[currentFeedbackLogoNum]->Image = Image::FromFile("assets/Logos/logo_incorrect.png");

				if (str != "") {
					soundImpact->BulletImpact();
				}
				soundAnswer->IncorrectAnswer();

				currentFeedbackLogoNum++;
			}
			if (str == "T")
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 740, 215, "assets/Doors/bunker_opened.png", false);
				openedDoor->BringToFront();
				openedDoor->setVisible(true);
			}
			else if (str == "F")
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 740, 455, "assets/Doors/bunker_opened.png", false);
				openedDoor->setVisible(true);
				openedDoor->BringToFront();
			}

			timerfinal->Enabled = true;
			timerfinal->Start();

		}


		/*
			Saves the player score and time taken to PlayerInfo.txt for later use
			Creates and displays the end of level screen (pop up) that displays feedback for the overall score and time taken for the current player
		*/
		void displayEndLvlScreen()
		{	
			this->levelcomplete = true;
			timerfinal->Enabled = false;
			timerfinal->Stop();

			this->shootTimer->Enabled = false;
			this->timeranimation->Enabled = false;
			this->timerProgress->Enabled = false;
			this->movePlayerTimer->Enabled = false;
			this->QuestionTransitionTimerHide->Enabled = false;
			this->QuestionTransitionTimerShow->Enabled = false;
			this->Transition1->Enabled = false;
			this->Transition2->Enabled = false;
			this->BulletTimer->Enabled = false;

			soundAnswer->StopSound();
			ambience->StopSound();
			music->StopSound();
			soundImpact->StopSound();

			delete soundAnswer;
			delete ambience;
			delete soundImpact;
			delete music;

			int levelTimeTaken = LvlMethods->PlayerStats->timeTaken;
			int levelScore = LvlMethods->PlayerStats->score;

			msclr::interop::marshal_context context;
			std::ofstream writer("textfiles/PlayerInfo.txt");
			std::string line;
			std::string username = context.marshal_as<std::string>(player->username);
			line = username;
			writer << username << "\n";

			this->player->score += LvlMethods->PlayerStats->score;
			this->player->timeTaken += LvlMethods->PlayerStats->timeTaken;
			writer << this->player->score << "\n";
			writer << this->player->timeTaken;
			writer.close();

			std::string windowPrompt = "Level 3 of 4 feedback (Jungle)\n\nNumber of correct answers: " + std::to_string(LvlMethods->PlayerStats->CorrectAnswers) + "\nTime Taken: " + std::to_string(levelTimeTaken) + " seconds\nScore: " + std::to_string(levelScore) + " Points\n\nOverall time taken: " + std::to_string(this->player->timeTaken) + " seconds\nOverall score: " + std::to_string(this->player->score) + " Points.\nPlease proceed to bonus level 3.";
			String^ unwrapped = gcnew String(windowPrompt.c_str());
			popup^ window = gcnew popup(unwrapped, 0, 0, "assets/Backgrounds/ForestDark.png");

			window->Visible = false;
			this->Hide();

			window->ShowDialog();

			BonusLevelThree^ bonus3 = gcnew BonusLevelThree();
			this->Hide();
			bonus3->ShowDialog();
			this->Close();
		}

	private:
		/*
			Displays a confirmation prompt when the player attempts to close the game
			Yes: Closes the game (No progress saved)
			No: Closes the confirmation prompt (Game stays open)
		*/
		System::Void lvl3Form_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			if (!levelcomplete) {
				if (MessageBox::Show("Are you sure you want to eliminate yourself?", "", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
				{
					e->Cancel = true;
					panelLogin->Focus();
				}
			}
			
		}
	};
}
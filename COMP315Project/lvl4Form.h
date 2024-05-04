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
#include "BonusLevelFour.h"

namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class lvl4Form : public System::Windows::Forms::Form
	{
	// Components
	private: System::Windows::Forms::Timer^ BulletTimer;
	private: System::Windows::Forms::Timer^ QuestionTransitionTimerShow;

	private: System::Windows::Forms::Timer^ QuestionTransitionTimerHide;
	private: System::Windows::Forms::PictureBox^ Barrier;

	private: System::Windows::Forms::PictureBox^ pbGeneralMilitary;
	private: System::Windows::Forms::Label^ lblMessage1;
	private: System::Windows::Forms::ProgressBar^ progressBarLevel1;
	private: System::Windows::Forms::PictureBox^ wasd;
	private: System::Windows::Forms::PictureBox^ space;

	private: System::Windows::Forms::PictureBox^ playerlevel1;

	private: System::Windows::Forms::Label^ textBoxQuestion;
	private: System::Windows::Forms::PictureBox^ pbstart;
	private: System::Windows::Forms::Button^ btnsafety;

	private: System::Windows::Forms::Panel^ panelLogin;
	private: System::Windows::Forms::Label^ DigitalStopWatch;
	private: System::Windows::Forms::Label^ MissLabel;
	private: System::Windows::Forms::Timer^ missTimer;
	private: System::Windows::Forms::Label^ textBoxTFB;
	private: System::Windows::Forms::Label^ textBoxTFA;
	private: System::Windows::Forms::Label^ textBoxD;
	private: System::Windows::Forms::Label^ textBoxC;
	private: System::Windows::Forms::Label^ textBoxB;
	private: System::Windows::Forms::Label^ textBoxA;
	private: System::Windows::Forms::Label^ lvl1Brief;
	private: System::Windows::Forms::PictureBox^ pbAsteroid3;
	private: System::Windows::Forms::PictureBox^ pbAsteroid15;
	private: System::Windows::Forms::PictureBox^ pbAsteroid16;
	private: System::Windows::Forms::PictureBox^ pbAsteroid19;

	private: System::Windows::Forms::PictureBox^ pbAsteroid4;
	private: System::Windows::Forms::PictureBox^ pbAsteroid7;
	private: System::Windows::Forms::PictureBox^ pbAsteroid8;

	private: System::Windows::Forms::PictureBox^ pbAsteroid1;
	private: System::Windows::Forms::PictureBox^ pbAsteroid10;

	private: System::Windows::Forms::PictureBox^ pbAsteroid9;

	private: System::Windows::Forms::PictureBox^ pbAsteroid2;
	private: System::Windows::Forms::PictureBox^ pbAsteroid14;

	private: System::Windows::Forms::PictureBox^ pbAsteroid13;

	private: System::Windows::Forms::PictureBox^ pbAsteroid11;
	private: System::Windows::Forms::PictureBox^ pbAsteroid18;

	private: System::Windows::Forms::PictureBox^ pbAsteroid6;
	private: System::Windows::Forms::PictureBox^ pbAsteroid12;
	private: System::Windows::Forms::PictureBox^ pbAsteroid17;

	private: System::Windows::Forms::PictureBox^ pbAsteroid5;

	private: System::Windows::Forms::Timer^ timerfinal;

	public:
		
		// Constructor
		lvl4Form()
		{
			// Initializes graphical components
			InitializeComponent();

			this->KeyPreview = true;

			// Instantiating LevelMethods, used to access methods useful for every level
			this->LvlMethods = gcnew LevelMethods(4);

			// passing necessary components to LevelMethods insatnce
			this->LvlMethods->SetQuestionComponents(textBoxQuestion, textBoxA, textBoxB, textBoxC, textBoxD, textBoxTFA, textBoxTFB);
			this->LvlMethods->SetProgressBarComponent(progressBarLevel1);
			this->LvlMethods->SetProgressBarTimerComponent(timerProgress);

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		}

	protected:

		// Destructor
		~lvl4Form()
		{
			//if there are any components, delete them
			if (components)
			{
				delete components;
			}
		}

	// Components
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ Transition1;

	private: System::Windows::Forms::Timer^ Transition2;

	private: System::Windows::Forms::Timer^ timerProgress;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Timer^ movePlayerTimer;
	private: System::Windows::Forms::Timer^ timeranimation;

	private: System::Windows::Forms::Timer^ shootTimer;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(lvl4Form::typeid));
			   this->Transition1 = (gcnew System::Windows::Forms::Timer(this->components));
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
			   this->Barrier = (gcnew System::Windows::Forms::PictureBox());
			   this->pbGeneralMilitary = (gcnew System::Windows::Forms::PictureBox());
			   this->lblMessage1 = (gcnew System::Windows::Forms::Label());
			   this->progressBarLevel1 = (gcnew System::Windows::Forms::ProgressBar());
			   this->wasd = (gcnew System::Windows::Forms::PictureBox());
			   this->space = (gcnew System::Windows::Forms::PictureBox());
			   this->playerlevel1 = (gcnew System::Windows::Forms::PictureBox());
			   this->textBoxQuestion = (gcnew System::Windows::Forms::Label());
			   this->pbstart = (gcnew System::Windows::Forms::PictureBox());
			   this->btnsafety = (gcnew System::Windows::Forms::Button());
			   this->panelLogin = (gcnew System::Windows::Forms::Panel());
			   this->pbAsteroid18 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid6 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid12 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid17 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid5 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid14 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid13 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid11 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid3 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid15 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid16 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid19 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid4 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid7 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid8 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid1 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid10 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid9 = (gcnew System::Windows::Forms::PictureBox());
			   this->pbAsteroid2 = (gcnew System::Windows::Forms::PictureBox());
			   this->lvl1Brief = (gcnew System::Windows::Forms::Label());
			   this->textBoxTFB = (gcnew System::Windows::Forms::Label());
			   this->textBoxTFA = (gcnew System::Windows::Forms::Label());
			   this->textBoxD = (gcnew System::Windows::Forms::Label());
			   this->textBoxC = (gcnew System::Windows::Forms::Label());
			   this->textBoxB = (gcnew System::Windows::Forms::Label());
			   this->textBoxA = (gcnew System::Windows::Forms::Label());
			   this->MissLabel = (gcnew System::Windows::Forms::Label());
			   this->DigitalStopWatch = (gcnew System::Windows::Forms::Label());
			   this->missTimer = (gcnew System::Windows::Forms::Timer(this->components));
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Barrier))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wasd))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->space))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playerlevel1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbstart))->BeginInit();
			   this->panelLogin->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid18))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid6))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid12))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid17))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid5))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid14))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid13))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid11))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid3))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid15))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid16))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid19))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid4))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid7))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid8))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid10))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid9))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid2))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // Transition1
			   // 
			   this->Transition1->Interval = 1;
			   this->Transition1->Tick += gcnew System::EventHandler(this, &lvl4Form::Transition1_Tick);
			   // 
			   // Transition2
			   // 
			   this->Transition2->Interval = 1;
			   this->Transition2->Tick += gcnew System::EventHandler(this, &lvl4Form::Transition2_Tick);
			   // 
			   // timerProgress
			   // 
			   this->timerProgress->Interval = 1;
			   this->timerProgress->Tick += gcnew System::EventHandler(this, &lvl4Form::timerProgress_Tick);
			   // 
			   // movePlayerTimer
			   // 
			   this->movePlayerTimer->Enabled = true;
			   this->movePlayerTimer->Interval = 1;
			   this->movePlayerTimer->Tick += gcnew System::EventHandler(this, &lvl4Form::movePlayerTimer_Tick);
			   // 
			   // timeranimation
			   // 
			   this->timeranimation->Enabled = true;
			   this->timeranimation->Interval = 1;
			   // 
			   // shootTimer
			   // 
			   this->shootTimer->Interval = 200;
			   this->shootTimer->Tick += gcnew System::EventHandler(this, &lvl4Form::shootTimer_Tick);
			   // 
			   // BulletTimer
			   // 
			   this->BulletTimer->Interval = 1;
			   this->BulletTimer->Tick += gcnew System::EventHandler(this, &lvl4Form::BulletTimer_Tick);
			   // 
			   // QuestionTransitionTimerShow
			   // 
			   this->QuestionTransitionTimerShow->Interval = 1;
			   this->QuestionTransitionTimerShow->Tick += gcnew System::EventHandler(this, &lvl4Form::QuestionTransitionTimerShow_Tick);
			   // 
			   // QuestionTransitionTimerHide
			   // 
			   this->QuestionTransitionTimerHide->Interval = 1000;
			   this->QuestionTransitionTimerHide->Tick += gcnew System::EventHandler(this, &lvl4Form::QuestionTransitionTimerHide_Tick);
			   // 
			   // timerfinal
			   // 
			   this->timerfinal->Interval = 2000;
			   this->timerfinal->Tick += gcnew System::EventHandler(this, &lvl4Form::timerfinal_Tick);
			   // 
			   // Barrier
			   // 
			   this->Barrier->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Barrier.Image")));
			   this->Barrier->Location = System::Drawing::Point(320, 224);
			   this->Barrier->Margin = System::Windows::Forms::Padding(4);
			   this->Barrier->Name = L"Barrier";
			   this->Barrier->Size = System::Drawing::Size(69, 656);
			   this->Barrier->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->Barrier->TabIndex = 36;
			   this->Barrier->TabStop = false;
			   this->Barrier->Visible = false;
			   // 
			   // pbGeneralMilitary
			   // 
			   this->pbGeneralMilitary->BackColor = System::Drawing::Color::Transparent;
			   this->pbGeneralMilitary->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			   this->pbGeneralMilitary->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbGeneralMilitary.Image")));
			   this->pbGeneralMilitary->Location = System::Drawing::Point(-325, 289);
			   this->pbGeneralMilitary->Margin = System::Windows::Forms::Padding(0);
			   this->pbGeneralMilitary->Name = L"pbGeneralMilitary";
			   this->pbGeneralMilitary->Size = System::Drawing::Size(371, 560);
			   this->pbGeneralMilitary->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pbGeneralMilitary->TabIndex = 11;
			   this->pbGeneralMilitary->TabStop = false;
			   // 
			   // lblMessage1
			   // 
			   this->lblMessage1->AutoSize = true;
			   this->lblMessage1->Font = (gcnew System::Drawing::Font(L"Courier New", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblMessage1->Location = System::Drawing::Point(330, 900);
			   this->lblMessage1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblMessage1->Name = L"lblMessage1";
			   this->lblMessage1->Size = System::Drawing::Size(0, 90);
			   this->lblMessage1->TabIndex = 1;
			   this->lblMessage1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			   // 
			   // progressBarLevel1
			   // 
			   this->progressBarLevel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->progressBarLevel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->progressBarLevel1->ForeColor = System::Drawing::Color::DarkOrange;
			   this->progressBarLevel1->Location = System::Drawing::Point(904, 31);
			   this->progressBarLevel1->Margin = System::Windows::Forms::Padding(4);
			   this->progressBarLevel1->Maximum = 1200;
			   this->progressBarLevel1->Name = L"progressBarLevel1";
			   this->progressBarLevel1->Size = System::Drawing::Size(562, 62);
			   this->progressBarLevel1->TabIndex = 12;
			   this->progressBarLevel1->Visible = false;
			   // 
			   // wasd
			   // 
			   this->wasd->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wasd.Image")));
			   this->wasd->Location = System::Drawing::Point(651, 776);
			   this->wasd->Margin = System::Windows::Forms::Padding(1);
			   this->wasd->Name = L"wasd";
			   this->wasd->Size = System::Drawing::Size(120, 90);
			   this->wasd->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->wasd->TabIndex = 15;
			   this->wasd->TabStop = false;
			   this->wasd->Visible = false;
			   // 
			   // space
			   // 
			   this->space->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"space.Image")));
			   this->space->Location = System::Drawing::Point(775, 799);
			   this->space->Margin = System::Windows::Forms::Padding(1);
			   this->space->Name = L"space";
			   this->space->Size = System::Drawing::Size(39, 49);
			   this->space->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->space->TabIndex = 16;
			   this->space->TabStop = false;
			   this->space->Visible = false;
			   // 
			   // playerlevel1
			   // 
			   this->playerlevel1->ImageLocation = L"assets/PlayerMove/spaceship.png";
			   this->playerlevel1->Location = System::Drawing::Point(61, 491);
			   this->playerlevel1->Margin = System::Windows::Forms::Padding(4);
			   this->playerlevel1->Name = L"playerlevel1";
			   this->playerlevel1->Size = System::Drawing::Size(121, 80);
			   this->playerlevel1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->playerlevel1->TabIndex = 35;
			   this->playerlevel1->TabStop = false;
			   this->playerlevel1->Visible = false;
			   // 
			   // textBoxQuestion
			   // 
			   this->textBoxQuestion->Font = (gcnew System::Drawing::Font(L"Courier New", 16.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->textBoxQuestion->ForeColor = System::Drawing::Color::Black;
			   this->textBoxQuestion->Location = System::Drawing::Point(0, 0);
			   this->textBoxQuestion->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			   this->textBoxQuestion->Name = L"textBoxQuestion";
			   this->textBoxQuestion->Padding = System::Windows::Forms::Padding(70, 0, 70, 0);
			   this->textBoxQuestion->Size = System::Drawing::Size(814, 225);
			   this->textBoxQuestion->TabIndex = 43;
			   this->textBoxQuestion->Text = L"label1";
			   this->textBoxQuestion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->textBoxQuestion->Visible = false;
			   this->textBoxQuestion->Click += gcnew System::EventHandler(this, &lvl4Form::textBoxQuestion_Click);
			   // 
			   // pbstart
			   // 
			   this->pbstart->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbstart.Image")));
			   this->pbstart->Location = System::Drawing::Point(500, 875);
			   this->pbstart->Margin = System::Windows::Forms::Padding(4);
			   this->pbstart->Name = L"pbstart";
			   this->pbstart->Size = System::Drawing::Size(311, 311);
			   this->pbstart->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbstart->TabIndex = 44;
			   this->pbstart->TabStop = false;
			   this->pbstart->Click += gcnew System::EventHandler(this, &lvl4Form::pbstart_Click);
			   // 
			   // btnsafety
			   // 
			   this->btnsafety->ForeColor = System::Drawing::Color::Transparent;
			   this->btnsafety->Location = System::Drawing::Point(1549, 4);
			   this->btnsafety->Margin = System::Windows::Forms::Padding(4);
			   this->btnsafety->Name = L"btnsafety";
			   this->btnsafety->Size = System::Drawing::Size(145, 824);
			   this->btnsafety->TabIndex = 45;
			   this->btnsafety->Text = L"button1";
			   this->btnsafety->UseVisualStyleBackColor = true;
			   this->btnsafety->Visible = false;
			   // 
			   // panelLogin
			   // 
			   this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			   this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));
			   this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->panelLogin->Controls->Add(this->pbAsteroid18);
			   this->panelLogin->Controls->Add(this->pbAsteroid6);
			   this->panelLogin->Controls->Add(this->pbAsteroid12);
			   this->panelLogin->Controls->Add(this->pbAsteroid17);
			   this->panelLogin->Controls->Add(this->pbAsteroid5);
			   this->panelLogin->Controls->Add(this->pbAsteroid14);
			   this->panelLogin->Controls->Add(this->pbAsteroid13);
			   this->panelLogin->Controls->Add(this->pbAsteroid11);
			   this->panelLogin->Controls->Add(this->pbAsteroid3);
			   this->panelLogin->Controls->Add(this->pbAsteroid15);
			   this->panelLogin->Controls->Add(this->pbAsteroid16);
			   this->panelLogin->Controls->Add(this->pbAsteroid19);
			   this->panelLogin->Controls->Add(this->pbAsteroid4);
			   this->panelLogin->Controls->Add(this->pbAsteroid7);
			   this->panelLogin->Controls->Add(this->pbAsteroid8);
			   this->panelLogin->Controls->Add(this->pbAsteroid1);
			   this->panelLogin->Controls->Add(this->pbAsteroid10);
			   this->panelLogin->Controls->Add(this->pbAsteroid9);
			   this->panelLogin->Controls->Add(this->pbAsteroid2);
			   this->panelLogin->Controls->Add(this->lvl1Brief);
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
			   this->panelLogin->Controls->Add(this->Barrier);
			   this->panelLogin->ForeColor = System::Drawing::Color::White;
			   this->panelLogin->Location = System::Drawing::Point(0, 0);
			   this->panelLogin->Margin = System::Windows::Forms::Padding(4);
			   this->panelLogin->Name = L"panelLogin";
			   this->panelLogin->Size = System::Drawing::Size(1540, 852);
			   this->panelLogin->TabIndex = 12;
			   // 
			   // pbAsteroid18
			   // 
			   this->pbAsteroid18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid18.Image")));
			   this->pbAsteroid18->Location = System::Drawing::Point(438, 645);
			   this->pbAsteroid18->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid18->Name = L"pbAsteroid18";
			   this->pbAsteroid18->Size = System::Drawing::Size(44, 42);
			   this->pbAsteroid18->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid18->TabIndex = 79;
			   this->pbAsteroid18->TabStop = false;
			   this->pbAsteroid18->Visible = false;
			   // 
			   // pbAsteroid6
			   // 
			   this->pbAsteroid6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid6.Image")));
			   this->pbAsteroid6->Location = System::Drawing::Point(788, 267);
			   this->pbAsteroid6->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid6->Name = L"pbAsteroid6";
			   this->pbAsteroid6->Size = System::Drawing::Size(42, 42);
			   this->pbAsteroid6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid6->TabIndex = 78;
			   this->pbAsteroid6->TabStop = false;
			   this->pbAsteroid6->Visible = false;
			   // 
			   // pbAsteroid12
			   // 
			   this->pbAsteroid12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid12.Image")));
			   this->pbAsteroid12->Location = System::Drawing::Point(487, 447);
			   this->pbAsteroid12->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid12->Name = L"pbAsteroid12";
			   this->pbAsteroid12->Size = System::Drawing::Size(51, 45);
			   this->pbAsteroid12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid12->TabIndex = 77;
			   this->pbAsteroid12->TabStop = false;
			   this->pbAsteroid12->Visible = false;
			   // 
			   // pbAsteroid17
			   // 
			   this->pbAsteroid17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid17.Image")));
			   this->pbAsteroid17->Location = System::Drawing::Point(431, 530);
			   this->pbAsteroid17->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid17->Name = L"pbAsteroid17";
			   this->pbAsteroid17->Size = System::Drawing::Size(51, 39);
			   this->pbAsteroid17->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid17->TabIndex = 76;
			   this->pbAsteroid17->TabStop = false;
			   this->pbAsteroid17->Visible = false;
			   // 
			   // pbAsteroid5
			   // 
			   this->pbAsteroid5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid5.Image")));
			   this->pbAsteroid5->Location = System::Drawing::Point(420, 734);
			   this->pbAsteroid5->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid5->Name = L"pbAsteroid5";
			   this->pbAsteroid5->Size = System::Drawing::Size(98, 70);
			   this->pbAsteroid5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid5->TabIndex = 75;
			   this->pbAsteroid5->TabStop = false;
			   this->pbAsteroid5->Visible = false;
			   // 
			   // pbAsteroid14
			   // 
			   this->pbAsteroid14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid14.Image")));
			   this->pbAsteroid14->Location = System::Drawing::Point(757, 598);
			   this->pbAsteroid14->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid14->Name = L"pbAsteroid14";
			   this->pbAsteroid14->Size = System::Drawing::Size(44, 39);
			   this->pbAsteroid14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid14->TabIndex = 74;
			   this->pbAsteroid14->TabStop = false;
			   this->pbAsteroid14->Visible = false;
			   // 
			   // pbAsteroid13
			   // 
			   this->pbAsteroid13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid13.Image")));
			   this->pbAsteroid13->Location = System::Drawing::Point(811, 530);
			   this->pbAsteroid13->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid13->Name = L"pbAsteroid13";
			   this->pbAsteroid13->Size = System::Drawing::Size(44, 39);
			   this->pbAsteroid13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid13->TabIndex = 73;
			   this->pbAsteroid13->TabStop = false;
			   this->pbAsteroid13->Visible = false;
			   // 
			   // pbAsteroid11
			   // 
			   this->pbAsteroid11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid11.Image")));
			   this->pbAsteroid11->Location = System::Drawing::Point(743, 482);
			   this->pbAsteroid11->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid11->Name = L"pbAsteroid11";
			   this->pbAsteroid11->Size = System::Drawing::Size(44, 39);
			   this->pbAsteroid11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid11->TabIndex = 72;
			   this->pbAsteroid11->TabStop = false;
			   this->pbAsteroid11->Visible = false;
			   // 
			   // pbAsteroid3
			   // 
			   this->pbAsteroid3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid3.Image")));
			   this->pbAsteroid3->Location = System::Drawing::Point(605, 547);
			   this->pbAsteroid3->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid3->Name = L"pbAsteroid3";
			   this->pbAsteroid3->Size = System::Drawing::Size(120, 90);
			   this->pbAsteroid3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid3->TabIndex = 71;
			   this->pbAsteroid3->TabStop = false;
			   this->pbAsteroid3->Visible = false;
			   // 
			   // pbAsteroid15
			   // 
			   this->pbAsteroid15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid15.Image")));
			   this->pbAsteroid15->Location = System::Drawing::Point(513, 587);
			   this->pbAsteroid15->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid15->Name = L"pbAsteroid15";
			   this->pbAsteroid15->Size = System::Drawing::Size(32, 25);
			   this->pbAsteroid15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid15->TabIndex = 70;
			   this->pbAsteroid15->TabStop = false;
			   this->pbAsteroid15->Visible = false;
			   // 
			   // pbAsteroid16
			   // 
			   this->pbAsteroid16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid16.Image")));
			   this->pbAsteroid16->Location = System::Drawing::Point(723, 682);
			   this->pbAsteroid16->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid16->Name = L"pbAsteroid16";
			   this->pbAsteroid16->Size = System::Drawing::Size(48, 36);
			   this->pbAsteroid16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid16->TabIndex = 69;
			   this->pbAsteroid16->TabStop = false;
			   this->pbAsteroid16->Visible = false;
			   // 
			   // pbAsteroid19
			   // 
			   this->pbAsteroid19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid19.Image")));
			   this->pbAsteroid19->Location = System::Drawing::Point(513, 682);
			   this->pbAsteroid19->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid19->Name = L"pbAsteroid19";
			   this->pbAsteroid19->Size = System::Drawing::Size(48, 36);
			   this->pbAsteroid19->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid19->TabIndex = 68;
			   this->pbAsteroid19->TabStop = false;
			   this->pbAsteroid19->Visible = false;
			   // 
			   // pbAsteroid4
			   // 
			   this->pbAsteroid4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid4.Image")));
			   this->pbAsteroid4->Location = System::Drawing::Point(590, 682);
			   this->pbAsteroid4->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid4->Name = L"pbAsteroid4";
			   this->pbAsteroid4->Size = System::Drawing::Size(94, 78);
			   this->pbAsteroid4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid4->TabIndex = 67;
			   this->pbAsteroid4->TabStop = false;
			   this->pbAsteroid4->Visible = false;
			   // 
			   // pbAsteroid7
			   // 
			   this->pbAsteroid7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid7.Image")));
			   this->pbAsteroid7->Location = System::Drawing::Point(487, 273);
			   this->pbAsteroid7->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid7->Name = L"pbAsteroid7";
			   this->pbAsteroid7->Size = System::Drawing::Size(48, 36);
			   this->pbAsteroid7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid7->TabIndex = 66;
			   this->pbAsteroid7->TabStop = false;
			   this->pbAsteroid7->Visible = false;
			   // 
			   // pbAsteroid8
			   // 
			   this->pbAsteroid8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid8.Image")));
			   this->pbAsteroid8->Location = System::Drawing::Point(753, 361);
			   this->pbAsteroid8->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid8->Name = L"pbAsteroid8";
			   this->pbAsteroid8->Size = System::Drawing::Size(48, 36);
			   this->pbAsteroid8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid8->TabIndex = 65;
			   this->pbAsteroid8->TabStop = false;
			   this->pbAsteroid8->Visible = false;
			   // 
			   // pbAsteroid1
			   // 
			   this->pbAsteroid1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid1.Image")));
			   this->pbAsteroid1->Location = System::Drawing::Point(618, 252);
			   this->pbAsteroid1->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid1->Name = L"pbAsteroid1";
			   this->pbAsteroid1->Size = System::Drawing::Size(98, 70);
			   this->pbAsteroid1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid1->TabIndex = 64;
			   this->pbAsteroid1->TabStop = false;
			   this->pbAsteroid1->Visible = false;
			   // 
			   // pbAsteroid10
			   // 
			   this->pbAsteroid10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid10.Image")));
			   this->pbAsteroid10->Location = System::Drawing::Point(618, 476);
			   this->pbAsteroid10->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid10->Name = L"pbAsteroid10";
			   this->pbAsteroid10->Size = System::Drawing::Size(48, 36);
			   this->pbAsteroid10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid10->TabIndex = 63;
			   this->pbAsteroid10->TabStop = false;
			   this->pbAsteroid10->Visible = false;
			   // 
			   // pbAsteroid9
			   // 
			   this->pbAsteroid9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid9.Image")));
			   this->pbAsteroid9->Location = System::Drawing::Point(460, 352);
			   this->pbAsteroid9->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid9->Name = L"pbAsteroid9";
			   this->pbAsteroid9->Size = System::Drawing::Size(44, 45);
			   this->pbAsteroid9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid9->TabIndex = 62;
			   this->pbAsteroid9->TabStop = false;
			   this->pbAsteroid9->Visible = false;
			   // 
			   // pbAsteroid2
			   // 
			   this->pbAsteroid2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAsteroid2.Image")));
			   this->pbAsteroid2->Location = System::Drawing::Point(581, 353);
			   this->pbAsteroid2->Margin = System::Windows::Forms::Padding(1);
			   this->pbAsteroid2->Name = L"pbAsteroid2";
			   this->pbAsteroid2->Size = System::Drawing::Size(125, 95);
			   this->pbAsteroid2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbAsteroid2->TabIndex = 61;
			   this->pbAsteroid2->TabStop = false;
			   this->pbAsteroid2->Visible = false;
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
			   // textBoxTFB
			   // 
			   this->textBoxTFB->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBoxTFB->ForeColor = System::Drawing::Color::Black;
			   this->textBoxTFB->Location = System::Drawing::Point(1272, 619);
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
			   this->textBoxTFA->Location = System::Drawing::Point(1275, 352);
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
			   this->textBoxD->Location = System::Drawing::Point(1243, 684);
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
			   this->textBoxC->Location = System::Drawing::Point(1243, 538);
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
			   this->textBoxB->Location = System::Drawing::Point(1243, 392);
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
			   this->textBoxA->Location = System::Drawing::Point(1243, 252);
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
			   this->DigitalStopWatch->Location = System::Drawing::Point(904, 175);
			   this->DigitalStopWatch->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->DigitalStopWatch->Name = L"DigitalStopWatch";
			   this->DigitalStopWatch->Size = System::Drawing::Size(116, 31);
			   this->DigitalStopWatch->TabIndex = 48;
			   this->DigitalStopWatch->Text = L"label1";
			   this->DigitalStopWatch->Visible = false;
			   this->DigitalStopWatch->Click += gcnew System::EventHandler(this, &lvl4Form::DigitalStopWatch_Click);
			   // 
			   // missTimer
			   // 
			   this->missTimer->Interval = 500;
			   this->missTimer->Tick += gcnew System::EventHandler(this, &lvl4Form::missTimer_Tick);
			   // 
			   // lvl4Form
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			   this->ClientSize = System::Drawing::Size(1580, 851);
			   this->Controls->Add(this->panelLogin);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"lvl4Form";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Level 4 of 4";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &lvl4Form::lvl4Form_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &lvl4Form::lvl4Form_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &lvl4Form::lvl4Form_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &lvl4Form::lvl4Form_KeyUp);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Barrier))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wasd))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->space))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playerlevel1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbstart))->EndInit();
			   this->panelLogin->ResumeLayout(false);
			   this->panelLogin->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid18))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid6))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid12))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid17))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid5))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid14))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid13))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid11))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid3))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid15))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid16))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid19))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid4))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid7))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid8))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid10))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid9))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAsteroid2))->EndInit();
			   this->ResumeLayout(false);

		   }

#pragma endregion


	private:
		// Player object
		playerInfo^ player;

		// Level Methods object
		LevelMethods^ LvlMethods;

		// Music objects
		MusicAndSFX* soundAnswer = new MusicAndSFX();
		MusicAndSFX* soundImpact = new MusicAndSFX();
		MusicAndSFX* ambience = new MusicAndSFX();
		MusicAndSFX* music = new MusicAndSFX();
		MusicAndSFX* destroy = new MusicAndSFX();

		array<definedPictureBox^>^ pictureBoxArray;

		// Destructible objects
		Destructible^ des = gcnew Destructible;
		Destructible::DestroyFunction^ destroyFuncA = gcnew Destructible::DestroyFunction(this, &lvl4Form::destroyA);
		Destructible::DestroyFunction^ destroyFuncB = gcnew Destructible::DestroyFunction(this, &lvl4Form::destroyB);
		Destructible::DestroyFunction^ destroyFuncC = gcnew Destructible::DestroyFunction(this, &lvl4Form::destroyC);
		Destructible::DestroyFunction^ destroyFuncD = gcnew Destructible::DestroyFunction(this, &lvl4Form::destroyD);
		Destructible::DestroyFunction^ destroyFuncTF1 = gcnew Destructible::DestroyFunction(this, &lvl4Form::destroyTF1);
		Destructible::DestroyFunction^ destroyFuncTF2 = gcnew Destructible::DestroyFunction(this, &lvl4Form::destroyTF2);
		Destructible::DestroyFunction^ destroyFuncSafety = gcnew Destructible::DestroyFunction(this, &lvl4Form::destroySafety);
		Destructible::DestroyFunction^ destroyFuncObstacle = gcnew Destructible::DestroyFunction(this, &lvl4Form::destroyObstacle);

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

		// Player animations
		String^ playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\spaceship.png");
		String^ playerRunRightGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\spaceship_boost.gif");
		String^ playerRunLeftGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\spaceship_boost_left.gif");
		String^ playerShootGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\spaceship.png");

		bool levelcomplete = false;
		bool isleft;
		bool canshoot = false;

		// Player animation variables:
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
			Creates and displays the "Welcome to level 4" pop up,
			Initalizes the player info object with info from PlayerInfo.txt
			Plays the levels' (background) music
		*/
		System::Void lvl4Form_Load(System::Object^ sender, System::EventArgs^ e) {
			Image^ backgroundImage = Image::FromFile("assets/Backgrounds/spaceblackrectangle.png");
			panelLogin->BackgroundImage = backgroundImage;

			this->ClientSize = System::Drawing::Size(1232, 682);

			lvl1Brief->Text = "Level 4 Brief:\n\n• 10 questions.\n\n• Multiple choice and true/false questions.\n\n• Shoot the meteor that contains confetti, i.e. The correct answer.\n\n• Destroy any obstructions.\n\n• 12 seconds per question.\n\n• Missing a target adds 10sec to your timer!\n\nAll The Best Soldier!!\n\n<Click Start To Begin>";

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
			std::string windowPrompt = "Welcome to the final mission, " + context.marshal_as<std::string>(this->player->username) + ". This level simulation takes place in space. \nWhere, as we are sure you know, no one can hear you scream :D \nOh, and " + context.marshal_as<std::string>(this->player->username) + "... \n\ndon't forget to breathe ;)";
			String^ unwrapped = gcnew String(windowPrompt.c_str());
			popup^ window = gcnew popup(unwrapped, 0, 0, "assets/level_transition_background.png");
			window->Visible = false;
			this->Hide();
			window->ShowDialog();

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			System::String^ recruitname = this->player->username;

			Transition1->Start();

			playerlevel1->ImageLocation = "assets/PlayerMove/spaceship.png";

			bullet = gcnew definedPictureBox(panelLogin, 15, 6, playerlevel1->Location.X, playerlevel1->Location.Y, "assets/Bullets/5.png", false);
			bullet->Hide();

			pictureBoxArray = gcnew array<definedPictureBox^>(10);
			int pbWidth = 45;
			int pbHeight = 45;


			System::String^ imagePath = "assets/Logos/logo_default.png";
			Image^ image = Image::FromFile(imagePath);
			for (int i = 0; i < 10; i++) {

				pictureBoxArray[i] = gcnew definedPictureBox(panelLogin, pbWidth, pbHeight, 723 + (i * pbWidth), 85, imagePath, false);

			}

			openedDoor = gcnew definedPictureBox();

			textBoxQuestion->BackgroundImage = Image::FromFile("assets/Backgrounds/alt.png");
			textBoxQuestion->BackgroundImageLayout = ImageLayout::Stretch;

			des->addObject(this->btnsafety, destroyFuncSafety);
			//Asteroids/Obstacle
			des->addObject(this->pbAsteroid1, destroyFuncObstacle);
			des->addObject(this->pbAsteroid2, destroyFuncObstacle);
			des->addObject(this->pbAsteroid3, destroyFuncObstacle);
			des->addObject(this->pbAsteroid4, destroyFuncObstacle);
			des->addObject(this->pbAsteroid5, destroyFuncObstacle);
			des->addObject(this->pbAsteroid6, destroyFuncObstacle);
			des->addObject(this->pbAsteroid7, destroyFuncObstacle);
			des->addObject(this->pbAsteroid8, destroyFuncObstacle);
			des->addObject(this->pbAsteroid9, destroyFuncObstacle);
			des->addObject(this->pbAsteroid10, destroyFuncObstacle);
			des->addObject(this->pbAsteroid11, destroyFuncObstacle);
			des->addObject(this->pbAsteroid12, destroyFuncObstacle);
			des->addObject(this->pbAsteroid13, destroyFuncObstacle);
			des->addObject(this->pbAsteroid14, destroyFuncObstacle);
			des->addObject(this->pbAsteroid15, destroyFuncObstacle);
			des->addObject(this->pbAsteroid16, destroyFuncObstacle);
			des->addObject(this->pbAsteroid17, destroyFuncObstacle);
			des->addObject(this->pbAsteroid18, destroyFuncObstacle);
			des->addObject(this->pbAsteroid19, destroyFuncObstacle);

			ambience->Space();
			music->Level4Music();
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
			if (x2 >= 1008)
			{
				x2 -= 10;
			}

			pbGeneralMilitary->Location = Point(x1, 230);
			lblMessage1->Location = Point(395, y1);
			pbstart->Location = Point(405, y2);
			lvl1Brief->Location = Point(x2, 220);
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

			if (!(x1 >= -325) && !(y1 <= 900) && !(y2 <= 1000))
			{
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
				Image^ backgroundImage = Image::FromFile("assets/Backgrounds/SpaceBackground.png");
				panelLogin->BackgroundImage = backgroundImage;
				canshoot = true;

				pictureBoxA = gcnew definedPictureBox(panelLogin, 90, 80, 850, 215, "assets/Doors/meteor_1.png", false);
				pictureBoxA->Show();
				pictureBoxB = gcnew definedPictureBox(panelLogin, 90, 80, 850, 335, "assets/Doors/meteor_1.png", false);
				pictureBoxB->Show();
				pictureBoxC = gcnew definedPictureBox(panelLogin, 90, 80, 850, 455, "assets/Doors/meteor_1.png", false);
				pictureBoxC->Show();
				pictureBoxD = gcnew definedPictureBox(panelLogin, 90, 80, 850, 575, "assets/Doors/meteor_1.png", false);
				pictureBoxD->Show();

				des->addObject(pictureBoxA, destroyFuncA);
				des->addObject(pictureBoxB, destroyFuncB);
				des->addObject(pictureBoxC, destroyFuncC);
				des->addObject(pictureBoxD, destroyFuncD);

				for (int i = 0; i < 10; i++) {
					pictureBoxArray[i]->setVisible(true);

				}

				pbAsteroid1->Visible = true;
				pbAsteroid2->Visible = true;
				pbAsteroid3->Visible = true;
				pbAsteroid4->Visible = true;
				pbAsteroid5->Visible = true;
				pbAsteroid6->Visible = true;
				pbAsteroid7->Visible = true;
				pbAsteroid8->Visible = true;
				pbAsteroid9->Visible = true;
				pbAsteroid10->Visible = true;
				pbAsteroid11->Visible = true;
				pbAsteroid12->Visible = true;
				pbAsteroid13->Visible = true;
				pbAsteroid14->Visible = true;
				pbAsteroid15->Visible = true;
				pbAsteroid16->Visible = true;
				pbAsteroid17->Visible = true;
				pbAsteroid18->Visible = true;
				pbAsteroid19->Visible = true;

				LvlMethods->DisplayNextQuestionSet();


			}
			pbGeneralMilitary->Location = Point(x1, 230);
			lblMessage1->Location = Point(395, y1);
			pbstart->Location = Point(405, y2);
			lvl1Brief->Location = Point(x2, 220);
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

			pictureBoxTF1 = gcnew definedPictureBox(panelLogin, 225, 200, 750, 215, "assets/Doors/meteor_1.png", false);

			des->addObject(pictureBoxTF1, destroyFuncTF1);

			LvlMethods->QuestionAnswered(0);

			if (LvlMethods->Correct)
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 750, 215, "assets/Doors/meteor_explode_right.png", false);
			}
			else
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 750, 215, "assets/Doors/meteor_explode.png", false);
			}
			openedDoor->setVisible(true);

			if (LvlMethods->QuestionsCompleted == 10)
			{
				this->btnsafety->Location = Point(308, 0);
				this->btnsafety->Size = System::Drawing::Size(653, 693);
				delete this->pictureBoxTF1;
				delete this->pictureBoxTF2;
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

			pictureBoxTF2 = gcnew definedPictureBox(panelLogin, 225, 200, 750, 455, "assets/Doors/meteor_1.png", false);

			des->addObject(pictureBoxTF2, destroyFuncTF2);

			LvlMethods->QuestionAnswered(1);

			if (LvlMethods->Correct)
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 750, 455, "assets/Doors/meteor_explode_right.png", false);
			}
			else
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 750, 455, "assets/Doors/meteor_explode.png", false);
			}
			openedDoor->setVisible(true);

			if (LvlMethods->QuestionsCompleted == 10)
			{
				this->btnsafety->Location = Point(308, 0);
				this->btnsafety->Size = System::Drawing::Size(653, 693);
				delete this->pictureBoxTF1;
				delete this->pictureBoxTF2;
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

			pictureBoxA = gcnew definedPictureBox(panelLogin, 90, 80, 850, 215, "assets/Doors/meteor_1.png", false);

			des->addObject(pictureBoxA, destroyFuncA);

			LvlMethods->QuestionAnswered(0);

			if (LvlMethods->Correct)
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 215, "assets/Doors/meteor_explode_right.png", false);
			}
			else
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 215, "assets/Doors/meteor_explode.png", false);
			}
			openedDoor->setVisible(true);

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

			pictureBoxB = gcnew definedPictureBox(panelLogin, 90, 80, 850, 335, "assets/Doors/meteor_1.png", false);

			des->addObject(pictureBoxB, destroyFuncB);

			LvlMethods->QuestionAnswered(1);

			if (LvlMethods->Correct)
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 335, "assets/Doors/meteor_explode_right.png", false);
			}
			else
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 335, "assets/Doors/meteor_explode.png", false);
			}
			openedDoor->setVisible(true);

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

			pictureBoxC = gcnew definedPictureBox(panelLogin, 90, 80, 850, 455, "assets/Doors/meteor_1.png", false);

			des->addObject(pictureBoxC, destroyFuncC);

			LvlMethods->QuestionAnswered(2);

			if (LvlMethods->Correct)
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 455, "assets/Doors/meteor_explode_right.png", false);
			}
			else
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 455, "assets/Doors/meteor_explode.png", false);
			}
			openedDoor->setVisible(true);

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



			pictureBoxD = gcnew definedPictureBox(panelLogin, 90, 80, 850, 575, "assets/Doors/meteor_1.png", false);

			des->addObject(pictureBoxD, destroyFuncD);
			LvlMethods->QuestionAnswered(3);

			if (LvlMethods->Correct)
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 575, "assets/Doors/meteor_explode_right.png", false);
			}
			else
			{
				openedDoor = gcnew definedPictureBox(panelLogin, 90, 80, 850, 575, "assets/Doors/meteor_explode.png", false);
			}
			openedDoor->setVisible(true);

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
			if (LvlMethods->QuestionsCompleted != 10) {
				ambience->playRandomSound("assets\\music\\ES_Human Grunt 15 - SFX Producer.wav", false);
			}
			
		}

		//Asteroids
		void destroyObstacle(){
			destroy->playRandomSound("assets\\music\\ES_Explosion Space 1 - SFX Producer.wav", false);
		}

		/*
			Hides the "+10 seconds" label 1 second after the player misses a target
			Shows the player that 10 seconds has been added to their time
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
		System::Void lvl4Form_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			e->SuppressKeyPress = true;
			if (LvlMethods->DisableControls != true) {

				if (e->KeyCode == Keys::Space && canshoot)
				{
					if (des->getBulletCount() == 0 && !isleft) {
						shootTimer->Start();
						soundAnswer->Laser();
					}
				}
			}

			if (e->KeyCode == Keys::W)
			{
				move_up = true;
				is_w_up = false;
				
			}
			if (e->KeyCode == Keys::A)
			{
				if (!isleft) {
					playerlevel1->ImageLocation = playerRunLeftGifPath;
				}
				isleft = true;
				move_left = true;
				is_a_up = false;
				
			}
			if (e->KeyCode == Keys::S)
			{
				move_down = true;
				is_s_up = false;
				
			}
			if (e->KeyCode == Keys::D)
			{
				if (isleft) {
					playerlevel1->ImageLocation = playerRunRightGifPath;
				}
				isleft = false;
				move_right = true;
				is_d_up = false;
				
			}
		}

		/*
			Checks when the keys for moving aren't being pressed
			Sets the required player animations
		*/
		System::Void lvl4Form_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
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
					playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\spaceship_left.png");
				}
				else
				{
					playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\spaceship.png");
				}
				playerlevel1->ImageLocation = playerIdleGifPath;
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
					playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\spaceship_boost_left.gif");
				}
				else
				{
					playerIdleGifPath = System::IO::Path::Combine(projectDirectory, "assets\\PlayerMove\\spaceship_boost.gif");
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
			if (move_down && playerlevel1->Top < 600)
			{
				playerlevel1->Top += 5;
			}
			if (move_right && playerlevel1->Left < 140)
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

				addBullet(10, 0, playerlevel1->Location.X + 80, playerlevel1->Location.Y + 28);
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
			bullet = gcnew definedPictureBox(panelLogin, 15, 6, playerlevel1->Location.X, playerlevel1->Location.Y, "assets/Bullets/5.png", false);
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
				soundImpact->BulletImpact();

			}
			else {
				LvlMethods->Correct = false;
				QuestionTransitionTimerHide->Start();
				QuestionTransitionTimerShow->Stop();

				pictureBoxArray[currentFeedbackLogoNum]->Image = Image::FromFile("assets/Logos/logo_incorrect.png");
				currentFeedbackLogoNum++;

				soundAnswer->IncorrectAnswer();
				soundImpact->BulletImpact();
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

				pictureBoxTF1 = gcnew definedPictureBox(panelLogin, 225, 200, 750, 215, "assets/Doors/meteor_1.png", false);
				pictureBoxTF1->Hide();
				pictureBoxTF2 = gcnew definedPictureBox(panelLogin, 225, 200, 750, 455, "assets/Doors/meteor_1.png", false);
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

						pictureBoxTF1 = gcnew definedPictureBox(panelLogin, 150, 240, 850, 195, "assets/Doors/meteor_1.png", false);
						pictureBoxTF1->Hide();
						pictureBoxTF2 = gcnew definedPictureBox(panelLogin, 150, 240, 850, 435, "assets/Doors/meteor_1.png", false);
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
				openedDoor->BringToFront();
				if (LvlMethods->Correct)
				{
					openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 750, 215, "assets/Doors/meteor_explode_right.png", false);
				}
				else
				{
					openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 750, 215, "assets/Doors/meteor_explode.png", false);
				}
				openedDoor->setVisible(true);

			}
			else if (str == "F")
			{
				openedDoor->BringToFront();
				if (LvlMethods->Correct)
				{
					openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 750, 455, "assets/Doors/meteor_explode_right.png", false);
				}
				else
				{
					openedDoor = gcnew definedPictureBox(panelLogin, 225, 200, 750, 455, "assets/Doors/meteor_explode.png", false);
				}
				openedDoor->setVisible(true);
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
			timerfinal->Enabled = false;
			timerfinal->Stop();
			levelcomplete = true;
	

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
			destroy->StopSound();

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

			std::string windowPrompt = "Level 4 feedback (Final Level - Space)\n\nNumber of correct answers: " + std::to_string(LvlMethods->PlayerStats->CorrectAnswers) + "\nTime Taken: " + std::to_string(levelTimeTaken) + " seconds\nScore: " + std::to_string(levelScore) + " Points\n\nOverall time taken: " + std::to_string(this->player->timeTaken) + " seconds\nOverall score: " + std::to_string(this->player->score) + " Points\nPlease proceed to the final bonus level.";
			String^ unwrapped = gcnew String(windowPrompt.c_str());
			popup^ window = gcnew popup(unwrapped, 0, 0, "assets/Backgrounds/SpaceBackgroundDark.png");

			window->Visible = false;
			this->Hide();
			soundImpact->playRandomSound("assets\\music\\ES_Sci Fi Spaceship 28 - SFX Producer.wav",false);

			window->ShowDialog();
			delete soundAnswer;
			delete ambience;
			delete soundImpact;
			delete music;
			delete destroy;

			BonusLevelFour^ bonus4 = gcnew BonusLevelFour();
			this->Hide();
			bonus4->ShowDialog();
			this->Close();
		}

	private:
		/*
			Displays a confirmation prompt when the player attempts to close the game
			Yes: Closes the game (No progress saved)
			No: Closes the confirmation prompt (Game stays open)
		*/
		System::Void lvl4Form_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			if (!levelcomplete) {
				if (MessageBox::Show("Are you sure you want to eliminate yourself?", "", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
				{
					e->Cancel = true;
					panelLogin->Focus();
				}
			}

		}
	private: System::Void DigitalStopWatch_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBoxQuestion_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
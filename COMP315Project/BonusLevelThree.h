#pragma once
#include <math.h>
#include <iostream>
#include <fstream>
#include "popup.h"
#include "LoadQuestion.h"
#include "PictureBox.h"
#include "MusicAndSFX.h"
namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BonusLevelOne
	/// </summary>
	public ref class BonusLevelThree : public System::Windows::Forms::Form
	{
		MusicAndSFX* sound = new MusicAndSFX();
	public:
		BonusLevelThree(void)
		{
			InitializeComponent();
			
			sound->Forest();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BonusLevelThree()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelBonusLevel;
	protected:

	protected:

	private: System::Windows::Forms::Label^ lblMessage1;
	private: System::Windows::Forms::PictureBox^ pbGeneralMilitary;

	private: System::Windows::Forms::Timer^ TargetTimer;
	private: System::Windows::Forms::Timer^ Transition2;
	private: System::Windows::Forms::Timer^ Transition1;
	private: System::Windows::Forms::ProgressBar^ countdownBar;

	private: System::Windows::Forms::Timer^ countdown;

	private: System::Windows::Forms::PictureBox^ pictureBox1;







	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BonusLevelThree::typeid));
			this->panelBonusLevel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->countdownBar = (gcnew System::Windows::Forms::ProgressBar());
			this->lblMessage1 = (gcnew System::Windows::Forms::Label());
			this->pbGeneralMilitary = (gcnew System::Windows::Forms::PictureBox());
			this->TargetTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Transition2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Transition1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->countdown = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelBonusLevel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->BeginInit();
			this->SuspendLayout();
			// 
			// panelBonusLevel
			// 
			this->panelBonusLevel->BackColor = System::Drawing::Color::Transparent;
			this->panelBonusLevel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelBonusLevel.BackgroundImage")));
			this->panelBonusLevel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelBonusLevel->Controls->Add(this->pictureBox1);
			this->panelBonusLevel->Controls->Add(this->countdownBar);
			this->panelBonusLevel->Controls->Add(this->lblMessage1);
			this->panelBonusLevel->Controls->Add(this->pbGeneralMilitary);
			this->panelBonusLevel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->panelBonusLevel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->panelBonusLevel->ForeColor = System::Drawing::Color::White;
			this->panelBonusLevel->Location = System::Drawing::Point(-11, -25);
			this->panelBonusLevel->Margin = System::Windows::Forms::Padding(4);
			this->panelBonusLevel->Name = L"panelBonusLevel";
			this->panelBonusLevel->Size = System::Drawing::Size(1600, 900);
			this->panelBonusLevel->TabIndex = 13;
			this->panelBonusLevel->Click += gcnew System::EventHandler(this, &BonusLevelThree::panelLogin_Click);
			this->panelBonusLevel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BonusLevelThree::panelBonusLevel_Paint);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(-17, -32);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// countdownBar
			// 
			this->countdownBar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->countdownBar->ForeColor = System::Drawing::Color::Red;
			this->countdownBar->Location = System::Drawing::Point(467, 75);
			this->countdownBar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->countdownBar->Name = L"countdownBar";
			this->countdownBar->Size = System::Drawing::Size(629, 46);
			this->countdownBar->TabIndex = 12;
			this->countdownBar->Click += gcnew System::EventHandler(this, &BonusLevelThree::countdownBar_Click);
			// 
			// lblMessage1
			// 
			this->lblMessage1->AutoSize = true;
			this->lblMessage1->Font = (gcnew System::Drawing::Font(L"Courier New", 27, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMessage1->Location = System::Drawing::Point(380, 900);
			this->lblMessage1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblMessage1->Name = L"lblMessage1";
			this->lblMessage1->Size = System::Drawing::Size(0, 52);
			this->lblMessage1->TabIndex = 1;
			this->lblMessage1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// pbGeneralMilitary
			// 
			this->pbGeneralMilitary->BackColor = System::Drawing::Color::Transparent;
			this->pbGeneralMilitary->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pbGeneralMilitary->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbGeneralMilitary.Image")));
			this->pbGeneralMilitary->Location = System::Drawing::Point(-325, 245);
			this->pbGeneralMilitary->Margin = System::Windows::Forms::Padding(0);
			this->pbGeneralMilitary->Name = L"pbGeneralMilitary";
			this->pbGeneralMilitary->Size = System::Drawing::Size(371, 560);
			this->pbGeneralMilitary->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbGeneralMilitary->TabIndex = 11;
			this->pbGeneralMilitary->TabStop = false;
			// 
			// TargetTimer
			// 
			this->TargetTimer->Interval = 500;
			this->TargetTimer->Tick += gcnew System::EventHandler(this, &BonusLevelThree::TargetTimer_Tick);
			// 
			// Transition2
			// 
			this->Transition2->Interval = 1;
			this->Transition2->Tick += gcnew System::EventHandler(this, &BonusLevelThree::Transition2_Tick);
			// 
			// Transition1
			// 
			this->Transition1->Interval = 1;
			this->Transition1->Tick += gcnew System::EventHandler(this, &BonusLevelThree::Transition1_Tick);
			// 
			// countdown
			// 
			this->countdown->Interval = 1000;
			this->countdown->Tick += gcnew System::EventHandler(this, &BonusLevelThree::countdown_Tick);
			// 
			// BonusLevelThree
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1580, 850);
			this->Controls->Add(this->panelBonusLevel);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"BonusLevelThree";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BonusLevelOne";
			this->Load += gcnew System::EventHandler(this, &BonusLevelThree::BonusLevelOne_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &BonusLevelThree::BonusLevelOne_KeyDown);
			this->panelBonusLevel->ResumeLayout(false);
			this->panelBonusLevel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panelLogin_Click(System::Object^ sender, System::EventArgs^ e) {

	}

		   int countTotal = 0;

		   //@aveshr
		   array<definedPictureBox^>^ buttons = gcnew array<definedPictureBox^>(27);
		   array<definedPictureBox^>^ boxes = gcnew array<definedPictureBox^>(5);
	private: System::Void BonusLevelOne_Load(System::Object^ sender, System::EventArgs^ e) {

		Image^ backgroundImage = Image::FromFile("assets/Backgrounds/Forest.png");
		panelBonusLevel->BackgroundImage = backgroundImage;
		int x_pos, y_pos, x_size, y_size;
		srand(time(0));
		for (int i = 0; i < buttons->Length; i++) {
			delete buttons[i];

			x_pos = rand() % 1050 + 10;
			y_pos = rand() % 420 + 180;
			x_size = rand() % 20 + 65;
			y_size = rand() % 20 + 75;
			buttons[i] = gcnew definedPictureBox(panelBonusLevel, x_size, y_size, x_pos, y_pos, "assets/BonusLevel/idle.gif", true);

			buttons[i]->Text = i.ToString() + "h";
			buttons[i]->ForeColor = System::Drawing::Color::White;
			buttons[i]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));



		}

		for (int i = 0; i < buttons->Length; i++) {


			if (i > 0) {
				int j = i - 1;
				while (j >= 0) {
					if (buttons[i] == buttons[j])
					{
						x_pos = rand() % 1050 + 10;
						y_pos = rand() % 420 + 180;
						buttons[i]->setLocation(x_pos, y_pos);
						j = i - 1;
					}
					else {
						j--;
					}
				}
			}
		}

		int randomTargetX = 0;
		for (int i = 0; i < boxes->Length; i++)
		{
			randomTargetX = rand() % 5 + i*5;
			std::cout << randomTargetX << std::endl;
			boxes[i] = gcnew definedPictureBox(panelBonusLevel, buttons[randomTargetX]->Size.Width, buttons[randomTargetX]->Size.Height, buttons[randomTargetX]->Location.X, buttons[randomTargetX]->Location.Y, "assets/Doors/Box.png", true);

		}

		lblMessage1->Text = "Welcome to the third bonus level.\nEnemies may use a box as cover\nBREAK IT!\n\nHint: Use your mouse";
		Transition1->Start();
	}

		   //@aveshr
		   int targetNum = 0;
	private: System::Void TargetTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < boxes->Length; i++)
		{
			if (boxes[i]->Location.X == buttons[targetNum]->Location.X && boxes[i]->Location.Y == buttons[targetNum]->Location.Y) {
				boxes[i]->BringToFront();
				boxes[i]->setVisible(true);
			}
		}
		buttons[targetNum]->setVisible(true);
		if (targetNum == buttons->Length - 1) {
			TargetTimer->Stop();
		}
		targetNum++;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   //@aveshr
	private: System::Void Transition2_Tick(System::Object^ sender, System::EventArgs^ e) {
		Point p1 = pbGeneralMilitary->Location;
		Point p2 = lblMessage1->Location;

		int x = p1.X, y1 = p2.Y;

		if (x >= -325)
		{
			x -= 15;
		}
		if (y1 <= 900)
		{
			y1 += 15;
		}

		// ensuring all stuff leaves screen before showing the player
		if (!(x >= -325) && !(y1 <= 900))
		{
			panelBonusLevel->Cursor = gcnew System::Windows::Forms::Cursor("assets/Retical/ShootRetical2.cur");
			countdown->Start();
			TargetTimer->Start();
			Transition2->Enabled = false;
		}
		pbGeneralMilitary->Location = Point(x, 245);
		lblMessage1->Location = Point(380, y1);
	}
		   //@aveshr
	private: System::Void Transition1_Tick(System::Object^ sender, System::EventArgs^ e) {

		Point p1 = pbGeneralMilitary->Location;
		Point p2 = lblMessage1->Location;
		int x = p1.X, y1 = p2.Y;

		if (x <= 40)
		{
			x += 10;
		}
		if (y1 >= 400)
		{
			y1 -= 10;
		}

		pbGeneralMilitary->Location = Point(x, 245);
		lblMessage1->Location = Point(380, y1);
	}
		   //@aveshr
	private: System::Void BonusLevelOne_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			Transition1->Stop();
			Transition2->Start();
		}
	}
		   //@aveshr
	private: System::Void countdown_Tick(System::Object^ sender, System::EventArgs^ e) {


		if (countdownBar->Value < 100) {
			if (countdownBar->Value + 7 > 100)
			{
				countdownBar->Value += (100 - countdownBar->Value);
			}
			else
			{
				countdownBar->Value = countdownBar->Value + 7;
			}

		}
		else {
			TargetTimer->Stop();
			countdown->Stop();

			int  currScore;
			for (int i = 0; i < buttons->Length; i++)
			{
				buttons[i]->Enabled = false;
				countTotal += buttons[i]->numClicks();

			}

			std::vector<std::string> lines;

			std::ifstream file("textfiles/PlayerInfo.txt");
			std::string line;
			if (file.is_open())
			{
				while (getline(file, line))
				{
					lines.push_back(line);
				}
			}
			file.close();

			currScore = stoi(lines[1]);

			if (countTotal >= 9) {
				int addToTotal = 0;
				if (countTotal >= 9 && countTotal < 18)
				{
					addToTotal += 1;
				}
				else if (countTotal >= 18 && countTotal < 27)
				{
					addToTotal += 2;
				}
				else if (countTotal == 27)
				{
					addToTotal += 3;
				}
				lines[1] = std::to_string(stoi(lines[1]) + addToTotal);

				std::ofstream outputFile("textfiles/PlayerInfo.txt");
				outputFile << lines[0] << std::endl;
				outputFile << lines[1] << std::endl;
				outputFile << lines[2] << std::endl;

				outputFile.close();

				std::string windowPrompt = "\nBonus Level One Feedback (9 Targets = 1 Point)\n\nTargets eliminated: " + std::to_string(countTotal) + "\nPrevious Score: " + std::to_string(currScore) + "\nNew Score: " + lines[1] + "\n\nWell done, " + lines[0] + "!";
				String^ unwrapped = gcnew String(windowPrompt.c_str());
				popup^ window = gcnew popup(unwrapped, 0, 0, "assets/Backgrounds/ForestDark.png");
				window->Visible = false;
				this->Hide();
				window->ShowDialog();

				this->Close();
			}
			else
			{
				std::string windowPrompt = "\nBonus Level One Feedback (9 Targets = 1 Point)\n\nTargets eliminated: " + std::to_string(countTotal) + "\nPrevious Score: " + std::to_string(currScore) + "\nNew Score: " + std::to_string(currScore) + "\n\nBetter luck next time, " + lines[0] + ".";
				String^ unwrapped = gcnew String(windowPrompt.c_str());
				popup^ window = gcnew popup(unwrapped, 0, 0, "assets/Backgrounds/ForestDark.png");

				window->Visible = false;
				this->Hide();
				window->ShowDialog();

				this->Close();
			}


		}


	}
	private: System::Void countdownBar_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panelBonusLevel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	
};


}

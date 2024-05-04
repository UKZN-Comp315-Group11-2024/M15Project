#pragma once
#include <math.h>
#include <iostream>
#include <fstream>
#include "popup.h"
#include "LoadQuestion.h"
#include "PictureBox.h"
#include "MusicAndSFX.h"
#include "lvl4Form.h"
namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class BonusLevelThree : public System::Windows::Forms::Form
	{
	public:
		//Constructor(Auto Generated)
		BonusLevelThree(void)
		{
			//Initializes components and draws them to the screen
			InitializeComponent();
		}

	protected:
		//Destructor(Auto Generated)
		//Clean up any resources being used.
		~BonusLevelThree()
		{
			//If there are components, destroy them
			if (components)
			{
				delete components;
			}
		}
	//Components(Auto Generated)
	private: System::Windows::Forms::Panel^ panelBonusLevel;
	private: System::Windows::Forms::Label^ lblMessage1;
	private: System::Windows::Forms::PictureBox^ pbGeneralMilitary;
	private: System::Windows::Forms::Timer^ TargetTimer;
	private: System::Windows::Forms::Timer^ Transition2;
	private: System::Windows::Forms::Timer^ Transition1;
	private: System::Windows::Forms::ProgressBar^ countdownBar;
	private: System::Windows::Forms::Timer^ countdown;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		//(Auto Generated):
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
			this->panelBonusLevel->Location = System::Drawing::Point(-9, -20);
			this->panelBonusLevel->Name = L"panelBonusLevel";
			this->panelBonusLevel->Size = System::Drawing::Size(1280, 720);
			this->panelBonusLevel->TabIndex = 13;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(-14, -26);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(80, 40);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// countdownBar
			// 
			this->countdownBar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->countdownBar->ForeColor = System::Drawing::Color::Red;
			this->countdownBar->Location = System::Drawing::Point(374, 60);
			this->countdownBar->Margin = System::Windows::Forms::Padding(2);
			this->countdownBar->Name = L"countdownBar";
			this->countdownBar->Size = System::Drawing::Size(503, 37);
			this->countdownBar->TabIndex = 12;
			// 
			// lblMessage1
			// 
			this->lblMessage1->AutoSize = true;
			this->lblMessage1->Font = (gcnew System::Drawing::Font(L"Courier New", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMessage1->ForeColor = System::Drawing::Color::Black;
			this->lblMessage1->Location = System::Drawing::Point(304, 720);
			this->lblMessage1->Name = L"lblMessage1";
			this->lblMessage1->Size = System::Drawing::Size(0, 36);
			this->lblMessage1->TabIndex = 1;
			this->lblMessage1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pbGeneralMilitary
			// 
			this->pbGeneralMilitary->BackColor = System::Drawing::Color::Transparent;
			this->pbGeneralMilitary->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pbGeneralMilitary->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbGeneralMilitary.Image")));
			this->pbGeneralMilitary->Location = System::Drawing::Point(-260, 196);
			this->pbGeneralMilitary->Margin = System::Windows::Forms::Padding(0);
			this->pbGeneralMilitary->Name = L"pbGeneralMilitary";
			this->pbGeneralMilitary->Size = System::Drawing::Size(297, 448);
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
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1264, 680);
			this->Controls->Add(this->panelBonusLevel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"BonusLevelThree";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BonusLevelThree";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &BonusLevelThree::BonusLevelThree_FormClosing);
			this->Load += gcnew System::EventHandler(this, &BonusLevelThree::BonusLevelThree_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &BonusLevelThree::BonusLevelThree_KeyDown);
			this->panelBonusLevel->ResumeLayout(false);
			this->panelBonusLevel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		bool levelcomplete = false;

		//Number of targets hit
		int countTotal = 0;
		//Number of targets on screen
		int targetNum = 0;

		//Music objects
		MusicAndSFX* ambience = new MusicAndSFX();
		MusicAndSFX* music = new MusicAndSFX();

		//Array of shootable targets
		array<definedPictureBox^>^ targets = gcnew array<definedPictureBox^>(27);
		//Array of shootable boxes blocking targets
		array<definedPictureBox^>^ boxes = gcnew array<definedPictureBox^>(5);

	private:

		/*
			Loads/instantiates certain UI elements,
			starts a timer to pull "welcome to the bonus level" message and Graphics to the screen
			fills the targets array with targets for the player to shoot once enter has been pressed
			Plays the levels' (background) music
			waits for enter key
		*/
		System::Void BonusLevelThree_Load(System::Object^ sender, System::EventArgs^ e) {

			//sets background
			Image^ backgroundImage = Image::FromFile("assets/Backgrounds/Forest.png");
			panelBonusLevel->BackgroundImage = backgroundImage;

			//Plays sounds
			ambience->NightForest();
			music->bonusLevels();

			//Assigns random x and y positions to objects the player shoots
			int x_pos, y_pos, x_size, y_size;
			srand(time(0));
			for (int i = 0; i < targets->Length; i++) {
				delete targets[i];

				x_pos = rand() % 1050 + 10;
				y_pos = rand() % 420 + 180;
				x_size = rand() % 20 + 65;
				y_size = rand() % 20 + 75;
				targets[i] = gcnew definedPictureBox(panelBonusLevel, x_size, y_size, x_pos, y_pos, "assets/BonusLevel/idle.gif", true);
			}

			//checks if any targets have the same position and then re-assigns one of them a new position to be drawn on screen
			for (int i = 0; i < targets->Length; i++) {
				if (i > 0) {
					int j = i - 1;
					while (j >= 0) {
						if (targets[i] == targets[j])
						{
							x_pos = rand() % 1050 + 10;
							y_pos = rand() % 420 + 180;
							targets[i]->setLocation(x_pos, y_pos);
							j = i - 1;
						}
						else {
							j--;
						}
					}
				}
			}

			//Asigns Boxes to Targets at random
			int randomTargetX = 0;
			for (int i = 0; i < boxes->Length; i++)
			{
				randomTargetX = rand() % 5 + i * 5;
				boxes[i] = gcnew definedPictureBox(panelBonusLevel, targets[randomTargetX]->Size.Width, targets[randomTargetX]->Size.Height, targets[randomTargetX]->Location.X, targets[randomTargetX]->Location.Y, "assets/Doors/Box.png", true);
			}

			//Sets welcome message text
			lblMessage1->Text = "Welcome To The Third Bonus Level:\n\nA few rogue assassins out of a total of 27\nare trying new defensive strategies.\nThey are taking cover in boxes,\nbreak those first before taking them out.\n\nEliminate the threat!!\n\nHint: Aim with your mouse\nand shoot with left-click\n\n<Press Enter To Start>";
			
			//Starts the timer
			Transition1->Start();
		}

		/*
		   Listens for when a key is pushed down
		   stops the first timer and begins the second timer
		*/
		System::Void BonusLevelThree_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Enter && Transition1->Enabled == true)
			{
				Transition1->Stop();
				Transition1->Enabled = false;
				Transition2->Start();
			}
		}

		/*
		   The first timer
		   Pulls a picture box and a message smoothly onto the screen
		*/
		System::Void Transition1_Tick(System::Object^ sender, System::EventArgs^ e) {

			//Position of the Picture box of the general 
			Point p1 = pbGeneralMilitary->Location;
			//Message to player's position
			Point p2 = lblMessage1->Location;
			int x = p1.X, y1 = p2.Y;

			// updates their positions every tick
			if (x <= 40)
			{
				x += 6;
			}
			if (y1 >= 220)
			{
				y1 -= 10;
			}

			//Sets their new positions every tick
			pbGeneralMilitary->Location = Point(x, 245);
			lblMessage1->Location = Point(380, y1);
		}

		/*
		   The second timer
		   Removes a picture box and a message smoothly off the screen
		   Starts a countdown and a target timer, disables transition2 timer
		   creates a retical as the cursor
		*/
		System::Void Transition2_Tick(System::Object^ sender, System::EventArgs^ e) {
			//current positions of the message and picture box containing the general
			Point p1 = pbGeneralMilitary->Location;
			Point p2 = lblMessage1->Location;

			int x = p1.X, y1 = p2.Y;

			//updates their positions every tick
			if (x >= -325)
			{
				x -= 15;
			}
			if (y1 <= 900)
			{
				y1 += 15;
			}

			//if the message and general are off screen
			if (!(x >= -325) && !(y1 <= 900))
			{
				//sets cursor to retical
				panelBonusLevel->Cursor = gcnew System::Windows::Forms::Cursor("assets/Retical/ShootRetical2.cur");
				
				//starts and disables timers
				countdown->Start();
				TargetTimer->Start();
				Transition2->Enabled = false;
			}

			//sets their new positions every tick
			pbGeneralMilitary->Location = Point(x, 245);
			lblMessage1->Location = Point(380, y1);
		}

	private:

		/*
		   Target timer
		   Pulls shootable targets from the targets array and places them on the screen along with boxes covering certain targets
		*/
		System::Void TargetTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			for (int i = 0; i < boxes->Length; i++)
			{
				//if the target should have a box ontop of it
				if (boxes[i]->Location.X == targets[targetNum]->Location.X && boxes[i]->Location.Y == targets[targetNum]->Location.Y) {
					//places a box ontop of a target
					boxes[i]->BringToFront();
					//makes a box visible
					boxes[i]->setVisible(true);
				}
			}
			//makes a target visible
			targets[targetNum]->setVisible(true);

			//stops displaying targets if there are too many targets on the screen
			if (targetNum == targets->Length - 1) {
				TargetTimer->Stop();
			}
			targetNum++;
		}

		/*
		   Count down timer
		   updates countdown bar
		   when full, updates points and closes the form
		   provides feedback on a popup form

		*/
		System::Void countdown_Tick(System::Object^ sender, System::EventArgs^ e) {

			//updates the count down bar if it is not full
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
				levelcomplete = true;
				//records the number of targets hit(clicked with the retical(cursor))
				int  currScore;
				for (int i = 0; i < targets->Length; i++)
				{
					targets[i]->Enabled = false;
					countTotal += targets[i]->numClicks();
					delete targets[i]->BonusSounds;

				}

				//reads in lines from PlayerInfo.txt into a vector called lines
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

				//Gets the score before adding points from bonus level
				currScore = stoi(lines[1]);

				//If the player earned any bonus points, adds them based on how many targets where shot
				//writes the updated points to the PlayerInfo.txt file
				//provides feedback to the player on popup form and closes this form
				if (countTotal >= 9) {
					//adding points
					int addToTotal = 0;
					if (countTotal >= 9 && countTotal < 18)
					{
						addToTotal += 50;
					}
					else if (countTotal >= 18 && countTotal < 27)
					{
						addToTotal += 100;
					}
					else if (countTotal == 27)
					{
						addToTotal += 150;
					}
					lines[1] = std::to_string(stoi(lines[1]) + addToTotal);

					//writing back to file
					std::ofstream outputFile("textfiles/PlayerInfo.txt");
					outputFile << lines[0] << std::endl;
					outputFile << lines[1] << std::endl;
					outputFile << lines[2] << std::endl;

					outputFile.close();

					//stops background music
					ambience->StopSound();
					music->StopSound();
					delete ambience;
					delete music;

					//Provides player feedback
					std::string windowPrompt = "\nBonus Level Three Feedback (9 Targets = 50 Points)\n\nTargets eliminated: " + std::to_string(countTotal) + "\nPrevious Score: " + std::to_string(currScore) + "\nNew Score: " + lines[1] + "\n\nWell done, " + lines[0] + "!\n Please proceed to level 4";
					String^ unwrapped = gcnew String(windowPrompt.c_str());
					popup^ window = gcnew popup(unwrapped, 0, 0, "assets/Backgrounds/ForestDark.png");
					window->Visible = false;
					this->Hide();
					window->ShowDialog();

					lvl4Form^ lvl4form = gcnew lvl4Form();
					this->Hide();
					lvl4form->ShowDialog();
					this->Close();


				}
				//if no points where earned, provides player feedback on popup form, closes form
				else
				{	
					//provide player feedback
					std::string windowPrompt = "\nBonus Level Threes Feedback (9 Targets = 50 Points)\n\nTargets eliminated: " + std::to_string(countTotal) + "\nPrevious Score: " + std::to_string(currScore) + "\nNew Score: " + std::to_string(currScore) + "\n\nBetter luck next time, " + lines[0] + ".\nPlease proceed to level 4.";
					String^ unwrapped = gcnew String(windowPrompt.c_str());
					popup^ window = gcnew popup(unwrapped, 0, 0, "assets/Backgrounds/ForestDark.png");

					//stops background music
					ambience->StopSound();
					music->StopSound();
					delete ambience;
					delete music;

					window->Visible = false;
					this->Hide();
					window->ShowDialog();


					lvl4Form^ lvl4form = gcnew lvl4Form();
					this->Hide();
					lvl4form->ShowDialog();
					this->Close();
				}
			}
		}
private: System::Void BonusLevelThree_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (!levelcomplete) {
		if (MessageBox::Show("Are you sure you want to eliminate yourself?", "", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
		{
			e->Cancel = true;
			panelBonusLevel->Focus();
		}
	}
	
}
};
}

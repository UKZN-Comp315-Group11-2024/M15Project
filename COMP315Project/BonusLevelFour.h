#pragma once
#include <math.h>
#include <iostream>
#include <fstream>
#include "popup.h"
#include "LoadQuestion.h"
#include "PictureBox.h"
#include "MusicAndSFX.h"
#include "Leaderboard.h"

namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class BonusLevelFour : public System::Windows::Forms::Form
	{
	public:
		BonusLevelFour(void)
		{
			InitializeComponent();
		}

	protected:
		// Clean up any resources being used.
		~BonusLevelFour()
		{
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
	private: System::Windows::Forms::Timer^ TargetMoveTimer;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BonusLevelFour::typeid));
			this->panelBonusLevel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->countdownBar = (gcnew System::Windows::Forms::ProgressBar());
			this->lblMessage1 = (gcnew System::Windows::Forms::Label());
			this->pbGeneralMilitary = (gcnew System::Windows::Forms::PictureBox());
			this->TargetTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Transition2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Transition1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->countdown = (gcnew System::Windows::Forms::Timer(this->components));
			this->TargetMoveTimer = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->panelBonusLevel->Location = System::Drawing::Point(-10, -20);
			this->panelBonusLevel->Margin = System::Windows::Forms::Padding(2);
			this->panelBonusLevel->Name = L"panelBonusLevel";
			this->panelBonusLevel->Size = System::Drawing::Size(1280, 720);
			this->panelBonusLevel->TabIndex = 13;
			this->panelBonusLevel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BonusLevelFour::panelBonusLevel_Paint);
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
			this->countdownBar->Size = System::Drawing::Size(502, 38);
			this->countdownBar->TabIndex = 12;
			// 
			// lblMessage1
			// 
			this->lblMessage1->AutoSize = true;
			this->lblMessage1->Font = (gcnew System::Drawing::Font(L"Courier New", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMessage1->Location = System::Drawing::Point(304, 720);
			this->lblMessage1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			this->pbGeneralMilitary->Location = System::Drawing::Point(-260, 230);
			this->pbGeneralMilitary->Margin = System::Windows::Forms::Padding(0);
			this->pbGeneralMilitary->Name = L"pbGeneralMilitary";
			this->pbGeneralMilitary->Size = System::Drawing::Size(298, 448);
			this->pbGeneralMilitary->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbGeneralMilitary->TabIndex = 11;
			this->pbGeneralMilitary->TabStop = false;
			// 
			// TargetTimer
			// 
			this->TargetTimer->Interval = 500;
			this->TargetTimer->Tick += gcnew System::EventHandler(this, &BonusLevelFour::TargetTimer_Tick);
			// 
			// Transition2
			// 
			this->Transition2->Interval = 1;
			this->Transition2->Tick += gcnew System::EventHandler(this, &BonusLevelFour::Transition2_Tick);
			// 
			// Transition1
			// 
			this->Transition1->Interval = 1;
			this->Transition1->Tick += gcnew System::EventHandler(this, &BonusLevelFour::Transition1_Tick);
			// 
			// countdown
			// 
			this->countdown->Interval = 1000;
			this->countdown->Tick += gcnew System::EventHandler(this, &BonusLevelFour::countdown_Tick);
			// 
			// TargetMoveTimer
			// 
			this->TargetMoveTimer->Interval = 10;
			this->TargetMoveTimer->Tick += gcnew System::EventHandler(this, &BonusLevelFour::TargetMoveTimer_Tick);
			// 
			// BonusLevelFour
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1264, 680);
			this->Controls->Add(this->panelBonusLevel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"BonusLevelFour";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BonusLevelFour";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &BonusLevelFour::BonusLevelFour_FormClosing);
			this->Load += gcnew System::EventHandler(this, &BonusLevelFour::BonusLevelFour_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &BonusLevelFour::BonusLevelFour_KeyDown);
			this->panelBonusLevel->ResumeLayout(false);
			this->panelBonusLevel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		bool levelcomplete = false;

		// Number of targets hit
		int countTotal = 0;
		// Target number to be displayed
		int targetNum = 0;
		// Number of visible targets
		int countNumVisible;

		// Music objects
		MusicAndSFX* ambience = new MusicAndSFX();
		MusicAndSFX* music = new MusicAndSFX();

		// Array of shootable targets
		array<definedPictureBox^>^ targets = gcnew array<definedPictureBox^>(36);

	private:

		/*
			Loads/instantiates certain UI elements,
			Starts a timer to move "Welcome to the bonus level" message and Graphics to the screen
			Fills the targets array with targets for the player to shoot once enter has been pressed
			Sets the speed for each target
			Plays the levels' (background) music
		*/
		System::Void BonusLevelFour_Load(System::Object^ sender, System::EventArgs^ e) {

			// Sets background image
			Image^ backgroundImage = Image::FromFile("assets/Backgrounds/SpaceBackgroundDark.png");
			panelBonusLevel->BackgroundImage = backgroundImage;

			// Plays (background) music
			ambience->Space();
			music->bonusLevels();

			// Assigns random x and y positions to shootable targets
			int x_pos, y_pos, x_size, y_size, speed;
			srand(time(0));
			for (int i = 0; i < targets->Length; i++) {
				delete targets[i];

				x_pos = rand() % 1050 + 10;
				y_pos = rand() % 420 + 180;
				x_size = rand() % 50 + 60;
				y_size = rand() % 50 + 30;
				targets[i] = gcnew definedPictureBox(panelBonusLevel, x_size, y_size, -100, y_pos, "assets/Doors/PageColorized.png", true);

				// Assigns targets' speed values
				speed = rand() % 8 + 5;
				targets[i]->setSpeed(speed);
				targets[i]->setAudioClickType("Laser");
			}

			// Sets welcome message text
			lblMessage1->Text = "Welcome To The Final Bonus Level:\n\nYour spaceship took a hit which resulted in\nsensitive documents being ejected.\nUnfortunately, we aren't able to retrieve\nthem so you need to destroy them.\n\nObliterate the documents!!\n\nHint: Aim with your mouse\nand shoot with left-click\n\n<Press Enter To Start>";
			
			// Starts the first transition timer
			Transition1->Start();

		}

		/*
		   Listens for when enter is pressed
		   Stops the first transition timer and begins the second transition timer
		*/
		System::Void BonusLevelFour_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Enter && Transition1->Enabled == true)
			{
				Transition1->Stop();
				Transition1->Enabled = false;
				Transition2->Start();
				Image^ backgroundImage = Image::FromFile("assets/Backgrounds/SpaceBackground.png");
				panelBonusLevel->BackgroundImage = backgroundImage;
			}
		}

		/*
		   Moves the military general and welcome message onto the screen
		   Serves as the first transition timer
		*/
		System::Void Transition1_Tick(System::Object^ sender, System::EventArgs^ e) {

			// Position of the military general 
			Point p1 = pbGeneralMilitary->Location;
			// Position of the welcome message
			Point p2 = lblMessage1->Location;
			int x = p1.X, y1 = p2.Y;

			// Updates their positions, moving them closer/onto the screen, every tick
			if (x <= 40)
			{
				x += 6;
			}
			if (y1 >= 220)
			{
				y1 -= 10;
			}

			// Sets their new position every tick
			pbGeneralMilitary->Location = Point(x, 230);
			lblMessage1->Location = Point(380, y1);
		}

		/*
		   Moves the military general and welcome message off the screen
		   Once those have left the screen:
		   Starts the countdown timer as well as the target timer used to display targets on the screen at constant intervals
		   Turns the cursor into a retical for shooting
		*/
		System::Void Transition2_Tick(System::Object^ sender, System::EventArgs^ e) {
			// Current positions of the miitary general and the welcome message
			Point p1 = pbGeneralMilitary->Location;
			Point p2 = lblMessage1->Location;

			int x = p1.X, y1 = p2.Y;

			// Updates their position
			if (x >= -325)
			{
				x -= 15;
			}
			if (y1 <= 900)
			{
				y1 += 15;
			}

			// Checks if the military general and welcome message has left the screen
			if (!(x >= -325) && !(y1 <= 900))
			{
				// Turns the cursor into a retical
				panelBonusLevel->Cursor = gcnew System::Windows::Forms::Cursor("assets/Retical/ShootRetical2.cur");
				
				// Starts timers and disables the last active transition
				countdown->Start();
				TargetTimer->Start();
				TargetMoveTimer->Start();
				Transition2->Enabled = false;
			}

			// Sets their new position
			pbGeneralMilitary->Location = Point(x, 230);
			lblMessage1->Location = Point(380, y1);
		}


	private:
		/*
		   Sets a new target to be visible at a constant interval
		*/
		System::Void TargetTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (!(countNumVisible >= 5))
			{
				// Makes a target visible
				targets[targetNum]->setVisible(true);

				// Stops displaying targets if there are too many targets on the screen (5)
				if (targetNum == targets->Length - 1) {
					TargetTimer->Stop();
				}
				targetNum++;
			}

		}

		// Updates a targets position based on their speed
		void update()
		{
			countNumVisible = 0;
			for (int i = 0; i < targets->Length; i++)
			{
				// Only updates a targets position if it is currently visible
				if (targets[i]->Visible == true)
				{
					countNumVisible++;
					targets[i]->setLocation(targets[i]->Location.X + targets[i]->getSpeed(), targets[i]->Location.Y);
					// If a target has reached the right-most bound then its visibility is set to false
					if (targets[i]->Location.X >= 1300)
					{
						targets[i]->setVisible(false);
					}
				}
			}
		}

		// Timer that allows targets to move
		System::Void TargetMoveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			update();
		}

		/*
		   Updates the countdown bar
		   When its full, it updates the players points based on the amount of targets they hit
		   Provides feedback on a popup form
		*/
		System::Void countdown_Tick(System::Object^ sender, System::EventArgs^ e) {
			int countTotalNotVisible = 0;
			// Gets the number of invisible targets
			for (int i = 0; i < targets->Length; i++)
			{
				if (targets[i]->Visible == false)
				{
					countTotalNotVisible++;
				}
			}

			// Updates the countdown bar if it is not full and the number of invisibale targets doesn't equal 36
			if (countdownBar->Value < 100 && countTotalNotVisible != 36) {

				if (countdownBar->Value + 3 > 100)
				{
					countdownBar->Value += (100 - countdownBar->Value);
				}
				else
				{
					countdownBar->Value = countdownBar->Value + 3;
				}
			}
			else {
				if (countTotalNotVisible < 36)
				{
					return;
				}

				TargetTimer->Stop();
				countdown->Stop();
				levelcomplete = true;
				// Counts the number of targets hit (Clicked on with the retical(cursor))
				int  currScore;
				for (int i = 0; i < targets->Length; i++)
				{
					targets[i]->Enabled = false;
					countTotal += targets[i]->numClicks();
					delete targets[i]->BonusSounds;

				}

				// Reads in lines from PlayerInfo.txt into a vector called lines
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

				// Gets the score before adding points from bonus level
				currScore = stoi(lines[1]);

				// If the player earned any bonus points, they're added to the players score
				// Writes the updated points to the PlayerInfo.txt file
				// Provides feedback to the player on popup form
				if (countTotal >= 12) {
					// Adding points
					int addToTotal = 0;
					if (countTotal >= 12 && countTotal < 24)
					{
						addToTotal += 50;
					}
					else if (countTotal >= 24 && countTotal < 36)
					{
						addToTotal += 100;
					}
					else if (countTotal == 36)
					{
						addToTotal += 150;
					}
					lines[1] = std::to_string(stoi(lines[1]) + addToTotal);

					// Writing back to the PlayerInfo.txt textfile 
					std::ofstream outputFile("textfiles/PlayerInfo.txt");
					outputFile << lines[0] << std::endl;
					outputFile << lines[1] << std::endl;
					outputFile << lines[2] << std::endl;

					outputFile.close();

					// Providing player feedback on the bonus level
					std::string windowPrompt = "\nFinal Bonus Level Feedback (12 Targets = 50 Points)\n\nTargets eliminated: " + std::to_string(countTotal) + "\nPrevious Score: " + std::to_string(currScore) + "\nNew Score: " + lines[1] + "\n\nWell done, " + lines[0] + "!";
					String^ unwrapped = gcnew String(windowPrompt.c_str());
					popup^ window = gcnew popup(unwrapped, 0, 0, "assets/Backgrounds/SpaceBackgroundDark.png");

					// Stops (all) background music
					ambience->StopSound();
					music->StopSound();
					delete ambience;
					delete music;

					window->Visible = false;
					this->Hide();
					window->ShowDialog();

					std::string window2Prompt = "\nThe simulation is now complete. You may see how you fared on the leaderboard. If you did not place in the top 3... let us just say you should make sure your affairs are in order;)";
					String^ unwrapped2 = gcnew String(window2Prompt.c_str());
					popup^ window2 = gcnew popup(unwrapped2, 0, 0, "assets/Backgrounds/SpaceBackgroundDark.png");
					window2->ShowDialog();

					Leaderboard^ leaderboard = gcnew Leaderboard("yes");
					this->Hide();
					leaderboard->ShowDialog();
					this->Close();


				}
				// If no points were earned then the players' score is not updated
				else
				{
					// Providing player feedback on the bonus level
					std::string windowPrompt = "\nFinal Bonus Level Feedback (12 Targets = 50 Points)\n\nTargets eliminated: " + std::to_string(countTotal) + "\nPrevious Score: " + std::to_string(currScore) + "\nNew Score: " + std::to_string(currScore) + "\n\nBetter luck next time, " + lines[0] + ".";
					String^ unwrapped = gcnew String(windowPrompt.c_str());
					popup^ window = gcnew popup(unwrapped, 0, 0, "assets/Backgrounds/SpaceBackgroundDark.png");

					// Stops (all) background music
					ambience->StopSound();
					music->StopSound();
					delete ambience;
					delete music;

					window->Visible = false;
					this->Hide();
					window->ShowDialog();

					std::string window2Prompt = "\nThe simulation is now complete. You may see how you fared on the leaderboard. If you did not place in the top 3... let us just say you should make sure your affairs are in order;)";
					String^ unwrapped2 = gcnew String(window2Prompt.c_str());
					popup^ window2 = gcnew popup(unwrapped2, 0, 0, "assets/Backgrounds/SpaceBackgroundDark.png");
					window2->ShowDialog();

					Leaderboard^ leaderboard = gcnew Leaderboard("yes");
					this->Hide();
					leaderboard->ShowDialog();
					this->Close();
				}
			}
		}
	private: System::Void BonusLevelFour_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (!levelcomplete) {
			if (MessageBox::Show("Are you sure you want to eliminate yourself?", "", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
			{
				e->Cancel = true;
				panelBonusLevel->Focus();
			}
		}
		
	}
private: System::Void panelBonusLevel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};


}

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "customAlgs.h"
#include "PlayerInfo.h"
#include "LoginForm.h"



namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Leaderboard
	/// </summary>

	/*struct UserData {
		std::string name;
		int score;
		int timeTaken;
	};*/


	public ref class Leaderboard : public System::Windows::Forms::Form
	{
	public:
		Leaderboard(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			LoadImage();
			std::vector<playerInfo> players = LoadAllPlayers();
			LoadCurrentPlayerData("textfiles/PlayerInfo.txt", players);

		}

		// Function that reads the current player data from the text file to a vector
		// Assuming that the scores and player data is written at the end of the play through from the playerinfo.txt
		void LoadCurrentPlayerData(std::string filename, std::vector<playerInfo> players)
		{
			std::ifstream file(filename);
			std::string uName;
			int sc, tt;
			//std::vector<UserData> userdata;
			playerInfo p;

			if (file.is_open())
			{
				// Reads the data line by line, for the username, score and timetaken
				while (getline(file, uName) && file >> sc && file >> tt)
				{
					// Creates the UserData object and adds it to the userdata vector
					p.username = uName;
					p.score = sc;
					p.timeTaken = tt;
				}
			}

			//players.insertScore(players, p);
			// close the file and update the labels
			file.close();

			// Sortint the vector and inserting the current players scores. 
			//customAlgs<playerInfo>::insertScore(players, p);
			players.push_back(p);

			UpdateLabels(players);
		}

		// Method that returns a vector of the leaderboard.txt
		std::vector<playerInfo> LoadAllPlayers() {
			std::vector<playerInfo> _players;
			std::ifstream file("textfiles/Leaderboard.txt");
			std::string line;
			if (file.is_open())
			{
				while (getline(file, line)) {
					int score = 0;
					int time;
					size_t pos = line.find('$');
					std::string username = line.substr(0, pos);
					line.substr(0, pos + 1).erase();
					for (int i = 0; i < 4; i++) {
						pos = line.find('$');
						score = score + stoi(line.substr(0, pos));
						line.substr(0, pos + 1).erase();
					}
					time = stoi(line);
					line.erase();
					_players.push_back({ username, score, time });
				}
			}

			return _players;
		}

	private:

		// Function to update the labels each time the leaderboard is accessed. 
		// Creates new labels from scratch and puts them in the appropriate locations
		void UpdateLabels(std::vector<playerInfo> v) {
			//Clear previous labels
			ClearLabels();
			
			for (int i = 0; i < v.size(); i++) {
				Label^ usernameLabel = gcnew Label();
				Label^ scoreLabel = gcnew Label();
				Label^ timeLabel = gcnew Label();

				usernameLabel->Text = gcnew String(msclr::interop::marshal_as<System::String^>(v[i].username.c_str()));
				scoreLabel->Text = v[i].score.ToString();
				timeLabel->Text = v[i].timeTaken.ToString();

				int marginTop = (i * 50) + 70;
				usernameLabel->Location = System::Drawing::Point(177, marginTop);
				scoreLabel->Location = System::Drawing::Point(518, marginTop);
				timeLabel->Location = System::Drawing::Point(720, marginTop);

				this->Controls->Add(usernameLabel);
				this->Controls->Add(scoreLabel);
				this->Controls->Add(timeLabel);
			}

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Leaderboard()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private:

		System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::ComponentModel::IContainer^ components;

	private:





















	internal:









	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		// Vector to store user data

		void LoadImage()
		{
			Image^ board = Image::FromFile("assets/LeaderboardTime.png");
			pictureBox2->Image = board;
			pictureBox2->SizeMode = PictureBoxSizeMode::StretchImage;
		}

		// Clears the created labels from memory
		void ClearLabels()
		{
			for each (Control ^ control in this->Controls) {
				delete control;
			}
		}


#pragma region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Leaderboard::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox2->MaximumSize = System::Drawing::Size(1238, 719);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1238, 719);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// Leaderboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1238, 719);
			this->Controls->Add(this->pictureBox2);
			this->MaximumSize = System::Drawing::Size(1256, 766);
			this->MinimizeBox = false;
			this->Name = L"Leaderboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Leaderboard";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



};
}
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cliext/list>
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
			LoadAllPlayers();
			LoadCurrentPlayerData("textfiles/PlayerInfo.txt", players);

		}

		// Function that reads the current player data from the text file to a vector
		// Assuming that the scores and player data is written at the end of the play through from the playerinfo.txt
		void LoadCurrentPlayerData(std::string filename, cliext::list<playerInfo> players)
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
		void LoadAllPlayers() {
			//std::vector<playerInfo> _players;
			//std::ifstream file("textfiles/Leaderboard.txt");
			System::IO::StreamReader^ file = gcnew System::IO::StreamReader(msclr::interop::marshal_as<System::String^>("textfiles/Leaderboard.txt"));
			//std::string line;
			System::String^ line;

			while ((line = file->ReadLine()) != nullptr) {
				int score = 0;
				int time;
				int pos = line->IndexOf('$');
				std::string username = msclr::interop::marshal_as<std::string>(line->Substring(0, pos));
				line = line->Remove(0, pos + 1);
				for (int i = 0; i < 4; i++) {
					pos = line->IndexOf('$');
					score = score + System::Int32::Parse(line->Substring(0, pos));
					line = line->Remove(0, pos + 1);
				}
				time = System::Int32::Parse(line);
				line->Remove(0, -1);
				players.push_back({ username, score, time });
			}
		}

	private:

		cliext::list<playerInfo> players;
		// Function to update the labels each time the leaderboard is accessed. 
		// Creates new labels from scratch and puts them in the appropriate locations
		void UpdateLabels(cliext::list<playerInfo> v) {
			//Clear previous labels
			ClearLabels();
			
			for (cliext::list<playerInfo>::iterator it = v.begin(); it != v.end(); ++it) {
				Label^ usernameLabel = gcnew Label();
				Label^ scoreLabel = gcnew Label();
				Label^ timeLabel = gcnew Label();

				playerInfo elem = *it;
				int i = 1;

				usernameLabel->Text = gcnew String(msclr::interop::marshal_as<System::String^>(elem.username.c_str()));
				scoreLabel->Text = elem.score.ToString();
				timeLabel->Text = elem.timeTaken.ToString();

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
			Image^ board = Image::FromFile("assets/leaderboard.png");
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
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1256, 766);
			this->pictureBox2->TabIndex = 0;
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
			this->Load += gcnew System::EventHandler(this, &Leaderboard::Leaderboard_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion



private: System::Void Leaderboard_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
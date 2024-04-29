#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "PlayerInfo.h"
#include "LoginForm.h"
#include <cliext/list>



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

	//comment when creating playerInfo objects
	struct UserData {
		std::string name;
		int score;
		int timeTaken;
	};

	public ref class Leaderboard : public System::Windows::Forms::Form
	{
	public:
		Leaderboard(void)
		{
			InitializeComponent();
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			LoadImage();
			this->Show();
			//LoadAllPlayers();
			players = gcnew List<playerInfo^>;
			LoadAllPlayers(players);
			UpdateLabels();
			
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

		void LoadAllPlayers(List<playerInfo^>^ players) {

			std::ifstream file("textfiles/Leaderboard.txt");
			std::string line;

			if (file.is_open())
			{
				while (getline(file, line))
				{
					int pos = line.find('$');
					playerInfo^ p = gcnew playerInfo;
					p->username = gcnew String(line.substr(0, pos).c_str());
					line.erase(0, pos + 1);

					for (int i = 0; i < 4; i++) {
						pos = line.find('$');
						p->score = stoi(line.substr(0, pos));
						line.erase(0, pos + 1);
					}

					p->timeTaken = stoi(line);
					players->Add(p);
				}

			}
			file.close();
		}

		// Function that reads the players data from the text file to a vector
		// It should read to a vector that is created from the leaderboard class 
		// but due the nonmanageble class error, a vector cannot be instantiated, 
		// see the commented method below this one

		//UserData LoadUserData(std::string filename)
		//{

		//	std::ifstream file(filename);
		//	std::string line;
		//	UserData userdata;

		//	if (file.is_open())
		//	{
		//		// Reads the data line by line, for the username, score and timetaken
		//		for (int i = 0; i < 3; i++) {
		//			
		//		}
		//	}
		//	// close the file and update the labels
		//	file.close();
		//	return 
		//}

		//error code
		/*
		void LoadCurrentPlayerData(std::string filename, cliext::list<playerInfo^>^ players)
		{
			std::ifstream file(filename);
			std::string uName;
			int sc, tt;
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
			customAlgs<playerInfo>::insertScore(players, p);
			players.push_back(p);

			UpdateLabels(players);
		}*/

	private:

		List<playerInfo^>^ players;

		// Function to update the labels each time the leaderboard is accessed. 
		// Creates new labels from scratch and puts them in the appropriate locations
		// Will implement a sorting algorithm to sort from highest to lowest.

		void UpdateLabels() {
			//Clear previous labels
			ClearLabels();

			
			// Creating an iterator for the list and iterating through each playerInfo object in the list to create the labels
			for each(playerInfo^ elem in this->players) {
				Label^ usernameLabel = gcnew Label();
				Label^ scoreLabel = gcnew Label();
				Label^ timeLabel = gcnew Label();

				playerInfo^ e = elem;
				int i = 1;

				// Converting the std::string to System::String^ 
				usernameLabel->Text = gcnew String(elem->username);
				scoreLabel->Text = elem->score.ToString();
				timeLabel->Text = elem->timeTaken.ToString();

				int marginTop = (i * 50) + 70;
				usernameLabel->Location = System::Drawing::Point(177, marginTop);
				scoreLabel->Location = System::Drawing::Point(518, marginTop);
				timeLabel->Location = System::Drawing::Point(720, marginTop);

				this->Controls->Add(usernameLabel);
				this->Controls->Add(scoreLabel);
				this->Controls->Add(timeLabel);
			}

			/*for (int i = 1; i <= u.size(); i++) {
				Label^ usernameLabel = gcnew Label();
				Label^ scoreLabel = gcnew Label();
				Label^ timeLabel = gcnew Label();

				usernameLabel->Text = gcnew String(msclr::interop::marshal_as<System::String^>(u[i].name.c_str()));
				scoreLabel->Text = [i].score.ToString();
				timeLabel->Text = u[i].timeTaken.ToString();

				int marginTop = (i * 50) + 70;
				usernameLabel->Location = System::Drawing::Point(177, marginTop);
				scoreLabel->Location = System::Drawing::Point(518, marginTop);
				timeLabel->Location = System::Drawing::Point(720, marginTop);

				this->Controls->Add(usernameLabel);
				this->Controls->Add(scoreLabel);
				this->Controls->Add(timeLabel);
			}*/
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
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Leaderboard::pictureBox2_Click);
			// 
			// Leaderboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1237, 718);
			this->Controls->Add(this->pictureBox2);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximumSize = System::Drawing::Size(1255, 765);
			this->MinimizeBox = false;
			this->Name = L"Leaderboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Leaderboard";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
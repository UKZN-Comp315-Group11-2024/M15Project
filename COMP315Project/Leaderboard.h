#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cliext/list>
#include "customAlgs.h"
#include "PlayerInfo.h"
#include "string.h"



namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	public ref class Leaderboard : public System::Windows::Forms::Form
	{
	public:
		Leaderboard(String^ doIupdate)
		{
			this->doIupdate = doIupdate;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//



		}

		// Function that reads the current player data from the text file to a vector
		// Assuming that the scores and player data is written at the end of the play through from the playerinfo.txt
		void LoadCurrentPlayerData(std::string filename, std::string filename2)
		{
			std::ifstream file(filename);
			playerInfo^ p = gcnew playerInfo;
			std::string line;
			std::vector<std::string> v;

			if (file.is_open())
			{
				while (getline(file, line))
				{
					v.push_back(line);
					
				}
				

			}
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
			file.close();
			this->player = p;


			players = customAlgs<playerInfo^>::insertScore(players, p);
			players->Reverse();
			msclr::interop::marshal_context context;


			UpdateLabels(players);

			std::ofstream writer(filename2);

				for (int i = 0; i < 9; i++) {
					std::string line = "";
					std::string username = context.marshal_as<std::string>(players[i]->username);
					line += username + "$";
					line += std::to_string(players[i]->score);
					line += "$";
					line += std::to_string(players[i]->timeTaken);
					writer << line << "\n";
				}

				std::string line2 = "";
				std::string username2 = context.marshal_as<std::string>(players[9]->username);
				line2 += username2 + "$";
				line2 += std::to_string(players[9]->score);
				line2 += "$";
				line2 += std::to_string(players[9]->timeTaken);
				writer << line2;

				writer.close();


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
				for (int i = 0; i < 1; i++) {
					pos = line->IndexOf('$');
					score = score + System::Int32::Parse(line->Substring(0, pos));
					line = line->Remove(0, pos + 1);
				}
				time = System::Int32::Parse(line);
				playerInfo^ p = gcnew playerInfo;
				p->username = gcnew String(username.c_str());
				p->score = score;
				p->timeTaken = time;
				players->Add(p);
			}
			players->Reverse();
			file->Close();
		}

	private:
		List <playerInfo^>^ players = gcnew List <playerInfo^>;
		String^ doIupdate;



	private: System::Windows::Forms::Timer^ timerleaderboard;
private: System::Windows::Forms::PictureBox^ pictureboxcrosses;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;






	   playerInfo^ player = gcnew playerInfo;
		// Function to update the labels each time the leaderboard is accessed. 
		// Creates new labels from scratch and puts them in the appropriate locations
		void UpdateLabels(List<playerInfo^>^ v) {
			//Clear previous labels
			ClearLabels();
			int i = 1;
			for each(playerInfo ^ elem in players) {

				int marginTop;
				if (i == 1) {
					marginTop = (i * 53) + 62;
				}
				else if (i == 2) {
					marginTop = (i * 55) + 62;
				}
				else if (i == 3) {
					marginTop = (i * 56) + 62;
				}
				else {
					marginTop = (i * 58) + 62;
				}


				Label^ usernameLabel = gcnew Label();
				Label^ scoreLabel = gcnew Label();

				if (i != 10) {
					Label^ timeLabel = gcnew Label();
					timeLabel->Text = gcnew String(elem->timeTaken.ToString()) + " sec";

					timeLabel->AutoSize = true;
					timeLabel->BackColor = System::Drawing::Color::Gainsboro;
					timeLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					timeLabel->Location = System::Drawing::Point(770, marginTop);
					this->Controls->Add(timeLabel);
					timeLabel->BringToFront();
				}
				

				usernameLabel->AutoSize = true;
				usernameLabel->BackColor = System::Drawing::Color::Transparent;
				usernameLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

				scoreLabel->AutoSize = true;
				scoreLabel->BackColor = System::Drawing::Color::Transparent;
				scoreLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
				scoreLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;

				usernameLabel->Text = elem->username;
				scoreLabel->Text = gcnew String(elem->score.ToString());
				


			
				
				usernameLabel->Location = System::Drawing::Point(177, marginTop);
				this->Controls->Add(usernameLabel);
				this->Controls->Add(scoreLabel);

				scoreLabel->Location = System::Drawing::Point(568, marginTop);
				scoreLabel->BringToFront();
				usernameLabel->BringToFront();
				i++;
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


	private: System::ComponentModel::IContainer^ components;

	private:

	internal:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Leaderboard::typeid));
			this->timerleaderboard = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureboxcrosses = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxcrosses))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// timerleaderboard
			// 
			this->timerleaderboard->Enabled = true;
			this->timerleaderboard->Interval = 10;
			this->timerleaderboard->Tick += gcnew System::EventHandler(this, &Leaderboard::timerleaderboard_Tick);
			// 
			// pictureboxcrosses
			// 
			this->pictureboxcrosses->BackColor = System::Drawing::Color::Transparent;
			this->pictureboxcrosses->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureboxcrosses.Image")));
			this->pictureboxcrosses->Location = System::Drawing::Point(64, 277);
			this->pictureboxcrosses->Name = L"pictureboxcrosses";
			this->pictureboxcrosses->Size = System::Drawing::Size(74, 414);
			this->pictureboxcrosses->TabIndex = 10;
			this->pictureboxcrosses->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(721, 629);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(531, 50);
			this->pictureBox2->TabIndex = 11;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(39, 216);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 12;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(39, 171);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"label2";
			// 
			// Leaderboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureboxcrosses);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1280, 720);
			this->Name = L"Leaderboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Top Spies";
			this->Load += gcnew System::EventHandler(this, &Leaderboard::Leaderboard_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Leaderboard::Leaderboard_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxcrosses))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Leaderboard_Load(System::Object^ sender, System::EventArgs^ e) {
		
		msclr::interop::marshal_context context;
		if (context.marshal_as<std::string>(doIupdate) == "yes") {
			LoadAllPlayers();
			LoadCurrentPlayerData("textfiles/PlayerInfo.txt", "textfiles/Leaderboard.txt");
		}
		else {
			LoadAllPlayers();
			players->Reverse();
			UpdateLabels(players);
			players->Reverse();
		}

	}
	private: System::Void timerleaderboard_Tick(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Leaderboard_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Escape) {
		this->Close();
	}
}
private: System::Void labelloginscroll2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
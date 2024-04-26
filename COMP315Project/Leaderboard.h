#pragma once
#include <string>
#include <vector>
#include <fstream>
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

	struct UserData {
		System::String^ name;
		int score;
		int timeTaken;
	};

	public ref class Leaderboard : public System::Windows::Forms::Form
	{
	public:
		Leaderboard(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			LoadUserData("textfiles/PlayerInfo.txt");
			LoadImage();
			// @Neo Kekana initialize the leaderboard by creating a vector of userdata
			std::ifstream file("textfiles/PlayerInfo.txt");
			std::string username;
			int score, timetaken;

			if (file.is_open())
			{
				while (getline(file, username) && file >> score && file >> timetaken)
				{
					System::String^ managedUsername = msclr::interop::marshal_as<System::String^>(username);

					userdata.push_back({ managedUsername, score, timetaken });
				}
			}
			file.close();
		}

		void LoadUserData(System::String^ filename)
		{
			userdata.clear();

		}

		void UpdateLabels(const std::vector<UserData>& userData) {

			ClearLabels();

			for (int i = 0; i < userData.size(); i++) {
				Label^ usernameLabel = gcnew Label();
				Label^ scoreLabel = gcnew Label();
				Label^ timeLabel = gcnew Label();

				usernameLabel->Text = gcnew String(userData[i].name.c_str());
				scoreLabel->Text = userData[i].score.ToString();
				timeLabel->Text = userData[i].timeTaken.ToString();

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
	private: std::vector<UserData> userdata;
	private:

		System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;

	private:


	private: System::Windows::Forms::PictureBox^ pictureBox2;


















	internal:









	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		// Vector to store user data

		void LoadImage()
		{
			Image^ board = Image::FromFile("assets/Leaderboard 2.png");
			pictureBox2->Image = board;
			pictureBox2->SizeMode = PictureBoxSizeMode::StretchImage;
		}

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
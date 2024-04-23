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
	public ref class Leaderboard : public System::Windows::Forms::Form
	{
	public:
		Leaderboard(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			// @Neo Kekana copied from Daniel's code
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
			playerInfo* p = new playerInfo();
			for (int i = 0; i < 3; i++) {
				std::string s = v[i];
				if (i == 0) {
					p->username = s;

				}

				else if (i == 1) {
					p->score = std::stoi(s);
				}
				else {
					p->timeTaken = std::stoi(s);
				}

			}
			// @Neo
			/*playerInfo* p = new playerInfo();
			int index = 0;
			for (int i = 0; i < v.size(); i++)
			{
				std::string info = v[i];
				if (i % 3 == 0 && p->username.length() == 0) {
					p->username = info;
					index++;
					continue;
				}
				if (index == 1 && p->score == NULL) {
					p->score = std::stoi(info);
					index++;
					continue;
				}
				if (index == 2 && p->timeTaken == NULL) {
					p->timeTaken = std::stoi(info);
					index = 0;
				}
			}*/

			this->player = p;



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

	internal: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	internal:
	private:









	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		playerInfo* player;

		void LoadImage()
		{
			Image^ board = Image::FromFile("assets/leaderboard.png");
			pictureBox1->Image = board;
			pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Leaderboard::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(177, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(2, 1);
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
			this->Controls->Add(this->label1);
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

	private: System::Void Leaderboard_Load(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Text = "";
	}
};
}
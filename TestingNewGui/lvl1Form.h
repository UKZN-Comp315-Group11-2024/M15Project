#pragma once
#include "PlayerInfo.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
namespace TestingNewGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for lvl1Form
	/// </summary>
	public ref class lvl1Form : public System::Windows::Forms::Form
	{
	public:
		lvl1Form()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			
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

			this->player = p;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~lvl1Form()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ lblMessage1;


	private: System::Windows::Forms::Timer^ Transition1;


	private: System::Windows::Forms::PictureBox^ pbGeneralMilitary;
	private: System::Windows::Forms::Panel^ panelLogin;


















	protected:
		
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		playerInfo* player;
		


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(lvl1Form::typeid));
			this->lblMessage1 = (gcnew System::Windows::Forms::Label());
			this->Transition1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pbGeneralMilitary = (gcnew System::Windows::Forms::PictureBox());
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->BeginInit();
			this->panelLogin->SuspendLayout();
			this->SuspendLayout();
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
			this->lblMessage1->Click += gcnew System::EventHandler(this, &lvl1Form::label2_Click);
			// 
			// Transition1
			// 
			this->Transition1->Interval = 1;
			this->Transition1->Tick += gcnew System::EventHandler(this, &lvl1Form::Transition1_Tick);
			// 
			// pbGeneralMilitary
			// 
			this->pbGeneralMilitary->BackColor = System::Drawing::Color::Transparent;
			this->pbGeneralMilitary->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pbGeneralMilitary->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbGeneralMilitary.Image")));
			this->pbGeneralMilitary->Location = System::Drawing::Point(-325, 287);
			this->pbGeneralMilitary->Margin = System::Windows::Forms::Padding(0);
			this->pbGeneralMilitary->Name = L"pbGeneralMilitary";
			this->pbGeneralMilitary->Size = System::Drawing::Size(371, 560);
			this->pbGeneralMilitary->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbGeneralMilitary->TabIndex = 11;
			this->pbGeneralMilitary->TabStop = false;
			// 
			// panelLogin
			// 
			this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));
			this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelLogin->Controls->Add(this->lblMessage1);
			this->panelLogin->Controls->Add(this->pbGeneralMilitary);
			this->panelLogin->ForeColor = System::Drawing::Color::White;
			this->panelLogin->Location = System::Drawing::Point(-10, -25);
			this->panelLogin->Margin = System::Windows::Forms::Padding(4);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(1600, 900);
			this->panelLogin->TabIndex = 12;
			// 
			// lvl1Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1580, 851);
			this->Controls->Add(this->panelLogin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"lvl1Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Level 1";
			this->Activated += gcnew System::EventHandler(this, &lvl1Form::lvl1Form_Activated);
			this->Load += gcnew System::EventHandler(this, &lvl1Form::lvl1Form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->EndInit();
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	//@avesh: text and timer
	private: System::Void lvl1Form_Load(System::Object^ sender, System::EventArgs^ e) {
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		System:String^ recruitname = gcnew System::String(this->player->username.c_str());
		lblMessage1->Text = "Welcome, agent " + recruitname+ "\nLevel 1";
		Transition1->Start();
	}
	private: System::Void lvl1Form_Activated(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void panelLogin_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

//@avesh: animation of the military general and text
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
	pbGeneralMilitary->Location = Point(x, 230);
	lblMessage1->Location = Point(395, y1);
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

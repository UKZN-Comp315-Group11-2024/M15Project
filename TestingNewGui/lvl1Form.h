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
			//@Daniel: need this to be true or listeners dont work
			this->KeyPreview = true;

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



	private: System::Windows::Forms::Timer^ Transition1;


	private: System::Windows::Forms::PictureBox^ pbGeneralMilitary;
	private: System::Windows::Forms::Panel^ panelLogin;
	private: System::Windows::Forms::Timer^ Transition2;
	private: System::Windows::Forms::Label^ lblMessage1;
	private: System::Windows::Forms::ProgressBar^ progressBarLevel1;
	private: System::Windows::Forms::Button^ beginButton;
	private: System::Windows::Forms::Timer^ timerProgress;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::PictureBox^ playerLvl1;
	private: System::Windows::Forms::Timer^ movePlayerTimer;






















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
			this->playerLvl1 = (gcnew System::Windows::Forms::PictureBox());
			this->beginButton = (gcnew System::Windows::Forms::Button());
			this->progressBarLevel1 = (gcnew System::Windows::Forms::ProgressBar());
			this->Transition2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerProgress = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->movePlayerTimer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->BeginInit();
			this->panelLogin->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playerLvl1))->BeginInit();
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
			this->pbGeneralMilitary->Location = System::Drawing::Point(-325, 288);
			this->pbGeneralMilitary->Margin = System::Windows::Forms::Padding(0);
			this->pbGeneralMilitary->Name = L"pbGeneralMilitary";
			this->pbGeneralMilitary->Size = System::Drawing::Size(371, 560);
			this->pbGeneralMilitary->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbGeneralMilitary->TabIndex = 11;
			this->pbGeneralMilitary->TabStop = false;
			this->pbGeneralMilitary->Click += gcnew System::EventHandler(this, &lvl1Form::pbGeneralMilitary_Click);
			// 
			// panelLogin
			// 
			this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));
			this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelLogin->Controls->Add(this->playerLvl1);
			this->panelLogin->Controls->Add(this->beginButton);
			this->panelLogin->Controls->Add(this->progressBarLevel1);
			this->panelLogin->Controls->Add(this->lblMessage1);
			this->panelLogin->Controls->Add(this->pbGeneralMilitary);
			this->panelLogin->ForeColor = System::Drawing::Color::White;
			this->panelLogin->Location = System::Drawing::Point(-10, -25);
			this->panelLogin->Margin = System::Windows::Forms::Padding(4);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(1600, 900);
			this->panelLogin->TabIndex = 12;
			this->panelLogin->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &lvl1Form::panelLogin_Paint_1);
			// 
			// playerLvl1
			// 
			this->playerLvl1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playerLvl1.Image")));
			this->playerLvl1->Location = System::Drawing::Point(144, 229);
			this->playerLvl1->Margin = System::Windows::Forms::Padding(4);
			this->playerLvl1->Name = L"playerLvl1";
			this->playerLvl1->Size = System::Drawing::Size(216, 220);
			this->playerLvl1->TabIndex = 14;
			this->playerLvl1->TabStop = false;
			this->playerLvl1->Visible = false;
			this->playerLvl1->Click += gcnew System::EventHandler(this, &lvl1Form::playerLvl1_Click);
			// 
			// beginButton
			// 
			this->beginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->beginButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->beginButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->beginButton->Location = System::Drawing::Point(612, 1000);
			this->beginButton->Margin = System::Windows::Forms::Padding(4);
			this->beginButton->Name = L"beginButton";
			this->beginButton->Size = System::Drawing::Size(244, 62);
			this->beginButton->TabIndex = 13;
			this->beginButton->Text = L"Begin";
			this->beginButton->UseVisualStyleBackColor = false;
			this->beginButton->Click += gcnew System::EventHandler(this, &lvl1Form::beginButton_Click);
			// 
			// progressBarLevel1
			// 
			this->progressBarLevel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBarLevel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->progressBarLevel1->ForeColor = System::Drawing::Color::Chartreuse;
			this->progressBarLevel1->Location = System::Drawing::Point(342, 40);
			this->progressBarLevel1->Margin = System::Windows::Forms::Padding(4);
			this->progressBarLevel1->Name = L"progressBarLevel1";
			this->progressBarLevel1->Size = System::Drawing::Size(728, 61);
			this->progressBarLevel1->TabIndex = 12;
			this->progressBarLevel1->Visible = false;
			// 
			// Transition2
			// 
			this->Transition2->Interval = 1;
			this->Transition2->Tick += gcnew System::EventHandler(this, &lvl1Form::Transition2_Tick);
			// 
			// timerProgress
			// 
			this->timerProgress->Interval = 20;
			this->timerProgress->Tick += gcnew System::EventHandler(this, &lvl1Form::timerProgress_Tick);
			// 
			// movePlayerTimer
			// 
			this->movePlayerTimer->Interval = 1;
			this->movePlayerTimer->Tick += gcnew System::EventHandler(this, &lvl1Form::movePlayerTimer_Tick);
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
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &lvl1Form::lvl1Form_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &lvl1Form::lvl1Form_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->EndInit();
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->playerLvl1))->EndInit();
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

//@avesh: animation of the military general and text into screen
//@avesh: animation of the military general and text
//@Daniel: and button
private: System::Void Transition1_Tick(System::Object^ sender, System::EventArgs^ e) {
	Point p1 = pbGeneralMilitary->Location;
	Point p2 = lblMessage1->Location;
	Point p3 = beginButton->Location;
	int x = p1.X, y1 = p2.Y, y2 = p3.Y;

	if (x <= 40)
	{
		x += 10;
	}
	if (y1 >= 400)
	{
		y1 -= 10;
	}
	if (y2 >= 470)
	{
		y2 -= 10;
	}
	
	pbGeneralMilitary->Location = Point(x, 230);
	lblMessage1->Location = Point(395, y1);
	beginButton->Location = Point(405, y2);
	
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}

//@avesh: animation of the military general and text out of screen
private: System::Void Transition2_Tick(System::Object^ sender, System::EventArgs^ e) {
	Point p1 = pbGeneralMilitary->Location;
	Point p2 = lblMessage1->Location;
	Point p3 = beginButton->Location;
	
	int x = p1.X, y1 = p2.Y, y2 = p3.Y;

	if (x >= -325)
	{
		x -= 10;
	}
	if (y1 <= 900)
	{
		y1 += 10;
	}
	if (y2 <= 1000)
	{
		y2 += 10;
	}

	// ensuring all stuff leaves screen before showing the player
	if (!(x >= -325) && !(y1 <= 900) && !(y2 <= 1000))
	{
		this->progressBarLevel1->Visible = true;
		this->playerLvl1->Visible = true;
		this->beginButton->Enabled = false;
		movePlayerTimer->Start();
		Transition2->Enabled = false;
	}
	pbGeneralMilitary->Location = Point(x, 230);
	lblMessage1->Location = Point(395, y1);
	beginButton->Location = Point(405, y2);
	
}
/*private: System::Void lvl1Form_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter && Transition1->Enabled)
	{
		Transition1->Enabled = false;
		Transition2->Start();
	}
}*/
private: System::Void panelLogin_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
//@Daniel: makes button and text invisible and starts the timer for each question
private: System::Void beginButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Transition1->Enabled = false;
	Transition2->Start();

	this->timerProgress->Start();

}
//@Daniel: timer for progress bar
private: System::Void timerProgress_Tick(System::Object^ sender, System::EventArgs^ e) {

	this->progressBarLevel1->Increment(1);
}
private: System::Void pbGeneralMilitary_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panelLogin_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
}

bool move_up = false;
bool move_left = false;
bool move_down = false;
bool move_right = false;

bool isRunning = false;

//@Daniel: listener for player movement
//@avesh: Edited and redefined how the player movement works (Smooth movement)
private: System::Void lvl1Form_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	e->SuppressKeyPress = true;
	/*switch (e->KeyCode) {
	case Keys::W:
		move_up = true;
		break;
		
	case Keys::A:
		move_left = true;
		break;
		
	case Keys::S:
		move_down = true;
		break;
		
	case Keys::D:
		move_right = true;
		break;
		
	default:
		break;
	}*/
	if (e->KeyCode == Keys::W)
	{
		move_up = true;
		isRunning = true;
	}
	else {
		move_up = false;
	}
	if (e->KeyCode == Keys::A)
	{
		move_left = true;
		isRunning = true;
	}
	else {
		move_left = false;
	}
	if (e->KeyCode == Keys::S)
	{
		move_down = true;
		isRunning = true;
	}
	else {
		move_down = false;
	}
	if (e->KeyCode == Keys::D)
	{
		move_right = true;
		isRunning = true;
	}
	else {
		move_right = false;
	}
	
}
	   
private: System::Void lvl1Form_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	e->SuppressKeyPress = true;
	switch (e->KeyCode)
	{
	case Keys::W:
		playerLvl1->Image = Image::FromFile("assets/PlayerMove/idle.gif");
		move_up = false;
		isRunning = false;
		break;
	case Keys::A:
		playerLvl1->Image = Image::FromFile("assets/PlayerMove/idle.gif");
		move_left = false;
		isRunning = false;
		break;
	case Keys::S:
		playerLvl1->Image = Image::FromFile("assets/PlayerMove/idle.gif");
		move_down = false;
		isRunning = false;
		break;
	case Keys::D:
		playerLvl1->Image = Image::FromFile("assets/PlayerMove/idle.gif");
		move_right = false;
		isRunning = false;
		break;

	default:
		break;
	}
}
private: System::Void movePlayerTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (isRunning && (move_up || move_down))
	{
		playerLvl1->Image = Image::FromFile("assets/PlayerMove/run.gif");
		isRunning = false;
	}
	if (move_up)
	{
		
		playerLvl1->Top += -5;
	}
	if (move_left)
	{
		
		playerLvl1->Left += -5;
	}
	if (move_down)
	{
		//playerLvl1->Image = Image::FromFile("assets/PlayerMove/run.gif");
		playerLvl1->Top += 5;
	}
	if (move_right)
	{
		//playerLvl1->Image = Image::FromFile("assets/PlayerMove/run.gif");
		playerLvl1->Left += 5;
	}
}

private: System::Void playerLvl1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void lvl1Form_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
}




private: System::Void lvl1Form_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
	/*switch (e->KeyCode) {
	case Keys::W:
		move_up = true;
		break;

	case Keys::A:
		move_left = true;
		break;

	case Keys::S:
		move_down = true;
		break;

	case Keys::D:
		move_right = true;
		break;

	default:
		break;
	}*/
	if (e->KeyChar == 'W')
	{
		move_up = true;
		isRunning = true;
	}
	if (e->KeyChar == 'A')
	{
		move_left = true;
		isRunning = true;
	}
	if (e->KeyChar == 'S')
	{
		move_down = true;
		isRunning = true;
	}
	if (e->KeyChar == 'D')
	{
		move_right = true;
		isRunning = true;
	}

}

};
}

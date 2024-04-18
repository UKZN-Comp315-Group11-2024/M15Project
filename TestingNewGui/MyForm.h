#pragma once
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <thread>
#include <windows.h>
#include <process.h>
#include <string>
#include "LoginForm.h"


namespace TestingNewGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		bool userClosed = false;
		MyForm(void)
		{
			PlaySound(TEXT("assets\\tensemusic.wav"), NULL, SND_FILENAME | SND_ASYNC);  //music can be found here https://pixabay.com/music/beats-dark-cinematic-ambient-beat-173058/
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tbSpyName;
	protected:

	private: System::Windows::Forms::Label^ lblSpyName;

	private: System::Windows::Forms::Panel^ panelLogin;
	private: System::Windows::Forms::Panel^ panelBoot;
	private: System::Windows::Forms::Button^ buttonVideo;

	protected:
		bool videoPlayed = false;
		int parity = 0;
	private: System::Windows::Forms::PictureBox^ loadingPictureBox;
	private: System::Windows::Forms::Label^ loadingLabel;
	private: System::Windows::Forms::Timer^ timerLoading;
	private: System::Windows::Forms::Timer^ timerGoToLogin;
	private: System::Windows::Forms::Timer^ timerVideo;
	private: System::Windows::Forms::PictureBox^ borderPictureBox;
	private: System::Windows::Forms::PictureBox^ bgpicturebox3;
	private: System::Windows::Forms::Label^ label1;







	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tbSpyName = (gcnew System::Windows::Forms::TextBox());
			this->lblSpyName = (gcnew System::Windows::Forms::Label());
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelBoot = (gcnew System::Windows::Forms::Panel());
			this->buttonVideo = (gcnew System::Windows::Forms::Button());
			this->borderPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->bgpicturebox3 = (gcnew System::Windows::Forms::PictureBox());
			this->loadingLabel = (gcnew System::Windows::Forms::Label());
			this->loadingPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->timerLoading = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerGoToLogin = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerVideo = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelLogin->SuspendLayout();
			this->panelBoot->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->borderPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bgpicturebox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->loadingPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// tbSpyName
			// 
			this->tbSpyName->BackColor = System::Drawing::Color::Firebrick;
			this->tbSpyName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSpyName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSpyName->Location = System::Drawing::Point(680, 382);
			this->tbSpyName->Margin = System::Windows::Forms::Padding(4);
			this->tbSpyName->MaxLength = 10;
			this->tbSpyName->Name = L"tbSpyName";
			this->tbSpyName->Size = System::Drawing::Size(676, 136);
			this->tbSpyName->TabIndex = 0;
			this->tbSpyName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbSpyName->TextChanged += gcnew System::EventHandler(this, &MyForm::tbSpyName_TextChanged);
			this->tbSpyName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::tbSpyName_KeyPress);
			// 
			// lblSpyName
			// 
			this->lblSpyName->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 40.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSpyName->Location = System::Drawing::Point(63, 400);
			this->lblSpyName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblSpyName->Name = L"lblSpyName";
			this->lblSpyName->Size = System::Drawing::Size(421, 109);
			this->lblSpyName->TabIndex = 1;
			this->lblSpyName->Text = L"Spy Name:";
			// 
			// panelLogin
			// 
			this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));
			this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelLogin->Controls->Add(this->tbSpyName);
			this->panelLogin->Controls->Add(this->lblSpyName);
			this->panelLogin->Location = System::Drawing::Point(0, 0);
			this->panelLogin->Margin = System::Windows::Forms::Padding(4);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(1600, 900);
			this->panelLogin->TabIndex = 2;
			this->panelLogin->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(629, 639);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 54);
			this->label1->TabIndex = 2;
			this->label1->Text = L"try";
			// 
			// panelBoot
			// 
			this->panelBoot->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panelBoot->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelBoot->Controls->Add(this->buttonVideo);
			this->panelBoot->Controls->Add(this->borderPictureBox);
			this->panelBoot->Controls->Add(this->bgpicturebox3);
			this->panelBoot->Controls->Add(this->loadingLabel);
			this->panelBoot->Controls->Add(this->loadingPictureBox);
			this->panelBoot->Location = System::Drawing::Point(0, 0);
			this->panelBoot->Margin = System::Windows::Forms::Padding(4);
			this->panelBoot->Name = L"panelBoot";
			this->panelBoot->Size = System::Drawing::Size(1600, 900);
			this->panelBoot->TabIndex = 3;
			// 
			// buttonVideo
			// 
			this->buttonVideo->BackColor = System::Drawing::Color::Black;
			this->buttonVideo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonVideo.BackgroundImage")));
			this->buttonVideo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonVideo->ForeColor = System::Drawing::Color::Transparent;
			this->buttonVideo->Location = System::Drawing::Point(571, 202);
			this->buttonVideo->Margin = System::Windows::Forms::Padding(0);
			this->buttonVideo->Name = L"buttonVideo";
			this->buttonVideo->Size = System::Drawing::Size(426, 404);
			this->buttonVideo->TabIndex = 4;
			this->buttonVideo->UseVisualStyleBackColor = false;
			this->buttonVideo->Click += gcnew System::EventHandler(this, &MyForm::buttonVideo_Click_1);
			// 
			// borderPictureBox
			// 
			this->borderPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"borderPictureBox.Image")));
			this->borderPictureBox->Location = System::Drawing::Point(491, 128);
			this->borderPictureBox->Margin = System::Windows::Forms::Padding(4);
			this->borderPictureBox->Name = L"borderPictureBox";
			this->borderPictureBox->Size = System::Drawing::Size(584, 551);
			this->borderPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->borderPictureBox->TabIndex = 7;
			this->borderPictureBox->TabStop = false;
			this->borderPictureBox->Visible = false;
			// 
			// bgpicturebox3
			// 
			this->bgpicturebox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bgpicturebox3.Image")));
			this->bgpicturebox3->Location = System::Drawing::Point(1235, 638);
			this->bgpicturebox3->Margin = System::Windows::Forms::Padding(4);
			this->bgpicturebox3->Name = L"bgpicturebox3";
			this->bgpicturebox3->Size = System::Drawing::Size(304, 211);
			this->bgpicturebox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bgpicturebox3->TabIndex = 10;
			this->bgpicturebox3->TabStop = false;
			this->bgpicturebox3->Click += gcnew System::EventHandler(this, &MyForm::bgpicturebox3_Click);
			// 
			// loadingLabel
			// 
			this->loadingLabel->AutoSize = true;
			this->loadingLabel->BackColor = System::Drawing::Color::Transparent;
			this->loadingLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 32.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadingLabel->ForeColor = System::Drawing::Color::Transparent;
			this->loadingLabel->Location = System::Drawing::Point(268, 399);
			this->loadingLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->loadingLabel->Name = L"loadingLabel";
			this->loadingLabel->Size = System::Drawing::Size(665, 59);
			this->loadingLabel->TabIndex = 6;
			this->loadingLabel->Text = L"Requesting Access...";
			this->loadingLabel->Visible = false;
			this->loadingLabel->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// loadingPictureBox
			// 
			this->loadingPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loadingPictureBox.Image")));
			this->loadingPictureBox->Location = System::Drawing::Point(-1, -1);
			this->loadingPictureBox->Margin = System::Windows::Forms::Padding(4);
			this->loadingPictureBox->Name = L"loadingPictureBox";
			this->loadingPictureBox->Size = System::Drawing::Size(1575, 850);
			this->loadingPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->loadingPictureBox->TabIndex = 5;
			this->loadingPictureBox->TabStop = false;
			this->loadingPictureBox->Visible = false;
			this->loadingPictureBox->Click += gcnew System::EventHandler(this, &MyForm::loadingPictureBox_Click);
			// 
			// timerLoading
			// 
			this->timerLoading->Interval = 10;
			this->timerLoading->Tick += gcnew System::EventHandler(this, &MyForm::timerLoading_Tick);
			// 
			// timerGoToLogin
			// 
			this->timerGoToLogin->Interval = 3000;
			this->timerGoToLogin->Tick += gcnew System::EventHandler(this, &MyForm::timerGoToLogin_Tick);
			// 
			// timerVideo
			// 
			this->timerVideo->Interval = 93000;
			this->timerVideo->Tick += gcnew System::EventHandler(this, &MyForm::timerVideo_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1580, 851);
			this->Controls->Add(this->panelLogin);
			this->Controls->Add(this->panelBoot);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Welcome, human";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			this->panelBoot->ResumeLayout(false);
			this->panelBoot->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->borderPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bgpicturebox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->loadingPictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void buttonVideo_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (!this->videoPlayed) {
		PlaySound(NULL, NULL, 0);								//get rid of existing sound and play video
		TCHAR szPath[] = TEXT("assets\\Welcome, human.mp4");  //voice for video can be found at https://elevenlabs.io/
		HINSTANCE hRet = ShellExecute(					      //glowing orb can be found at https://pixabay.com/videos/astronomy-glow-ray-science-star-140671/
			HWND_DESKTOP, //Parent window	
			TEXT("open"),       //Operation to perform
			szPath,       //Path to program
			NULL,         //Parameters
			NULL,         //Default directory
			SW_SHOW);     //How to open
		this->timerVideo->Enabled = true;
		this->timerVideo->Start();
		this->videoPlayed = true;
		this->borderPictureBox->Visible = true;				//once video is played the player can access the boot by pressing the button
	}
	else {
		//switches from initial screen to boot screen
		PlaySound(NULL, NULL, 0);
		PlaySound(TEXT("assets\\Mouse Click Sound Effect.wav"), NULL, SND_FILENAME | SND_SYNC);
		this->buttonVideo->Hide();
		this->loadingPictureBox->Visible = true;			
		this->loadingLabel->Parent = this->loadingPictureBox;
		this->loadingLabel->Visible = true;
		this->timerLoading->Enabled = true;
		this->timerLoading->Start();
		PlaySound(TEXT("assets\\tech sounds with music.wav"), NULL, SND_FILENAME | SND_ASYNC); //sound effect can be found at https://www.youtube.com/watch?v=SbO9xfTzXwA
	}
}
private: System::Void loadingPictureBox_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void timerLoading_Tick(System::Object^ sender, System::EventArgs^ e) {
	//code to slide loading label across the screen
	Point p = this->loadingLabel->Location;
	int x = p.X;
	int y = p.Y;
	this->loadingLabel->Location = Point(x+1, y);
	if (x < 325) {
		//rand() % 2 stuff is for the random flickering
		if (rand() % 2 == 0) {
			this->loadingLabel->Visible = false;
		}
		else{
			this->loadingLabel->Visible = true;
		}
		 
	}
	else {
		this->loadingLabel->Visible = true;
	}
	borderPictureBox->Visible = false;
	this->bgpicturebox3->Visible = false;
	
	if (x == 420 && loadingLabel->Text == L"Requesting Access...") {
		x = 214;
		this->loadingLabel->Location = Point(x + 1, y);
		loadingLabel->Text = L"Loading Spy Resources...";
	}

	//once it reaches a point it changes to "Loading Spy Resources..."
	if (x == 420 && loadingLabel->Text == L"Loading Spy Resources...") {
		timerLoading->Stop();
		timerLoading->Enabled = false;
		x = 356;
		this->loadingLabel->Location = Point(x + 1, y);
		timerGoToLogin->Enabled = true;
		loadingLabel->Text = L"Guest Access Granted.";
		PlaySound(NULL, NULL, 0);
		this->loadingPictureBox->Load(L"assets\\loadinggifstatic.png");  //loading gif can be found at: https://gifer.com/en/7SJe
		PlaySound(TEXT("assets\\chime"), NULL, SND_FILENAME | SND_ASYNC);
		timerGoToLogin->Start();

	}
}
	//after 3 seconds the timer to go to login switches panels from boot to login
private: System::Void timerGoToLogin_Tick(System::Object^ sender, System::EventArgs^ e) {
	timerGoToLogin->Stop();
	timerGoToLogin->Enabled = false;
	timerVideo->Stop();
	timerVideo->Enabled = false;
	//this->panelLogin->Visible = true;
	//loginForm.Show();
	this->Close();
	this->Text = L"Spy Login";			//login background can be found at https://www.wallpaperflare.com/red-and-black-world-map-handprints-map-technology-streaks-wallpaper-195790
	PlaySound(TEXT("assets\\tensemusic.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	//loginForm = (gcnew TestingNewGui::LoginForm());
}
private: System::Void timerVideo_Tick(System::Object^ sender, System::EventArgs^ e) {
	PlaySound(TEXT("assets\\Crystal Glow Sound Effect.wav"), NULL, SND_FILENAME | SND_ASYNC);
	this->timerVideo->Stop();
	this->timerVideo->Enabled = false;
}
private: System::Void bgpicturebox3_Click(System::Object^ sender, System::EventArgs^ e) {
	int x;
	//fun minigame on very first screen where the gif moves around the screen randomly 
	//but kept in bounds and doesn't overlap with main button
	parity = rand() % 2;
	if (parity%2==1) {
		this->bgpicturebox3->Load(L"assets\\bggif3.gif");
		x = rand() % 150;
	}
	else {
		this->bgpicturebox3->Load(L"assets\\bggif1.gif");
		x = (rand() % 170) + 830;
	}
	int y = rand() % 500;
	bgpicturebox3->Location = Point(x, y);
	
}
private: System::Void tbSpyName_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
}
private: System::Void tbSpyName_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	userClosed = true;
	LoginForm login;

}
};
}

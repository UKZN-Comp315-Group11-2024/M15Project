#pragma once
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <thread>
#include <windows.h>
#include <process.h>

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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panelLogin;
	private: System::Windows::Forms::Panel^ panelBoot;
	private: System::Windows::Forms::Button^ buttonVideo;

	protected:
		bool videoPlayed = false;
	private: System::Windows::Forms::PictureBox^ loadingPictureBox;
	private: System::Windows::Forms::Label^ loadingLabel;
	private: System::Windows::Forms::Timer^ timerLoading;
	private: System::Windows::Forms::Timer^ timerGoToLogin;
	private: System::Windows::Forms::Timer^ timerVideo;
	private: System::Windows::Forms::PictureBox^ borderPictureBox;
	private: System::Windows::Forms::PictureBox^ bgpicturebox3;







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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			this->panelBoot = (gcnew System::Windows::Forms::Panel());
			this->buttonVideo = (gcnew System::Windows::Forms::Button());
			this->bgpicturebox3 = (gcnew System::Windows::Forms::PictureBox());
			this->borderPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->loadingLabel = (gcnew System::Windows::Forms::Label());
			this->loadingPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->timerLoading = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerGoToLogin = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerVideo = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelLogin->SuspendLayout();
			this->panelBoot->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bgpicturebox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->borderPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->loadingPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(116, 346);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(193, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"BRUH";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(448, 320);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(386, 55);
			this->label1->TabIndex = 1;
			this->label1->Text = L"THIS IS A LABEL";
			// 
			// panelLogin
			// 
			this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));
			this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelLogin->Controls->Add(this->textBox1);
			this->panelLogin->Controls->Add(this->label1);
			this->panelLogin->Location = System::Drawing::Point(0, 0);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(1280, 720);
			this->panelLogin->TabIndex = 2;
			this->panelLogin->Visible = false;
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
			this->panelBoot->Name = L"panelBoot";
			this->panelBoot->Size = System::Drawing::Size(1280, 720);
			this->panelBoot->TabIndex = 3;
			// 
			// buttonVideo
			// 
			this->buttonVideo->BackColor = System::Drawing::Color::Black;
			this->buttonVideo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonVideo.BackgroundImage")));
			this->buttonVideo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonVideo->ForeColor = System::Drawing::Color::Transparent;
			this->buttonVideo->Location = System::Drawing::Point(457, 162);
			this->buttonVideo->Margin = System::Windows::Forms::Padding(0);
			this->buttonVideo->Name = L"buttonVideo";
			this->buttonVideo->Size = System::Drawing::Size(341, 323);
			this->buttonVideo->TabIndex = 4;
			this->buttonVideo->UseVisualStyleBackColor = false;
			this->buttonVideo->Click += gcnew System::EventHandler(this, &MyForm::buttonVideo_Click_1);
			// 
			// bgpicturebox3
			// 
			this->bgpicturebox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bgpicturebox3.Image")));
			this->bgpicturebox3->Location = System::Drawing::Point(1016, 510);
			this->bgpicturebox3->Name = L"bgpicturebox3";
			this->bgpicturebox3->Size = System::Drawing::Size(243, 169);
			this->bgpicturebox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bgpicturebox3->TabIndex = 10;
			this->bgpicturebox3->TabStop = false; //image can be found at: https://gifer.com/en/7GW5
			this->bgpicturebox3->Click += gcnew System::EventHandler(this, &MyForm::bgpicturebox3_Click);
			// 
			// borderPictureBox
			// 
			this->borderPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"borderPictureBox.Image")));
			this->borderPictureBox->Location = System::Drawing::Point(452, 158);
			this->borderPictureBox->Name = L"borderPictureBox";
			this->borderPictureBox->Size = System::Drawing::Size(353, 332);
			this->borderPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->borderPictureBox->TabIndex = 7;
			this->borderPictureBox->TabStop = false;
			// 
			// loadingLabel
			// 
			this->loadingLabel->AutoSize = true;
			this->loadingLabel->BackColor = System::Drawing::Color::Transparent;
			this->loadingLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 32.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loadingLabel->ForeColor = System::Drawing::Color::Transparent;
			this->loadingLabel->Location = System::Drawing::Point(270, 319);
			this->loadingLabel->Name = L"loadingLabel";
			this->loadingLabel->Size = System::Drawing::Size(540, 46);
			this->loadingLabel->TabIndex = 6;
			this->loadingLabel->Text = L"Requesting Access...";
			this->loadingLabel->Visible = false;
			this->loadingLabel->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// loadingPictureBox
			// 
			this->loadingPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loadingPictureBox.Image")));
			this->loadingPictureBox->Location = System::Drawing::Point(-1, -1);
			this->loadingPictureBox->Name = L"loadingPictureBox";
			this->loadingPictureBox->Size = System::Drawing::Size(1260, 680);
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
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->panelBoot);
			this->Controls->Add(this->panelLogin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Welcome, human";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			this->panelBoot->ResumeLayout(false);
			this->panelBoot->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bgpicturebox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->borderPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->loadingPictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void buttonVideo_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (!this->videoPlayed) {
		PlaySound(NULL, NULL, 0);
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
	}
	else {
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
	Point p = this->loadingLabel->Location;
	int x = p.X;
	int y = p.Y;
	this->loadingLabel->Location = Point(x+1, y);
	borderPictureBox->Visible = false;
	this->bgpicturebox3->Visible = false;
	if (x == 420 && loadingLabel->Text == L"Requesting Access...") {
		x = 214;
		this->loadingLabel->Location = Point(x + 1, y);
		loadingLabel->Text = L"Loading Spy Resources...";
	}

	if (x == 360 && loadingLabel->Text == L"Loading Spy Resources...") {
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

private: System::Void timerGoToLogin_Tick(System::Object^ sender, System::EventArgs^ e) {
	timerGoToLogin->Stop();
	timerGoToLogin->Enabled = false;
	timerVideo->Stop();
	timerVideo->Enabled = false;

	this->panelLogin->Visible = true;
	this->panelBoot->Visible = false;
	this->Text = L"Spy Login";			//login background can be found at https://www.wallpaperflare.com/red-and-black-world-map-handprints-map-technology-streaks-wallpaper-195790
	PlaySound(TEXT("assets\\tensemusic.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timerVideo_Tick(System::Object^ sender, System::EventArgs^ e) {
	PlaySound(TEXT("assets\\tensemusic.wav"), NULL, SND_FILENAME | SND_ASYNC);
	this->timerVideo->Stop();
	this->timerVideo->Enabled = false;
}
private: System::Void bgpicturebox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

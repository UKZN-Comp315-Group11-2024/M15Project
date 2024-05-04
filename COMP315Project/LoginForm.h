#pragma once
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <string>
#include "lvl1Form.h"
#include "playerInfo.h"
#include "FaceRecognition.h"
#include "customAlgs.h"
#include "Leaderboard.h"
#include "TutorialForm.h"
#include "MusicAndSFX.h"


namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Show();
			PlaySound(TEXT("assets\\tensemusic.wav"), NULL, SND_FILENAME | SND_ASYNC);
			userlist = gcnew List<playerInfo^>;
			std::ifstream file("textfiles/UsersAlphabetical.txt");
			std::string line;


			if (file.is_open())
			{
				while (getline(file, line))
				{
					playerInfo^ p = gcnew playerInfo;
					p->username = gcnew String(line.c_str());
					p->score = 0;
					p->timeTaken = 0;
					userlist->Add(p);
				}

			}
			file.close();
		}

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panelLogin;
	private: System::Windows::Forms::Label^ lblSuggestor;
	protected:

	private: System::Windows::Forms::TextBox^ tbSpyName;
	private: System::Windows::Forms::Label^ lblSpyName;
	private: System::Windows::Forms::Label^ lblWarning;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ Loginlabelscroll1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelloginscroll2;
	private: System::Windows::Forms::Timer^ timerloginscroll;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Timer^ starttypingtimer;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::PictureBox^ pictureboxlockgif;
	private: System::Windows::Forms::Timer^ timerlockgif;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label2;




	private:
		int logindots = 0;
		MusicAndSFX* sound = new MusicAndSFX;
		List<playerInfo^>^ userlist;
		bool tutorialWatched = false;


	private: System::Windows::Forms::PictureBox^ pbleaderboard;
	private: System::Windows::Forms::Button^ TutorialButton;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			   this->panelLogin = (gcnew System::Windows::Forms::Panel());
			   this->pictureboxlockgif = (gcnew System::Windows::Forms::PictureBox());
			   this->TutorialButton = (gcnew System::Windows::Forms::Button());
			   this->pbleaderboard = (gcnew System::Windows::Forms::PictureBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			   this->tbSpyName = (gcnew System::Windows::Forms::TextBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->labelloginscroll2 = (gcnew System::Windows::Forms::Label());
			   this->Loginlabelscroll1 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->lblWarning = (gcnew System::Windows::Forms::Label());
			   this->lblSuggestor = (gcnew System::Windows::Forms::Label());
			   this->lblSpyName = (gcnew System::Windows::Forms::Label());
			   this->timerloginscroll = (gcnew System::Windows::Forms::Timer(this->components));
			   this->starttypingtimer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timerlockgif = (gcnew System::Windows::Forms::Timer(this->components));
			   this->panelLogin->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxlockgif))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbleaderboard))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // panelLogin
			   // 
			   this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			   this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));
			   this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->panelLogin->Controls->Add(this->TutorialButton);
			   this->panelLogin->Controls->Add(this->pbleaderboard);
			   this->panelLogin->Controls->Add(this->label2);
			   this->panelLogin->Controls->Add(this->pictureBox3);
			   this->panelLogin->Controls->Add(this->tbSpyName);
			   this->panelLogin->Controls->Add(this->pictureBox2);
			   this->panelLogin->Controls->Add(this->labelloginscroll2);
			   this->panelLogin->Controls->Add(this->Loginlabelscroll1);
			   this->panelLogin->Controls->Add(this->label1);
			   this->panelLogin->Controls->Add(this->pictureBox1);
			   this->panelLogin->Controls->Add(this->lblWarning);
			   this->panelLogin->Controls->Add(this->lblSuggestor);
			   this->panelLogin->Controls->Add(this->lblSpyName);
			   this->panelLogin->Controls->Add(this->pictureboxlockgif);
			   this->panelLogin->ForeColor = System::Drawing::Color::White;
			   this->panelLogin->Location = System::Drawing::Point(-8, -20);
			   this->panelLogin->Name = L"panelLogin";
			   this->panelLogin->Size = System::Drawing::Size(1280, 720);
			   this->panelLogin->TabIndex = 3;
			   this->panelLogin->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::panelLogin_Paint);
			   // 
			   // pictureboxlockgif
			   // 
			   this->pictureboxlockgif->BackColor = System::Drawing::Color::Black;
			   this->pictureboxlockgif->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureboxlockgif.Image")));
			   this->pictureboxlockgif->Location = System::Drawing::Point(-276, -238);
			   this->pictureboxlockgif->Name = L"pictureboxlockgif";
			   this->pictureboxlockgif->Size = System::Drawing::Size(1846, 1066);
			   this->pictureboxlockgif->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureboxlockgif->TabIndex = 9;
			   this->pictureboxlockgif->TabStop = false;
			   this->pictureboxlockgif->Visible = false;
			   this->pictureboxlockgif->Click += gcnew System::EventHandler(this, &LoginForm::pictureboxlockgif_Click);
			   // 
			   // TutorialButton
			   // 
			   this->TutorialButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->TutorialButton->ForeColor = System::Drawing::Color::Black;
			   this->TutorialButton->Location = System::Drawing::Point(48, 540);
			   this->TutorialButton->Name = L"TutorialButton";
			   this->TutorialButton->Size = System::Drawing::Size(165, 94);
			   this->TutorialButton->TabIndex = 13;
			   this->TutorialButton->Text = L"Tutorial";
			   this->TutorialButton->UseVisualStyleBackColor = true;
			   this->TutorialButton->Click += gcnew System::EventHandler(this, &LoginForm::TutorialButton_Click);
			   // 
			   // pbleaderboard
			   // 
			   this->pbleaderboard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbleaderboard.Image")));
			   this->pbleaderboard->Location = System::Drawing::Point(20, 31);
			   this->pbleaderboard->Name = L"pbleaderboard";
			   this->pbleaderboard->Size = System::Drawing::Size(193, 163);
			   this->pbleaderboard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pbleaderboard->TabIndex = 12;
			   this->pbleaderboard->TabStop = false;
			   this->pbleaderboard->Click += gcnew System::EventHandler(this, &LoginForm::pbleaderboard_Click);
			   // 
			   // label2
			   // 
			   this->label2->BackColor = System::Drawing::Color::Transparent;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::Color::White;
			   this->label2->Location = System::Drawing::Point(737, 616);
			   this->label2->Margin = System::Windows::Forms::Padding(0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(287, 88);
			   this->label2->TabIndex = 11;
			   this->label2->Text = L"OR:\nFacial Recognition";
			   this->label2->Click += gcnew System::EventHandler(this, &LoginForm::label2_Click_1);
			   // 
			   // pictureBox3
			   // 
			   this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			   this->pictureBox3->Location = System::Drawing::Point(1017, 508);
			   this->pictureBox3->Name = L"pictureBox3";
			   this->pictureBox3->Size = System::Drawing::Size(154, 182);
			   this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox3->TabIndex = 10;
			   this->pictureBox3->TabStop = false;
			   this->pictureBox3->Click += gcnew System::EventHandler(this, &LoginForm::pictureBox3_Click);
			   // 
			   // tbSpyName
			   // 
			   this->tbSpyName->BackColor = System::Drawing::Color::Maroon;
			   this->tbSpyName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->tbSpyName->Font = (gcnew System::Drawing::Font(L"Courier New", 90, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->tbSpyName->ForeColor = System::Drawing::Color::White;
			   this->tbSpyName->Location = System::Drawing::Point(418, 182);
			   this->tbSpyName->MaxLength = 10;
			   this->tbSpyName->Name = L"tbSpyName";
			   this->tbSpyName->Size = System::Drawing::Size(785, 136);
			   this->tbSpyName->TabIndex = 0;
			   this->tbSpyName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->tbSpyName->TextChanged += gcnew System::EventHandler(this, &LoginForm::tbSpyName_TextChanged);
			   this->tbSpyName->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginForm::tbSpyName_KeyDown);
			   this->tbSpyName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LoginForm::tbSpyName_KeyPress);
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			   this->pictureBox2->Location = System::Drawing::Point(410, 177);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(798, 145);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox2->TabIndex = 8;
			   this->pictureBox2->TabStop = false;
			   // 
			   // labelloginscroll2
			   // 
			   this->labelloginscroll2->AutoSize = true;
			   this->labelloginscroll2->Font = (gcnew System::Drawing::Font(L"Courier New", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->labelloginscroll2->ForeColor = System::Drawing::Color::DarkGray;
			   this->labelloginscroll2->Location = System::Drawing::Point(401, 453);
			   this->labelloginscroll2->Name = L"labelloginscroll2";
			   this->labelloginscroll2->Size = System::Drawing::Size(661, 54);
			   this->labelloginscroll2->TabIndex = 7;
			   this->labelloginscroll2->Text = L"Press <ENTER> to Login";
			   // 
			   // Loginlabelscroll1
			   // 
			   this->Loginlabelscroll1->AutoSize = true;
			   this->Loginlabelscroll1->Font = (gcnew System::Drawing::Font(L"Courier New", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Loginlabelscroll1->ForeColor = System::Drawing::Color::DarkGray;
			   this->Loginlabelscroll1->Location = System::Drawing::Point(-642, 453);
			   this->Loginlabelscroll1->Name = L"Loginlabelscroll1";
			   this->Loginlabelscroll1->Size = System::Drawing::Size(661, 54);
			   this->Loginlabelscroll1->TabIndex = 6;
			   this->Loginlabelscroll1->Text = L"Press <ENTER> to Login";
			   this->Loginlabelscroll1->Click += gcnew System::EventHandler(this, &LoginForm::label2_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(0, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(35, 13);
			   this->label1->TabIndex = 5;
			   this->label1->Text = L"label1";
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->Location = System::Drawing::Point(1160, 31);
			   this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(100, 102);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 4;
			   this->pictureBox1->TabStop = false;
			   // 
			   // lblWarning
			   // 
			   this->lblWarning->AutoSize = true;
			   this->lblWarning->BackColor = System::Drawing::Color::Transparent;
			   this->lblWarning->Font = (gcnew System::Drawing::Font(L"Courier New", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblWarning->ForeColor = System::Drawing::Color::Red;
			   this->lblWarning->Location = System::Drawing::Point(584, 354);
			   this->lblWarning->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lblWarning->Name = L"lblWarning";
			   this->lblWarning->Size = System::Drawing::Size(370, 50);
			   this->lblWarning->TabIndex = 3;
			   this->lblWarning->Text = L"Start typing";
			   this->lblWarning->Click += gcnew System::EventHandler(this, &LoginForm::lblWarning_Click);
			   // 
			   // lblSuggestor
			   // 
			   this->lblSuggestor->AutoSize = true;
			   this->lblSuggestor->BackColor = System::Drawing::Color::Transparent;
			   this->lblSuggestor->Enabled = false;
			   this->lblSuggestor->Font = (gcnew System::Drawing::Font(L"Courier New", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblSuggestor->ForeColor = System::Drawing::Color::White;
			   this->lblSuggestor->Location = System::Drawing::Point(19, 636);
			   this->lblSuggestor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lblSuggestor->Name = L"lblSuggestor";
			   this->lblSuggestor->Size = System::Drawing::Size(0, 54);
			   this->lblSuggestor->TabIndex = 2;
			   // 
			   // lblSpyName
			   // 
			   this->lblSpyName->BackColor = System::Drawing::Color::Transparent;
			   this->lblSpyName->Font = (gcnew System::Drawing::Font(L"Courier New", 56.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblSpyName->ForeColor = System::Drawing::Color::White;
			   this->lblSpyName->Location = System::Drawing::Point(58, 206);
			   this->lblSpyName->Margin = System::Windows::Forms::Padding(0);
			   this->lblSpyName->Name = L"lblSpyName";
			   this->lblSpyName->Size = System::Drawing::Size(334, 87);
			   this->lblSpyName->TabIndex = 1;
			   this->lblSpyName->Text = L"Alias:";
			   this->lblSpyName->Click += gcnew System::EventHandler(this, &LoginForm::lblSpyName_Click);
			   // 
			   // timerloginscroll
			   // 
			   this->timerloginscroll->Enabled = true;
			   this->timerloginscroll->Interval = 1;
			   this->timerloginscroll->Tick += gcnew System::EventHandler(this, &LoginForm::timerloginscroll_Tick);
			   // 
			   // starttypingtimer
			   // 
			   this->starttypingtimer->Enabled = true;
			   this->starttypingtimer->Interval = 1000;
			   this->starttypingtimer->Tick += gcnew System::EventHandler(this, &LoginForm::starttypingtimer_Tick);
			   // 
			   // timerlockgif
			   // 
			   this->timerlockgif->Interval = 6000;
			   this->timerlockgif->Tick += gcnew System::EventHandler(this, &LoginForm::timerlockgif_Tick);
			   // 
			   // LoginForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->ClientSize = System::Drawing::Size(1264, 681);
			   this->Controls->Add(this->panelLogin);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->MaximizeBox = false;
			   this->Name = L"LoginForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Spy Login";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LoginForm::LoginForm_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			   this->panelLogin->ResumeLayout(false);
			   this->panelLogin->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxlockgif))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbleaderboard))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;

	}

	private: bool LoginForm::usernameExists(System::String^ s)
	{
		msclr::interop::marshal_context context;
		playerInfo^ p = gcnew playerInfo;
		p->username = s;
		p->score = 0;
		p->timeTaken = 0;

		return (customAlgs<playerInfo^>::binarySearchUsername(userlist, p) != -1);

	}

	private: System::Void tbSpyName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		lblWarning->Location = Point(604, 347);
		//Creates a name for the user incase they're struggling to create one
		System::String^ username = tbSpyName->Text;
		username = username->Trim();

		System::String^ suggestedName = "";
		bool isLastCharDigit = false;
		wchar_t temp = ' '; //Windows uses widechars, conversion between wide chars and chars can cause weird side effects
		//So make sure to use wchar whenever working with System::String

		//make sure the $ character doesn't appear cause that would break the game
		if (username->Length > 0) {
			if (username->Contains("$")) {
				int i = username->IndexOf("$");
				username = username->Substring(0, i) + username->Substring(i + 1, username->Length - i - 1);
				tbSpyName->Text = username;
			}
		}
		

		if (username->Length < 3) {
			lblWarning->Text = "Too Short";
			lblWarning->Location = Point(650, 347);
			lblSuggestor->Text = "";
			return;
		}

		if (username->Length == 0) {
			lblWarning->Location = Point(604, 347);
			lblSuggestor->Text = "";
			return;
		}

		if (username->Length == 10 && (!usernameExists(username))) {
			lblWarning->Text = "Alias available\n->(Max alias length)";
			lblSuggestor->Text = "";
			return;
		}

		if (usernameExists(username))
		{
			lblWarning->Location = Point(700, 347);
			lblWarning->Text = "TAKEN";
			if (username->Length >= 3 && username->Length <= 7) { //adding on a number to the name
				if (!usernameExists(username + "007") && usernameExists(username)) { //suggestedName is unique
					lblSuggestor->Enabled = true;
					lblSuggestor->Text = "Suggestion: " + username + "007";

					return;
				}

			}

			if (!isdigit(username[username->Length - 1])) {  //last char isn't a Number

				username = username->Substring(0, username->Length - 1); //removes last char
			}
			else { // last char is a number
				temp = username[username->Length - 1]; // keeping last digit
				isLastCharDigit = true;
				username = username->Substring(0, username->Length - 1);
				username = username->Substring(0, username->Length - 1);
			}

			//appending name with numbers
			for (int i = 1; i <= 9; i++) {

				username += i.ToString();

				if (isLastCharDigit) {
					username += temp - '0'; //returning the original digit this had at the end
				}
				if (!usernameExists(username)) { //username is unique
					isLastCharDigit = false;
					lblSuggestor->Enabled = true;
					lblSuggestor->Text = "Suggestion: " + username;
					return;
				}
				else {
					username = username->Substring(0, username->Length - 1);
					username = username->Substring(0, username->Length - 1);
					temp = i + '0';
					isLastCharDigit = true;
				}
			}

		}
		else
		{
			lblWarning->Text = "Alias available";
			lblSuggestor->Enabled = false;
			lblSuggestor->Text = "";
		}
	}

	private: System::Void tbSpyName_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter && (lblWarning->Text == "Alias available" || lblWarning->Text == "Alias available\n->(Max alias length)")) {
			// Show a message to indicate that the next form will be displayed
			if (!tutorialWatched) {
				if (MessageBox::Show("Are you sure you want to log in without watching the tutorial?", "", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
				{
					e->SuppressKeyPress = true;
					TutorialButton->Hide();
					pictureboxlockgif->Visible = true;
					timerlockgif->Enabled = true;
					timerlockgif->Start();
					PlaySound(NULL, NULL, 0);
					PlaySound(TEXT("assets\\techsounds"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
			else {
				e->SuppressKeyPress = true;
				TutorialButton->Hide();
				pictureboxlockgif->Visible = true;
				timerlockgif->Enabled = true;
				timerlockgif->Start();
				PlaySound(NULL, NULL, 0);
				PlaySound(TEXT("assets\\techsounds"), NULL, SND_FILENAME | SND_ASYNC);
			}
		}
	}

	//just to scroll the info at the top. uses 2 identical labels
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void timerloginscroll_Tick(System::Object^ sender, System::EventArgs^ e) {
		int x;
		Point p1 = Loginlabelscroll1->Location;
		Point p2 = labelloginscroll2->Location;
		x = p1.X;

		if (x == 1260) {
			x = -640;
			Loginlabelscroll1->Visible = false;
		}

		if (p2.X == 628) {

			x = -640;
			Loginlabelscroll1->Visible = false;
		}

		if (!(p2.X > -10 && p2.X < 630)) {
			x++;
			Loginlabelscroll1->Visible = true;
		}

		Loginlabelscroll1->Location = Point(x, 453);
		x = p2.X;

		if (x == 1260) {
			x = -640;
			labelloginscroll2->Visible = false;
		}

		if (p1.X == 628) {
			x = -640;
			labelloginscroll2->Visible = false;
		}

		if (!(p1.X > -10 && p1.X < 630)) {
			x++;
			labelloginscroll2->Visible = true;
		}

		labelloginscroll2->Location = Point(x, 453);
	}
	private: System::Void lblSpyName_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblWarning_Click(System::Object^ sender, System::EventArgs^ e) {

	}


	//little elipis animation
	private: System::Void starttypingtimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (tbSpyName->Text->Length == 0) {

			logindots = (logindots + 1) % 4;

			if (logindots == 0) {
				lblWarning->Text = "Start typing";
			}

			if (logindots == 1) {
				lblWarning->Text = "Start typing.";
			}

			if (logindots == 2) {
				lblWarning->Text = "Start typing..";
			}

			if (logindots == 3) {
				lblWarning->Text = "Start typing...";
			}
		}
	}

	private: System::Void panelLogin_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void tbSpyName_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {


	}
	private: System::Void pictureboxlockgif_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timerlockgif_Tick(System::Object^ sender, System::EventArgs^ e) {
		pictureboxlockgif->Visible = true; //image found at https://www.behance.net/gallery/111619785/4K-Network-Cyber-Security-Hack?log_shim_removal=1
		PlaySound(NULL, NULL, 0);
		PlaySound(TEXT("assets\\accessgranted.wav"), NULL, SND_FILENAME | SND_SYNC);
		PlaySound(TEXT("assets\\boom.wav"), NULL, SND_FILENAME | SND_SYNC);
		timerloginscroll->Enabled = false;
		starttypingtimer->Enabled = false;
		timerlockgif->Enabled = false;
		playerInfo^ player = gcnew playerInfo;
		player->score = 0;
		player->username = tbSpyName->Text;
		player->timeTaken = 0;
		std::ofstream ofs("textfiles/PlayerInfo.txt");
		msclr::interop::marshal_context context;
		ofs << context.marshal_as<std::string>(player->username) << "\n" << player->score << "\n" << player->timeTaken;
		ofs.close();
		lvl1Form^ lvl1form = gcnew lvl1Form();
		lvl1form->Visible = false;
		this->Hide();
		lvl1form->ShowDialog();
		this->Close();
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
		sound->MouseClick();
		if (!tutorialWatched) {
			if (MessageBox::Show("Are you sure you want to start facial recognition without watching the tutorial?", "", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
			{
				sound->playRandomSound("assets\\chime.wav", false);
				FaceRecognition^ facerec = gcnew FaceRecognition();
				std::string comm;
				this->Visible = false;
				this->Hide();
				facerec->ShowDialog();
				std::fstream file;
				file.open("textfiles/communication.txt", std::ios::in);
				if (file.is_open()) {
					getline(file, comm);
				}
				file.close();
				if (comm == "1") {

					this->Visible = true;
				}
				else if (comm == "0") {
					lvl1Form^ lvl1form = gcnew lvl1Form();
					lvl1form->Visible = false;
					this->Hide();
					lvl1form->ShowDialog();
					this->Close();
				}

				else if (comm == "-1") {
					this->Close();
				}
			}
		}
		else {
			sound->playRandomSound("assets\\chime.wav", false);
			FaceRecognition^ facerec = gcnew FaceRecognition();
			std::string comm;
			this->Visible = false;
			this->Hide();
			facerec->ShowDialog();
			std::fstream file;
			file.open("textfiles/communication.txt", std::ios::in);
			if (file.is_open()) {
				getline(file, comm);
			}
			file.close();
			if (comm == "1") {

				this->Visible = true;
			}
			else if (comm == "0") {
				lvl1Form^ lvl1form = gcnew lvl1Form();
				lvl1form->Visible = false;
				this->Hide();
				lvl1form->ShowDialog();
				this->Close();
			}

			else if (comm == "-1") {
				this->Close();
			}
		}

	}
	private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pbleaderboard_Click(System::Object^ sender, System::EventArgs^ e) {
		sound->playRandomSound("assets\\Mouse Click Sound Effect.wav", false);
		Leaderboard^ leaderboard = gcnew Leaderboard("no");
		leaderboard->Visible = false;
		this->Hide();
		leaderboard->ShowDialog();
		this->Show();
	}

	private: System::Void TutorialButton_Click(System::Object^ sender, System::EventArgs^ e) {
		sound->playRandomSound("assets\\Mouse Click Sound Effect.wav", false);
		tutorialWatched = true;
		TutorialForm^ tut = gcnew TutorialForm();
		tut->Visible = false;
		this->Hide();
		tut->ShowDialog();
		this->Show();
	}
	private: System::Void LoginForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		delete sound;
	}
	};
}

#pragma once
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <string>
#include "lvl1Form.h"
#include "playerInfo.h"

namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Show();
			PlaySound(TEXT("assets\\tensemusic.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
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




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int logindots = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			this->pictureboxlockgif = (gcnew System::Windows::Forms::PictureBox());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panelLogin
			// 
			this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));
			this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panelLogin->Controls->Add(this->pictureboxlockgif);
			this->panelLogin->Controls->Add(this->tbSpyName);
			this->panelLogin->Controls->Add(this->pictureBox2);
			this->panelLogin->Controls->Add(this->labelloginscroll2);
			this->panelLogin->Controls->Add(this->Loginlabelscroll1);
			this->panelLogin->Controls->Add(this->label1);
			this->panelLogin->Controls->Add(this->pictureBox1);
			this->panelLogin->Controls->Add(this->lblWarning);
			this->panelLogin->Controls->Add(this->lblSuggestor);
			this->panelLogin->Controls->Add(this->lblSpyName);
			this->panelLogin->ForeColor = System::Drawing::Color::White;
			this->panelLogin->Location = System::Drawing::Point(-10, -25);
			this->panelLogin->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(1600, 900);
			this->panelLogin->TabIndex = 3;
			this->panelLogin->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::panelLogin_Paint);
			// 
			// pictureboxlockgif
			// 
			this->pictureboxlockgif->BackColor = System::Drawing::Color::Black;
			this->pictureboxlockgif->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureboxlockgif.Image")));
			this->pictureboxlockgif->Location = System::Drawing::Point(-345, -298);
			this->pictureboxlockgif->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureboxlockgif->Name = L"pictureboxlockgif";
			this->pictureboxlockgif->Size = System::Drawing::Size(2308, 1332);
			this->pictureboxlockgif->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureboxlockgif->TabIndex = 9;
			this->pictureboxlockgif->TabStop = false;
			this->pictureboxlockgif->Visible = false;
			this->pictureboxlockgif->Click += gcnew System::EventHandler(this, &LoginForm::pictureboxlockgif_Click);
			// 
			// tbSpyName
			// 
			this->tbSpyName->BackColor = System::Drawing::Color::Maroon;
			this->tbSpyName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSpyName->Font = (gcnew System::Drawing::Font(L"Courier New", 90, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSpyName->ForeColor = System::Drawing::Color::White;
			this->tbSpyName->Location = System::Drawing::Point(522, 228);
			this->tbSpyName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tbSpyName->MaxLength = 10;
			this->tbSpyName->Name = L"tbSpyName";
			this->tbSpyName->Size = System::Drawing::Size(981, 170);
			this->tbSpyName->TabIndex = 0;
			this->tbSpyName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbSpyName->TextChanged += gcnew System::EventHandler(this, &LoginForm::tbSpyName_TextChanged);
			this->tbSpyName->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginForm::tbSpyName_KeyDown);
			this->tbSpyName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LoginForm::tbSpyName_KeyPress);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(512, 221);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(998, 181);
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
			this->labelloginscroll2->Location = System::Drawing::Point(501, 625);
			this->labelloginscroll2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelloginscroll2->Name = L"labelloginscroll2";
			this->labelloginscroll2->Size = System::Drawing::Size(821, 67);
			this->labelloginscroll2->TabIndex = 7;
			this->labelloginscroll2->Text = L"Press <ENTER> to Login";
			// 
			// Loginlabelscroll1
			// 
			this->Loginlabelscroll1->AutoSize = true;
			this->Loginlabelscroll1->Font = (gcnew System::Drawing::Font(L"Courier New", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Loginlabelscroll1->ForeColor = System::Drawing::Color::DarkGray;
			this->Loginlabelscroll1->Location = System::Drawing::Point(-800, 625);
			this->Loginlabelscroll1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Loginlabelscroll1->Name = L"Loginlabelscroll1";
			this->Loginlabelscroll1->Size = System::Drawing::Size(821, 67);
			this->Loginlabelscroll1->TabIndex = 6;
			this->Loginlabelscroll1->Text = L"Press <ENTER> to Login";
			this->Loginlabelscroll1->Click += gcnew System::EventHandler(this, &LoginForm::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1430, 732);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(125, 128);
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
			this->lblWarning->Location = System::Drawing::Point(736, 434);
			this->lblWarning->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblWarning->Name = L"lblWarning";
			this->lblWarning->Size = System::Drawing::Size(460, 65);
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
			this->lblSuggestor->Location = System::Drawing::Point(24, 795);
			this->lblSuggestor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblSuggestor->Name = L"lblSuggestor";
			this->lblSuggestor->Size = System::Drawing::Size(0, 65);
			this->lblSuggestor->TabIndex = 2;
			// 
			// lblSpyName
			// 
			this->lblSpyName->BackColor = System::Drawing::Color::Transparent;
			this->lblSpyName->Font = (gcnew System::Drawing::Font(L"Courier New", 56.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSpyName->ForeColor = System::Drawing::Color::White;
			this->lblSpyName->Location = System::Drawing::Point(72, 258);
			this->lblSpyName->Margin = System::Windows::Forms::Padding(0);
			this->lblSpyName->Name = L"lblSpyName";
			this->lblSpyName->Size = System::Drawing::Size(418, 109);
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
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1580, 851);
			this->Controls->Add(this->panelLogin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Spy Login";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxlockgif))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;

		// Used to rotate images - might be useful at some point
		//@archan: plane rotation
		//@avesh: adapted and edited
		// Create an image from the picturebox
		//System::Drawing::Image^ down_img = pictureBox1->Image;

		// Rotate the image
		//down_img->RotateFlip(System::Drawing::RotateFlipType::Rotate90FlipNone);

		// Set the rotated image to PictureBox
		//this->pictureBox1->Image = down_img;
	}

	//@jaedon: original code
	//@avesh: edited and adapted
	private: bool LoginForm::usernameExists(System::String^ s)
	{
		// Create a marshal context
		msclr::interop::marshal_context context;

		// Convert System::String^ to std::string
		std::string stdString = context.marshal_as<std::string>(s);

		std::ifstream file("textfiles/Leaderboard.txt");
		std::string line;

		if (file.is_open())
		{
			while (getline(file, line))
			{
				//size_t alias for unsigned long long
				//used in system functions where the return is a non-negative index, such as finding a position
				size_t pos = line.find('$');

				if (pos != -1 && line.substr(0, pos) == stdString)
				{

					return true;
				}
			}
			
		}
		file.close();
		return false;
		//moved return false outside if, makes sure the function always explicitly returns something
		//and it doesn't alter the logic

	}


	//@archan: original code
	//@avesh: edited and adapted
	private: System::Void tbSpyName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		lblWarning->Location = Point(604, 347);
		//Creates a name for the user incase they're struggling to create one
		System::String^ username = tbSpyName->Text;
		username = username->Trim();
		
		System::String^ suggestedName = "";
		bool isLastCharDigit = false;
		wchar_t temp = ' '; //Windows uses widechars, conversion between wide chars and chars can cause weird side effects
		//So make sure to use wchar whenever working with System::String

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

			//if (username->Length == 10) { //max chars
			if (!isdigit(username[username->Length - 1])) {  //last char isn't a Number

				username = username->Substring(0, username->Length - 1); //removes last char
			}
			else { // last char is a number
				temp = username[username->Length - 1]; // keeping last digit
				//cout << temp;
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

//@avesh: to move to next form after getting an acceptable alias (sound notification)
private: System::Void tbSpyName_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter && (lblWarning->Text == "Alias available" || lblWarning->Text == "Alias available\n->(Max alias length)")) {
		// Show a message to indicate that the next form will be displayed
		e->SuppressKeyPress = true;
		pictureboxlockgif->Visible = true;
		timerlockgif->Enabled = true;
		timerlockgif->Start();
		PlaySound(NULL, NULL, 0);
		PlaySound(TEXT("assets\\techsounds"), NULL, SND_FILENAME | SND_ASYNC);
		
		//std::cout<<"Show next form";
		//MessageBox::Show("Show next form", "Next Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

	   //just to scroll the info at the top. uses 2 identical labels
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timerloginscroll_Tick(System::Object^ sender, System::EventArgs^ e) {
	int x; //Removed y as it was never used
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

	Loginlabelscroll1->Location = Point(x, 500);
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

	labelloginscroll2->Location = Point(x, 500);
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
	playerInfo player;
	player.score = 0;
	player.username = msclr::interop::marshal_as<std::string>(tbSpyName->Text);
	player.timeTaken = 0;
	std::ofstream ofs("textfiles/PlayerInfo.txt");
	ofs << player.username << "\n" << player.score << "\n" << player.timeTaken;
	ofs.close();

	lvl1Form^ lvl1form = gcnew lvl1Form();
	lvl1form->Visible = false;
	this->Hide();
	lvl1form->ShowDialog();
	this->Close();
}
};
}

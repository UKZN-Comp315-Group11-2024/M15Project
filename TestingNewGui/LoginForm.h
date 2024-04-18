#pragma once
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <string>

namespace TestingNewGui {

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


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lblWarning = (gcnew System::Windows::Forms::Label());
			this->lblSuggestor = (gcnew System::Windows::Forms::Label());
			this->tbSpyName = (gcnew System::Windows::Forms::TextBox());
			this->lblSpyName = (gcnew System::Windows::Forms::Label());
			this->panelLogin->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panelLogin
			// 
			this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));
			this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panelLogin->Controls->Add(this->pictureBox1);
			this->panelLogin->Controls->Add(this->lblWarning);
			this->panelLogin->Controls->Add(this->lblSuggestor);
			this->panelLogin->Controls->Add(this->tbSpyName);
			this->panelLogin->Controls->Add(this->lblSpyName);
			this->panelLogin->Location = System::Drawing::Point(-10, -25);
			this->panelLogin->Margin = System::Windows::Forms::Padding(4);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(1600, 900);
			this->panelLogin->TabIndex = 3;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(447, 96);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(149, 174);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// lblWarning
			// 
			this->lblWarning->AutoSize = true;
			this->lblWarning->BackColor = System::Drawing::Color::Transparent;
			this->lblWarning->Font = (gcnew System::Drawing::Font(L"Determination Mono Web", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWarning->ForeColor = System::Drawing::Color::Red;
			this->lblWarning->Location = System::Drawing::Point(680, 552);
			this->lblWarning->Name = L"lblWarning";
			this->lblWarning->Size = System::Drawing::Size(477, 61);
			this->lblWarning->TabIndex = 3;
			this->lblWarning->Text = L"Start typing...";
			// 
			// lblSuggestor
			// 
			this->lblSuggestor->AutoSize = true;
			this->lblSuggestor->BackColor = System::Drawing::Color::Transparent;
			this->lblSuggestor->Enabled = false;
			this->lblSuggestor->Font = (gcnew System::Drawing::Font(L"Determination Mono Web", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSuggestor->ForeColor = System::Drawing::Color::Red;
			this->lblSuggestor->Location = System::Drawing::Point(680, 641);
			this->lblSuggestor->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblSuggestor->Name = L"lblSuggestor";
			this->lblSuggestor->Size = System::Drawing::Size(357, 61);
			this->lblSuggestor->TabIndex = 2;
			this->lblSuggestor->Text = L"Suggestion:";
			// 
			// tbSpyName
			// 
			this->tbSpyName->BackColor = System::Drawing::Color::Firebrick;
			this->tbSpyName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSpyName->Font = (gcnew System::Drawing::Font(L"Determination Mono Web", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSpyName->Location = System::Drawing::Point(680, 382);
			this->tbSpyName->Margin = System::Windows::Forms::Padding(4);
			this->tbSpyName->MaxLength = 10;
			this->tbSpyName->Name = L"tbSpyName";
			this->tbSpyName->Size = System::Drawing::Size(676, 123);
			this->tbSpyName->TabIndex = 0;
			this->tbSpyName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbSpyName->TextChanged += gcnew System::EventHandler(this, &LoginForm::tbSpyName_TextChanged);
			this->tbSpyName->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginForm::tbSpyName_KeyDown);
			this->tbSpyName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LoginForm::tbSpyName_KeyPress);
			// 
			// lblSpyName
			// 
			this->lblSpyName->BackColor = System::Drawing::Color::Transparent;
			this->lblSpyName->Font = (gcnew System::Drawing::Font(L"Determination Mono Web", 55.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSpyName->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblSpyName->Location = System::Drawing::Point(107, 392);
			this->lblSpyName->Margin = System::Windows::Forms::Padding(0);
			this->lblSpyName->Name = L"lblSpyName";
			this->lblSpyName->Size = System::Drawing::Size(339, 109);
			this->lblSpyName->TabIndex = 1;
			this->lblSpyName->Text = L"Alias:";
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
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Spy Login";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginForm::LoginForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LoginForm::LoginForm_KeyPress);
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;


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
	//@avesh: edited and adpated
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
				int pos = line.find('$');

				if (pos != -1 && line.substr(0, pos) == stdString)
				{

					return true;
				}
			}
			return false;
		}

	}


	//@archan: original code
	//@avesh: edited and adpated
	private: System::Void tbSpyName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//Creates a name for the user incase they're struggling to create one
		System::String^ username = tbSpyName->Text;
		System::String^ suggestedName = "";
		bool isLastCharDigit = false;
		char temp = ' ';

		if (username->Length < 3) {
			lblWarning->Text = "TOO SHORT";
			return;
		}

		if (username->Length == 0) {
			lblWarning->Text = "Start typing...";
			return;
		}

		if (usernameExists(username))
		{
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
			lblWarning->Text = "Accept state";
			lblSuggestor->Enabled = false;
			lblSuggestor->Text = "Suggestion:";
		}
	}
private: System::Void LoginForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
}
private: System::Void LoginForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
}
private: System::Void tbSpyName_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
}

//@avesh: to move to next form (sound notification)
private: System::Void tbSpyName_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter && lblWarning->Text == "Accept state") {
		// Show a message to indicate that the next form will be displayed
		e->SuppressKeyPress = true;
		
		//std::cout<<"Show next form";
		//MessageBox::Show("Show next form", "Next Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
};
}

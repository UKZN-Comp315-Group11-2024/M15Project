#pragma once
#include <iostream>

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
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbSpyName;
	private: System::Windows::Forms::Label^ lblSpyName;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbSpyName = (gcnew System::Windows::Forms::TextBox());
			this->lblSpyName = (gcnew System::Windows::Forms::Label());
			this->panelLogin->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelLogin
			// 
			this->panelLogin->BackColor = System::Drawing::Color::Transparent;
			this->panelLogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelLogin.BackgroundImage")));////login background can be found at https://www.wallpaperflare.com/red-and-black-world-map-handprints-map-technology-streaks-wallpaper-195790
			this->panelLogin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelLogin->Controls->Add(this->label1);
			this->panelLogin->Controls->Add(this->tbSpyName);
			this->panelLogin->Controls->Add(this->lblSpyName);
			this->panelLogin->Location = System::Drawing::Point(-8, -20);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(1280, 720);
			this->panelLogin->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(570, 506);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 44);
			this->label1->TabIndex = 2;
			this->label1->Text = L"try";
			// 
			// tbSpyName
			// 
			this->tbSpyName->BackColor = System::Drawing::Color::Firebrick;
			this->tbSpyName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSpyName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbSpyName->Location = System::Drawing::Point(544, 306);
			this->tbSpyName->MaxLength = 10;
			this->tbSpyName->Name = L"tbSpyName";
			this->tbSpyName->Size = System::Drawing::Size(541, 109);
			this->tbSpyName->TabIndex = 0;
			this->tbSpyName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbSpyName->TextChanged += gcnew System::EventHandler(this, &LoginForm::tbSpyName_TextChanged);
			// 
			// lblSpyName
			// 
			this->lblSpyName->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 40.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSpyName->Location = System::Drawing::Point(50, 320);
			this->lblSpyName->Name = L"lblSpyName";
			this->lblSpyName->Size = System::Drawing::Size(337, 87);
			this->lblSpyName->TabIndex = 1;
			this->lblSpyName->Text = L"Spy Name:";
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->panelLogin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Spy Login";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	}
private: System::Void tbSpyName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//Creates a name for the user incase they're struggling to create one
	System::String^ username = tbSpyName->Text;
	System::String^ suggestedName = "";
	bool isLastCharDigit = false;
	char temp = ' ';

	if (username->Length >= 3 && username->Length <= 7) { //adding on a number to the name
		suggestedName = username + "007";
		//if (!usernameExists(suggestedName)) { //suggestedName is unique
		//	username = suggestedName;
		//	return username;
		//}
		label1->Text = suggestedName;
	}

	/*if (username.length() == 10) { //max chars
		if (!isdigit(username[username.length() - 1])) {  //last char isn't a Number

			username.pop_back(); //removes last char
		}
		else { // last char is a number
			temp = username[username.length() - 1]; // keeping last digit
			//cout << temp;
			isLastCharDigit = true;
			username.pop_back();
			username.pop_back();

		}

	}
	//appending name with numbers
	for (int i = 1; i <= 9; i++) {
		username += to_string(i);

		if (isLastCharDigit) {
			username += temp; //returning the original digit this had at the end
		}
		if (!usernameExists(username)) { //username is unique
			isLastCharDigit = false;
			return username;
		}
		else {
			username.pop_back();
			username.pop_back();
		}
	}*/
}
};
}

#pragma once
#include <iostream>
#include <fstream>
#include "facerec.h"
#include "playerInfo.h"
#include "customAlgs.h"
#include "lvl1Form.h"
#include "MusicAndSFX.h"

namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FaceRecognition : public System::Windows::Forms::Form
	{
	public:
		FaceRecognition(void)
		{
			InitializeComponent();
		}

	protected:
		~FaceRecognition()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblrecognize1;
	private: System::Windows::Forms::Label^ lbladd1;


	protected:


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Timer^ timerfacerec;
	private: System::Windows::Forms::Label^ lblrecognize2;
	private: System::Windows::Forms::Label^ lbladd2;


	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TextBox^ txtusername;
	private: System::Windows::Forms::Label^ lblusername;
	private: System::Windows::Forms::Button^ btnokay;

	private:
		facerec* f = new facerec;

		List<playerInfo^>^ userlist = gcnew List<playerInfo^>;
		List<System::String^>^ facenames = gcnew List<System::String^>;

		System::String^ state = gcnew System::String("");
		System::String^ username = gcnew System::String("");

		bool labelsVisible = false;
		bool successful = false;

		MusicAndSFX* sound1 = new MusicAndSFX;
		MusicAndSFX* sound2 = new MusicAndSFX;
		MusicAndSFX* sound3 = new MusicAndSFX;

	private: System::Windows::Forms::Label^ lblSuggestor;
	private: System::Windows::Forms::Label^ lblWarning;
	private: System::Windows::Forms::PictureBox^ pictureboxbigface;
	private: System::Windows::Forms::Label^ lblpretty;
	private: System::Windows::Forms::TextBox^ txtpretty;
	private: System::Windows::Forms::Timer^ timerentrance;
	private: System::Windows::Forms::Timer^ timerexit;
		   

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FaceRecognition::typeid));
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->lblrecognize1 = (gcnew System::Windows::Forms::Label());
			   this->lbladd1 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->timerfacerec = (gcnew System::Windows::Forms::Timer(this->components));
			   this->lblrecognize2 = (gcnew System::Windows::Forms::Label());
			   this->lbladd2 = (gcnew System::Windows::Forms::Label());
			   this->txtusername = (gcnew System::Windows::Forms::TextBox());
			   this->lblusername = (gcnew System::Windows::Forms::Label());
			   this->btnokay = (gcnew System::Windows::Forms::Button());
			   this->lblSuggestor = (gcnew System::Windows::Forms::Label());
			   this->lblWarning = (gcnew System::Windows::Forms::Label());
			   this->pictureboxbigface = (gcnew System::Windows::Forms::PictureBox());
			   this->lblpretty = (gcnew System::Windows::Forms::Label());
			   this->timerexit = (gcnew System::Windows::Forms::Timer(this->components));
			   this->txtpretty = (gcnew System::Windows::Forms::TextBox());
			   this->timerentrance = (gcnew System::Windows::Forms::Timer(this->components));
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxbigface))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Transparent;
			   this->label1->Location = System::Drawing::Point(600, 186);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(0, 13);
			   this->label1->TabIndex = 0;
			   // 
			   // lblrecognize1
			   // 
			   this->lblrecognize1->AutoSize = true;
			   this->lblrecognize1->BackColor = System::Drawing::Color::Transparent;
			   this->lblrecognize1->Font = (gcnew System::Drawing::Font(L"Courier New", 50.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblrecognize1->ForeColor = System::Drawing::Color::White;
			   this->lblrecognize1->Location = System::Drawing::Point(183, 123);
			   this->lblrecognize1->Name = L"lblrecognize1";
			   this->lblrecognize1->Size = System::Drawing::Size(672, 76);
			   this->lblrecognize1->TabIndex = 1;
			   this->lblrecognize1->Text = L"<Recognize Face>";
			   this->lblrecognize1->Click += gcnew System::EventHandler(this, &FaceRecognition::lblrecognize1_Click);
			   // 
			   // lbladd1
			   // 
			   this->lbladd1->AutoSize = true;
			   this->lbladd1->BackColor = System::Drawing::Color::Transparent;
			   this->lbladd1->Font = (gcnew System::Drawing::Font(L"Courier New", 50.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lbladd1->ForeColor = System::Drawing::Color::Red;
			   this->lbladd1->Location = System::Drawing::Point(336, 251);
			   this->lbladd1->Name = L"lbladd1";
			   this->lbladd1->Size = System::Drawing::Size(432, 76);
			   this->lbladd1->TabIndex = 2;
			   this->lbladd1->Text = L"<Add Face>";
			   this->lbladd1->Click += gcnew System::EventHandler(this, &FaceRecognition::lbladd1_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->Location = System::Drawing::Point(960, 366);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(318, 328);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox1->TabIndex = 3;
			   this->pictureBox1->TabStop = false;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			   this->pictureBox2->Location = System::Drawing::Point(12, 561);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(118, 108);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox2->TabIndex = 4;
			   this->pictureBox2->TabStop = false;
			   this->pictureBox2->Click += gcnew System::EventHandler(this, &FaceRecognition::pictureBox2_Click);
			   // 
			   // timerfacerec
			   // 
			   this->timerfacerec->Enabled = true;
			   this->timerfacerec->Interval = 50;
			   this->timerfacerec->Tick += gcnew System::EventHandler(this, &FaceRecognition::timerfacerec_Tick);
			   // 
			   // lblrecognize2
			   // 
			   this->lblrecognize2->AutoSize = true;
			   this->lblrecognize2->BackColor = System::Drawing::Color::Transparent;
			   this->lblrecognize2->Font = (gcnew System::Drawing::Font(L"Courier New", 50.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblrecognize2->ForeColor = System::Drawing::Color::White;
			   this->lblrecognize2->Location = System::Drawing::Point(-669, 123);
			   this->lblrecognize2->Name = L"lblrecognize2";
			   this->lblrecognize2->Size = System::Drawing::Size(672, 76);
			   this->lblrecognize2->TabIndex = 5;
			   this->lblrecognize2->Text = L"<Recognize Face>";
			   this->lblrecognize2->Click += gcnew System::EventHandler(this, &FaceRecognition::lblrecognize2_Click);
			   // 
			   // lbladd2
			   // 
			   this->lbladd2->AutoSize = true;
			   this->lbladd2->BackColor = System::Drawing::Color::Transparent;
			   this->lbladd2->Font = (gcnew System::Drawing::Font(L"Courier New", 50.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lbladd2->ForeColor = System::Drawing::Color::Red;
			   this->lbladd2->Location = System::Drawing::Point(-419, 251);
			   this->lbladd2->Name = L"lbladd2";
			   this->lbladd2->Size = System::Drawing::Size(432, 76);
			   this->lbladd2->TabIndex = 6;
			   this->lbladd2->Text = L"<Add Face>";
			   this->lbladd2->Click += gcnew System::EventHandler(this, &FaceRecognition::lbladd2_Click);
			   // 
			   // txtusername
			   // 
			   this->txtusername->Font = (gcnew System::Drawing::Font(L"Courier New", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txtusername->ForeColor = System::Drawing::Color::Red;
			   this->txtusername->Location = System::Drawing::Point(438, 410);
			   this->txtusername->MaxLength = 10;
			   this->txtusername->Name = L"txtusername";
			   this->txtusername->Size = System::Drawing::Size(449, 80);
			   this->txtusername->TabIndex = 8;
			   this->txtusername->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   this->txtusername->TextChanged += gcnew System::EventHandler(this, &FaceRecognition::txtusername_TextChanged);
			   // 
			   // lblusername
			   // 
			   this->lblusername->AutoSize = true;
			   this->lblusername->Font = (gcnew System::Drawing::Font(L"Courier New", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblusername->ForeColor = System::Drawing::Color::White;
			   this->lblusername->Location = System::Drawing::Point(130, 427);
			   this->lblusername->Name = L"lblusername";
			   this->lblusername->Size = System::Drawing::Size(284, 54);
			   this->lblusername->TabIndex = 9;
			   this->lblusername->Text = L"Username:";
			   // 
			   // btnokay
			   // 
			   this->btnokay->Font = (gcnew System::Drawing::Font(L"Courier New", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnokay->Location = System::Drawing::Point(603, 510);
			   this->btnokay->Name = L"btnokay";
			   this->btnokay->Size = System::Drawing::Size(93, 53);
			   this->btnokay->TabIndex = 10;
			   this->btnokay->Text = L"OK";
			   this->btnokay->UseVisualStyleBackColor = true;
			   this->btnokay->Click += gcnew System::EventHandler(this, &FaceRecognition::btnokay_Click);
			   // 
			   // lblSuggestor
			   // 
			   this->lblSuggestor->AutoSize = true;
			   this->lblSuggestor->Font = (gcnew System::Drawing::Font(L"Courier New", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblSuggestor->ForeColor = System::Drawing::Color::White;
			   this->lblSuggestor->Location = System::Drawing::Point(432, 612);
			   this->lblSuggestor->Name = L"lblSuggestor";
			   this->lblSuggestor->Size = System::Drawing::Size(0, 31);
			   this->lblSuggestor->TabIndex = 11;
			   this->lblSuggestor->Tag = L"";
			   // 
			   // lblWarning
			   // 
			   this->lblWarning->AutoSize = true;
			   this->lblWarning->Font = (gcnew System::Drawing::Font(L"Courier New", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblWarning->ForeColor = System::Drawing::Color::Red;
			   this->lblWarning->Location = System::Drawing::Point(133, 510);
			   this->lblWarning->Name = L"lblWarning";
			   this->lblWarning->Size = System::Drawing::Size(94, 31);
			   this->lblWarning->TabIndex = 12;
			   this->lblWarning->Text = L"Enter";
			   // 
			   // pictureboxbigface
			   // 
			   this->pictureboxbigface->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureboxbigface.Image")));
			   this->pictureboxbigface->Location = System::Drawing::Point(0, 0);
			   this->pictureboxbigface->Name = L"pictureboxbigface";
			   this->pictureboxbigface->Size = System::Drawing::Size(1280, 720);
			   this->pictureboxbigface->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			   this->pictureboxbigface->TabIndex = 13;
			   this->pictureboxbigface->TabStop = false;
			   // 
			   // lblpretty
			   // 
			   this->lblpretty->AutoSize = true;
			   this->lblpretty->Font = (gcnew System::Drawing::Font(L"Courier New", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblpretty->ForeColor = System::Drawing::Color::White;
			   this->lblpretty->Location = System::Drawing::Point(212, 595);
			   this->lblpretty->Name = L"lblpretty";
			   this->lblpretty->Size = System::Drawing::Size(864, 54);
			   this->lblpretty->TabIndex = 14;
			   this->lblpretty->Text = L"Facial Recognition Successful";
			   this->lblpretty->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // timerexit
			   // 
			   this->timerexit->Interval = 3000;
			   this->timerexit->Tick += gcnew System::EventHandler(this, &FaceRecognition::timerexit_Tick);
			   // 
			   // txtpretty
			   // 
			   this->txtpretty->BackColor = System::Drawing::Color::Black;
			   this->txtpretty->Font = (gcnew System::Drawing::Font(L"Courier New", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txtpretty->ForeColor = System::Drawing::Color::White;
			   this->txtpretty->Location = System::Drawing::Point(139, 595);
			   this->txtpretty->Name = L"txtpretty";
			   this->txtpretty->ReadOnly = true;
			   this->txtpretty->Size = System::Drawing::Size(967, 49);
			   this->txtpretty->TabIndex = 15;
			   this->txtpretty->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // 
			   // timerentrance
			   // 
			   this->timerentrance->Enabled = true;
			   this->timerentrance->Interval = 3000;
			   this->timerentrance->Tick += gcnew System::EventHandler(this, &FaceRecognition::timerentrance_Tick);
			   // 
			   // FaceRecognition
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->ClientSize = System::Drawing::Size(1264, 681);
			   this->Controls->Add(this->pictureboxbigface);
			   this->Controls->Add(this->txtpretty);
			   this->Controls->Add(this->lblpretty);
			   this->Controls->Add(this->lblWarning);
			   this->Controls->Add(this->lblSuggestor);
			   this->Controls->Add(this->btnokay);
			   this->Controls->Add(this->lblusername);
			   this->Controls->Add(this->txtusername);
			   this->Controls->Add(this->lbladd2);
			   this->Controls->Add(this->lblrecognize2);
			   this->Controls->Add(this->pictureBox2);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->lbladd1);
			   this->Controls->Add(this->lblrecognize1);
			   this->Controls->Add(this->label1);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MaximizeBox = false;
			   this->Name = L"FaceRecognition";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Face Identifier";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FaceRecognition::FaceRecognition_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &FaceRecognition::FaceRecognition_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxbigface))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion


	//Start up the form. Set visibility of components, etc
	private: System::Void FaceRecognition_Load(System::Object^ sender, System::EventArgs^ e) {
		sound2->FacialRegocnition();
		sound1->playRandomSound("assets\\boom.wav", false);
		this->txtpretty->BringToFront();
		this->timerentrance->Start();
		txtpretty->Visible = true;
		txtpretty->Text = "Welcome to M15's Facial Recognition AI";
		pictureboxbigface->Visible = true;

		//read in existing usernames
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

		//read in existing faces
		std::ifstream file2("textfiles/usernameFaceNum.txt");
		if (file2.is_open())
		{
			getline(file2, line);
			while (getline(file2, line))
			{
				int pos = line.find("$");
				line.erase(0, pos + 1);
				facenames->Add(gcnew String(line.c_str()));
			}

		}
		file2.close();

	}

	//clean up resources when form closed
	private: System::Void FaceRecognition_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		timerfacerec->Stop();
		timerentrance->Stop();
		timerexit->Stop();

		if (!successful) {
			std::ofstream ofs("textfiles\\communication.txt", std::ofstream::trunc);

			if (ofs.is_open()) {  // Check if the file was successfully opened
				ofs << "1"; //1 meaning login should not close
			}
			ofs.close();  // Close the file after writing
		}

		delete sound1;
		delete sound2;
		delete sound3;
		delete f;

	}

	//back button depends on state of form
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		sound3->MouseClick();
		//if entering username, back should take them out of the entering username part
		if (state != "entering username") {
			std::ofstream ofs("textfiles\\communication.txt", std::ofstream::trunc);

			if (ofs.is_open()) {  // Check if the file was successfully opened
				ofs << "1"; //1 meaning login should not close
			}
			ofs.close();  // Close the file after writing
			this->Close();
		}

		//otherwise back takes them back to login
		else {
			this->lblusername->Visible = false;
			this->txtusername->Visible = false;
			this->btnokay->Visible = false;
			this->lblSuggestor->Visible = false;
			this->lblWarning->Visible = false;
			this->state = "waiting";
		}
		

	}

	//scrolling animations, using 2 identical labels for each line of text
	private: System::Void timerfacerec_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (labelsVisible) {
			int x;
			System::Drawing::Point p1 = lblrecognize1->Location;
			System::Drawing::Point p2 = lblrecognize2->Location;
			x = p1.X;

			if (x == 1262) {
				x = -640;
				lblrecognize1->Visible = false;
			}

			if (p2.X == 630) {

				x = -640;
				lblrecognize1->Visible = false;
			}

			if (!(p2.X > -10 && p2.X < 630)) {
				x += 3;
				lblrecognize1->Visible = true;
			}

			lblrecognize1->Location = System::Drawing::Point(x, 123);
			x = p2.X;

			if (x == 1262) {
				x = -640;
				lblrecognize2->Visible = false;
			}

			if (p1.X == 632) {
				x = -640;
				lblrecognize2->Visible = false;
			}

			if (!(p1.X > -10 && p1.X < 630)) {
				x += 3;
				lblrecognize2->Visible = true;
			}

			lblrecognize2->Location = System::Drawing::Point(x, 123);

			p1 = lbladd1->Location;
			p2 = lbladd2->Location;
			x = p1.X;

			if (x == 1260) {
				x = -640;
				lbladd1->Visible = false;
			}

			if (p2.X == 628) {

				x = -640;
				lbladd1->Visible = false;
			}

			if (!(p2.X > -10 && p2.X < 630)) {
				x += 4;
				lbladd1->Visible = true;
			}

			lbladd1->Location = System::Drawing::Point(x, 251);
			x = p2.X;

			if (x == 1260) {
				x = -640;
				lbladd2->Visible = false;
			}

			if (p1.X == 628) {
				x = -640;
				lbladd2->Visible = false;
			}

			if (!(p1.X > -10 && p1.X < 630)) {
				x += 4;
				lbladd2->Visible = true;
			}

			lbladd2->Location = System::Drawing::Point(x, 251);
		}
		
	}

	//attempts to recognize face. Exceptions are caught.
	private: System::Void lblrecognize1_Click(System::Object^ sender, System::EventArgs^ e) {
		sound1->MouseClick();
		if (MessageBox::Show("The AI is about to commence facial recognition. Please look directly at the webcam and ensure there is no one else around you.", "", MessageBoxButtons::OKCancel, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK)
		{
			btnokay->Enabled = false;
			try {
				state = "recognizing";
				std::string s = f->FaceRecognitionNew();
				if (s != "") {
					username = gcnew System::String(s.c_str());
					pictureboxbigface->Visible = true;
					this->txtpretty->Visible = true;
					txtpretty->Text = "Facial Recognition Successful";
					successful = true;
					timerexit->Start();
				}
				else {
					MessageBox::Show("The AI could not recognize you. Make sure you are close enough to the camera.", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
					btnokay->Enabled = true;
				}
			}
			catch (System::Exception^ e) {
				MessageBox::Show("The AI is grumpy today and doesn't feel like recognizing (We're too scared of her to do anything about it). Try logging in with a username instead.", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
	}

	//attempts to recognize face. Exceptions are caught.
	private: System::Void lblrecognize2_Click(System::Object^ sender, System::EventArgs^ e) {
		sound1->MouseClick();
		if (MessageBox::Show("The AI is about to commence facial recognition. Please look directly at the webcam and ensure there is no one else around you.", "", MessageBoxButtons::OKCancel, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK)
		{
			btnokay->Enabled = false;
			try {
				state = "recognizing";
				std::string s = f->FaceRecognitionNew();
				if (s != "") {
					username = gcnew System::String(s.c_str());
					pictureboxbigface->Visible = true;
					this->txtpretty->Visible = true;
					txtpretty->Text = "Facial Recognition Successful";
					successful = true;
					timerexit->Start();
				}
				else {
					MessageBox::Show("The AI could not recognize you. Make sure you are close enough to the camera.", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
					btnokay->Enabled = true;
				}
			}
			catch (System::Exception^ e) {
				MessageBox::Show("The AI is grumpy today and doesn't feel like recognizing (We're too scared of her to do anything about it). Try logging in with a username instead.", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
	}

	//allows user to enter a new username. Exceptions are caught.
	private: System::Void lbladd1_Click(System::Object^ sender, System::EventArgs^ e) {
		sound1->MouseClick();
		try {
			this->lblusername->Visible = true;
			this->txtusername->Visible = true;
			this->btnokay->Visible = true;
			this->lblSuggestor->Visible = true;
			this->lblWarning->Visible = true;
			state = "entering username";
		}
		catch (System::Exception^ e) {
			MessageBox::Show("The AI is grumpy today and doesn't feel like recognizing (We're too scared of her to do anything about it). This might be because more than one person is visible.", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		
	}

	//allows user to enter a new username. Exceptions are caught.
	private: System::Void lbladd2_Click(System::Object^ sender, System::EventArgs^ e) {
		sound1->MouseClick();
		try {
			this->lblusername->Visible = true;
			this->txtusername->Visible = true;
			this->btnokay->Visible = true;
			this->lblSuggestor->Visible = true;
			this->lblWarning->Visible = true;
			state = "entering username";
		}
		catch (System::Exception^ e) {
			MessageBox::Show("The AI is grumpy today and doesn't feel like recognizing (We're too scared of her to do anything about it). This might be because more than one person is visible.", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	}

	//username exists when it exists in the exiting usernames, or the existing faces
	private: bool usernameExists(System::String^ s)
	{
		msclr::interop::marshal_context context;
		playerInfo^ p = gcnew playerInfo;
		p->username = s;
		p->score = 0;
		p->timeTaken = 0;

		return ((customAlgs<playerInfo^>::binarySearchUsername(userlist, p) != -1) || (facenames->Contains(s)));

	}

	private: System::Void txtusername_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		lblWarning->Location = Point(133, 510);
		//Creates a name for the user incase they're struggling to create one
		System::String^ username = txtusername->Text;
		username = username->Trim();

		System::String^ suggestedName = "";
		bool isLastCharDigit = false;
		wchar_t temp = ' '; //Windows uses widechars, conversion between wide chars and chars can cause weird side effects
		//So make sure to use wchar whenever working with System::String

		if (username->Length < 3) {
			lblWarning->Text = "Too Short";
			lblWarning->Location = Point(133, 510);
			lblSuggestor->Text = "";
			return;
		}

		if (username->Length == 0) {
			lblWarning->Location = Point(133, 510);
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
			lblWarning->Location = Point(133, 510);
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

	//attempts to add user's face. Exceptions are caught.
	private: System::Void btnokay_Click(System::Object^ sender, System::EventArgs^ e) {
		int result = -1;
		if (lblWarning->Text == "Alias available" || lblWarning->Text == "Alias available\n->(Max alias length)") {
			sound1->MouseClick();
			if (MessageBox::Show("Please look directly at your webcam. Our AI will now start the webcam, and then take 10 pictures of you instantly, all within 1 second. Thereafter it will process your facial structure. Please wait for all processing to complete before continuing", "", MessageBoxButtons::OKCancel, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK)
			{	
				btnokay->Enabled = false;
				this->lblusername->Visible = false;
				this->txtusername->Visible = false;
				this->btnokay->Visible = false;
				this->lblSuggestor->Visible = false;
				this->lblWarning->Visible = false;
				try {
					this->lblrecognize1->Visible = false;
					this->lblrecognize2->Visible = false;
					this->lbladd1->Visible = false;
					this->lbladd2->Visible = false;
					this->pictureBox1->Visible = false;
					this->pictureBox2->Visible = false;
					labelsVisible = false;

					this->pictureboxbigface->Visible = true;
					this->txtpretty->Text = "Processing...";
					sound3->FacialRegocnition();
					this->txtpretty->Visible = true;
					std::string s = assignNumber();
					result = f->addFace(s);
					if (result == 0) {
						f->eigenFaceTrainer();
					}
					else {
						MessageBox::Show("The AI was unable to open your camera. Please exit the Face Recognition AI and login with a username instead", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
						std::ofstream ofs2("textfiles\\communication.txt", std::ofstream::trunc);

						successful = true;
						if (ofs2.is_open()) {  // Check if the file was successfully opened
							ofs2 << "-1"; //-1 meaning login should close
						}
						ofs2.close();  // Close the file after writing
						this->Close();
					}
					

				}
				catch (System::Exception^ e) {
					MessageBox::Show("The AI is grumpy today and doesn't feel like recognizing (We're too scared of her to do anything about it). This might be because more than one person is visible.", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			PlaySound(NULL, NULL, 0);
			sound1->playRandomSound("assets\\boom.wav", false);
			sound3->FacialRegocnition();
			this->txtpretty->Text = "Processing complete";
			MessageBox::Show("Facial processing complete. Please restart the application to login with facial recognition.", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->lblrecognize1->Visible = true;
				this->lblrecognize2->Visible = true;
				this->lbladd1->Visible = true;
				this->lbladd2->Visible = true;
				this->pictureBox1->Visible = true;
				this->pictureBox2->Visible = true;
				labelsVisible = true;
				this->pictureboxbigface->Visible = false;
				this->lblpretty->Visible = false;
				this->timerfacerec->Stop();
				this->txtpretty->Visible = false;
				std::ofstream ofs2("textfiles\\communication.txt", std::ofstream::trunc);

				successful = true;
				if (ofs2.is_open()) {  // Check if the file was successfully opened
					ofs2 << "-1"; //-1 meaning login should close
				}
				ofs2.close();  // Close the file after writing
				this->Close();

		}
		btnokay->Enabled = true;

	}
	//to convert username to a number so facerec.cpp can use it. Assigns user next number sequentially.
	std::string assignNumber() {
		std::ifstream file("textfiles\\usernameFaceNum.txt");
		std::string line;
		std::vector<std::string> facenames;
		msclr::interop::marshal_context context;
		int numusers;

		if (file.is_open())
		{
			getline(file, line);
			numusers = std::stoi(line);
			while (getline(file, line))
			{
				int pos = line.find("$");
				line.erase(0, pos + 1);
				facenames.push_back(line);
			}
		}
		file.close();


		std::ofstream ofs("textfiles\\usernameFaceNum.txt", std::ofstream::trunc);

		if (ofs.is_open()) {
			ofs << (numusers + 1) << "\n";
			for (int i = 0; i < facenames.size(); i++) {
				ofs << i << "$" << facenames[i] << "\n";
			}
			ofs << (numusers + 1) << "$" << context.marshal_as<std::string>(txtusername->Text);
		}
		ofs.close();
		return std::to_string(numusers + 1);
	}

	//2-part animation to exit the form
	int counts = 0;
	private: System::Void timerexit_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (counts == 0) {
			this->lblpretty->Text = "Welcome, " + username;
			this->txtpretty->Text = "Welcome, " + username;
			sound3->playRandomSound("assets\\accessgranted.wav", false);
		}

		if (counts == 1) {
			timerexit->Stop();

			playerInfo^ player = gcnew playerInfo;
			player->score = 0;
			player->username = username;
			player->timeTaken = 0;
			std::ofstream ofs("textfiles/PlayerInfo.txt");
			msclr::interop::marshal_context context;
			ofs << context.marshal_as<std::string>(player->username) << "\n" << player->score << "\n" << player->timeTaken;
			ofs.close();

			std::ofstream ofs2("textfiles\\communication.txt", std::ofstream::trunc);

			//signal to the login form that it needs to boot level 1
			if (ofs2.is_open()) {  // Check if the file was successfully opened
				ofs2 << "0"; //0 meaning login should close
			}
			ofs2.close();  // Close the file after writing
			successful = true;
			this->Close();

			this->timerexit->Stop();
		}

		counts++;
	}

	//animation for the start of the form
	private: System::Void timerentrance_Tick(System::Object^ sender, System::EventArgs^ e) {

		this->lblusername->Visible = false;
		this->txtusername->Visible = false;
		this->btnokay->Visible = false;
		this->lblSuggestor->Visible = false;
		this->lblWarning->Visible = false;
		this->state = "waiting";
		this->pictureboxbigface->Visible = false;
		this->lblpretty->Visible = false;
		this->txtpretty->Visible = false;
		this->timerexit->Enabled = false;

		this->lblrecognize1->Visible = true;
		this->lblrecognize2->Visible = true;
		this->lbladd2->Visible = true;
		this->lbladd1->Visible = true;
		this->pictureBox1->Visible = true;
		this->pictureBox2->Visible = true;
		labelsVisible = true;
		sound2->playRandomSound("assets\\chime.wav", false);
		this->timerentrance->Stop();
	}
};
}

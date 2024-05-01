#pragma once
#include <iostream>
#include <fstream>

namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FaceRecognition
	/// </summary>
	public ref class FaceRecognition : public System::Windows::Forms::Form
	{
	public:
		FaceRecognition(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
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
	private: System::Windows::Forms::Label^ dummy;

	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FaceRecognition::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblrecognize1 = (gcnew System::Windows::Forms::Label());
			this->lbladd1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->timerfacerec = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblrecognize2 = (gcnew System::Windows::Forms::Label());
			this->lbladd2 = (gcnew System::Windows::Forms::Label());
			this->dummy = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->lblrecognize1->Location = System::Drawing::Point(181, 123);
			this->lblrecognize1->Name = L"lblrecognize1";
			this->lblrecognize1->Size = System::Drawing::Size(672, 76);
			this->lblrecognize1->TabIndex = 1;
			this->lblrecognize1->Text = L"<Recognize Face>";
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
			this->lbladd1->Click += gcnew System::EventHandler(this, &FaceRecognition::label3_Click);
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
			// 
			// dummy
			// 
			this->dummy->AutoSize = true;
			this->dummy->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dummy->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dummy->Location = System::Drawing::Point(704, 44);
			this->dummy->Name = L"dummy";
			this->dummy->Size = System::Drawing::Size(89, 28);
			this->dummy->TabIndex = 7;
			this->dummy->Text = L"dummy";
			this->dummy->Click += gcnew System::EventHandler(this, &FaceRecognition::dummy_Click);
			// 
			// FaceRecognition
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->dummy);
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
			this->Load += gcnew System::EventHandler(this, &FaceRecognition::FaceRecognition_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {

		std::ofstream ofs("textfiles\\communication.txt", std::ofstream::trunc);  // Open/create a file named "test.txt" for writing

		if (ofs.is_open()) {  // Check if the file was successfully opened
			std::cout << "hi";
			ofs << "1"; //1 meaning login should not close
		}
		ofs.close();  // Close the file after writing
		this->Close();
	}
	private: System::Void timerfacerec_Tick(System::Object^ sender, System::EventArgs^ e) {
		int x; //Removed y as it was never used
		Point p1 = lblrecognize1->Location;
		Point p2 = lblrecognize2->Location;
		x = p1.X;

		if (x == 1260) {
			x = -640;
			lblrecognize1->Visible = false;
		}

		if (p2.X == 628) {

			x = -640;
			lblrecognize1->Visible = false;
		}

		if (!(p2.X > -10 && p2.X < 630)) {
			x += 3;
			lblrecognize1->Visible = true;
		}

		lblrecognize1->Location = Point(x, 123);
		x = p2.X;

		if (x == 1260) {
			x = -640;
			lblrecognize2->Visible = false;
		}

		if (p1.X == 628) {
			x = -640;
			lblrecognize2->Visible = false;
		}

		if (!(p1.X > -10 && p1.X < 630)) {
			x += 3;
			lblrecognize2->Visible = true;
		}

		lblrecognize2->Location = Point(x, 123);

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

		lbladd1->Location = Point(x, 251);
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

		lbladd2->Location = Point(x, 251);
	}
	private: System::Void dummy_Click(System::Object^ sender, System::EventArgs^ e) {
		std::ofstream ofs("textfiles\\communication.txt");  // Open/create a file named "test.txt" for writing

		if (ofs.is_open()) {  // Check if the file was successfully opened
			ofs << "0"; //0 meaning login should close
		}
		ofs.close();  // Close the file after writing
		this->Close();
	}
	private: System::Void FaceRecognition_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

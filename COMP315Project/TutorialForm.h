#pragma once
#include "MusicAndSFX.h"
namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TutorialForm
	/// </summary>
	public ref class TutorialForm : public System::Windows::Forms::Form
	{
	public:

		TutorialForm(void)
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
		~TutorialForm()
		{
			if (components)
			{
				delete components;
				
			}
		}

	protected:

	private:

		List<String^>^ pictures = gcnew List<String^>;
		int index = 0;
		MusicAndSFX* sound = new MusicAndSFX;

	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pbImage;
	private: System::Windows::Forms::Label^ lbltut;
	private: System::Windows::Forms::Label^ lblnumber;


		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TutorialForm::typeid));
			   this->btnNext = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->pbImage = (gcnew System::Windows::Forms::PictureBox());
			   this->lbltut = (gcnew System::Windows::Forms::Label());
			   this->lblnumber = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbImage))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // btnNext
			   // 
			   this->btnNext->Font = (gcnew System::Drawing::Font(L"Courier New", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnNext->ForeColor = System::Drawing::Color::Red;
			   this->btnNext->Location = System::Drawing::Point(1051, 582);
			   this->btnNext->Name = L"btnNext";
			   this->btnNext->Size = System::Drawing::Size(201, 87);
			   this->btnNext->TabIndex = 0;
			   this->btnNext->Text = L"Next";
			   this->btnNext->UseVisualStyleBackColor = true;
			   this->btnNext->Click += gcnew System::EventHandler(this, &TutorialForm::btnNext_Click);
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"Courier New", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button1->ForeColor = System::Drawing::Color::Red;
			   this->button1->Location = System::Drawing::Point(12, 582);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(201, 87);
			   this->button1->TabIndex = 1;
			   this->button1->Text = L"Previous";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &TutorialForm::button1_Click);
			   // 
			   // pbImage
			   // 
			   this->pbImage->Location = System::Drawing::Point(229, 109);
			   this->pbImage->Name = L"pbImage";
			   this->pbImage->Size = System::Drawing::Size(802, 437);
			   this->pbImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbImage->TabIndex = 2;
			   this->pbImage->TabStop = false;
			   // 
			   // lbltut
			   // 
			   this->lbltut->AutoSize = true;
			   this->lbltut->Font = (gcnew System::Drawing::Font(L"Courier New", 60, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->lbltut->ForeColor = System::Drawing::Color::Red;
			   this->lbltut->Location = System::Drawing::Point(404, 9);
			   this->lbltut->Name = L"lbltut";
			   this->lbltut->Size = System::Drawing::Size(423, 92);
			   this->lbltut->TabIndex = 3;
			   this->lbltut->Text = L"TUTORIAL";
			   this->lbltut->Click += gcnew System::EventHandler(this, &TutorialForm::label1_Click);
			   // 
			   // lblnumber
			   // 
			   this->lblnumber->AutoSize = true;
			   this->lblnumber->Font = (gcnew System::Drawing::Font(L"Courier New", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblnumber->ForeColor = System::Drawing::Color::White;
			   this->lblnumber->Location = System::Drawing::Point(42, 39);
			   this->lblnumber->Name = L"lblnumber";
			   this->lblnumber->Size = System::Drawing::Size(143, 40);
			   this->lblnumber->TabIndex = 4;
			   this->lblnumber->Text = L"label1";
			   // 
			   // TutorialForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			   this->ClientSize = System::Drawing::Size(1264, 681);
			   this->Controls->Add(this->lblnumber);
			   this->Controls->Add(this->lbltut);
			   this->Controls->Add(this->pbImage);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->btnNext);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MaximizeBox = false;
			   this->Name = L"TutorialForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Tutorial";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TutorialForm::TutorialForm_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &TutorialForm::TutorialForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbImage))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void TutorialForm_Load(System::Object^ sender, System::EventArgs^ e) {
		pictures->Add("assets\\tutorial\\1.png");
		pictures->Add("assets\\tutorial\\2.png");
		pictures->Add("assets\\tutorial\\3.png");
		pictures->Add("assets\\tutorial\\4.png");
		pictures->Add("assets\\tutorial\\5.png");
		pictures->Add("assets\\tutorial\\6.png");
		pictures->Add("assets\\tutorial\\7.png");

		this->pbImage->Image = Image::FromFile("assets\\tutorial\\1.png");
		this->index = 0;
		this->lblnumber->Text = 1 + "/7";
	}

		   void updateImage() {
			   this->pbImage->Image = Image::FromFile(pictures[index]);
			   this->lblnumber->Text = (index + 1) + "/7";
		   }
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		sound->playRandomSound("assets\\Mouse Click Sound Effect.wav", false);
		if (index > 0) {
			index--;
		}

		updateImage();
	}
	private: System::Void btnNext_Click(System::Object^ sender, System::EventArgs^ e) {
		sound->playRandomSound("assets\\Mouse Click Sound Effect.wav", false);
		if (index < 6) {
			index++;
			std::cout << index;
			updateImage();
		}

		else if (index == 6) {
			if (MessageBox::Show("Are you ready to return to login?", "", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				this->Close();
			}
		}

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TutorialForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		delete sound;
	}
};
}

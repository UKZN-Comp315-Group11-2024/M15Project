#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for popup
	/// </summary>
	public ref class popup : public System::Windows::Forms::Form
	{
	public:
		String^ backgroundImage;
		popup(String^ text, int x, int y, String^ backgroundImage) 
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->x = x;
			this->y = y;
			this->text = text;
			this->backgroundImage = backgroundImage;
			
			displayText();
			PlaySound(NULL, NULL, 0);
			PlaySound(TEXT("assets\\digitaltyping"), NULL, SND_LOOP | SND_ASYNC);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~popup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureboxbackground;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		String^ text;
		int x, y;
		int numcharsdone = 0;
	private: System::Windows::Forms::Label^ lblText;
	private: System::Windows::Forms::Timer^ timertext;
	private: System::Windows::Forms::Label^ lblspace;
	private: System::Windows::Forms::Timer^ timerclose;
	private: System::Windows::Forms::PictureBox^ backgroundPictureBox;


	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(popup::typeid));
			this->pictureboxbackground = (gcnew System::Windows::Forms::PictureBox());
			this->lblText = (gcnew System::Windows::Forms::Label());
			this->timertext = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblspace = (gcnew System::Windows::Forms::Label());
			this->timerclose = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundPictureBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxbackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureboxbackground
			// 
			this->pictureboxbackground->BackColor = System::Drawing::Color::Transparent;
			this->pictureboxbackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureboxbackground.Image")));
			this->pictureboxbackground->Location = System::Drawing::Point(1198, 572);
			this->pictureboxbackground->Margin = System::Windows::Forms::Padding(4);
			this->pictureboxbackground->Name = L"pictureboxbackground";
			this->pictureboxbackground->Size = System::Drawing::Size(347, 227);
			this->pictureboxbackground->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureboxbackground->TabIndex = 0;
			this->pictureboxbackground->TabStop = false;
			// 
			// lblText
			// 
			this->lblText->BackColor = System::Drawing::Color::Transparent;
			this->lblText->Font = (gcnew System::Drawing::Font(L"Courier New", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblText->ForeColor = System::Drawing::Color::White;
			this->lblText->Location = System::Drawing::Point(47, 42);
			this->lblText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblText->Name = L"lblText";
			this->lblText->Size = System::Drawing::Size(1605, 493);
			this->lblText->TabIndex = 1;
			this->lblText->Text = L"label1";
			this->lblText->Click += gcnew System::EventHandler(this, &popup::lblText_Click);
			// 
			// timertext
			// 
			this->timertext->Interval = 30;
			this->timertext->Tick += gcnew System::EventHandler(this, &popup::timertext_Tick);
			// 
			// lblspace
			// 
			this->lblspace->BackColor = System::Drawing::Color::Transparent;
			this->lblspace->Font = (gcnew System::Drawing::Font(L"Courier New", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblspace->ForeColor = System::Drawing::Color::White;
			this->lblspace->Location = System::Drawing::Point(47, 753);
			this->lblspace->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblspace->Name = L"lblspace";
			this->lblspace->Size = System::Drawing::Size(1007, 74);
			this->lblspace->TabIndex = 2;
			this->lblspace->Text = L"label1";
			this->lblspace->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timerclose
			// 
			this->timerclose->Interval = 30;
			this->timerclose->Tick += gcnew System::EventHandler(this, &popup::timerclose_Tick);
			// 
			// backgroundPictureBox
			// 
			this->backgroundPictureBox->Location = System::Drawing::Point(0, 0);
			this->backgroundPictureBox->Name = L"backgroundPictureBox";
			this->backgroundPictureBox->Size = System::Drawing::Size(1685, 838);
			this->backgroundPictureBox->TabIndex = 3;
			this->backgroundPictureBox->TabStop = false;
			// 
			// popup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1685, 838);
			this->Controls->Add(this->pictureboxbackground);
			this->Controls->Add(this->lblText);
			this->Controls->Add(this->lblspace);
			this->Controls->Add(this->backgroundPictureBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->HelpButton = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"popup";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"popup";
			this->Load += gcnew System::EventHandler(this, &popup::popup_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &popup::popup_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxbackground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->backgroundPictureBox))->EndInit();
			this->ResumeLayout(false);

		}

		void displayText(){
			Point p;
			p.X = x;
			p.Y = y;
			this->Location = p;

			timertext->Enabled = true;
			timerclose->Enabled = true;
		}
#pragma endregion
	private: System::Void timertext_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Create a marshal context
		msclr::interop::marshal_context context;

		// Convert System::String^ to std::string
		std::string stdString = context.marshal_as<std::string>(text);
		if (numcharsdone < stdString.size()) {
			stdString = stdString.substr(0, numcharsdone + 1);
			String^ unwrapped = gcnew String(stdString.c_str());
			this->lblText->Text = unwrapped;
			numcharsdone++;
		}
		else {
			PlaySound(NULL, NULL, 0);
			timertext->Enabled = false;
		}

	}
private: System::Void popup_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	if (e->KeyCode == Keys::Space)
	{
		PlaySound(NULL, NULL, 0);
		this->Close();
	}
}

	   int numcharsdone2 = 0;
	   int parity = 0;
private: System::Void timerclose_Tick(System::Object^ sender, System::EventArgs^ e) {
	std::string stdString = "Press <SPACE> to return";
	if (numcharsdone2 < stdString.size()) {
		stdString = stdString.substr(0, numcharsdone + 1);
		String^ unwrapped = gcnew String(stdString.c_str());
		this->lblspace->Text = unwrapped;
		numcharsdone2++;
	}
	else {
		timerclose->Interval = 500;
		if (parity == 0) {
			lblspace->Text = "";
		}
		else {
			lblspace->Text = "Press <SPACE> to return";
		}
		parity++;
		parity = parity % 2;
	}
}
private: System::Void lblText_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void popup_Load(System::Object^ sender, System::EventArgs^ e) {
	if (backgroundImage->Length != 0)
	{
		lblspace->Parent = backgroundPictureBox;
		lblText->Parent = backgroundPictureBox;
		pictureboxbackground->Parent = backgroundPictureBox;
		Image^ BackgroundImage = Image::FromFile(backgroundImage);
		backgroundPictureBox->Image = BackgroundImage;
	}

}
};
}

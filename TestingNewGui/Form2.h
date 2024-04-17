#pragma once
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "advapi32.lib")
#include <iostream>
#include <thread>
#include <windows.h>
#include <process.h>
#include "MyForm.h"

namespace TestingNewGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonVideo;
	protected:





	private: System::ComponentModel::IContainer^ components;
	protected:
		bool videoPlayed = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->buttonVideo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonVideo
			// 
			this->buttonVideo->BackColor = System::Drawing::Color::Black;
			this->buttonVideo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonVideo.BackgroundImage")));
			this->buttonVideo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonVideo->ForeColor = System::Drawing::Color::Transparent;
			this->buttonVideo->Location = System::Drawing::Point(444, 180);
			this->buttonVideo->Margin = System::Windows::Forms::Padding(0);
			this->buttonVideo->Name = L"buttonVideo";
			this->buttonVideo->Size = System::Drawing::Size(341, 323);
			this->buttonVideo->TabIndex = 3;
			this->buttonVideo->UseVisualStyleBackColor = false;
			this->buttonVideo->Click += gcnew System::EventHandler(this, &Form2::buttonVideo_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->buttonVideo);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Welcome, human";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonVideo_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!this->videoPlayed) {
			TCHAR szPath[] = TEXT("assets\\Welcome, human.mp4");

			HINSTANCE hRet = ShellExecute(
				HWND_DESKTOP, //Parent window
				TEXT("open"),       //Operation to perform
				szPath,       //Path to program
				NULL,         //Parameters
				NULL,         //Default directory
				SW_SHOW);     //How to open

			this->videoPlayed = true;
		}
		else {
			MyForm^ newForm = gcnew MyForm();
			newForm->ShowDialog();
			this->Hide();
			this->Close();

		}
		


	}
};
}

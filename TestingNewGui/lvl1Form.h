#pragma once
#include "PlayerInfo.h"
#include <iostream>
#include <windows.h>
namespace TestingNewGui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for lvl1Form
	/// </summary>
	public ref class lvl1Form : public System::Windows::Forms::Form
	{
	public:
		lvl1Form(playerInfo player)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->player = &player;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~lvl1Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ label2;
	protected:
		playerInfo* player;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(lvl1Form::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(398, 261);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(453, 110);
			this->label1->TabIndex = 0;
			this->label1->Text = L"LEVEL 1";
			this->label1->Click += gcnew System::EventHandler(this, &lvl1Form::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 72, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(312, 132);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(395, 110);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Player";
			// 
			// lvl1Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"lvl1Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Level 1";
			this->Activated += gcnew System::EventHandler(this, &lvl1Form::lvl1Form_Activated);
			this->Load += gcnew System::EventHandler(this, &lvl1Form::lvl1Form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lvl1Form_Load(System::Object^ sender, System::EventArgs^ e) {
	
	}
	private: System::Void lvl1Form_Activated(System::Object^ sender, System::EventArgs^ e) {
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
	}

	};
}

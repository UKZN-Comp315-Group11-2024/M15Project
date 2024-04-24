#pragma once
#include <math.h>

namespace M15Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BonusLevelOne
	/// </summary>
	public ref class BonusLevelOne : public System::Windows::Forms::Form
	{
	public:
		BonusLevelOne(void)
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
		~BonusLevelOne()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelBonusLevel;
	protected:

	protected:

	private: System::Windows::Forms::Label^ lblMessage1;
	private: System::Windows::Forms::PictureBox^ pbGeneralMilitary;

	private: System::Windows::Forms::Timer^ TargetTimer;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BonusLevelOne::typeid));
			this->panelBonusLevel = (gcnew System::Windows::Forms::Panel());
			this->lblMessage1 = (gcnew System::Windows::Forms::Label());
			this->pbGeneralMilitary = (gcnew System::Windows::Forms::PictureBox());
			this->TargetTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelBonusLevel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->BeginInit();
			this->SuspendLayout();
			// 
			// panelBonusLevel
			// 
			this->panelBonusLevel->BackColor = System::Drawing::Color::Transparent;
			this->panelBonusLevel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelBonusLevel.BackgroundImage")));
			this->panelBonusLevel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelBonusLevel->Controls->Add(this->lblMessage1);
			this->panelBonusLevel->Controls->Add(this->pbGeneralMilitary);
			this->panelBonusLevel->Cursor = System::Windows::Forms::Cursors::NoMove2D;
			this->panelBonusLevel->ForeColor = System::Drawing::Color::White;
			this->panelBonusLevel->Location = System::Drawing::Point(-10, -25);
			this->panelBonusLevel->Margin = System::Windows::Forms::Padding(4);
			this->panelBonusLevel->Name = L"panelBonusLevel";
			this->panelBonusLevel->Size = System::Drawing::Size(1600, 900);
			this->panelBonusLevel->TabIndex = 13;
			this->panelBonusLevel->Click += gcnew System::EventHandler(this, &BonusLevelOne::panelLogin_Click);
			// 
			// lblMessage1
			// 
			this->lblMessage1->AutoSize = true;
			this->lblMessage1->Font = (gcnew System::Drawing::Font(L"Courier New", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMessage1->Location = System::Drawing::Point(330, 900);
			this->lblMessage1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblMessage1->Name = L"lblMessage1";
			this->lblMessage1->Size = System::Drawing::Size(0, 90);
			this->lblMessage1->TabIndex = 1;
			this->lblMessage1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// pbGeneralMilitary
			// 
			this->pbGeneralMilitary->BackColor = System::Drawing::Color::Transparent;
			this->pbGeneralMilitary->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pbGeneralMilitary->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbGeneralMilitary.Image")));
			this->pbGeneralMilitary->Location = System::Drawing::Point(-325, 288);
			this->pbGeneralMilitary->Margin = System::Windows::Forms::Padding(0);
			this->pbGeneralMilitary->Name = L"pbGeneralMilitary";
			this->pbGeneralMilitary->Size = System::Drawing::Size(371, 560);
			this->pbGeneralMilitary->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbGeneralMilitary->TabIndex = 11;
			this->pbGeneralMilitary->TabStop = false;
			// 
			// TargetTimer
			// 
			this->TargetTimer->Interval = 500;
			this->TargetTimer->Tick += gcnew System::EventHandler(this, &BonusLevelOne::TargetTimer_Tick);
			// 
			// BonusLevelOne
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1580, 851);
			this->Controls->Add(this->panelBonusLevel);
			this->Name = L"BonusLevelOne";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BonusLevelOne";
			this->Load += gcnew System::EventHandler(this, &BonusLevelOne::BonusLevelOne_Load);
			this->panelBonusLevel->ResumeLayout(false);
			this->panelBonusLevel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbGeneralMilitary))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void panelLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		
		}


		ref class definedButton : public Button {
		public:
			definedButton()
			{
				this->Size = System::Drawing::Size(100, 100);
			}
			definedButton(Panel^ panelBonusLevel)
			{
				this->Size = System::Drawing::Size(100, 100);
				this->Parent = panelBonusLevel;
				this->Visible = false;
				this->Click += gcnew System::EventHandler(this, &definedButton::button_Click);
				this->BackgroundImage = System::Drawing::Image::FromFile("assets/PlayerMove/idle.gif");
				this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				this->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			}

			void setLocation(int x, int y) {
				this->Location = System::Drawing::Point(x, y);
			}



			void setVisible(bool visible) {
				this->Visible = visible;
			}

		//private:
			bool operator ==(definedButton^ b1) {
				if (  Math::Pow(this->Location.X - b1->Location.X, 2) + Math::Pow(this->Location.Y - b1->Location.Y, 2) < 20000)
				{
					return true;
				}
				return false;
			}

			void button_Click(System::Object^ sender, System::EventArgs^ e) {
				this->Hide();
			}
			

		};

		array<definedButton^>^ buttons = gcnew array<definedButton^>(15);
		private: System::Void BonusLevelOne_Load(System::Object^ sender, System::EventArgs^ e) {

			for (int i = 0; i < buttons->Length; i++) {
				delete buttons[i];
				buttons[i] = gcnew definedButton(panelBonusLevel);

				int x_pos = rand() % 1050 + 10;
				int y_pos = rand() % 420 + 180;
				buttons[i]->setLocation(x_pos, y_pos);

				buttons[i]->Text = i.ToString() + "h";
				buttons[i]->ForeColor = System::Drawing::Color::Black;

				if (i > 0) {

					for (int j = i - 1; j >= 0; j--)
					{
						if (buttons[i] == buttons[j] || buttons[j] == buttons[i])
						{
							int x_pos = rand() % 1050 + 10;
							int y_pos = rand() % 420 + 180;
							buttons[i]->setLocation(x_pos, y_pos);
							j = i - 1;
						}
					}
				}
				
			}
			TargetTimer->Start();
		}

		int targetNum = 0;
		private: System::Void TargetTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			buttons[targetNum]->setVisible(true);
			if (targetNum == 14) {
				TargetTimer->Stop();
			}
			targetNum++;
		}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

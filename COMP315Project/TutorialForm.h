#pragma once

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
			this->SuspendLayout();
			// 
			// TutorialForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"TutorialForm";
			this->Text = L"TutorialForm";
			this->Load += gcnew System::EventHandler(this, &TutorialForm::TutorialForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TutorialForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

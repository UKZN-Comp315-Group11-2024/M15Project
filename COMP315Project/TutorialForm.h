#pragma once

namespace M15Namespace {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic; // Include for List

    /// <summary>
    /// Summary for TutorialForm
    /// </summary>
    public ref class TutorialForm : public System::Windows::Forms::Form
    {
    public:
        List<String^>^ imageList; // Define imageList
        TutorialForm(void)
        {
            imageList = gcnew List<String^>(); // Initialize imageList
            imageList->Add("assets/move The player.png");
            imageList->Add("assets/Press Space to shoot.png");
            imageList->Add("assets/door-tut.png");
            imageList->Add("assets/feedback_tutorial.png");
            imageList->Add("assets/feedbacktutorial1.png");
            imageList->Add("assets/feedbacktutorial2.png");
            imageList->Add("assets/BONUS LEVEL.png");
            imageList->Add("assets/tutorialexample.png");
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
    private: System::ComponentModel::IContainer^ components;
    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>


        int currentSlideIndex = 0;
        bool slideshowStarted = false;

        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Timer^ timer1;
        System::Windows::Forms::Button^ nextButton;
        System::Windows::Forms::Button^ previousButton;
        System::Windows::Forms::Button^ startSlideshowButton;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->nextButton = (gcnew System::Windows::Forms::Button());
            this->previousButton = (gcnew System::Windows::Forms::Button());
            this->startSlideshowButton = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(18, 14);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(1352, 365);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // timer1
            // 
            this->timer1->Interval = 3000;
            this->timer1->Tick += gcnew System::EventHandler(this, &TutorialForm::timer1_Tick);
            // 
            // nextButton
            // 
            this->nextButton->Location = System::Drawing::Point(296, 392);
            this->nextButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->nextButton->Name = L"nextButton";
            this->nextButton->Size = System::Drawing::Size(112, 35);
            this->nextButton->TabIndex = 1;
            this->nextButton->Text = L"Next";
            this->nextButton->UseVisualStyleBackColor = true;
            this->nextButton->Click += gcnew System::EventHandler(this, &TutorialForm::nextButton_Click);
            // 
            // previousButton
            // 
            this->previousButton->Location = System::Drawing::Point(18, 392);
            this->previousButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->previousButton->Name = L"previousButton";
            this->previousButton->Size = System::Drawing::Size(112, 35);
            this->previousButton->TabIndex = 2;
            this->previousButton->Text = L"Previous";
            this->previousButton->UseVisualStyleBackColor = true;
            this->previousButton->Click += gcnew System::EventHandler(this, &TutorialForm::previousButton_Click);
            // 
            // startSlideshowButton
            // 
            this->startSlideshowButton->Location = System::Drawing::Point(147, 392);
            this->startSlideshowButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->startSlideshowButton->Name = L"startSlideshowButton";
            this->startSlideshowButton->Size = System::Drawing::Size(112, 35);
            this->startSlideshowButton->TabIndex = 3;
            this->startSlideshowButton->Text = L"Start Slideshow";
            this->startSlideshowButton->UseVisualStyleBackColor = true;
            this->startSlideshowButton->Click += gcnew System::EventHandler(this, &TutorialForm::startSlideshowButton_Click);
            // 
            // TutorialForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1383, 446);
            this->Controls->Add(this->startSlideshowButton);
            this->Controls->Add(this->previousButton);
            this->Controls->Add(this->nextButton);
            this->Controls->Add(this->pictureBox1);
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->Name = L"TutorialForm";
            this->Text = L"TutorialForm";
            this->Load += gcnew System::EventHandler(this, &TutorialForm::TutorialForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void TutorialForm_Load(System::Object^ sender, System::EventArgs^ e) {
        // Do not start the slideshow timer when the form loads
    }
    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        // Display the next slide if the slideshow has been started
        if (slideshowStarted) {
            pictureBox1->Image = Image::FromFile(imageList[currentSlideIndex]);
            currentSlideIndex = (currentSlideIndex + 1) % imageList->Count;
        }
    }
    private: System::Void nextButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Display the next slide if the slideshow has been started
        if (slideshowStarted) {
            currentSlideIndex = (currentSlideIndex + 1) % imageList->Count;
            pictureBox1->Image = Image::FromFile(imageList[currentSlideIndex]);
        }
    }
    private: System::Void previousButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Display the previous slide if the slideshow has been started
        if (slideshowStarted) {
            currentSlideIndex = (currentSlideIndex - 1 + imageList->Count) % imageList->Count;
            pictureBox1->Image = Image::FromFile(imageList[currentSlideIndex]);
        }
    }
    private: System::Void startSlideshowButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Start the slideshow timer and set the slideshowStarted flag to true
        timer1->Start();
        slideshowStarted = true;
    }

};
}

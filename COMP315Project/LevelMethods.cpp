#include "pch.h"
#include "LevelMethods.h"

//Constructor, takes in the int corresponding to the level it is called in, gets a question list, enables player controls
LevelMethods::LevelMethods(int lvlno) {
	this->DisableControls = false;
	this->lvlNum = lvlno;
	LoadQuestion^ QuestionLoader = gcnew LoadQuestion(this->lvlNum);
	this->QuestionList = QuestionLoader->levelQuestions;
	this->PlayerStats = gcnew playerInfo();

}


//Displays the next set of questions in the question list
void LevelMethods::DisplayNextQuestionSet() {
	ExtractQuestionSet();
	Question->Text = question;
	Question->Visible = true;
	if (QuestionType == "0") {

		Option1->Text = OptionA;
		Option1->Visible = true;

		Option2->Text = OptionB;
		Option2->Visible = true;

		Option3->Text = OptionC;
		Option3->Visible = true;

		Option4->Text = OptionD;
		Option4->Visible = true;
	}
	else {

		TFOption1->Text = OptionA;
		TFOption1->Visible = true;

		TFOption2->Text = OptionB;
		TFOption2->Visible = true;

		Option1->Visible = false;
		Option2->Visible = false;
		Option3->Visible = false;
		Option4->Visible = false;
	}
	DetermCorrectOptionInt();
	this->ProgressBar->Value = 0;
	this->ProgressBarTimer->Start();
}

//dequeues an instance of the Question struct and makes a copy of its members for this class to access
void LevelMethods::ExtractQuestionSet() {
	LoadQuestion::Question^ QuestionSet = QuestionList[QuestionsCompleted];
	QuestionType = QuestionSet->QuestionType;
	question = QuestionSet->question;
	OptionA = QuestionSet->OptionA;
	OptionB = QuestionSet->OptionB;
	OptionC = QuestionSet->OptionC;
	OptionD = QuestionSet->OptionD;
	CorrectOption = QuestionSet->CorrectOption;
}

//Determines the correct options corresponding int representative
void LevelMethods::DetermCorrectOptionInt() {
	if (this->CorrectOption == this->OptionA) {
		this->CorrectOptionInt = 0;
	}
	else if (this->CorrectOption == this->OptionB) {
		this->CorrectOptionInt = 1;
	}
	else if (this->CorrectOption == this->OptionC) {
		this->CorrectOptionInt = 2;
	}
	else if (this->CorrectOption == this->OptionD) {
		this->CorrectOptionInt = 3;
	}
}


//called if a bullet collides with an answer option
void LevelMethods::QuestionAnswered(int option) {
		this->QuestionsCompleted += 1;
		this->QuestionsAnswered += 1;
		if (option == CorrectOptionInt) {
			this->PlayerStats->score += 1;
			this->PlayerStats->CorrectAnswers += 1;
			this->Correct = true;
		}
		else {
			this->Correct = false;
		}

		this->ProgressBarTimer->Stop();
}

//called if timer runs out
void LevelMethods::QuestionCompleted() {
		this->QuestionsCompleted += 1;
		this->ProgressBarTimer->Stop();

	if (this->QuestionsCompleted < 10) {
		DisplayNextQuestionSet();
	}
}


//Setters:
void LevelMethods::SetQuestionComponents(System::Windows::Forms::Label^ lblQuestion, System::Windows::Forms::Label^ lblOption1, System::Windows::Forms::Label^ lblOption2, System::Windows::Forms::Label^ lblOption3, System::Windows::Forms::Label^ lblOption4, System::Windows::Forms::Label^ lblTFOption1, System::Windows::Forms::Label^ lblTFOption2) {

	this->Question = lblQuestion;
	this->Option1 = lblOption1;
	this->Option2 = lblOption2;
	this->Option3 = lblOption3;
	this->Option4 = lblOption4;
	this->TFOption1 = lblTFOption1;
	this->TFOption2 = lblTFOption2;

}

void LevelMethods::SetProgressBarTimerComponent(System::Windows::Forms::Timer^ PBtmr) {
	this->ProgressBarTimer = PBtmr;
}

void LevelMethods::SetProgressBarComponent(System::Windows::Forms::ProgressBar^ PB) {
	this->ProgressBar = PB;
}


#include "pch.h"
#include "LevelMethods.h"

LevelMethods::LevelMethods(int lvlno) {
	this->lvlNum = lvlno;
	QuestionLoader = gcnew LoadQuestion(this->lvlNum);
	QuestionQueue = QuestionLoader->QuestionQueue;
	ShuffelQuestionSets();

}

void LevelMethods::SetQuestionComponents(System::Windows::Forms::Label^ lblQuestion, System::Windows::Forms::Label^ lblOption1, System::Windows::Forms::Label^ lblOption2, System::Windows::Forms::Label^ lblOption3, System::Windows::Forms::Label^ lblOption4, System::Windows::Forms::Label^ lblTFOption1, System::Windows::Forms::Label^ lblTFOption2, int lvlNumber) {
	
	this->Question = lblQuestion;
	this->Option1 = lblOption1;
	this->Option2 = lblOption2;
	this->Option3 = lblOption3;
	this->Option4 = lblOption4;
	this->TFOption1 = lblTFOption1;
	this->TFOption2 = lblTFOption2;
	this->lvlNum = lvlNumber;

}

/*void LevelMethods::TransitionIn() {
	LevelFormInstance->lblMessage1->Text
}*/

/*void LevelMethods::SetTransLabel(String^ label, Control^ item) {
	//msgBox->Text = label;
	item->
}*/

void LevelMethods::DisplayNextQuestionSet() {
	ExtractQuestionSet();
	//lable->Text = "Bruh";
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
	}
	this->ProgressBarTimer->Start();
}

//dequeues a Question and pulls the members
void LevelMethods::ExtractQuestionSet() {
	LoadQuestion::Question^ QuestionSet = QuestionQueue->Dequeue();
	QuestionType = QuestionSet->QuestionType;
	question = QuestionSet->question;
	OptionA = QuestionSet->OptionA;
	OptionB = QuestionSet->OptionB;
	OptionC = QuestionSet->OptionC;
	OptionD = QuestionSet->OptionD;
	CorrectOption = QuestionSet->CorrectOption;
}
/// <summary>
/// used the Fisher-Yates shuffle
/// </summary>
void LevelMethods::ShuffelQuestionSets() {
	Random^ rand = gcnew Random();
	List<LoadQuestion::Question^>^ ShuffelList = gcnew List<LoadQuestion::Question^>;
	while (QuestionQueue->Count > 0) {
		ShuffelList->Add(QuestionQueue->Dequeue());
	}

	for (int i = ShuffelList->Count - 1; i > 0; i--) {

		int j = rand->Next(0, i + 1);
		LoadQuestion::Question^ temp = ShuffelList[i];
		ShuffelList[i] = ShuffelList[j];
		ShuffelList[j] = temp;

	}

	for each (LoadQuestion::Question ^ item in ShuffelList) {
		QuestionQueue->Enqueue(item);
	}
}
//called if bullet collsion with answer option
void LevelMethods::QuestionAnswered(int option) {
	QuestionsCompleted += 1;
	QuestionsAnswered += 1;
	if (option == 1) {
		CorrectAnswers += 1;
	}
	
	this->ProgressBarTimer->Stop();
	calculateTime();
	
	if (CheckLevelEnd()) {
		EndLevel();
	}

	ResetPlayerPos();
	DisplayNextQuestionSet();
	
}

//called if timer runs out
void LevelMethods::QuestionCompleted() {
	QuestionsCompleted += 1;
	this->ProgressBarTimer->Stop();
	calculateTime();

	if (CheckLevelEnd()) {
		EndLevel();
	}

	ResetPlayerPos();
	DisplayNextQuestionSet();
}

void LevelMethods::SetPlayerComponent(System::Windows::Forms::PictureBox^ plyr) {
	this->PlayerImage = plyr;
}

void LevelMethods::SetLoadingBarComponent(System::Windows::Forms::Timer^ PBtmr) {
	this->ProgressBarTimer = PBtmr;
}

void LevelMethods::SetPanelComponant(System::Windows::Forms::Panel^ Pnl) {
	this->Panel = Pnl;
}

void LevelMethods::SetLevelFormInstance(System::Windows::Forms::Form^ lvlFrmInst) {
	this->LevelFormInstance = lvlFrmInst;
}

void LevelMethods::calculateTime() {
	if (this->ProgressBarTimer->Interval < 30000) {
		this->Time += this->ProgressBarTimer->Interval;
	}
	else {
		this->Time += 30000;
	}
}

void LevelMethods::ResetPlayerPos() {
	System::Drawing::Point point;
	point.X = 115;
	point.Y = 183;
	this->PlayerImage->Location = point;
}

bool LevelMethods::CheckLevelEnd() {
	if (this->QuestionsCompleted == 10) {
		return true;
	}
	else {
		return false;
	}
}

void LevelMethods::EndLevel() {
	//send all necessary info to PlayerInfo

	//change background
	Panel->BackgroundImage = Image::FromFile("path_to_image.jpg");
	//disable player controlls
	//LevelFormInstance->
	//hide player, loading bar, question, answer options, collonel, the controlls
	
	//reveal player stats by calling PrintPlayerStats()
	//reveal button to continue to next level
}
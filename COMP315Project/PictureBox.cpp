#include "pch.h"
#include "PictureBox.h"
#include "MusicAndSFX.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



definedPictureBox::definedPictureBox() {

	this->Size = System::Drawing::Size(100, 100);

}

/*
	Constructor
	takes in parent, x size, y size, x position, y position, image location, a bool for if its clickable or not
*/
definedPictureBox::definedPictureBox(Panel^ panelBonusLevel, int x_size, int y_size,int x_pos, int y_pos, String^ imageLocation, bool clickable)
{
	this->Parent = panelBonusLevel;
	this->Size = System::Drawing::Size(x_size, y_size);
	this->Location = System::Drawing::Point(x_pos, y_pos);
	this->Image = System::Drawing::Image::FromFile(imageLocation);
	this->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
	if (clickable)
	{
		this->Click += gcnew System::EventHandler(this, &definedPictureBox::pictureBox_Click);
	}
	this->Visible = false;
}

void definedPictureBox::setLocation(const int& x, const int& y) {
	this->Location = System::Drawing::Point(x, y);
}



void definedPictureBox::setVisible(bool visible) {
	this->Visible = visible;
}

bool definedPictureBox::operator ==(definedPictureBox^ b1) {
	if (this->Bounds.IntersectsWith(b1->Bounds))
	{
		return true;
	}
	return false;
}



void definedPictureBox::pictureBox_Click(System::Object^ sender, System::EventArgs^ e) {
	MusicAndSFX* BonusSounds = new MusicAndSFX();
	MusicAndSFX* BonusSFX = new MusicAndSFX();
	this->Hide();
	countClick++;

	if (audioType == "Laser")
	{
		BonusSounds->Laser();
	}
	else
	{
		BonusSounds->playRandomSound("assets\\music\\ES_Human Grunt 15 - SFX Producer.wav", false);
		BonusSounds->gunshot();
	}
}

int definedPictureBox::numClicks()
{
	return countClick;
}

void definedPictureBox::setSpeed(int speed)
{
	this->speed = speed;
}

int definedPictureBox::getSpeed()
{
	return speed;
}

void definedPictureBox::setAudioClickType(String^ audioType)
{
	this->audioType = audioType;
}
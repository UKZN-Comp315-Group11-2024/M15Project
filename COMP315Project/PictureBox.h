#pragma once
#include "pch.h"
#include "MusicAndSFX.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class definedPictureBox : public PictureBox {
public:
	MusicAndSFX* BonusSounds;

	definedPictureBox();
	definedPictureBox(Panel^ panelBonusLevel, int x_size, int y_size, int x_pos, int y_pos, String^ imageLocation, bool clickable);

	void setLocation(const int& x, const int& y);
	void setVisible(bool visible);
	bool operator ==(definedPictureBox^ b1);
	void pictureBox_Click(System::Object^ sender, System::EventArgs^ e);
	int numClicks();
	void setSpeed(int speed);
	int definedPictureBox::getSpeed();
	void setAudioClickType(String^ audioType);

private:
	int countClick = 0;
	int speed = 0;
	String^ audioType;
};
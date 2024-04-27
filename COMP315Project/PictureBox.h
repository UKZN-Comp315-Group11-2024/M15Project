#pragma once
#include "pch.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class definedPictureBox : public PictureBox { 
public:
	definedPictureBox();
	definedPictureBox(Panel^ panelBonusLevel, int x_size, int y_size, int x_pos, int y_pos, String^ imageLocation, bool clickable);

	void setLocation(int x, int y);
	void setVisible(bool visible);
	bool operator ==(definedPictureBox^ b1);
	void pictureBox_Click(System::Object^ sender, System::EventArgs^ e);
	int numClicks();

private:
	int countClick = 0;
};
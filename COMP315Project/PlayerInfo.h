#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
public ref struct playerInfo {
public:
	//user Statistics 
	System::String^ username;
	int score;
	int timeTaken;
	int CorrectAnswers;

	playerInfo();

	//used to order players
	bool operator<(playerInfo^ p2);
	bool operator>(playerInfo^ p2);
	bool operator==(playerInfo^ p2);

	bool operator<=(playerInfo^ p2);
	bool operator>=(playerInfo^ p2);
	bool operator%(playerInfo^ p2);
};



#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
public ref struct playerInfo {
public:
	System::String^ username;
	int score;
	int timeTaken;

	playerInfo();

	bool operator<(playerInfo^ p2);
	bool operator>(playerInfo^ p2);
	bool operator==(playerInfo^ p2);

	bool operator<=(playerInfo^ p2);
	bool operator>=(playerInfo^ p2);
	bool operator%(playerInfo^ p2);
};



#pragma once
#include <string>
struct playerInfo {
public:
	std::string username;
	//@Daniel: changed name of variables
	int Score = 0;
	int Time = 0;
	int CorrectAnswers = 0;

	bool operator<(playerInfo p2);
	bool operator>(playerInfo p2);
	bool operator==(playerInfo p2);

	bool operator<=(playerInfo p2);
	bool operator>=(playerInfo p2);
	bool operator%(playerInfo p2);
};

bool playerInfo::operator<(playerInfo p2) {
	return (this->Score < p2.Score);
}

bool playerInfo::operator>(playerInfo p2) {
	return (this->Score > p2.Score);
}

bool playerInfo::operator==(playerInfo p2) {
	return (this->Score == p2.Score);
}

bool playerInfo::operator<=(playerInfo p2) {
	return (this->username < p2.username);
}

bool playerInfo::operator>=(playerInfo p2) {
	return (this->username > p2.username);
}

bool playerInfo::operator%(playerInfo p2) {
	return (this->username == p2.username);
}

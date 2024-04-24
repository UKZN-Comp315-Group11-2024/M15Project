#pragma once
#include <string>
struct playerInfo {
public:
	std::string username;
	int score;
	int timeTaken;

	bool operator<(playerInfo p2);
	bool operator>(playerInfo p2);
	bool operator==(playerInfo p2);

	bool operator<=(playerInfo p2);
	bool operator>=(playerInfo p2);
	bool operator%(playerInfo p2);
};

bool playerInfo::operator<(playerInfo p2) {
	return (this->score < p2.score);
}

bool playerInfo::operator>(playerInfo p2) {
	return (this->score > p2.score);
}

bool playerInfo::operator==(playerInfo p2) {
	return (this->score == p2.score);
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

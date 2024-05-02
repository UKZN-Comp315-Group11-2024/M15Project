#include "PlayerInfo.h"
#include "iostream"
#include "pch.h"

playerInfo::playerInfo() {
	this->username = "";
	this->score = 0;
	this->timeTaken = 0;
}

bool playerInfo::operator<(playerInfo^ p2) {
	if (this->score == p2->score) {
		return this->timeTaken > p2->timeTaken;
	}
	else {
		return (this->score < p2->score);
	}
	
}

bool playerInfo::operator>(playerInfo^ p2) {
	if (this->score == p2->score) {
		return this->timeTaken < p2->timeTaken;
	}
	else {
		return (this->score > p2->score);
	}
}

bool playerInfo::operator==(playerInfo^ p2) {
	return (this->score == p2->score);
}

bool playerInfo::operator<=(playerInfo^ p2) {
	msclr::interop::marshal_context context;
	return context.marshal_as<std::string>(this->username).compare(context.marshal_as<std::string>(p2->username)) < 0;
	
}

bool playerInfo::operator>=(playerInfo^ p2) {
	msclr::interop::marshal_context context;
	return context.marshal_as<std::string>(this->username).compare(context.marshal_as<std::string>(p2->username)) > 0;
	
}

bool playerInfo::operator%(playerInfo^ p2) {
	msclr::interop::marshal_context context;
	return context.marshal_as<std::string>(this->username).compare(context.marshal_as<std::string>(p2->username))==0;
	
}
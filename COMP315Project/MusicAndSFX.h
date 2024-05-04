
#pragma once
#include "pch.h"
#include "SFML/Audio.hpp"
#include <iostream>

class MusicAndSFX {
public:
	sf::Music sound; // @jaedon: changed this to Music since the other one didn't seem to work
	sf::Music Background; //object that streams sound directly from source file
	sf::Music music;//object that streams sound directly from source file
	sf::Music randomSound;
	sf::Music Thrusters;

	MusicAndSFX();
	~MusicAndSFX();

	void gunshot();
	void MouseClick();
	void FacialRegocnition();
	void CorrectAnswer();
	void IncorrectAnswer();
	void Laser();
	void BulletImpact();

	void LevelOneMusic();
	void LevelTwoMusic();
	void LevelThreeMusic();
	void Level4Music();
	void bonusLevels();

	void OfficeNoise();
	void Forest();
	void NightForest();
	void Space();
	void ThrusterSound();


	void StopSound();
	void playRandomSound(std::string path, bool loop);



};




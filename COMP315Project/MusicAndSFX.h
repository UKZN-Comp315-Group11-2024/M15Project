
#pragma once
#include "pch.h"
#include "SFML/Audio.hpp"
#include <iostream>

class MusicAndSFX {
public:
	// Music objects
	sf::Music sound;
	sf::Music Background;
	sf::Music music;
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

	void StopSound();
	void playRandomSound(std::string path, bool loop);
};





#pragma once
#include "pch.h"
#include "SFML/Audio.hpp"
#include <iostream>

class MusicAndSFX {
public:
	sf::Sound sound;// objects that plays sounds from sound buffer
	sf::Music Background; //object that streams sound directly from source file
	sf::Music music;//object that streams sound directly from source file

	MusicAndSFX();
    ~MusicAndSFX();
	void gunshot();
	void MouseClick();
	void FacialRegocnition();
	void LevelOneMusic();
	void LevelTwoMusic();
	void LevelThreeMusic();
	void OfficeNoise();
	void Forest();
	void NightForest();
	void StopSound(boolean Stop);



};




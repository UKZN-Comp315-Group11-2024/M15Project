#include "pch.h"
#include "SFML/Audio.hpp"
#include <iostream>
#include "MusicAndSFX.h"




	MusicAndSFX::MusicAndSFX() {
		sound.setVolume(70); // sets sound effect volume
		Background.setVolume(60);//sets background sounds volume
		music.setVolume(50); //sets music volume

	}

	MusicAndSFX::~MusicAndSFX(){
		
	}
	//useful code-https://www.sfml-dev.org/tutorials/2.6/audio-sounds.php

	//Sound effects

	void MusicAndSFX::gunshot() {
		//sf::SoundBuffer buffer; //stores small sounds that can fit in memory

		sf::SoundBuffer buffer;

		buffer.loadFromFile("TempSoundEffect.wav");
		

		sf::Sound sound;

		if (!buffer.loadFromFile(" ")) {  //loads audio file
			sound.setBuffer(buffer);
		}
		sound.play();

	
		//TempSoundEffect.wav

		//if (!buffer.loadFromFile("assets/TempSoundEffect.wav")) {  //loads audio file
		//	std:: cout << "sound failed to load into file" << std:: endl;
		//}
		//

		//sound.setBuffer(buffer); 
		//sound.play();   //plays what's in the buffer
		//buffer.dispose();
	}

	void MusicAndSFX::MouseClick() {
		sf::SoundBuffer buffer; //stores small sounds that can fit in memory

		if (!buffer.loadFromFile(" ")) {  //loads audio file
			std::cout << "sound failed to load into file" << std::endl;
		}

		sound.setBuffer(buffer);
		sound.play();   //plays what's in the buffer
	}

	void MusicAndSFX::FacialRegocnition() {
		sf::SoundBuffer buffer; //stores small sounds that can fit in memory

		if (!buffer.loadFromFile(" ")) {  //loads audio file
			std::cout << "sound failed to load into file" << std::endl;
		}

		sound.setBuffer(buffer);
		sound.play();   //plays what's in the buffer
	}

	
	//Music

	void MusicAndSFX::LevelOneMusic() {

		if (!music.openFromFile("TempBackgroundMusic.wav")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		music.play();

		music.setLoop(true); //loops music file
		
	}

	void MusicAndSFX::LevelTwoMusic() {

		if (!music.openFromFile("")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		music.play();

		music.setLoop(true); //loops music file
	}
	
	void MusicAndSFX::LevelThreeMusic() {

		if (!music.openFromFile("")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		music.play();

		music.setLoop(true); //loops music file
	}




	//  background themes

	void MusicAndSFX::OfficeNoise() {

		if (!Background.openFromFile("")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		Background.play();

		Background.setLoop(true); //loops music file
	}

	void MusicAndSFX::Forest() {

		if (!Background.openFromFile("")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		Background.play();

		Background.setLoop(true); //loops music file
	}

	void MusicAndSFX::NightForest() {

		if (!Background.openFromFile("")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		Background.play();

		Background.setLoop(true); //loops music file
	}



	void MusicAndSFX::StopSound(boolean Stop) { //stops music if sent boolean value true
		
		if (Stop == true) {
			music.stop();
			Background.stop();
		}
		
	}









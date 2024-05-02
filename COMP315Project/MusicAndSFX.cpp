#include "pch.h"
#include "SFML/Audio.hpp"
#include <iostream>
#include "MusicAndSFX.h"

MusicAndSFX::MusicAndSFX() {
	sound.setVolume(70); // sets sound effect volume
	Background.setVolume(70);//sets background sounds volume
	music.setVolume(50); //sets music volume
	randomSound.setVolume(100);

}

MusicAndSFX::~MusicAndSFX() {

}
//useful code-https://www.sfml-dev.org/tutorials/2.6/audio-sounds.php
//All music is from:h ttps://www.epidemicsound.com/sound-effects/search/?term=running%20footsteps

//Sound effects

void MusicAndSFX::gunshot() {

	if (!sound.openFromFile("assets\\music\\ES_Gunshot Rifle 77 - SFX Producer.wav")) {  //loads audio file
		std::cout << "sound failed to load into file" << std::endl;
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
	//sf::SoundBuffer buffer; //stores small sounds that can fit in memory

	if (!sound.openFromFile("assets\\music\\Mouse Click Sound Effect.wav")) {  //loads audio file
		std::cout << "sound failed to load into file" << std::endl;
	}
	sound.play();   //plays what's in the buffer
}

void MusicAndSFX::FacialRegocnition() {
	sf::SoundBuffer buffer; //stores small sounds that can fit in memory

	if (!sound.openFromFile("assets\\music\\ES_Sci Fi Retinal Scan - SFX Producer.wav")) {  //loads audio file
		std::cout << "sound failed to load into file" << std::endl;
	}
	sound.play();   //plays what's in the buffer
}

void MusicAndSFX::CorrectAnswer() {

	if (!sound.openFromFile("assets\\music\\CorrectAnswerBell.wav")) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	sound.play();


}

void MusicAndSFX::IncorrectAnswer() {

	if (!sound.openFromFile("assets\\music\\ES_Buzzer 4 - SFX Producer.wav")) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	sound.play();


}

void MusicAndSFX::Laser() {

	if (!sound.openFromFile("assets\\music\\ES_Laser Gun Fire 5 - SFX Producer.wav")) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	sound.play();


}

void MusicAndSFX::BulletImpact() {

	if (!sound.openFromFile("assets\\music\\ES_Bullet Impact Metal 3 - SFX Producer.wav")) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	sound.play();


}

//Music

void MusicAndSFX::LevelOneMusic() {

	if (!music.openFromFile("assets\\music\\ES_Intentional Terror - Trailer Worx.wav")) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	music.play();

	music.setLoop(true); //loops music file

}

void MusicAndSFX::LevelTwoMusic() {

		if (!music.openFromFile("assets\\music\\ES_Thrilling Games - Phoenix Tail.wav")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		music.play();

	music.setLoop(true); //loops music file
}

void MusicAndSFX::LevelThreeMusic() {

		if (!music.openFromFile("assets\\music\\ES_Shivers in the Shadows - Victor Lundberg.wav")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		music.play();

	music.setLoop(true); //loops music file
}

	void MusicAndSFX::Level4Music() {

		if (!music.openFromFile("assets\\music\\ES_Empty Space - Etienne Roussel.wav")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		music.play();

		music.setLoop(true); //loops music file
	}

	void MusicAndSFX::bonusLevels() {

		if (!music.openFromFile("assets\\music\\ES_Spy Game - Jon Sumner.wav")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		music.play();  

		music.setLoop(true); //loops music file
	}



//  background themes

void MusicAndSFX::OfficeNoise() {

	if (!Background.openFromFile("assets\\music\\ES_Office Walla - SFX Producer.wav")) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	Background.play();

	Background.setLoop(true); //loops music file
}

	void MusicAndSFX::Forest() {
		if (!Background.openFromFile("assets\\music\\ES_Forest 3 - SFX Producer.wav")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		std::cout << "here";
		Background.play();

	Background.setLoop(true); //loops music file
	std::cout << "exited";
}

void MusicAndSFX::NightForest() {

		if (!Background.openFromFile("assets\\music\\ES_Forest 7 - SFX Producer.wav")) {  //opens music file
			std::cout << "could not open music file" << std::endl;
		}
		Background.play();

	Background.setLoop(true); //loops music file
}

void MusicAndSFX::Space() {

	if (!Background.openFromFile("assets\\music\\.ES_Drone Empty Void - SFX Producer.wav")) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	Background.play();

	Background.setLoop(true); //loops music file
}



void MusicAndSFX::StopSound() { //stops music if sent boolean value true
	music.stop();
	Background.stop();
	sound.stop();	
}

void MusicAndSFX::playRandomSound(std::string path, bool loop) {
	if (!randomSound.openFromFile(path)) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	randomSound.play();
	randomSound.setLoop(loop);
}
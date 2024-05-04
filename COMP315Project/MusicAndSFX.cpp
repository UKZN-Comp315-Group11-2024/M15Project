#include "pch.h"
#include "SFML/Audio.hpp"
#include <iostream>
#include "MusicAndSFX.h"

MusicAndSFX::MusicAndSFX() {
	sound.setVolume(70);	// Sets sound effect volume
	Background.setVolume(70);	// Sets background sounds volume
	music.setVolume(60);	// Sets music volume
	randomSound.setVolume(100);	// Sets random sound volume
}

MusicAndSFX::~MusicAndSFX() {

}
// Useful code-https://www.sfml-dev.org/tutorials/2.6/audio-sounds.php
// All music is from: https://www.epidemicsound.com/sound-effects/search/?term=running%20footsteps

// Sound effects

void MusicAndSFX::gunshot() {

	if (!sound.openFromFile("assets\\music\\ES_Gunshot Rifle 77 - SFX Producer.wav")) {  //loads audio file
		std::cout << "sound failed to load into file" << std::endl;
	}
	sound.play();

}

void MusicAndSFX::MouseClick() {

	if (!sound.openFromFile("assets\\music\\Mouse Click Sound Effect.wav")) {  //opens music file
		std::cout << "sound failed to load into file" << std::endl;
	}
	sound.play();
}

void MusicAndSFX::FacialRegocnition() {

	if (!sound.openFromFile("assets\\music\\ES_Sci Fi Retinal Scan - SFX Producer.wav")) {  //opens music file
		std::cout << "sound failed to load into file" << std::endl;
	}
	sound.play();
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

// Level Music

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

// Background themes

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
	Background.play();

	Background.setLoop(true); //loops music file
}

void MusicAndSFX::NightForest() {

	if (!Background.openFromFile("assets\\music\\ES_Forest 7 - SFX Producer.wav")) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	Background.play();

	Background.setLoop(true); //loops music file
}

void MusicAndSFX::Space() {

	if (!Background.openFromFile("assets\\music\\ES_Drone Empty Void - SFX Producer.wav")) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	Background.play();

	Background.setLoop(true); //loops music file
}

// Stops music
void MusicAndSFX::StopSound() {
	music.stop();
	Background.stop();
	sound.stop();
	Thrusters.stop();
}

// Plays a random sound from the path that is sent in, optionally allowing it to loop using the sent in bool
void MusicAndSFX::playRandomSound(std::string path, bool loop) {
	if (!randomSound.openFromFile(path)) {  //opens music file
		std::cout << "could not open music file" << std::endl;
	}
	randomSound.play();
	randomSound.setLoop(loop);
}
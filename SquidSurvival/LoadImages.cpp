#include "LoadImages.h"

int StartButton = 0;
int OptionsButton = 0;
int CreditsButton = 0;
int HighScoreButton = 0;
int DifficultyStateBG = 0;
int EasyButton = 0;
int MediumButton = 0;
int HardButton = 0;
int BackButton = 0;
int OptionsPageBG = 0;
int SoundButtonTurnedOn = 0;
int SoundButtonTurnedOff = 0;

void loadAllImages(){
	StartButton = iLoadImage("StartButton.png");
	OptionsButton = iLoadImage("OptionsButton.png");
	CreditsButton = iLoadImage("CreditsButton.png");
	HighScoreButton = iLoadImage("HighScoreButton.png");
	DifficultyStateBG = iLoadImage("DifficultyStateBG.png");
	EasyButton = iLoadImage("EasyButton.png");
	MediumButton = iLoadImage("MediumButton.png");
	HardButton = iLoadImage("HardButton.png");
	BackButton = iLoadImage("BackButton.png");
	OptionsPageBG = iLoadImage("OptionsPageBG.png");
	SoundButtonTurnedOn = iLoadImage("SoundButtonTurnedOn.png");
	SoundButtonTurnedOff = iLoadImage("SoundButtonTurnedOff.png");
}
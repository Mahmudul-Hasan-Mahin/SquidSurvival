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
int CreditsStateBG = 0; //

int level3RunA = 0, level3RunB = 0;
int level3Wait[5] = { 0, 0, 0, 0, 0 };
int level3WaitPlayer = 0;

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
	CreditsStateBG = iLoadImage("CREDITS.png");
	

	//Level 3: whoever's turn it is toggles between these two run frames
	level3RunA = iLoadImage("level3_run_A.png");
	level3RunB = iLoadImage("level3_run_B.png");

	//Level 3: everyone else stands in these fixed "waiting in line" poses
	level3Wait[0] = iLoadImage("level3_wait_1.png");
	level3Wait[1] = iLoadImage("level3_wait_2.png");
	level3Wait[2] = iLoadImage("level3_wait_3.png");
	level3Wait[3] = iLoadImage("level3_wait_4.png");
	level3Wait[4] = iLoadImage("level3_wait_5.png");
	level3WaitPlayer = iLoadImage("level3_wait_player.png");
}
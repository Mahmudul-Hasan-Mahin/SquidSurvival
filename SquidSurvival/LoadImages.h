#include "iGraphics.h"
# include "stb_image.h"

extern int StartButton;
extern int OptionsButton;
extern int CreditsButton;
extern int HighScoreButton;
extern int DifficultyStateBG;
extern int EasyButton;
extern int MediumButton;
extern int HardButton;
extern int BackButton;
extern int OptionsPageBG;
extern int SoundButtonTurnedOn;
extern int SoundButtonTurnedOff;
extern int CreditsStateBG;

//Level 3 top-down sprites (cut from the reference bridge image)
extern int level3RunA, level3RunB;
extern int level3Wait[5];
extern int level3WaitPlayer;

void loadAllImages();
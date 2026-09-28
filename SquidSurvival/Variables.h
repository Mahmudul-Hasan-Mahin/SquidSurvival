#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

#pragma comment(lib, "winmm.lib")

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Game States
#define STATE_MENU 0
#define STATE_LEVEL1 1
#define STATE_LEVEL2 2
#define STATE_LEVEL3 3
#define STATE_GAMEOVER 4
#define STATE_VICTORY 5
#define STATE_DIFFICULTY 6 
#define STATE_CREDITS 7 
#define STATE_PLAYER_SELECT 8
#define OPTIONS_PAGE 9

extern int selectedPlayer;
extern bool isMenuMusicPlaying;
extern bool vistorySoundPlayed;
extern bool eliminatedSoundPlayed;
extern bool level1SoundPlaying;

extern bool soundIsOn;

// Audio Control Declarations
void playBGM(const char* filepath);
void stopBGM();
void playSFX(const char* relativePath);
void setBGMVolume(int percent);


//Difficulty Levels
#define DIFFICULTY_EASY 1
#define DIFFICULTY_MEDIUM 2
#define DIFFICULTY_HARD 3
extern int difficulty;
extern double botSpeedMultiplier;
extern int botMistakeChance;
extern int greenMin, greenRange;
extern int warningDuration;
extern int redMin, redRange;
extern double playerSpeed;


// Declare all globals as extern
extern int timeCount;
extern int gameState;
extern int score;

//Level 1 Variable
extern double p1_x, p1_y;
extern int signalState;
extern int signalTimer;
extern int signalDuration;
#define LEVEL1_SPEED 5
#define LEVEL_1_TIMELIMIT 60
extern int timeLimit;
// The Level 1 track is now two 800-wide background images placed side by
// side (a scrolling camera follows the player), so the world is twice the
// screen width. The finish line sits near the right edge of the second
// image (world x 800-1600), at the same relative spot the old finish line
// used to be in the single 0-800 image.
#define LEVEL1_WORLD_WIDTH 1600
#define LEVEL1_FINISH_X 1530
//Level 1 Bots
#define NUMBER_OF_BOTS 5
extern int rowRevealed[5];   
extern int activeBotIndex;   
extern int level3Queue[NUMBER_OF_BOTS + 1];
extern int level3QueueCount;
extern int level3TurnIndex;
extern int level3Phase;
struct Bot{
	double x, y;
	double speed;
	int isAlive;
	int isFinished;
	int reactionTimer;
	int currentRow;
	int isDoomed;
};
extern Bot bots[NUMBER_OF_BOTS];

//Level 2 Variables
extern int candyCenterX, candyCenterY;
// Different shapes need different numbers of checkpoints (triangle=3 up to
// the 13-point umbrella), so the arrays are sized to the largest shape and
// numCheckpoints says how many of those slots are actually used this round.
#define MAX_SHAPE_POINTS 13
extern double starX[MAX_SHAPE_POINTS], starY[MAX_SHAPE_POINTS];
extern int checkpointsVisited[MAX_SHAPE_POINTS];
extern int numCheckpoints;
extern int isMouseDown;
#define LEVEL2_RADIUS 100.0

//Level 3 Variables
extern int safePath[5];
extern int currentStep;
#define LEVEL3_BOX_WIDTH 100
#define LEVEL3_BOX_HEIGHT 50
#define LEVEL3_GAP_HEIGHT 30
#define LEVEL3_ROW_SPACING (LEVEL3_BOX_HEIGHT + LEVEL3_GAP_HEIGHT)
#define LEVEL3_ROW_START_Y 100
#define LEVEL3_LEFT_BOX_X 280
#define LEVEL3_RIGHT_BOX_X 420
#define LEVEL3_CHOICE_BOUNDARY_X 400

void setDifficulty(int d);
void saveGame();
int loadGame();
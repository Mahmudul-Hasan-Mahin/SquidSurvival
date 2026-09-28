#include "Variables.h"
#include<stdio.h>
bool isMenuMusicPlaying = false;
bool vistorySoundPlayed = false;
bool eliminatedSoundPlayed = false;
bool level1SoundPlaying = false;

bool soundIsOn = true;

int difficulty = 4;
double botSpeedMultiplier = 1.0;
int botMistakeChance = 25;
int greenMin = 90, greenRange = 70;
int warningDuration = 40;
int redMin = 70, redRange = 50;
double playerSpeed = 6;
// Define each global variable exactly once
int timeCount = 0;
int gameState = STATE_MENU;
int selectedPlayer = 0;
int rowRevealed[5] = { 0, 0, 0, 0, 0 };
int activeBotIndex = 0;
int level3Queue[NUMBER_OF_BOTS + 1];
int level3QueueCount = 0;
int level3TurnIndex = 0;
int level3Phase = 0;
int score = 0;
int timeLimit = LEVEL_1_TIMELIMIT;
Bot bots[NUMBER_OF_BOTS];

double p1_x = 400, p1_y = 50;
int signalState = 0;
int signalTimer = 0;
int signalDuration = 0;

int candyCenterX = 400, candyCenterY = 300;
double starX[MAX_SHAPE_POINTS] = { 0 };
double starY[MAX_SHAPE_POINTS] = { 0 };
int checkpointsVisited[MAX_SHAPE_POINTS] = { 0 };
int numCheckpoints = 5;
int isMouseDown = 0;

int safePath[5] = { 0 };
int currentStep = 0;

void setDifficulty(int d){
	if (d == DIFFICULTY_EASY){
		timeLimit = 45;
		botSpeedMultiplier = 0.7;
		botMistakeChance = 40;
		greenMin = 150; greenRange = 80;    
		warningDuration = 50;
		redMin = 50; redRange = 40;
		playerSpeed = 20;
	}
	else if (d == DIFFICULTY_MEDIUM){
		timeLimit = 30;
		botSpeedMultiplier = 1.0;
		botMistakeChance = 25;
		greenMin = 90; greenRange = 70;
		warningDuration = 40;
		redMin = 70; redRange = 50;
		playerSpeed = 1.7;
	}
	else if (d == DIFFICULTY_HARD){
		timeLimit = 20;
		botSpeedMultiplier = 1.4;
		botMistakeChance = 10;
		greenMin = 40; greenRange = 30;
		warningDuration = 25;
		redMin = 150; redRange = 100;
		playerSpeed = 1.15;
	}
}

void saveGame(){
	FILE* f = fopen("savegame.dat", "w");
	if (!f) return;

	fprintf(f, "%d\n", gameState);
	fprintf(f, "%d\n", difficulty);
	fprintf(f, "%lf\n", botSpeedMultiplier);
	fprintf(f, "%d\n", botMistakeChance);
	fprintf(f, "%d %d\n", greenMin, greenRange);
	fprintf(f, "%d\n", warningDuration);
	fprintf(f, "%d %d\n", redMin, redRange);
	fprintf(f, "%lf\n", playerSpeed);
	fprintf(f, "%d\n", selectedPlayer);
	fprintf(f, "%d\n", score);
	fprintf(f, "%d\n", timeLimit);

	fprintf(f, "%lf %lf\n", p1_x, p1_y);
	fprintf(f, "%d %d %d\n", signalState, signalTimer, signalDuration);

	for (int i = 0; i < NUMBER_OF_BOTS; i++){
		fprintf(f, "%lf %lf %lf %d %d %d %d\n",
			bots[i].x, bots[i].y, bots[i].speed,
			bots[i].isAlive, bots[i].isFinished,
			bots[i].reactionTimer, bots[i].currentRow);
	}

	fprintf(f, "%d %d\n", candyCenterX, candyCenterY);
	fprintf(f, "%d\n", numCheckpoints);
	for (int i = 0; i < MAX_SHAPE_POINTS; i++){
		fprintf(f, "%lf %lf %d\n", starX[i], starY[i], checkpointsVisited[i]);
	}
	fprintf(f, "%d\n", isMouseDown);

	for (int i = 0; i < 5; i++){
		fprintf(f, "%d %d\n", safePath[i], rowRevealed[i]);
	}
	fprintf(f, "%d\n", currentStep);
	fprintf(f, "%d %d\n", activeBotIndex, level3Phase);

	fclose(f);
}

int loadGame(){
	FILE* f = fopen("savegame.dat", "r");
	if (!f) return 0;

	fscanf(f, "%d", &gameState);
	fscanf(f, "%d", &difficulty);
	fscanf(f, "%lf", &botSpeedMultiplier);
	fscanf(f, "%d", &botMistakeChance);
	fscanf(f, "%d %d", &greenMin, &greenRange);
	fscanf(f, "%d", &warningDuration);
	fscanf(f, "%d %d", &redMin, &redRange);
	fscanf(f, "%lf", &playerSpeed);
	fscanf(f, "%d", &selectedPlayer);
	fscanf(f, "%d", &score);
	fscanf(f, "%d", &timeLimit);

	fscanf(f, "%lf %lf", &p1_x, &p1_y);
	fscanf(f, "%d %d %d", &signalState, &signalTimer, &signalDuration);

	for (int i = 0; i < NUMBER_OF_BOTS; i++){
		fscanf(f, "%lf %lf %lf %d %d %d %d",
			&bots[i].x, &bots[i].y, &bots[i].speed,
			&bots[i].isAlive, &bots[i].isFinished,
			&bots[i].reactionTimer, &bots[i].currentRow);
	}

	fscanf(f, "%d %d", &candyCenterX, &candyCenterY);
	fscanf(f, "%d", &numCheckpoints);
	for (int i = 0; i < MAX_SHAPE_POINTS; i++){
		fscanf(f, "%lf %lf %d", &starX[i], &starY[i], &checkpointsVisited[i]);
	}
	fscanf(f, "%d", &isMouseDown);

	for (int i = 0; i < 5; i++){
		fscanf(f, "%d %d", &safePath[i], &rowRevealed[i]);
	}
	fscanf(f, "%d", &currentStep);
	fscanf(f, "%d %d", &activeBotIndex, &level3Phase);

	fclose(f);
	return 1;
}

// Play looped background music (MP3 or WAV)
void playBGM(const char* relativePath) {
	if (soundIsOn == false) return;
	char fullPath[MAX_PATH];
	GetFullPathNameA(relativePath, MAX_PATH, fullPath, NULL);

	char shortPath[MAX_PATH];
	DWORD res = GetShortPathNameA(fullPath, shortPath, MAX_PATH);
	const char* targetPath = (res > 0) ? shortPath : fullPath;

	// 1. Close any existing BGM channel
	mciSendStringA("close bgm_channel", NULL, 0, NULL);

	// 2. Open using 'type mpegvideo' (Enables volume control on .wav & .mp3)
	char cmd[512];
	sprintf(cmd, "open \"%s\" type mpegvideo alias bgm_channel", targetPath);

	MCIERROR err = mciSendStringA(cmd, NULL, 0, NULL);
	if (err != 0) {
		char errBuf[256];
		mciGetErrorStringA(err, errBuf, sizeof(errBuf));
		printf("BGM Open Error (%d): %s\n", err, errBuf);
		return;
	}

	// 3. Play track in loop
	mciSendStringA("play bgm_channel repeat", NULL, 0, NULL);
}

// Stop background music
void stopBGM() {
	mciSendString("stop bgm_channel", NULL, 0, NULL);
	mciSendString("close bgm_channel", NULL, 0, NULL);
}

// Play sound effect on an independent channel
void playSFX(const char* relativePath) {
	if (soundIsOn == false) return;
	char fullPath[MAX_PATH];
	GetFullPathNameA(relativePath, MAX_PATH, fullPath, NULL);

	// PlaySound handles long filenames and paths with spaces perfectly
	BOOL result = PlaySoundA(fullPath, NULL, SND_FILENAME | SND_ASYNC);

	if (!result) {
		printf("SFX Error: Could not play file at: %s\n", fullPath);
	}
}

// Set BGM Volume (0 to 100)
void setBGMVolume(int percent) {
	if (percent < 0) percent = 0;
	if (percent > 100) percent = 100;

	// MCI volume scale ranges from 0 to 1000
	int mciVol = percent * 10;

	char cmd[128];
	sprintf(cmd, "setaudio bgm_channel volume to %d", mciVol);

	MCIERROR err = mciSendStringA(cmd, NULL, 0, NULL);
	if (err != 0) {
		char errBuf[256];
		mciGetErrorStringA(err, errBuf, sizeof(errBuf));
		printf("Volume Set Error (%d): %s\n", err, errBuf);
	}
}
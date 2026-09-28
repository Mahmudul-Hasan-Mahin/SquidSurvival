#include "Level1.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

void initLevel1(){
	p1_x = 30;
	p1_y = 220;
	signalState = 0;
	signalTimer = 0;
	signalDuration = 100 + rand() % 80;

	// Bot lanes stay in their own band (20-180) with 40px spacing so they
	// never touch each other, and the player's lane (220) sits a further
	// 40px above the topmost bot lane so the selected player's sprite
	// doesn't start out overlapping a bot.
	int botLanes[5] = { 20, 60, 100, 140, 180 };
	for (int i = 0; i < NUMBER_OF_BOTS; i++) {
		bots[i].x = 30;
		bots[i].y = botLanes[i];
		bots[i].speed = (0.6 + (rand() % 10) / 10.0) * botSpeedMultiplier;
		bots[i].isAlive = 1;
		bots[i].isFinished = 0;
		bots[i].reactionTimer = 0;
		bots[i].isDoomed = 0;
	}

	
	int botsToDie = (difficulty == DIFFICULTY_EASY) ? 1 : 2;
	for (int d = 0; d < botsToDie; d++){
		int pick;
		do {
			pick = rand() % NUMBER_OF_BOTS;
		} while (bots[pick].isDoomed);
		bots[pick].isDoomed = 1;
	}
}

//Keyboard Function
void fixedUpdate()
{
	/*
	//sound
	bool shouldPlayMusic = (gameState == STATE_MENU || gameState == STATE_DIFFICULTY || gameState == STATE_PLAYER_SELECT);
	if (shouldPlayMusic && !isMenuMusicPlaying){
		PlaySound(TEXT("game_sound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		isMenuMusicPlaying = true;
	}
	else if (!shouldPlayMusic && isMenuMusicPlaying){
		PlaySound(NULL, NULL, 0);
		isMenuMusicPlaying = false;
	}
	
	if (gameState == STATE_LEVEL1 && !level1SoundPlaying){
		PlaySound(TEXT("level1_sound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		eliminatedSoundPlayed = true;
	}
	else if (gameState == !STATE_LEVEL1 && level1SoundPlaying){
		PlaySound(NULL, NULL, 0);
		eliminatedSoundPlayed = false;
	}
	
	if (gameState == STATE_VICTORY && !vistorySoundPlayed){
		PlaySound(TEXT("victory_sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
		vistorySoundPlayed = true;
	}
	
	if (gameState == STATE_GAMEOVER && !eliminatedSoundPlayed){
		PlaySound(TEXT("eliminated_sound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		eliminatedSoundPlayed = true;
	}
	*/
	//
	if ((gameState == STATE_LEVEL1 || gameState == STATE_LEVEL2 || gameState == STATE_LEVEL3) &&
		(isKeyPressed('p') || isKeyPressed('P'))){
		isMouseDown = 0;
		saveGame();
		gameState = STATE_MENU;
	}
	if (gameState == STATE_MENU && isKeyPressed(' ')){
		resetGame();
		gameState = STATE_LEVEL1;
	}

	if ((gameState == STATE_GAMEOVER || gameState == STATE_VICTORY) && (isKeyPressed('r') || isKeyPressed('R'))){
		resetGame();
		gameState = STATE_LEVEL1;
	}

	if (gameState == STATE_LEVEL1){
		if (isSpecialKeyPressed(GLUT_KEY_UP)) p1_y += playerSpeed;
		if (isSpecialKeyPressed(GLUT_KEY_DOWN)) p1_y -= playerSpeed;
		if (isSpecialKeyPressed(GLUT_KEY_LEFT)) p1_x -= playerSpeed;
		if (isSpecialKeyPressed(GLUT_KEY_RIGHT)) p1_x += playerSpeed;

		if (p1_y < 20) p1_y = 20;
		if (p1_y > SCREEN_HEIGHT - 20) p1_y = SCREEN_HEIGHT - 20;
		if (p1_x < 20) p1_x = 20;

		if (((isSpecialKeyPressed(GLUT_KEY_UP) || isSpecialKeyPressed(GLUT_KEY_DOWN) || isSpecialKeyPressed(GLUT_KEY_RIGHT) || isSpecialKeyPressed(GLUT_KEY_LEFT)) && signalState == 2) || timeCount == 1500){
			gameState = STATE_GAMEOVER;
		}

		if (p1_x >= LEVEL1_FINISH_X){
			score += 500;
			initLevel2();
			gameState = STATE_LEVEL2;
		}
	}

	if (gameState == STATE_LEVEL3){
		if (isSpecialKeyPressed(GLUT_KEY_UP)) p1_y += LEVEL1_SPEED;
		if (isSpecialKeyPressed(GLUT_KEY_LEFT)) p1_x -= LEVEL1_SPEED;
		if (isSpecialKeyPressed(GLUT_KEY_RIGHT)) p1_x += LEVEL1_SPEED;

		if (p1_x < 300) p1_x = 300;
		if (p1_x > 500) p1_x = 500;

		if (currentStep < 5){
			int rowY = LEVEL3_ROW_START_Y + currentStep * LEVEL3_ROW_SPACING + LEVEL3_BOX_HEIGHT / 2;
			if (p1_y >= rowY){
				int chosen = (p1_x < LEVEL3_CHOICE_BOUNDARY_X) ? 0 : 1;
				rowRevealed[currentStep] = 1;

				if (chosen == safePath[currentStep]){
					currentStep++;
					score += 100;
					if (currentStep >= 5){
						score += 500;
						gameState = STATE_VICTORY;
					}
				}
				else{
					gameState = STATE_GAMEOVER;
				}
			}
		}
	}
}
void gameUpdateTimer(){

	if (gameState == STATE_LEVEL1){

		signalTimer++;
		if (signalTimer >= signalDuration){
			signalTimer = 0;
			if (signalState == 0){
				signalState = 1;
				signalDuration = warningDuration;          
			}
			else if (signalState == 1){
				signalState = 2;
				signalDuration = redMin + rand() % redRange;   

				
				for (int i = 0; i < NUMBER_OF_BOTS; i++) {
					if (bots[i].isAlive && !bots[i].isFinished) {
						bots[i].reactionTimer = bots[i].isDoomed ? (10 + rand() % 20) : 0;
					}
				}
			}
			else if (signalState == 2){
				signalState = 0;
				signalDuration = greenMin + rand() % greenRange;   
			}
		}

		for (int i = 0; i < NUMBER_OF_BOTS; i++) {
			if (!bots[i].isAlive || bots[i].isFinished) continue;

			if (signalState == 0) {
				bots[i].x += bots[i].speed;
			}
			else if (signalState == 1) {
				if (rand() % 100 < 70) {
					bots[i].x += bots[i].speed * 0.5;
				}
			}
			else if (signalState == 2) {
				if (bots[i].reactionTimer > 0) {
					bots[i].x += bots[i].speed;
					bots[i].reactionTimer--;
					bots[i].isAlive = 0;
				}
			}

			if (bots[i].x >= LEVEL1_FINISH_X) {
				bots[i].isFinished = 1;
				gameState = STATE_GAMEOVER;
			}
		}
	}

	if (gameState == STATE_LEVEL3){
		for (int i = 0; i < NUMBER_OF_BOTS; i++) {
			if (!bots[i].isAlive || bots[i].isFinished) continue;

			bots[i].y += bots[i].speed;

			if (bots[i].currentRow < 5){
				int rowY = LEVEL3_ROW_START_Y + bots[i].currentRow * LEVEL3_ROW_SPACING + LEVEL3_BOX_HEIGHT / 2;
				if (bots[i].y >= rowY){
					int r = bots[i].currentRow;
					int choice;

					if (rowRevealed[r]){
						choice = safePath[r];
					}
					else{
						choice = rand() % 2;
						rowRevealed[r] = 1;
					}


					bots[i].x = (choice == 0) ? (LEVEL3_LEFT_BOX_X + LEVEL3_BOX_WIDTH / 2) : (LEVEL3_RIGHT_BOX_X + LEVEL3_BOX_WIDTH / 2);

					if (choice == safePath[r]){
						bots[i].currentRow++;
						if (bots[i].currentRow >= 5){
							bots[i].isFinished = 1;
						}
					}
					else{
						bots[i].isAlive = 0;
					}
				}
			}
		}
	}
}
//TimerCount
void timeLimiter(){
	if (gameState == STATE_LEVEL1){
		timeLimit--;
		if (timeLimit <= 0){
			gameState = STATE_GAMEOVER;
		}
	}
}
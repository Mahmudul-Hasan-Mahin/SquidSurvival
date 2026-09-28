#include "ScreenLayout.h"


void iDraw()
{
	iClear();

	if (gameState == STATE_MENU){

		if (!isMenuMusicPlaying) {
			isMenuMusicPlaying = true;
			playBGM("Audios/MenuBackgroundSound.wav"); // Play your WAV music in loop
			setBGMVolume(10);                  // Set volume
		}

		iShowBMP(0, 0, "HomeScreenBackground.bmp");


		// START button
		iShowImage(300, 275, 200, 64, StartButton);
		/*
		iSetColor(30, 30, 30);                       
		iFilledRectangle(350, 320, 100, 30);
		iSetColor(255, 255, 255);
		iRectangle(350, 320, 100, 30);                
		iText(375, 330, "START", GLUT_BITMAP_9_BY_15);
		*/

		//Options Button
		iShowImage(300, 200, 200, 64, OptionsButton);

		//CreditsButton
		iShowImage(300, 125, 200, 64, CreditsButton);

		//HighScoreButton
		iShowImage(300, 50, 200, 64, HighScoreButton);

		/*
		// CONTINUE button
		iSetColor(30, 30, 30);
		iFilledRectangle(350, 270, 100, 30);
		iSetColor(255, 255, 255);
		iRectangle(350, 270, 100, 30);
		iText(362, 280, "CONTINUE", GLUT_BITMAP_9_BY_15);

		// HELP button
		iSetColor(30, 30, 30);
		iFilledRectangle(350, 220, 100, 30);
		iSetColor(255, 255, 255);
		iRectangle(350, 220, 100, 30);
		iText(378, 230, "HELP", GLUT_BITMAP_9_BY_15);
		*/
	}
		
		//iText(270, 340, "COURSE PROJECT : CSE1200", GLUT_BITMAP_9_BY_15);
		//iText(240, 240, "PRESS SPACE TO START GAME", GLUT_BITMAP_TIMES_ROMAN_24);
	
	else if (gameState == STATE_DIFFICULTY){
		//iShowBMP(0, 0, "difficulty_bg.bmp");
		iShowImage(0, 0, 800, 600, DifficultyStateBG);

		//EasyButton
		iShowImage(300, 300, 200, 64, EasyButton);

		//MediumButton
		iShowImage(300, 225, 200, 64, MediumButton);

		//HardButton
		iShowImage(300, 150, 200, 64, HardButton);

		//BackButton
		iShowImage(725, 25, 50, 50, BackButton);
		/*
		iSetColor(231, 76, 60);
		iText(300,450, "SELECT DIFFICULTY", GLUT_BITMAP_TIMES_ROMAN_24);
		
		// EASY button
		iSetColor(30, 30, 30);
		iFilledRectangle(370, 310, 100, 30);
		iSetColor(255, 255, 255);
		iRectangle(370, 310, 100, 30);
		iText(400, 320, "EASY", GLUT_BITMAP_9_BY_15);

		// MEDIUM button
		iSetColor(30, 30, 30);
		iFilledRectangle(370, 260, 100, 30);
		iSetColor(255, 255, 255);
		iRectangle(370, 260, 100, 30);
		iText(390, 270, "MEDIUM", GLUT_BITMAP_9_BY_15);

		// HARD button
		iSetColor(30, 30, 30);
		iFilledRectangle(370, 210, 100, 30);
		iSetColor(255, 255, 255);
		iRectangle(370, 210, 100, 30);
		iText(400, 220, "HARD", GLUT_BITMAP_9_BY_15);
		*/
	}
		else if (gameState == STATE_HELP){
			iSetColor(20, 20, 30);
			iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

			iSetColor(255, 255, 255);
			iText(150, 420, "Arrow Keys: Move. Stop on RED light.", GLUT_BITMAP_9_BY_15);
			iText(150, 390, "Level 2: Hold click, trace the star.", GLUT_BITMAP_9_BY_15);
			iText(150, 360, "Level 3: Click the safe glass panel.", GLUT_BITMAP_9_BY_15);

			iSetColor(231, 76, 60);
			iRectangle(350, 250, 100, 30);
			iText(370, 260, "BACK", GLUT_BITMAP_9_BY_15);
		}
	else if (gameState == STATE_PLAYER_SELECT){
			iSetColor(255 ,255 ,255);
			iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

			iSetColor(27, 149, 158);
			iText(260, 550, "CHOOSE YOUR PLAYER", GLUT_BITMAP_TIMES_ROMAN_24);

			iShowBMP(80, 330, "player_001.bmp");
			iRectangle(75, 325, 160, 160);

			iShowBMP(325, 330, "player_007.bmp");
			iRectangle(320, 325, 160, 160);

			iShowBMP(570, 330, "player_222.bmp");
			iRectangle(565, 325, 160, 160);

			iShowBMP(80, 140, "player_230.bmp");
			iRectangle(75, 135, 160, 160);

			iShowBMP(325, 140, "player_284.bmp");
			iRectangle(320, 135, 160, 160);

			iShowBMP(570, 140, "player_456.bmp");
			iRectangle(565, 135, 160, 160);

			//BackButton
			iShowImage(725, 25, 50, 50, BackButton);
	} 
	//Options Page
	else if (gameState == OPTIONS_PAGE){
		//OptionsPageBackground Image
		iShowImage(0, 0, 800, 600, OptionsPageBG);

		//BackButton
		iShowImage(725, 25, 50, 50, BackButton);

		if (soundIsOn == true){
			iShowImage(517, 258, 70, 35, SoundButtonTurnedOn);
		}
		else if (soundIsOn == false){
			iShowImage(517, 258, 70, 35, SoundButtonTurnedOff);
		}
	}
	else if (gameState == STATE_LEVEL1){
		// Scrolling camera: keep the player roughly centered horizontally,
		// clamped so we never scroll past either end of the world.
		double camX = p1_x - SCREEN_WIDTH / 2.0;
		if (camX < 0) camX = 0;
		if (camX > LEVEL1_WORLD_WIDTH - SCREEN_WIDTH) camX = LEVEL1_WORLD_WIDTH - SCREEN_WIDTH;

		// The level is two 800-wide background images placed side by side in
		// world space (0-800 and 800-1600). Both are drawn every frame at
		// their world position minus the camera offset; iShowBMPClipped
		// handles whichever one is partly or fully off-screen.
		iShowBMPClipped((int)(0 - camX), 0, "level1_bg2.bmp", SCREEN_WIDTH);
		iShowBMPClipped((int)(800 - camX), 0, "level1_bg.bmp", SCREEN_WIDTH);

		//Signal Indicator 
		if (signalState == 0){
			iSetColor(46, 204, 113);
		}
		else if (signalState == 1){
			iSetColor(241, 196, 15);
		}
		else{
			iSetColor(231, 76, 60);
		}
		iFilledCircle(760, 570, 15);

		char* playerImagesA[6] = {
			"avatar_player_001_runA.bmp", "avatar_player_007_runA.bmp", "avatar_player_222_runA.bmp",
			"avatar_player_230_runA.bmp", "avatar_player_284_runA.bmp", "avatar_player_456_runA.bmp"
		};
		char* playerImagesB[6] = {
			"avatar_player_001_runB.bmp", "avatar_player_007_runB.bmp", "avatar_player_222_runB.bmp",
			"avatar_player_230_runB.bmp", "avatar_player_284_runB.bmp", "avatar_player_456_runB.bmp"
		};

		for (int i = 0; i < NUMBER_OF_BOTS; i++) {
			int botScreenX = (int)(bots[i].x - camX);
			if (bots[i].isAlive) {
				int botImgIndex = i % 5;
				if (botImgIndex >= selectedPlayer) botImgIndex++;
				int botCycle = ((int)bots[i].x) % 20;
				int botBounce = (botCycle < 10) ? botCycle / 2 : (19 - botCycle) / 2;

				if (botCycle < 10)
					iShowBMP2(botScreenX - 15, (int)bots[i].y - 15 + botBounce, playerImagesA[botImgIndex], 16777215);
				else
					iShowBMP2(botScreenX - 15, (int)bots[i].y - 15 + botBounce, playerImagesB[botImgIndex], 16777215);
			}
			else {
				iSetColor(180, 40, 40);
				iLine(botScreenX - 8, (int)bots[i].y - 8, botScreenX + 8, (int)bots[i].y + 8);
				iLine(botScreenX - 8, (int)bots[i].y + 8, botScreenX + 8, (int)bots[i].y - 8);
			}
		}

		int playerScreenX = (int)(p1_x - camX);
		int playerCycle = ((int)p1_x) % 20;
		int playerBounce = (playerCycle < 10) ? playerCycle / 2 : (19 - playerCycle) / 2;

		if (playerCycle < 10)
			iShowBMP2(playerScreenX - 15, (int)p1_y - 15 + playerBounce, playerImagesA[selectedPlayer], 16777215);
		else
			iShowBMP2(playerScreenX - 15, (int)p1_y - 15 + playerBounce, playerImagesB[selectedPlayer], 16777215);

		//Timer
		iSetColor(231, 76, 60);
		char timeLimitStr[50];
		sprintf(timeLimitStr, "Timer: %d", timeLimit);
		iText(20, 560, timeLimitStr, GLUT_BITMAP_HELVETICA_12);
		//UI Header
		iSetColor(0, 0, 0);
		char scoreStr[50];
		sprintf(scoreStr, "SCORE : %d", score);
		iText(20, 580, scoreStr, GLUT_BITMAP_HELVETICA_12);
		iText(20, 10, "Controls: Arrow Keys to move RIGHT. Stop when RED light appears!", GLUT_BITMAP_8_BY_13);
	}
	else if (gameState == STATE_LEVEL2){
		iSetColor(20, 20, 30);
		iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		//Dalgona Base
		iSetColor(210, 140, 70);
		iFilledCircle(candyCenterX, candyCenterY, 160);

		//Shape Outline
		iSetColor(120, 70, 30);
		for (int i = 0; i < numCheckpoints; i++){
			int next = (i + 1) % numCheckpoints;
			iLine(starX[i], starY[i], starX[next], starY[next]);
		}

		//Check Points
		for (int i = 0; i < numCheckpoints; i++){
			if (checkpointsVisited[i]){
				iSetColor(46, 204, 113);//Green
			}
			else{
				iSetColor(231, 76, 60);//Red
			}
			iFilledCircle(starX[i], starY[i], 8);
		}
		char scoreStr[50];
		iSetColor(255, 255, 255);
		sprintf(scoreStr, "SCORE : %d", score);
		iText(650, 560, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20, 560, "LEVEL 2: Dalgona Candy", GLUT_BITMAP_TIMES_ROMAN_24);
		char instrStr[80];
		sprintf(instrStr, "Hold left Click and trace all %d checkpoints without slipping!", numCheckpoints);
		iText(20, 530, instrStr, GLUT_BITMAP_8_BY_13);
	}
	else if (gameState == STATE_LEVEL3){
		iSetColor(10, 15, 25);
		iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		iLine(270, 50, 270, 530);
		iLine(530, 50, 530, 530);

		for (int r = 0; r < 5; r++){
			int y = LEVEL3_ROW_START_Y + r * LEVEL3_ROW_SPACING;

			if (rowRevealed[r]){
				if (safePath[r] == 0) iSetColor(46, 204, 113);
				else iSetColor(180, 40, 40);
				iFilledRectangle(LEVEL3_LEFT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);

				if (safePath[r] == 1) iSetColor(46, 204, 113);
				else iSetColor(180, 40, 40);
				iFilledRectangle(LEVEL3_RIGHT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);
			}
			else{
				iSetColor(100, 140, 160);
				iFilledRectangle(LEVEL3_LEFT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);
				iFilledRectangle(LEVEL3_RIGHT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);
			}

			iSetColor(255, 255, 255);
			iRectangle(LEVEL3_LEFT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);
			iRectangle(LEVEL3_RIGHT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);
		}

		for (int r = 0; r < 4; r++){
			int y = LEVEL3_ROW_START_Y + r * LEVEL3_ROW_SPACING;
			int gapTop = y + LEVEL3_BOX_HEIGHT;
			int gapHeight = LEVEL3_GAP_HEIGHT;

			iSetColor(180, 190, 200);
			int leftInner = LEVEL3_LEFT_BOX_X + LEVEL3_BOX_WIDTH - 10;
			int rightInner = LEVEL3_RIGHT_BOX_X;
			iFilledRectangle(leftInner, gapTop, 10, gapHeight);
			iFilledRectangle(rightInner, gapTop, 10, gapHeight);
			iFilledRectangle(leftInner + 5, gapTop + gapHeight / 2 - 5, (rightInner - leftInner) - 5, 10);
		}

		char* playerImagesA[6] = {
			"avatar_player_001_runA.bmp", "avatar_player_007_runA.bmp", "avatar_player_222_runA.bmp",
			"avatar_player_230_runA.bmp", "avatar_player_284_runA.bmp", "avatar_player_456_runA.bmp"
		};
		char* playerImagesB[6] = {
			"avatar_player_001_runB.bmp", "avatar_player_007_runB.bmp", "avatar_player_222_runB.bmp",
			"avatar_player_230_runB.bmp", "avatar_player_284_runB.bmp", "avatar_player_456_runB.bmp"
		};

		for (int i = 0; i < NUMBER_OF_BOTS; i++){
			if (bots[i].isAlive){
				int botImgIndex = i % 5;
				if (botImgIndex >= selectedPlayer) botImgIndex++;
				int botCycle = ((int)bots[i].y) % 20;
				int botBounce = (botCycle < 10) ? botCycle / 2 : (19 - botCycle) / 2;

				iSetColor(190, 160, 120);
				int botShadowW = 12 - botBounce;
				iFilledEllipse((int)bots[i].x, (int)bots[i].y - 16, botShadowW, botShadowW / 3 + 2, 16);

				if (botCycle < 10)
					iShowBMP2((int)bots[i].x - 20, (int)bots[i].y - 20 + botBounce, playerImagesA[botImgIndex], 16777215);
				else
					iShowBMP2((int)bots[i].x - 20, (int)bots[i].y - 20 + botBounce, playerImagesB[botImgIndex], 16777215);
			}
			else{
				iSetColor(180, 40, 40);
				iLine((int)bots[i].x - 8, (int)bots[i].y - 8, (int)bots[i].x + 8, (int)bots[i].y + 8);
				iLine((int)bots[i].x - 8, (int)bots[i].y + 8, (int)bots[i].x + 8, (int)bots[i].y - 8);
			}
		}

		int playerCycle = ((int)p1_y) % 20;
		int playerBounce = (playerCycle < 10) ? playerCycle / 2 : (19 - playerCycle) / 2;

		iSetColor(190, 160, 120);
		int playerShadowW = 12 - playerBounce;
		iFilledEllipse((int)p1_x, (int)p1_y - 16, playerShadowW, playerShadowW / 3 + 2, 16);

		if (playerCycle < 10)
			iShowBMP2((int)p1_x - 20, (int)p1_y - 20 + playerBounce, playerImagesA[selectedPlayer], 16777215);
		else
			iShowBMP2((int)p1_x - 20, (int)p1_y - 20 + playerBounce, playerImagesB[selectedPlayer], 16777215);
		char scoreStr[50];
		iSetColor(255, 255, 255);
		sprintf(scoreStr, "SCORE : %d", score);
		iText(650, 560, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20, 560, "LEVEL 3: Glass Bridge", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20, 530, "Watch the bots and follow the SAFE (green) side!", GLUT_BITMAP_8_BY_13);
	}
	else if (gameState == STATE_GAMEOVER){
		if (!eliminatedSoundPlayed){
			playGameOverSound();
			eliminatedSoundPlayed = true;
		}

		iSetColor(40, 10, 10);
		iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		iSetColor(231, 76, 60);
		iText(310, 360, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 255, 255);
		char scoreStr[50];
		sprintf(scoreStr, "Final Score: %d", score);
		iText(330, 300, scoreStr, GLUT_BITMAP_9_BY_15);
		iText(270, 220, "Press 'R' to Restart Game", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gameState == STATE_VICTORY){
		if (!vistorySoundPlayed){
			playVictorySound();
			vistorySoundPlayed = true;
		}

		iSetColor(10, 40, 20);
		iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		iSetColor(46, 204, 113);
		iText(250, 360, "VICTORY - YOU SURVIVED!", GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 255, 255);
		char scoreStr[50];
		sprintf(scoreStr, "Total Score: %d", score);
		iText(330, 300, scoreStr, GLUT_BITMAP_9_BY_15);
		iText(270, 220, "Press 'R' to Play Again", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

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
	else if (gameState == STATE_CREDITS){
			//Background Image
			iShowImage(0, 0, 800, 600, CreditsStateBG);
			
			//BackButton
			iShowImage(725, 25, 50, 50, BackButton);
			/*
			iSetColor(20, 20, 30);
			iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

			iSetColor(255, 255, 255);
			iText(150, 420, "Arrow Keys: Move. Stop on RED light.", GLUT_BITMAP_9_BY_15);
			iText(150, 390, "Level 2: Hold click, trace the star.", GLUT_BITMAP_9_BY_15);
			iText(150, 360, "Level 3: Click the safe glass panel.", GLUT_BITMAP_9_BY_15);

			iSetColor(231, 76, 60);
			iRectangle(350, 250, 100, 30);
			iText(370, 260, "BACK", GLUT_BITMAP_9_BY_15);
			*/
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


		int leftRopeA = LEVEL3_LEFT_BOX_X - 14;
		int leftRopeB = LEVEL3_LEFT_BOX_X + LEVEL3_BOX_WIDTH + 6;
		int rightRopeA = LEVEL3_RIGHT_BOX_X - 6;
		int rightRopeB = LEVEL3_RIGHT_BOX_X + LEVEL3_BOX_WIDTH + 14;
		int ropeTop = 45, ropeBottom = 535;

		iSetColor(120, 88, 58);
		iFilledRectangle(leftRopeA, ropeTop, 7, ropeBottom - ropeTop);
		iFilledRectangle(leftRopeB, ropeTop, 7, ropeBottom - ropeTop);
		iFilledRectangle(rightRopeA, ropeTop, 7, ropeBottom - ropeTop);
		iFilledRectangle(rightRopeB, ropeTop, 7, ropeBottom - ropeTop);


		iSetColor(70, 48, 30);
		for (int t = ropeTop + 4; t <= ropeBottom - 4; t += 10){
			int off = ((t / 10) % 2 == 0) ? 0 : 3;
			iFilledRectangle(leftRopeA + off, t, 3, 5);
			iFilledRectangle(leftRopeB + off, t, 3, 5);
			iFilledRectangle(rightRopeA + off, t, 3, 5);
			iFilledRectangle(rightRopeB + off, t, 3, 5);
		}
		iSetColor(90, 65, 42);
		iFilledRectangle(leftRopeA, ropeTop, rightRopeB - leftRopeA, LEVEL3_ROW_START_Y - ropeTop);

		for (int r = 0; r < 5; r++){
			int y = LEVEL3_ROW_START_Y + r * LEVEL3_ROW_SPACING;


			iSetColor(90, 65, 42);
			iFilledRectangle(leftRopeA + 7, y + LEVEL3_BOX_HEIGHT / 2 - 2, LEVEL3_LEFT_BOX_X - (leftRopeA + 7), 4);
			iFilledRectangle(LEVEL3_LEFT_BOX_X + LEVEL3_BOX_WIDTH, y + LEVEL3_BOX_HEIGHT / 2 - 2, leftRopeB - (LEVEL3_LEFT_BOX_X + LEVEL3_BOX_WIDTH), 4);
			iFilledRectangle(rightRopeA + 7, y + LEVEL3_BOX_HEIGHT / 2 - 2, LEVEL3_RIGHT_BOX_X - (rightRopeA + 7), 4);
			iFilledRectangle(LEVEL3_RIGHT_BOX_X + LEVEL3_BOX_WIDTH, y + LEVEL3_BOX_HEIGHT / 2 - 2, rightRopeB - (LEVEL3_RIGHT_BOX_X + LEVEL3_BOX_WIDTH), 4);

			if (rowRevealed[r]){
				if (safePath[r] == 0) iSetColor(46, 204, 113);
				else iSetColor(180, 40, 40);
				iFilledRectangle(LEVEL3_LEFT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);

				if (safePath[r] == 1) iSetColor(46, 204, 113);
				else iSetColor(180, 40, 40);
				iFilledRectangle(LEVEL3_RIGHT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);
			}
			else{

				iSetColor(150, 195, 210);
				iFilledRectangle(LEVEL3_LEFT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);
				iFilledRectangle(LEVEL3_RIGHT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);

				iSetColor(210, 235, 240);
				iFilledRectangle(LEVEL3_LEFT_BOX_X + 8, y + LEVEL3_BOX_HEIGHT - 14, LEVEL3_BOX_WIDTH - 30, 6);
				iFilledRectangle(LEVEL3_RIGHT_BOX_X + 8, y + LEVEL3_BOX_HEIGHT - 14, LEVEL3_BOX_WIDTH - 30, 6);
			}

			iSetColor(230, 230, 235);
			iRectangle(LEVEL3_LEFT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);
			iRectangle(LEVEL3_RIGHT_BOX_X, y, LEVEL3_BOX_WIDTH, LEVEL3_BOX_HEIGHT);
		}
		for (int i = 0; i < NUMBER_OF_BOTS; i++){
			if (bots[i].isAlive){
				iSetColor(190, 160, 120);
				iFilledEllipse((int)bots[i].x, (int)bots[i].y - 14, 10, 4, 16);

				if (i == activeBotIndex && bots[i].reactionTimer <= 0){
					//This bot's turn, and it's actually walking right now
					int cyc = ((int)bots[i].y) % 20;
					int tex = (cyc < 10) ? level3RunA : level3RunB;
					iShowImage((int)bots[i].x - 22, (int)bots[i].y - 30, 44, 58, tex);
				}
				else{
					//Either waiting in line, or standing on the panel deciding
					iShowImage((int)bots[i].x - 20, (int)bots[i].y - 30, 40, 50, level3Wait[i % 5]);
				}


				int qNum = 0;
				for (int q = 0; q < level3QueueCount; q++){
					if (level3Queue[q] == i){ qNum = q + 1; break; }
				}
				char numStr[8];
				sprintf(numStr, "%d", qNum);
				iSetColor(255, 255, 255);
				iText((int)bots[i].x - 4, (int)bots[i].y + 30, numStr, GLUT_BITMAP_8_BY_13);
			}
			else{
				iSetColor(180, 40, 40);
				iLine((int)bots[i].x - 8, (int)bots[i].y - 8, (int)bots[i].x + 8, (int)bots[i].y + 8);
				iLine((int)bots[i].x - 8, (int)bots[i].y + 8, (int)bots[i].x + 8, (int)bots[i].y - 8);
			}
		}

		iSetColor(190, 160, 120);
		iFilledEllipse((int)p1_x, (int)p1_y - 14, 10, 4, 16);

		if (activeBotIndex == -1){
			//Your turn - actively walking, toggle the two run frames
			int cyc = ((int)p1_y) % 20;
			int tex = (cyc < 10) ? level3RunA : level3RunB;
			iShowImage((int)p1_x - 22, (int)p1_y - 30, 44, 58, tex);
		}
		else{
			//Waiting for your turn
			iShowImage((int)p1_x - 20, (int)p1_y - 30, 40, 50, level3WaitPlayer);
		}

		int playerQNum = 0;
		for (int q = 0; q < level3QueueCount; q++){
			if (level3Queue[q] == NUMBER_OF_BOTS){ playerQNum = q + 1; break; }
		}
		char playerNumStr[8];
		sprintf(playerNumStr, "%d", playerQNum);
		iSetColor(255, 215, 0);
		iText((int)p1_x - 4, (int)p1_y + 30, playerNumStr, GLUT_BITMAP_8_BY_13);
		char scoreStr[50];
		iSetColor(255, 255, 255);
		sprintf(scoreStr, "SCORE : %d", score);
		iText(650, 560, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(20, 560, "LEVEL 3: Glass Bridge", GLUT_BITMAP_TIMES_ROMAN_24);

		int remaining = 1; //you
		for (int i = 0; i < NUMBER_OF_BOTS; i++) if (bots[i].isAlive) remaining++;
		char hudStr[60];
		sprintf(hudStr, "STEP %d OF 5   |   PLAYERS REMAINING: %d", (currentStep < 5 ? currentStep + 1 : 5), remaining);
		iSetColor(255, 215, 0);
		iText(20, 538, hudStr, GLUT_BITMAP_8_BY_13);

		if (activeBotIndex == -1){
			iSetColor(46, 204, 113);
			iText(20, 20, "YOUR TURN! Walk up and choose left or right.", GLUT_BITMAP_8_BY_13);
		}
		else{
			iSetColor(255, 255, 255);
			iText(20, 20, "Watch closely - someone else is crossing right now...", GLUT_BITMAP_8_BY_13);
		}
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

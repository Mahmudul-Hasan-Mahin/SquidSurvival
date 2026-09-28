#include "Level3.h"
#include "Level1.h"

void initLevel3(){
	currentStep = 0;
	activeBotIndex = -1;
	level3TurnIndex = 0;

	for (int i = 0; i < 5; i++){
		safePath[i] = rand() % 2;
		rowRevealed[i] = 0;
	}

	p1_x = 400;
	p1_y = 60;

	int botStartX[5] = { 300, 340, 400, 460, 500 };
	int aliveBots[NUMBER_OF_BOTS];
	int aliveCount = 0;
	for (int i = 0; i < NUMBER_OF_BOTS; i++){
		bots[i].x = botStartX[i];
		bots[i].y = 60;
		bots[i].speed = (1.0 + (rand() % 10) / 10.0) * botSpeedMultiplier;
		bots[i].isFinished = 0;
		bots[i].currentRow = 0;
		//bots[i].isAlive is left as-is - anyone who died in Level 1 stays out
		if (bots[i].isAlive) aliveBots[aliveCount++] = i;
	}

	//একটা fixed turn-order বানানো হচ্ছে, আর তুমি (player) এর মধ্যে
	//randomly বাছাই করা একটা position-এ বসবে - এতে নিশ্চিতভাবে তোমার
	//পালা আসবে, বাকিরা জীবিত থাকা অবস্থায় বার বার স্কিপ হয়ে যাবে না
	int playerPos = rand() % (aliveCount + 1);
	level3QueueCount = 0;
	int botIdx = 0;
	for (int slot = 0; slot <= aliveCount; slot++){
		if (slot == playerPos){
			level3Queue[level3QueueCount++] = NUMBER_OF_BOTS; //sentinel = "you"
		}
		else{
			level3Queue[level3QueueCount++] = aliveBots[botIdx++];
		}
	}
}
void updateLevel3(){
	if (currentStep >= 5) return; //already won, nothing left to referee
	if (level3TurnIndex >= level3QueueCount) return; //safety check

	int activeId = level3Queue[level3TurnIndex];

	if (activeId == NUMBER_OF_BOTS){
		if (activeBotIndex != -1){

			p1_x = 400;
			p1_y = (currentStep == 0) ? 60 : (LEVEL3_ROW_START_Y + currentStep * LEVEL3_ROW_SPACING - LEVEL3_GAP_HEIGHT - 10);
		}
		activeBotIndex = -1; //genuinely your turn - Level1.cpp's fixedUpdate() handles your movement
		return;
	}
	if (activeBotIndex != activeId){
		//This bot's turn has just begun - start it fresh from the waiting platform
		bots[activeId].x = 400;
		bots[activeId].y = 60;
		bots[activeId].currentRow = 0;
		bots[activeId].reactionTimer = 10 + rand() % 20;
		activeBotIndex = activeId;
	}

	if (bots[activeId].reactionTimer > 0){
		bots[activeId].reactionTimer--; //standing still on this panel
		return;
	}

	int row = bots[activeId].currentRow;
	int rowY = LEVEL3_ROW_START_Y + row * LEVEL3_ROW_SPACING + LEVEL3_BOX_HEIGHT / 2;
	bots[activeId].y += bots[activeId].speed;

	if (bots[activeId].y >= rowY){
		if (row < currentStep){
			//Already-known-safe panel - cross it, pause briefly, keep going
			bots[activeId].x = (safePath[row] == 0) ? (LEVEL3_LEFT_BOX_X + LEVEL3_BOX_WIDTH / 2) : (LEVEL3_RIGHT_BOX_X + LEVEL3_BOX_WIDTH / 2);
			bots[activeId].y = rowY;
			bots[activeId].currentRow++;
			bots[activeId].reactionTimer = 8 + rand() % 15;
			return;
		}

		//This is the real frontier panel - actually test it
		int choice;
		if (rowRevealed[row]){
			choice = safePath[row];
		}
		else{
			choice = 1 - safePath[row];
			rowRevealed[row] = 1;
		}
		bots[activeId].x = (choice == 0) ? (LEVEL3_LEFT_BOX_X + LEVEL3_BOX_WIDTH / 2) : (LEVEL3_RIGHT_BOX_X + LEVEL3_BOX_WIDTH / 2);
		bots[activeId].y = rowY;

		if (choice == safePath[row]){
			bots[activeId].currentRow++;
			currentStep++;
			if (currentStep >= 5){
				bots[activeId].isFinished = 1;
				gameState = STATE_GAMEOVER; //a bot crossed the whole bridge before your turn came
			}
			else{
				bots[activeId].reactionTimer = 20 + rand() % 50;
			}
		}
		else{
			bots[activeId].isAlive = 0; //fell through
			level3TurnIndex++; //next participant in the fixed order steps up
		}
	}
}
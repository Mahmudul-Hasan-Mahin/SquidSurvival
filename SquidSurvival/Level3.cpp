#include "Level3.h"
#include "Level1.h"
void initLevel3(){
	currentStep = 0;
	for (int i = 0; i < 5; i++){
		safePath[i] = rand() % 2;
		rowRevealed[i] = 0;
	}

	p1_x = 400;
	p1_y = 30;

	
	int botStartX[5] = { 250, 320, 480, 550, 620 };
	for (int i = 0; i < NUMBER_OF_BOTS; i++){
		bots[i].x = botStartX[i];
		bots[i].y = 30;
		bots[i].speed = (1.0 + (rand() % 10) / 10.0) * botSpeedMultiplier;
		bots[i].isFinished = 0;
		bots[i].currentRow = 0;
	}
}

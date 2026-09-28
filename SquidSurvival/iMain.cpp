
#include "iGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Variables.h"
#include "Level1.h"
#include "ScreenLayout.h"
#include "LoadImages.h"
#include "MouseFunction.h"

void iPassiveMouseMove(int mx, int my)
{
    // leave empty if not used
}

int main()
{
	srand(time(NULL));
	iSetTimer(20, gameUpdateTimer);
	iSetTimer(1000, timeLimiter);
	gameState = STATE_MENU;
	//initLevel2();
	iInitialize(SCREEN_WIDTH, SCREEN_HEIGHT, "SQUID SURVIVAL");
	loadAllImages();
	iStart();
    return 0;
}

#include "MouseFunction.h"

//Mouse button press
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gameState == STATE_MENU){
			if (mx >= 300 && mx <= 500 && my >= 275 && my <= 339){
				playButtonClickSound();
				isMenuMusicPlaying = false;
				stopBGM();
				gameState = STATE_DIFFICULTY;
			}
			/*
			else if (mx >= 350 && mx <= 450 && my >= 270 && my <= 300){
				if (!loadGame()){
					gameState = STATE_LEVEL1;
					resetGame();
				}
			}
			*/
			else if (mx >= 300 && mx <= 500 && my >= 200 && my <= 264){
				playButtonClickSound();
				isMenuMusicPlaying = false;
				stopBGM();
				gameState = OPTIONS_PAGE;
			}
			else if (mx >= 350 && mx <= 450 && my >= 220 && my <= 250){
				gameState = STATE_HELP;
			}
		}
		else if (gameState == STATE_DIFFICULTY){
			if (mx >= 370 && mx <= 470 && my >= 310 && my <= 340){
				playButtonClickSound();
				difficulty = DIFFICULTY_EASY;
				setDifficulty(difficulty);
				gameState = STATE_PLAYER_SELECT;
			}
			else if (mx >= 370 && mx <= 470 && my >= 260 && my <= 290){
				playButtonClickSound();
				difficulty = DIFFICULTY_MEDIUM;
				setDifficulty(difficulty);
				gameState = STATE_PLAYER_SELECT;
			}
			else if (mx >= 370 && mx <= 470 && my >= 210 && my <= 240){
				playButtonClickSound();
				difficulty = DIFFICULTY_HARD;
				setDifficulty(difficulty);
				gameState = STATE_PLAYER_SELECT;
			}
			else if (mx >= 725 && mx <= 775 && my >= 25 && my <= 75){
				playButtonClickSound();
				gameState = STATE_MENU;
			}
		}
		else if (gameState == OPTIONS_PAGE){
			if (mx >= 725 && mx <= 775 && my >= 25 && my <= 75){
				playButtonClickSound();
				gameState = STATE_MENU;
			}
			if (mx >= 517 && mx <= 587 && my >= 258 && my <= 293){
				playButtonClickSound();
				if (soundIsOn == true){
					soundIsOn = false;
				}
				else if (soundIsOn == false){
					soundIsOn = true;
				}
			}
		}
		else if (gameState == STATE_HELP){
			if (mx >= 350 && mx <= 450 && my >= 250 && my <= 280){
				gameState = STATE_MENU;
			}
		}
		else if (gameState == STATE_PLAYER_SELECT){
			if (mx >= 75 && mx <= 235 && my >= 325 && my <= 485){
				playButtonClickSound();
				selectedPlayer = 0; gameState = STATE_LEVEL1; resetGame();
			}
			else if (mx >= 320 && mx <= 480 && my >= 325 && my <= 485){
				playButtonClickSound();
				selectedPlayer = 1; gameState = STATE_LEVEL1; resetGame();
			}
			else if (mx >= 565 && mx <= 725 && my >= 325 && my <= 485){
				playButtonClickSound();
				selectedPlayer = 2; gameState = STATE_LEVEL1; resetGame();
			}
			else if (mx >= 75 && mx <= 235 && my >= 135 && my <= 295){
				playButtonClickSound();
				selectedPlayer = 3; gameState = STATE_LEVEL1; resetGame();
			}
			else if (mx >= 320 && mx <= 480 && my >= 135 && my <= 295){
				playButtonClickSound();
				selectedPlayer = 4; gameState = STATE_LEVEL1; resetGame();
			}
			else if (mx >= 565 && mx <= 725 && my >= 135 && my <= 295){
				playButtonClickSound();
				selectedPlayer = 5; gameState = STATE_LEVEL1; resetGame();
			}
			else if (mx >= 725 && mx <= 775 && my >= 25 && my <= 75){
				playButtonClickSound();
				gameState = STATE_DIFFICULTY;
			}
		}
		if (gameState == STATE_LEVEL2){
			isMouseDown = 1;
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if (gameState == STATE_LEVEL2){
			isMouseDown = 0;
		}
	}
}
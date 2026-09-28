#pragma once

#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glaux.lib")
#include "glut.h"
#include <time.h>
#include <math.h>
#include <windows.h>
#include "glaux.h"
#include "stb_image.h"

// Function prototypes (declarations)
void iDraw();
void fixedUpdate();
void iMouseMove(int, int);
void iPassiveMouseMove(int, int);
void iMouse(int button, int state, int x, int y);

int isKeyPressed(unsigned char key);
int isSpecialKeyPressed(unsigned char key);
int iSetTimer(int msec, void(*f)(void));
void iPauseTimer(int index);
void iResumeTimer(int index);
void iShowBMP2(int x, int y, char filename[], int ignoreColor);
void iShowBMP(int x, int y, char filename[]);
// Like iShowBMP, but safe to call with x partly or fully off the left/right
// edge of the screen (for scrolling backgrounds). screenWidth is the width
// of the visible window (e.g. SCREEN_WIDTH).
void iShowBMPClipped(int x, int y, char filename[], int screenWidth);
unsigned int iLoadImage(char filename[]);
void iShowImage(int x, int y, int width, int height, unsigned int texture);
void iGetPixelColor(int cursorX, int cursorY, int rgb[]);
void iText(double x, double y, char *str, void* font);
void iPoint(double x, double y, int size);
void iLine(double x1, double y1, double x2, double y2);
void iFilledPolygon(double x[], double y[], int n);
void iPolygon(double x[], double y[], int n);
void iRectangle(double left, double bottom, double dx, double dy);
void iFilledRectangle(double left, double bottom, double dx, double dy);
void iFilledCircle(double x, double y, double r, int slices = 100);
void iCircle(double x, double y, double r, int slices = 100);
void iEllipse(double x, double y, double a, double b, int slices);
void iFilledEllipse(double x, double y, double a, double b, int slices);
void iRotate(double x, double y, double degree);
void iUnRotate();
void iSetColor(double r, double g, double b);
void iDelay(int sec);
void iDelayMS(int msec);
void iClear();
void iInitialize(int width, int height, char *title, int keyboardSamplingRate = 16);
void iStart();

// Global variables – declare as extern
extern int iScreenHeight, iScreenWidth;
extern int iMouseX, iMouseY;
extern int ifft;
extern void(*iAnimFunction[10])(void);
extern int iAnimCount;
extern int iAnimDelays[10];
extern int iAnimPause[10];
extern unsigned int keyPressed[512];
extern unsigned int specialKeyPressed[512];
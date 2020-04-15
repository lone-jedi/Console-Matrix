#pragma once
#include "windows.h"

const int STRING_SIZE = 100;
const int LINE_SIZE = 30;

const int WHITESPACE_PERIOD = 10;	/* Input whitespace in string period*/
int FIRST_CODE_ASCII = 179;
int LAST_CODE_ASCII = 223;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
enum LightningSide {Left, Right};
void printSymb(ConsoleColor color = Green, int codeAcsii = -1);
void speedPrint(std::string str, int speed); /* slow motion text function */
void gotoxy(int x, int y);
void lightningStruck(int step, LightningSide side = Left);
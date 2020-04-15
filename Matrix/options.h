#pragma once
#include "windows.h"

const int STRING_SIZE = 100;
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
void printSymb();
void speedPrint(std::string str, int speed); /* slow motion text function */

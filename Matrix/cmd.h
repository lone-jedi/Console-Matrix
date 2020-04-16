#pragma once
#include <iostream>
#include <fstream>
#include "windows.h"
#include <random>
#include <string>
using namespace std;

namespace cmd {
	const int STRING_SIZE = 100;
	const int LINE_SIZE = 30;

	const int WHITESPACE_PERIOD = 10;	/* Input whitespace in string period*/

	/*
	*	ACSII CODES:
	*	(FIRST_CODE_ASCII - LAST_CODE_ASCII)
	*	179 - 223 - symbols
	*	33	- 38  - symbols
	*	48  - 49  - 0, 1
	*	242 - 254 - some obscure symbols
	*	I think it's cool, actually.
	*/
	const int CODES_ACSII[][2] = { {179, 223}, {33, 38}, {48, 49}, {242, 254} };

	const LPCSTR CONSOLE_TITLE = "Matrix";
	const LPCSTR MUSIC_PATH = "wav/fullTheme.wav";
	const string INTRO_IMG_PATH = "neoinv.txt";
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
	enum LightningSide { Left, Right };

	const HANDLE H_CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);

	void printSymb(ConsoleColor color = Green, const int codeAcsii = -1);
	void speedPrint(string str, int speed); /* slow motion text function */
	void gotoxy(int x, int y);
	void lightningStruck(int step, LightningSide side = Left);
	void printFile(string path);
	void fixConsoleWindow();
}
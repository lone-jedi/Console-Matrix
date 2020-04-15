#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "options.h"
#pragma comment (lib, "winmm.lib")
#pragma warning(disable : 4996) // PlaySound() - old function

using namespace std;

int main()
{
	/* Fixed console window */
	HWND hWnd;
	HMENU hm;
	if ((hWnd = GetConsoleWindow()) == NULL)
	{
		cout << "No console window!?\n";
		return 0;
	}
	hm = GetSystemMenu(hWnd, FALSE);
	RemoveMenu(hm, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
	RemoveMenu(hm, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
	DrawMenuBar(hWnd);

	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));
	SetConsoleTitleA("Matrix");

	/* !!! Console window size. Width = STRING_SIZE symbols, height = ... lines */
	system("mode con cols=100 lines=30"); 
	srand(time(0));

	// Play main theme The Matrix, start title
	if (PlaySound("wav/fullTheme.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC))
	{
		speedPrint("PlaySound - init \n", 100);
		speedPrint("Matrix ", 100);
		speedPrint("...", 1000);
		speedPrint(" loaded\n", 100);
		speedPrint("...", 1000);
		speedPrint("You are in matrix \n", 100);
		speedPrint("Knock, knock User ", 100);
		speedPrint("..\n", 1000); 
	}
	else
		cout << "PlaySound - ERROR " << strerror(GetLastError()) << endl;

	// Print Matrix
	for(int j = 1; ; ++j)
	{
		for (int i = 0; i < STRING_SIZE; ++i)
		{
			if (j == LINE_SIZE)
			{
				lightningStruck(3 + rand() % 6);
				j = 1;
			}

			if (i % WHITESPACE_PERIOD == 0 || rand() % 4 == 0)
			{
				cout << " ";
				continue;
			}

			if (rand() % 10 == 0)
			{
				printSymb(White);
				continue;
			}

			printSymb();
		}
		Sleep(100);
		cout << endl;
	}

	return 0;
}

void speedPrint(string str, int speed)
{
	for (int i = 0; i < str.length(); ++i)
	{
		cout << str[i];
		Sleep(speed);
	}
}


void printSymb(ConsoleColor color, int codeAcsii)
{
	int value;

	if (codeAcsii == -1)
		value = FIRST_CODE_ASCII + rand() % (LAST_CODE_ASCII - FIRST_CODE_ASCII + 1);
	else
		value = codeAcsii;

	if (color != Green)
	{
		SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | color));
		cout << char(value);
		SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));
	}
	else
		cout << char(value);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}

void lightningStruck(int step, LightningSide side)
{
	short middle = LINE_SIZE / 2;
	short randEndX = rand() % (STRING_SIZE / 3) + STRING_SIZE / 2;

	for (short i = rand() % (STRING_SIZE / 6); i < randEndX; ++i)
	{
		SetConsoleCursorPosition(hConsole, { i , middle + rand() % (short)step - (short)step }); //XCoord = i, YCoord = [ -step ; +step]
		cout << "\b";
		printSymb(White);
	}
	SetConsoleCursorPosition(hConsole, { 0, 29 }); // Cursor to left bottom position 
}
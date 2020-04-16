#include "cmd.h"

void cmd::fixConsoleWindow()
{
	HWND hWnd;
	HMENU hm;

	if ((hWnd = GetConsoleWindow()) == NULL)
	{
		cout << "No console window!?\n";
		exit(-1);
	}
	hm = GetSystemMenu(hWnd, FALSE);
	RemoveMenu(hm, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
	RemoveMenu(hm, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
	DrawMenuBar(hWnd);
}

void cmd::speedPrint(string str, int speed)
{
	for (int i = 0; i < str.length(); ++i)
	{
		cout << str[i];
		Sleep(speed);
	}
}


void cmd::printSymb(ConsoleColor color, const int codeAcsii)
{
	int value;

	if (codeAcsii == -1)
	{
		/* Random CODES_ACSII[] int pair */
		const int randV = rand() % 4;
		value = CODES_ACSII[randV][0] + rand() % (CODES_ACSII[randV][1] - CODES_ACSII[randV][0] + 1);
	}
	else
		value = codeAcsii;

	if (color != Green)
	{
		SetConsoleTextAttribute(H_CONSOLE, (WORD)((Black << 4) | color));
		cout << char(value);
		SetConsoleTextAttribute(H_CONSOLE, (WORD)((Black << 4) | Green));
	}
	else
		cout << char(value);
}

void cmd::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(H_CONSOLE, coord);
}

void cmd::lightningStruck(int step, LightningSide side)
{
	short middleYCmdSize = LINE_SIZE / 2;
	short randXEnd = rand() % (STRING_SIZE / 3) + STRING_SIZE / 2;

	for (short i = rand() % (STRING_SIZE / 6); i < randXEnd; ++i)
	{
		/* XCoord = i, YCoord = [ -step ; +step] */
		SetConsoleCursorPosition(H_CONSOLE, { i , middleYCmdSize + rand() % (short)step - (short)step });
		cout << "\b";
		printSymb(White);
	}
	/* Move cursor to left bottom position */
	SetConsoleCursorPosition(H_CONSOLE, { 0, LINE_SIZE - 1 });
}


void cmd::printFile(string path)
{
	string line;
	ifstream myfile(path);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			cout << '\t' << line << endl;
			Sleep(70);
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}
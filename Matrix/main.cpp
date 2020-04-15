#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "options.h"

using namespace std;

int main()
{
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));
	system("mode con cols=100 lines=30"); /* Console window size. Width = STRING_SIZE symbols, height = ... lines */
	SetConsoleTitleA("Matrix");
	srand(time(0));
	int exit = false;

	while (!exit)
	{
		for (int i = 0; i < STRING_SIZE; ++i)
		{
			if (i % WHITESPACE_PERIOD == 0 || rand() % 4 == 0)
			{
				cout << " ";
				continue;
			}

			if (rand() % 10 == 0)
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | White));
				printSymb();
				SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));
				continue;
			}
			printSymb();
		}
		Sleep(100);
		cout << endl;
	}
	return 0;
}

void printSymb()
{
	int value = FIRST_CODE_ASCII + rand() % (LAST_CODE_ASCII - FIRST_CODE_ASCII + 1);
	cout << char(value);
}
#include <ctime>
#include "cmd.h"
using namespace cmd;
#pragma comment (lib, "winmm.lib") // For PlaySound()
#pragma warning(disable : 4996) // PlaySound() - old function

int main()
{
	fixConsoleWindow();

	/* !!! Console window size. Width = STRING_SIZE symbols, height = LINE_SIZE lines !!! */
	system("mode con cols=100 lines=30");

	/* Set console background and text color*/
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));

	/* Set console title */
	SetConsoleTitleA(consoleTitle);

	srand(time(0));

	/* Play main theme The Matrix, intro */
	if (PlaySound(musicPath, NULL, SND_LOOP | SND_FILENAME | SND_ASYNC))
		speedPrint("PlaySound - init \n", 100);
	else
		cout << "PlaySound - ERROR " << strerror(GetLastError()) << endl;

	speedPrint("Matrix ", 100);
	speedPrint("...", 500);
	speedPrint(" loaded\n", 100);
	printFile(introImgPath);
	speedPrint("...", 500);
	speedPrint("You are in matrix \n", 100);
	speedPrint("Knock, knock User", 100);
	speedPrint(".\n\n", 500);

	/* Print Matrix */
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
#include <iostream>
#include <random>
#include <ctime>
#include "windows.h"
#include <string>

using namespace std;

const int STRING_SIZE = 100;		
const int WHITESPACE_PERIOD = 10;	/* Input whitespace in string period*/
int FIRST_CODE_ASCI = 179;			
int LAST_CODE_ASCI = 223;			

int main()
{
	system("color 2");
	system("mode con cols=110 lines=30"); /* Console window size. 
										  Width = (STRING_SIZE + WHITESPACE_PERIOD) symbols, height = ... lines */
	srand(time(0));
	int exit = false;
	while (!exit)
	{
		for (int i = 0; i < STRING_SIZE; ++i)
		{
			if (i % WHITESPACE_PERIOD == 0)
			{
				cout << " ";
			}
			int value = FIRST_CODE_ASCI + rand() % (LAST_CODE_ASCI - FIRST_CODE_ASCI + 1);
			cout << char(value);
		}
		Sleep(100);
		cout << endl;
	}
	return 0;
}
#include "stdafx.h"
#include "TicTacToe.h"
#include "../libTicTacToe/libTicTacToe.h"

using namespace libTicTacToe;


/// <summary>
/// Runs the TicTacToe game
/// </summary>
/// <param name="argc">Num params</param>
/// <param name="argv">Params</param>
/// <returns></returns>
int main(int argc, char* argv[])
{
	int selection;

	do
	{
		system("cls");  //todo: make nicer

		std::cout << "Please select from the following options:" << std::endl;
		std::cout << "1: Train (auto)" << std::endl;
		std::cout << "2: Play" << std::endl;
		std::cout << "3: Quit" << std::endl;

		std::cin >> selection;

		switch (selection)
		{
		case 1:
			Train();
			break;
		case 2:
			Play();
			break;
		case 3:
			return 0;
		default:
			std::cout << "Invalid option:" << selection << std::endl;
			WaitForUser();
		}
	} while (true);

}


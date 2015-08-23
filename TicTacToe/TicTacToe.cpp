// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TicTacToe.h"
#include "../libTicTacToe/libTicTacToe.h"

using namespace libTicTacToe;

/// <summary>
/// Runs the program.
/// </summary>
void Run()
{
	std::string usrInput("x");
	int selection;

	while (usrInput != "")
	{
		system("cls");  //todo: make nice

		std::cout << "Please select from the following options:" << std::endl;
		std::cout << "1: Train (auto)" << std::endl;
		std::cout << "2: Play" << std::endl;

		std::cin >> usrInput;

		try
		{
			selection = std::stoi(usrInput);
		}
		catch (std::invalid_argument& exception)
		{
			std::cout << "Invalid selection:" << exception.what() << std::endl;
			continue;
		}

		switch (selection)
		{
		case 1:
			Train();
			break;
		case 2:
			Play();
			break;
		default:
			std::cout << "Invalid option:" << selection << std::endl;
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	//OPTIONS options;
	//try 
	//{
	//	options = getOptions(argc, argv);
	//}
	//catch (...)
	//{
	//	std::cout << "Invalid commandline" << std::endl;
	//	std::cout << "usage: -i<num_iterations> -o<log_file_path> -a<algorithm>" << std::endl;
	//}

	//if(options._logFilePath != "")
	//	initLogging(options._logFilePath);

	Run();

    return 0;
}


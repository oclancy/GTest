// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TicTacToe.h"
#include "../libTicTacToe/libTicTacToe.h"

using namespace libTicTacToe;

void run(OPTIONS& options)
{
	std::string usrInput("x");
	int selection;

	while (usrInput != "")
	{
		system("cls");  //todo: make nice

		std::cout << "Please select from the following options:" << std::endl;
		std::cout << "1: Train (auto)" << std::endl;
		std::cout << "2: Load" << std::endl;
		std::cout << "3: Play" << std::endl;

		std::cin >> usrInput;

		try
		{
			selection = std::stoi(usrInput);
		}
		catch (std::invalid_argument& exception)
		{
			std::cout << "Invalid selection:" << selection << std::endl;
			continue;
		}

		switch (selection)
		{
		case 1:
			train(options);
		default:
			std::cout << "Invalid option:" << selection << std::endl;
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	OPTIONS options;
	try 
	{
		options = getOptions(argc, argv);
	}
	catch (...)
	{
		std::cout << "Invalid commandline" << std::endl;
		std::cout << "usage: -i<num_iterations> -o<log_file_path> -a<algorithm>" << std::endl;
	}

	initLogging(options._logFilePath);

	run(options);

    return 0;
}


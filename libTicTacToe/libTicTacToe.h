#pragma once

#include <stdio.h>
#include <tchar.h>
#include <string>

namespace libTicTacToe
{
	enum ALGO {
		Q,
		SARSA
	};

	struct OPTIONS {
		int _numEpisodes;
		ALGO _algo;
		std::string _logFilePath;
	};

	OPTIONS getOptions(int argc, char* argv[]);

	void train(OPTIONS& options);

	void initLogging(std::string filePath);
}
#pragma once

#include <stdio.h>
#include <tchar.h>
#include <string>
#include "Player.h"

namespace libTicTacToe
{
	enum ALGO {
		Q,
		SARSA
	};

	struct OPTIONS {
		size_t _numEpisodes;
		ALGO _algo;
		std::string _logFilePath;
	};

	OPTIONS getOptions(int argc, char* argv[]);

	void train(OPTIONS& options);

	void initLogging(std::string filePath);

	void save(CAutoPlayer& player);

}
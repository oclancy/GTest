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

	void play();

	void initLogging(std::string filePath);

	std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

	std::vector<std::string> split(const std::string &s, char delim);
}
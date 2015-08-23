#pragma once
#include "ArtificialIntelligence.h"
#include <memory>

namespace libTicTacToe
{
	const int INVALID_SQUARE = -1;

	const int WIN = 100;
	const int LOSE = -100;
	const int DRAW = -10;

	enum ALGO {
		Q,
		SARSA
	};

	struct OPTIONS {
		size_t _numEpisodes;
		ALGO _algo;
		std::string _logFilePath;
	};

	//OPTIONS getOptions(int argc, char* argv[]);

	void Train();

	void Play();

	//void initLogging(std::string filePath);

	std::vector<std::string>& Split(const std::string &s, char delim, std::vector<std::string> &elems);

	std::vector<std::string> Split(const std::string &s, char delim);

	std::unique_ptr<CArtificialIntelligence> GetArtificialIntelligence(const char id);
}
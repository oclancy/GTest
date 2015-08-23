#pragma once
#include "ArtificialIntelligence.h"
#include <memory>

namespace libTicTacToe
{
	const int INVALID_SQUARE = -1;

	const int WIN = 100;
	const int LOSE = -100;
	const int DRAW = -10;

	void Train();

	void Play();

	std::vector<std::string>& Split(const std::string &s, char delim, std::vector<std::string> &elems);

	std::vector<std::string> Split(const std::string &s, char delim);

	std::unique_ptr<CArtificialIntelligence> GetArtificialIntelligence(const char id);

	void SaveRewardsPerEpisodes(const std::vector<double> ai1, const std::vector<double> ai2);
}
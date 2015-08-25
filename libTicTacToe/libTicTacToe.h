#pragma once
#include "ArtificialIntelligence.h"
#include <memory>

namespace libTicTacToe
{
	/// <summary>
	/// Value of an invalid square
	/// </summary>
	const unsigned int INVALID_SQUARE = -1;

	/// <summary>
	/// The win value
	/// </summary>
	const int WIN = 100;
	/// <summary>
	/// The lose value
	/// </summary>
	const int LOSE = -100;
	/// <summary>
	/// The draw value
	/// </summary>
	const int DRAW = -10;

	/// <summary>
	/// Runs the training environment for algo development
	/// </summary>
	void Train();

	/// <summary>
	/// Allows a human to play against an algo opponent.
	/// </summary>
	void Play();

	/// <summary>
	/// Split a string by specified delimiter into a vector
	/// </summary>
	std::vector<std::string>& Split(const std::string &s, char delim, std::vector<std::string> &elems);

	/// <summary>
	/// Split a string by specified delimiter
	/// </summary>
	std::vector<std::string> Split(const std::string &s, char delim);

	/// <summary>
	/// Factory function to construct a CArtificialIntelligence derived object given a specified char
	/// </summary>
	std::unique_ptr<CArtificialIntelligence> GetArtificialIntelligence(const char id);

	/// <summary>
	/// Persist the current stored rewards-per-episode values to disk for each ai. (Training mode)
	/// </summary>
	std::string SaveRewardsPerEpisodes(const std::vector<double> ai1, const std::vector<double> ai2);

	/// <summary>
	/// Waits for user input
	/// </summary>
	void WaitForUser();
}
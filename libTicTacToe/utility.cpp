#include "stdafx.h"
#include "libTicTacToe.h"
#include "RandomGuesser.h"
#include <memory>
#include "SARSAIntelligence.h"
#include "QlearningIntelligence.h"
#include <time.h>

namespace libTicTacToe
{

	/// <summary>
	/// Saves the rewards per episodes.
	/// </summary>
	/// <param name="ai1">The ai1.</param>
	/// <param name="ai2">The ai2.</param>
	void SaveRewardsPerEpisodes(const std::vector<double> ai1, const std::vector<double> ai2)
	{
		time_t rawtime;
		struct tm timeinfo;
		char buffer[80];

		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);

		strftime(buffer, 25, "%F-%H%M%S.plot", &timeinfo);

		std::ofstream file(buffer, std::ios::out);

		std::stringstream ai1_out_string;
		std::stringstream ai2_out_string;

		for (auto reward : ai1)
			ai1_out_string << reward << ",";
		for (auto reward : ai2)
			ai2_out_string << reward << ",";

		if (file.is_open())
		{
			file << ai1_out_string.rdbuf() << std::endl;
			file << ai2_out_string.rdbuf() << std::endl;
			file.close();
		}
		else
		{
			std::cout << "Unable to open file" << std::endl;
		}
	}

	/// <summary>
	/// Splits the specified string using the delimiter.
	/// source	http://stackoverflow.com/questions/236129/split-a-string-in-c
	/// </summary>
	/// <param name="s">The s.</param>
	/// <param name="delim">The delimiter.</param>
	/// <param name="elems">The elems.</param>
	/// <returns></returns>
	std::vector<std::string>& Split(const std::string &s, char delim, std::vector<std::string> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}


	/// <summary>
	/// Splits the specified string using the delimiter.
	/// </summary>
	/// <param name="s">The s.</param>
	/// <param name="delim">The delimiter.</param>
	/// <returns></returns>
	std::vector<std::string> Split(const std::string &s, char delim) {
		std::vector<std::string> elems;
		Split(s, delim, elems);
		return elems;
	}

	/// <summary>
	/// Gets the artificial intelligence.
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <returns></returns>
	std::unique_ptr<CArtificialIntelligence> GetArtificialIntelligence(const char id)
	{
		switch (id)
		{
		case 'r':
			return std::make_unique<CRandomGuesser>();
		case 'q':
			return std::make_unique<CQLearningIntelligence>();
		case 's':
			return std::make_unique<CSarsaIntelligence>();
		default:
			return std::make_unique<CRandomGuesser>();
		}
	}
}

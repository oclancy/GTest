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
	/// Saves the rewards per episode for each AI to a file named with the current time.
	/// </summary>
	/// <param name="ai1">Ai1 average rewards.</param>
	/// <param name="ai2">Ai2 average rewards.</param>
	/// <returns>The output filename.</returns>
	std::string SaveRewardsPerEpisodes(const std::vector<double> ai1, const std::vector<double> ai2)
	{
		time_t rawtime;
		struct tm timeinfo;
		char buffer[80];

		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);

		strftime(buffer, 25, "%F-%H%M%S.plot", &timeinfo);

		std::ofstream file(buffer, std::ios::out);

		std::stringstream episode_count_out_string;
		std::stringstream ai1_out_string;
		std::stringstream ai2_out_string;
		
		episode_count_out_string << "Episodes count: ";
		for (size_t count = 1; count <= ai1.size(); ++count)
		{
			episode_count_out_string << count * 100 << ",";
		}

		ai1_out_string << "Average reward AI_1: ";
		for (auto reward : ai1)
		{
			ai1_out_string << reward << ",";
		}

		ai2_out_string << "Average reward AI_2: ";
		for (auto reward : ai2)
		{
			ai2_out_string << reward << ",";
		}

		if (file.is_open())
		{
			file << episode_count_out_string.rdbuf() << std::endl;
			file << ai1_out_string.rdbuf() << std::endl;
			file << ai2_out_string.rdbuf() << std::endl;
			file.close();
			return std::string(buffer);
		}
		else
		{
			std::cout << "Unable to open file to persist average reward information." << std::endl;
			return std::string();
		}
	}

	/// <summary>
	/// Splits the specified string using the delimiter.
	/// source	http://stackoverflow.com/questions/236129/split-a-string-in-c
	/// </summary>
	/// <param name="s">The s.</param>
	/// <param name="delim">The delimiter.</param>
	/// <param name="elems">The elems.</param>
	/// <returns>A reference to a vestor of strings</returns>
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
	/// <returns>A vector of strings</returns>
	std::vector<std::string> Split(const std::string &s, char delim) {
		std::vector<std::string> elems;
		Split(s, delim, elems);
		return elems;
	}

	/// <summary>
	/// Gets the requested artificial intelligence.
	/// </summary>
	/// <param name="id">The identifier.</param>
	/// <returns>A unique_ptr to a CArtificialIntelligence derived class</returns>
	std::unique_ptr<CArtificialIntelligence> GetArtificialIntelligence(const char id)
	{
		switch (id)
		{
		case 'q':
			return std::make_unique<CQLearningIntelligence>();
		case 's':
			return std::make_unique<CSarsaIntelligence>();
		default:
			return std::make_unique<CRandomGuesser>();
		}
	}
	
	/// <summary>
	/// Waits for any user input.
	/// </summary>
	void WaitForUser()
	{
		// wait - not optimal but cheapest to impl.
#ifdef _WIN32
		system("pause");
#else
		system("read");
#endif 
	}
}

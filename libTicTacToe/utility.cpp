#include "stdafx.h"
#include "libTicTacToe.h"
#include "RandomGuesser.h"
#include <memory>
#include "SARSAIntelligence.h"
#include "QlearningIntelligence.h"

class CAutoPlayer;

namespace libTicTacToe
{
	//static std::ofstream g_logOs;

	//void Log(std::string& message)
	//{
	//	std::clog << message;
	//}

	//OPTIONS getOptions(int argc, char* argv[])
	//{
	//	OPTIONS retVal;
	//	for (auto param = 1; param < argc; ++param)
	//	{
	//		if (argv[param][0] == '-')
	//		{
	//			switch (argv[param][1])
	//			{
	//			case 'o':
	//				retVal._logFilePath = argv[param] + 2;
	//				break;
	//			//case 'i':
	//			//	retVal._numEpisodes = std::atoi(argv[param] + 2);
	//			//	break;
	//			//case 'a':
	//			//	retVal._algo = (ALGO)std::atoi(argv[param] + 2);
	//			//	break;
	//			default:
	//				char buffer[100];
	//				snprintf(buffer, 100, "Unknown parameter %c", argv[param][1]);
	//				throw std::exception(buffer);
	//			}
	//		}
	//	}

	//	return retVal;
	//}

	//void initLogging(std::string filePath)
	//{
	//	if (!g_logOs.is_open())
	//	{
	//		g_logOs.open(filePath, std::ofstream::out | std::ofstream::app);

	//		if (g_logOs.fail())
	//			throw std::invalid_argument(filePath);

	//		std::clog.rdbuf(g_logOs.rdbuf());
	//	}
	//}

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

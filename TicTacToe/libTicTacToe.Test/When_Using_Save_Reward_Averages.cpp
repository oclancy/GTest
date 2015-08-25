#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../libTicTacToe/libTicTacToe.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace libTicTacToeTest
{		
	using namespace libTicTacToe;

	TEST_CLASS(When_Using_Save_Reward_Episodes)
	{
	public:

		TEST_METHOD(Can_Save)
		{
			auto filename = SaveRewardsPerEpisodes(std::vector<double>{15.1, 35.3}, std::vector<double>{10.2, -27.2});

			std::ifstream file(filename, std::ios::in);

			if (file.is_open())
			{
				std::string line;
				std::getline(file, line);
				Assert::AreEqual(std::string("Episodes count: 100,200,"), line);
				std::getline(file, line);
				Assert::AreEqual(std::string("Average reward AI_1: 15.1,35.3,"), line);
				std::getline(file, line);
				Assert::AreEqual(std::string("Average reward AI_2: 10.2,-27.2,"), line);
				std::getline(file, line);
				Assert::IsTrue(file.eof());
			}
		}
	};
}
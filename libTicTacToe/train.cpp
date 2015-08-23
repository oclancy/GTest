#include "stdafx.h"
#include <memory>
#include "libTicTacToe.h"
#include "Player.h"
#include "Episode.h"

namespace libTicTacToe
{
	void Train()
	{
		char choice;

		std::cout << "Please select algorithm to train for player 1: (s)arsa, (q)learning, (r)andomguesser (default)" << std::endl;
		std::cin >> choice;

		auto ai1 = GetArtificialIntelligence(tolower(choice));

		CAutoPlayer player1('x', *ai1);

		std::cout << "Please select algorithm to train for player 2: (s)arsa, (q)learning, (r)andomguesser (default)" << std::endl;
		std::cin >> choice;

		auto ai2 = GetArtificialIntelligence(tolower(choice));
		CAutoPlayer player2('o', *ai2);

		std::cout << "Please select number of training episodes: ";
		size_t iterations;
		std::cin >> iterations;

		std::vector<double> ai1_average_rewards;
		std::vector<double> ai2_average_rewards;

		for (size_t count = 0; count < iterations; ++count)
		{
			CEpisode::Play(player1, player2);

			if(count % 100==0)
			{
				ai1_average_rewards.push_back(ai1->GetAverageReward());
				ai2_average_rewards.push_back(ai2->GetAverageReward());
			};
		}

		std::cout << "Training session finished. Save? (y/n)";

		std::cin >> choice;

		if (tolower(choice) == 'y')
		{
			std::string filename;
			std::cout << "Enter filename player1:" << std::endl;
			std::cin >> filename;
			ai1->Save(filename);
			
			std::cout << "Enter filename player2:" << std::endl;
			std::cin >> filename;
			ai2->Save(filename);
		}

		std::cout << "Output avg. reward/episode log? (y/n)";

		std::cin >> choice;

		if (tolower(choice) == 'y')
		{
			SaveRewardsPerEpisodes(ai1_average_rewards, ai2_average_rewards);
		}
	}
}
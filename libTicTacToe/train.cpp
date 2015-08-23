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

		for (size_t count=0; count < iterations; ++ count )
			CEpisode::Play(player1, player2);

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

		std::cout << "Output reward/episode log? (y/n)";

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
	}
}
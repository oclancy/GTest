#include "stdafx.h"
#include "libTicTacToe.h"
#include "Player.h"
#include "Episode.h"
#include "RandomGuesser.h"
#include "QlearningIntelligence.h"

namespace libTicTacToe
{
	void train(OPTIONS& options)
	{
		//CRandomGuesser guesser;
		//CRandomGuesser guesser2;

		CQLearningIntelligence guesser;
		CQLearningIntelligence guesser2;

		CAutoPlayer player1('x', guesser);
		CAutoPlayer player2('o', guesser2);

		for (size_t count=0; count < options._numEpisodes; ++ count )
			CEpisode::Play(player1, player2);

		std::cout << "Training session finished. Save? (y/n)";

		std::string input;
		std::cin >> input;

		if (tolower(input[0]) == 'y')
		{
			std::string filename;
			std::cout << "Enter filename player1:" << std::endl;
			std::cin >> filename;
			guesser.Save(filename);
			
			std::cout << "Enter filename player2:" << std::endl;
			std::cin >> filename;
			guesser2.Save(filename);
		}
	}

}
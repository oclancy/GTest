#include "stdafx.h"
#include "libTicTacToe.h"
#include "Player.h"
#include "Episode.h"
#include "ArtificialIntelligence.h"
#include "RandomGuesser.h"

namespace libTicTacToe
{
	void train(OPTIONS& options)
	{
		CRandomGuesser guesser{CModel()};
		CRandomGuesser guesser2{ CModel() };

		CAutoPlayer player1('x', guesser);
		CAutoPlayer player2('o', guesser2);

		for (size_t count=0; count < options._numEpisodes; ++ count )
			CEpisode::Play(player1, player2);

		std::cout << "Training session finished. Save? (y/n)";

		std::string input;
		std::cin >> input;

		if(tolower(input[0]) == 'y' )
			save(player1);
	}
}
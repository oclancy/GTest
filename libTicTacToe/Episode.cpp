#include "stdafx.h"
#include "Episode.h"

namespace libTicTacToe
{
	void CEpisode::Play(CPlayer& player1, CPlayer& player2)
	{
		CBoard board;

		do
		{
			player1.TakeTurn(board);
			player2.TakeTurn(board);
		} while (!board.IsFinished());

		auto winner = board.GetWinner();
		std::cout << "Board state: " << board.GetState().c_str() << std::endl;

		if (winner == ' ')
			std::cout << "Game tied." << std::endl;
		else
			std::cout << "The winner is: " << winner << std::endl;

		player1.Learn(board.GetReward(player1.GetToken()));
		player2.Learn(board.GetReward(player2.GetToken()));
	}

}
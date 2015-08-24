#include "stdafx.h"
#include "Episode.h"

namespace libTicTacToe
{
	/// <summary>
	/// Runs one game of TicTacToe.
	/// </summary>
	/// <param name="player1">The player1.</param>
	/// <param name="player2">The player2.</param>
	void CEpisode::Play(CPlayer& player1, CPlayer& player2)
	{
		CBoard board;

		do
		{
			player1.TakeTurn(board);
			player2.TakeTurn(board);
		} while (!board.IsFinished());

#ifdef _DEBUG
		auto winner = board.GetWinner();
		std::cout << "Board state: " << board.GetState().c_str() << std::endl;

		if (winner == ' ')
			std::cout << "Game tied." << std::endl;
		else
			std::cout << "The winner is: " << winner << std::endl;
#endif

		player1.Learn(board.GetReward(player1.GetToken()));
		player2.Learn(board.GetReward(player2.GetToken()));
	}

}
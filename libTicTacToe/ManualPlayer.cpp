#include "stdafx.h"
#include "ManualPlayer.h"

namespace libTicTacToe
{
	/// <summary>
	/// Takes a turn.
	/// </summary>
	/// <param name="board">The board.</param>
	void CManualPlayer::TakeTurn(CBoard& board)
	{
		auto state = board.GetState();

		std::cout << "Current board state:" << std::endl;
		std::cout << state.substr(0, 3) << std::endl;
		std::cout << state.substr(3, 3) << std::endl;
		std::cout << state.substr(6, 3) << std::endl;

		auto availableSquares = board.GetAvailableSquares();

		std::cout << "Enter square (0-8):" << std::endl;

		int square = libTicTacToe::INVALID_SQUARE;

		while (std::find(availableSquares.begin(), availableSquares.end(), square) == availableSquares.end())
		{
			if (square != libTicTacToe::INVALID_SQUARE)
				std::cout << "Invalid square. Try again." << std::endl;

			std::cin >> square;
		}

		board.SetSquare(_token, square);
	}

	/// <summary>
	/// Implements the abstract base class. No side effects.
	/// </summary>
	/// <param name="reward">The reward.</param>
	void CManualPlayer::Learn(int reward)
	{
	}
}
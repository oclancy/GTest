#include "stdafx.h"
#include "AutoPlayer.h"

namespace libTicTacToe
{
	/// <summary>
	/// Takes the turn.
	/// </summary>
	/// <param name="board">The board.</param>
	void CAutoPlayer::TakeTurn(CBoard& board)
	{
		auto state = board.GetState();
		auto availableSquares = board.GetAvailableSquares();

		if (availableSquares.size() > 0)
		{
			auto square = _ai.SelectSquare(state, availableSquares);
			board.SetSquare(_token, square);
		}
	}

	/// <summary>
	/// Updates the AI with the reward.
	/// </summary>
	/// <param name="reward">The reward.</param>
	void CAutoPlayer::Learn(int reward)
	{
		_ai.UpdateStrategy(reward);
	}

}
#include "stdafx.h"
#include "RandomGuesser.h"

namespace libTicTacToe
{
	/// <summary>
	/// Selects a random move from the available squares.
	/// </summary>
	/// <param name="state">The state.</param>
	/// <param name="availableSquares">The available squares.</param>
	/// <returns></returns>
	int CRandomGuesser::SelectSquare(const std::string state, const std::vector<int>& availableSquares)
	{
		std::uniform_int_distribution<int> distribution(0, availableSquares.size() - 1);
		return availableSquares[distribution(_generator)];
	}

	/// <summary>
	/// Updates the strategy. Does nothing
	/// </summary>
	/// <param name="reward">The reward.</param>
	void CRandomGuesser::UpdateStrategy(int reward)
	{
		// do nothing
	}
}
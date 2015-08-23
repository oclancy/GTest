#include "stdafx.h"
#include "RandomGuesser.h"

namespace libTicTacToe
{
	int CRandomGuesser::SelectSquare(const std::string state, const std::vector<int>& availableSquares)
	{
		std::uniform_int_distribution<int> distribution(0, availableSquares.size() - 1);
		return availableSquares[distribution(_generator)];
	}

	void CRandomGuesser::UpdateStrategy(int reward)
	{
		// do nothing
	}
}
#include "stdafx.h"
#include "Player.h"
#include "ArtificialIntelligence.h"

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

void CAutoPlayer::Learn(int reward)
{
	std::cout << "My token is " << _token << " and my reward is " << reward << std::endl;
	_ai.UpdateStrategy(reward);
}

void CManualPlayer::TakeTurn(CBoard& board)
{
	auto state = board.GetState();

	std::cout << "Current board state:" << std::endl;
	std::cout << state.substr(0, 3) << std::endl;
	std::cout << state.substr(3, 3) << std::endl;
	std::cout << state.substr(6, 3) << std::endl;

	auto availableSquares = board.GetAvailableSquares();

	std::cout << "Enter square (0-8):" << std::endl;

	int square = -1;

	while(std::find(availableSquares.begin(), availableSquares.end(), square) == availableSquares.end() )
	{
		if (square != -1)
			std::cout << "Invalid square. Try again." << std::endl;

		std::cin >> square;
	}
	
	board.SetSquare(_token, square);
}

void CManualPlayer::Learn(int reward)
{
}
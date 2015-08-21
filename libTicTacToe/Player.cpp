#include "stdafx.h"
#include "Player.h"
#include "ArtificialIntelligence.h"

void CAutoPlayer::TakeTurn(CBoard& board)
{
	auto state = board.GetAvailableSquares();
	
	auto square = _ai.SelectSquare(state);

	board.SetSquare(_token, square);
}

void CAutoPlayer::Learn(int reward)
{
	std::cout << "My token is " << _token << " and my reward is " << reward << std::endl;

}
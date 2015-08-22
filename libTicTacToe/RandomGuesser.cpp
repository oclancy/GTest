#include "stdafx.h"
#include "RandomGuesser.h"
#include <random>

int CRandomGuesser::SelectSquare(const std::string state, const std::vector<int>& availableSquares) 
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, availableSquares.size() - 1);
	return availableSquares[distribution(generator)];
}

void CRandomGuesser::UpdateStrategy(int reward)
{
	// do nothing
}

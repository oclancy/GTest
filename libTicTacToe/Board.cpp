#include "stdafx.h"
#include "Board.h"


bool CBoard::SetSquare(char token, int position)
{
	if (_isFinished) return false;

	if (SPACE == _currentState.at(position))
	{
		_currentState[position] = token;

		Check();

		return true;
	}

	return false;
}

std::vector<int> CBoard::GetAvailableSquares() const
{
	std::vector<int> availableSpaces;
	auto index = 0;
	for (auto c : _currentState)
	{
		if (c == ' ')
			availableSpaces.push_back(index);

		++index;
	}

	//RVO
	return availableSpaces;
}

std::string CBoard::GetState() const
{
	return _currentState;
}


bool CBoard::Check()
{
	if (_isFinished)
		return _winner != SPACE;

	// 1st row
	auto sub =_currentState.substr(0, 3);
	if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0])== std::string::npos)
		_winner = sub[0];

	// 2nd row
	sub = _currentState.substr(3, 3);
	if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0])== std::string::npos)
		_winner = sub[0];
	
	// 3rd row
	sub = _currentState.substr(6, 3);
	if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0])== std::string::npos)
		_winner = sub[0];

	// 1st col
	sub = _currentState.substr(0,1) + _currentState.substr(3,1) + _currentState.substr(6,1);
	if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0])== std::string::npos)
		_winner = sub[0];
	
	// 2nd col
	sub = _currentState.substr(1,1) + _currentState.substr(4, 1) + _currentState.substr(7, 1);
	if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0])== std::string::npos)
		_winner = sub[0];

	// 3rd col
	sub = _currentState.substr(2, 1) + _currentState.substr(5, 1) + _currentState.substr(8, 1);
	if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0])== std::string::npos)
		_winner = sub[0];

	// diagonal l to r
	sub = _currentState.substr(0, 1) + _currentState.substr(4, 1) + _currentState.substr(8, 1);
	if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0])== std::string::npos)
		_winner = sub[0];
	// diagonal r to l
	sub = _currentState.substr(2, 1) + _currentState.substr(4, 1) + _currentState.substr(6, 1);
	if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0])== std::string::npos)
		_winner = sub[0];

	_isFinished = _winner != SPACE;

	if (!_isFinished)
		_isFinished = _currentState.find(SPACE) == std::string::npos;

	return _isFinished;
}

bool CBoard::IsFinished() 
{
	if(!_isFinished)
		_isFinished = _currentState.find_first_not_of(SPACE) == std::string::npos;

	return _isFinished;
}

int CBoard::GetReward(char token)
{
	if (!IsFinished())return 0;
	if (_winner == token)return 100; //won
	if (_winner == SPACE)return -5; // Finished, no winner = DRAW
	return -100; //lost
}
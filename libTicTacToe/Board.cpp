#include "stdafx.h"
#include "Board.h"
namespace libTicTacToe
{

	bool CBoard::SetSquare(char token, int position)
	{
		if (_is_finished) return false;

		if (SPACE == _current_state.at(position))
		{
			_current_state[position] = token;

			Check();

			return true;
		}

		return false;
	}

	std::vector<int> CBoard::GetAvailableSquares() const
	{
		std::vector<int> availableSpaces;
		auto index = 0;
		for (auto c : _current_state)
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
		return _current_state;
	}


	bool CBoard::Check()
	{
		if (_is_finished)
			return _winner != SPACE;

		// 1st row
		auto sub = _current_state.substr(0, 3);
		if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0]) == std::string::npos)
			_winner = sub[0];

		// 2nd row
		sub = _current_state.substr(3, 3);
		if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0]) == std::string::npos)
			_winner = sub[0];

		// 3rd row
		sub = _current_state.substr(6, 3);
		if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0]) == std::string::npos)
			_winner = sub[0];

		// 1st col
		sub = _current_state.substr(0, 1) + _current_state.substr(3, 1) + _current_state.substr(6, 1);
		if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0]) == std::string::npos)
			_winner = sub[0];

		// 2nd col
		sub = _current_state.substr(1, 1) + _current_state.substr(4, 1) + _current_state.substr(7, 1);
		if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0]) == std::string::npos)
			_winner = sub[0];

		// 3rd col
		sub = _current_state.substr(2, 1) + _current_state.substr(5, 1) + _current_state.substr(8, 1);
		if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0]) == std::string::npos)
			_winner = sub[0];

		// diagonal l to r
		sub = _current_state.substr(0, 1) + _current_state.substr(4, 1) + _current_state.substr(8, 1);
		if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0]) == std::string::npos)
			_winner = sub[0];
		// diagonal r to l
		sub = _current_state.substr(2, 1) + _current_state.substr(4, 1) + _current_state.substr(6, 1);
		if (sub.find(SPACE) == std::string::npos && sub.find_first_not_of(sub[0]) == std::string::npos)
			_winner = sub[0];

		_is_finished = _winner != SPACE;

		if (!_is_finished)
			_is_finished = _current_state.find(SPACE) == std::string::npos;

		return _is_finished;
	}

	bool CBoard::IsFinished()
	{
		if (!_is_finished)
			_is_finished = _current_state.find_first_not_of(SPACE) == std::string::npos;

		return _is_finished;
	}

	int CBoard::GetReward(char token)
	{
		if (!IsFinished())return 0;
		if (_winner == token)return libTicTacToe::WIN;
		if (_winner == SPACE)return libTicTacToe::DRAW;
		return libTicTacToe::LOSE;
	}
}
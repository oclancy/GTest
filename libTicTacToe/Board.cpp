#include "stdafx.h"
#include "Board.h"
namespace libTicTacToe
{

	/// <summary>
	/// Sets the square if available.
	/// </summary>
	/// <param name="token">The token.</param>
	/// <param name="position">The position.</param>
	/// <returns>Success or fail</returns>
	bool CBoard::SetSquare(char token, int position)
	{
		if (IsFinished()) return false;

		if (position < _current_state.size() && SPACE == _current_state.at(position))
		{
			_current_state[position] = token;

			Check();

			return true;
		}

		return false;
	}

	/// <summary>
	/// Gets the available squares.
	/// </summary>
	/// <returns>The available squares</returns>
	std::vector<int> CBoard::GetAvailableSquares() const
	{
		std::vector<int> availableSpaces;

		if (!_is_finished)
		{
			auto index = 0;
			for (auto c : _current_state)
			{
				if (c == SPACE)
					availableSpaces.push_back(index);

				++index;
			}
		}
		//RVO
		return availableSpaces;
	}

	/// <summary>
	/// Gets the state.
	/// </summary>
	/// <returns>The current state</returns>
	std::string CBoard::GetState() const
	{
		return _current_state;
	}


	/// <summary>
	/// Checks this instance to see if either there is a winner or if the board is still playable.
	/// </summary>
	/// <returns>True if there is a winner or the board is no longer playable</returns>
	bool CBoard::Check()
	{
		if (_is_finished)
			return _is_finished;

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

	/// <summary>
	/// Determines whether this instance is finished. 
	/// DOES NOT determine a stalemate
	/// </summary>
	/// <returns></returns>
	bool CBoard::IsFinished() const
	{
		return _is_finished;
	}

	/// <summary>
	/// Gets the reward.
	/// </summary>
	/// <param name="token">The token.</param>
	/// <returns></returns>
	int CBoard::GetReward(char token) const
	{
		if (!IsFinished())return 0;
		if (_winner == token)return WIN;
		if (_winner == SPACE)return DRAW;
		return LOSE;
	}
}
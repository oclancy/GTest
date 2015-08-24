#pragma once

namespace libTicTacToe
{
	/// <summary>
	/// Represents a game of tictactoe
	/// Board is implemented as a string of 9 chars
	/// </summary>
	class CBoard
	{
	public:
		CBoard() :_current_state(9, SPACE) {};

		~CBoard() {};

		bool SetSquare(char token, int position);

		std::vector<int> GetAvailableSquares() const;

		std::string GetState() const;

		bool Check();

		bool IsFinished()const;

		int GetReward(char token)const;

		char GetWinner() const { return _winner; };

		static const char SPACE = ' ';
	
	private:
		
		std::string _current_state;

		bool _is_finished = false;

		char _winner = SPACE;
	};

}
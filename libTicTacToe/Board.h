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
		/// <summary>
		/// Initializes a new instance of the <see cref="CBoard"/> class.
		/// </summary>
		CBoard() :_current_state(9, SPACE) {};

		/// <summary>
		/// Finalizes an instance of the <see cref="CBoard"/> class.
		/// </summary>
		~CBoard() {};

		bool SetSquare(char token, int position);

		std::vector<int> GetAvailableSquares() const;

		std::string GetState() const;

		bool Check();

		bool IsFinished()const;

		int GetReward(char token)const;

		char GetWinner() const { return _winner; };

		/// <summary>
		/// The represents a free square
		/// </summary>
		static const char SPACE = ' ';
	
	private:
				
		/// <summary>
		/// The _current_state
		/// </summary>
		std::string _current_state;

		/// <summary>
		/// Whether the games is playable
		/// </summary>
		bool _is_finished = false;

		/// <summary>
		/// The _winner default is DRAW value
		/// </summary>
		char _winner = SPACE;
	};

}
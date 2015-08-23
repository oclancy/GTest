#pragma once

namespace libTicTacToe
{
	class CBoard
	{

	public:
		CBoard() :_current_state(9, SPACE) {};

		~CBoard() {};

		bool SetSquare(char token, int position);

		std::vector<int> GetAvailableSquares() const;

		std::string GetState() const;

		bool Check();

		bool IsFinished();

		int GetReward(char token);

		char GetWinner() const { return _winner; };

	private:
		static const char SPACE = ' ';

		std::string _current_state;

		bool _is_finished = false;

		char _winner = SPACE;
	};

}
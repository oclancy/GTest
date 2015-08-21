#pragma once
#include <vector>

class CBoard
{

public:
	CBoard():_currentState(9, SPACE) {};

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

	std::string _currentState;

	bool _isFinished = false;

	char _winner = SPACE;
};


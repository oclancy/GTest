#pragma once
#include "Player.h"

namespace libTicTacToe
{
	/// <summary>
	/// Runs one game of TicTacToe
	/// </summary>
	class CEpisode
	{
	public:
		static void Play(CPlayer& player1, CPlayer& player2);
	};

}
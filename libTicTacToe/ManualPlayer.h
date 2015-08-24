#pragma once
#include "Player.h"

namespace libTicTacToe
{
	/// <summary>
	/// Interactive implementation of CPlayer .
	/// </summary>
	class CManualPlayer : public CPlayer
	{
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="CManualPlayer"/> class.
		/// </summary>
		/// <param name="token">The token.</param>
		CManualPlayer(char token)
			: CPlayer(token)
		{}

		void TakeTurn(CBoard& board) override final;
		void Learn(int reward) override final;

	};
}
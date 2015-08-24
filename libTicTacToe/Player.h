#pragma once
#include "Board.h"


namespace libTicTacToe
{
	/// <summary>
	/// Abtsract base class of TicTacToe players
	/// </summary>
	class CPlayer
	{
	protected:
		/// <summary>
		/// Initializes a new instance of the <see cref="CPlayer"/> class.
		/// </summary>
		/// <param name="token">The token.</param>
		CPlayer(char token) :_token(token) {};

	public:
		/// <summary>
		/// Finalizes an instance of the <see cref="CPlayer"/> class.
		/// </summary>
		virtual ~CPlayer()
		{
		}

		virtual void TakeTurn(CBoard& board) = 0;

		virtual void Learn(int reward) = 0;

		/// <summary>
		/// Gets the token.
		/// </summary>
		/// <returns></returns>
		char GetToken() const { return _token; };

	protected:
		/// <summary>
		/// The _token of the player on the board
		/// </summary>
		const char _token;
	};

}
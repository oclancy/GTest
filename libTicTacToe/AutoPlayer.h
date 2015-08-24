#include "Player.h"
#include "ArtificialIntelligence.h"

namespace libTicTacToe
{
	/// <summary>
	/// Implementation of CPlayer that uses an AI instance to play the game.
	/// </summary>
	class CAutoPlayer : public CPlayer
	{
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="CAutoPlayer"/> class.
		/// </summary>
		/// <param name="token">The token.</param>
		/// <param name="ai">The ai.</param>
		CAutoPlayer(char token, CArtificialIntelligence& ai)
			: CPlayer(token), _ai(ai)
		{}

		void TakeTurn(CBoard& board) override final;
		void Learn(int reward) override final;

	private:
		/// <summary>
		/// The AI to use to play the game
		/// </summary>
		CArtificialIntelligence& _ai;
	};
}
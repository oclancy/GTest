#pragma once
#include "ArtificialIntelligence.h"

namespace libTicTacToe
{
	/// <summary>
	/// An implementation of the CArtificialIntelligence base that provides no intelligence
	/// </summary>
	class CRandomGuesser : public CArtificialIntelligence
	{
	public:
		virtual int SelectSquare(const std::string state, const std::vector<int>& availableSquares) override final;

		virtual void UpdateStrategy(int reward) override final;

		/// <summary>
		/// Implements base class interface. No side effects.
		/// </summary>
		/// <param name="filename">The filename.</param>
		void Load(const std::string& filename)  override final {};

		/// <summary>
		/// Implements base class interface. No side effects.
		/// </summary>
		/// <param name="filename">The filename.</param>
		void Save(const std::string& filename)  override final {};
	};

}
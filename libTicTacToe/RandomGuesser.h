#pragma once
#include "ArtificialIntelligence.h"

namespace libTicTacToe
{
	class CRandomGuesser : public CArtificialIntelligence
	{
	public:
		virtual int SelectSquare(const std::string state, const std::vector<int>& availableSquares) override final;

		virtual void UpdateStrategy(int reward) override final;

		void Load(const std::string& filename)  override final {};

		void Save(const std::string& filename)  override final {};
	};

}
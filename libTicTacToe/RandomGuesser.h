#pragma once
class CRandomGuesser : public CArtificialIntelligence
{
public:
	explicit CRandomGuesser(CModel& model)
		:CArtificialIntelligence(model) {}

	virtual int SelectSquare(const std::vector<int>& availableSquares) const override final;
};

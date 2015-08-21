#pragma once
#include "Model.h"
#include <vector>
#include <tuple>

class CArtificialIntelligence
{
protected:
	const CModel& _model;

public:
	CArtificialIntelligence(CModel& model)
		: _model(model){}

	virtual ~CArtificialIntelligence() {};

	virtual int SelectSquare(const std::vector<int>& availableSquares) const = 0;

};



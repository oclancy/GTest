#pragma once
#include <vector>
#include <tuple>

class CArtificialIntelligence
{
protected:
	typedef std::vector<std::tuple<std::string, int>> Moves;
	// move log per episode
	Moves _moves;

public:
	CArtificialIntelligence() {};
		
	virtual ~CArtificialIntelligence() {};

	virtual int SelectSquare(const std::string state, const std::vector<int>& availableSquares) = 0;

	virtual void UpdateStrategy(int reward) = 0;

	virtual void Load(const std::string& filename) = 0;
	
	virtual void Save(const std::string& filename) = 0;
};



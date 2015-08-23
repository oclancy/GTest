#pragma once
#include <map>
#include <memory>
#include "ArtificialIntelligence.h"

namespace libTicTacToe
{
	class CSarsaIntelligence : public CArtificialIntelligence
	{
		typedef std::tuple<std::string, int> StateAction;
		//typedef std::tuple<StateAction, double> StateActionValue;

		struct StateActionValue
		{
			StateActionValue(std::string s, int a, double v)
				:state(s),
				action(a),
				value(v) {}

			std::string state;
			int action;
			double value;
		};

		//struct StateAction
		//{
		//	StateAction(std::string s, int a)
		//		:state(s),
		//		action(a){}

		//	std::string state;
		//	int action;
		//};

		typedef std::vector<std::shared_ptr<StateActionValue>> StateActionValueVector;
		// map of StateAction to 'StateAction
		typedef std::map<StateAction, std::vector<std::shared_ptr<StateActionValue>>> Strategy;

		// map of state to vector of action-values
		Strategy _strategy;

		typedef std::tuple<std::string, int> Move;
		typedef std::vector<Move> Moves;

	protected:
		std::vector<std::tuple<std::string, int>> _movesInEpisode;

	public:
		virtual int SelectSquare(const std::string state, const std::vector<int>& available_squares) override final;

		virtual void UpdateStrategy(int reward) override final;

		void Load(const std::string& filename)  override final;

		void Save(const std::string& filename) override final;
	};

}
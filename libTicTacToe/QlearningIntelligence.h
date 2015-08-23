#pragma once
#include <map>
#include <memory>
#include "ArtificialIntelligence.h"
namespace libTicTacToe
{
	class CQLearningIntelligence : public CArtificialIntelligence
	{
	public:

		struct ActionValue
		{
			ActionValue(int a, double v)
				:action(a),
				value(v) {}

			int action;
			double value;
		};

		typedef std::vector<std::shared_ptr<ActionValue>> ActionValueVector;

		typedef std::map<std::string, ActionValueVector> Strategy;

		// map of state to vector of action-values
		Strategy _strategy;

		typedef std::tuple<std::string, int> Move;
		typedef std::vector<Move> Moves;

		// move log per episode
		/// <summary>
		/// The _moves
		/// </summary>
		Moves _movesInEpisode;

	public:
		virtual int SelectSquare(const std::string state, const std::vector<int>& available_squares) override final;

		virtual void UpdateStrategy(int reward) override final;

		virtual void Load(const std::string& filename) override final;

		virtual void Save(const std::string& filename) override final;
	};

}
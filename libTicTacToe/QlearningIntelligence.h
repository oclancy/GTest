#pragma once
#include <map>
#include <memory>
#include "ArtificialIntelligence.h"

namespace libTicTacToe
{
	/// <summary>
	/// Artificial Intelligence that implements the Q-Learning algorithm
	/// </summary>
	class CQLearningIntelligence : public CArtificialIntelligence
	{
	private:
		/// <summary>
		/// Stores action and value for a given state
		/// </summary>
		struct ActionValue
		{
			ActionValue(int a, double v)
				:action(a),
				 value(v)
			{
			}

			int action;
			double value;
		};

		typedef std::vector<std::shared_ptr<ActionValue>> ActionValueVector;

		// the rate at which the AI learns
		double _learning_rate = 0.1;
		// the discount factor
		double _discount_factor = 0.9;

	protected:
		typedef std::map<std::string, ActionValueVector> Strategy;
		// map of state to vector of action-values
		Strategy _strategy;

		double CalculateQValue(double existing_value, double reward) const;

	public:
		virtual unsigned int SelectSquare(const std::string state, const std::vector<unsigned int>& available_squares) override final;

		virtual void UpdateStrategy(int reward) override final;

		virtual void Load(const std::string& filename) override final;

		virtual void Save(const std::string& filename) override final;
	};
}

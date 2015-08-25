#include "stdafx.h"
#include "QlearningIntelligence.h"


namespace libTicTacToe
{
	/// <summary>
	/// Calculates the q value.
	/// </summary>
	/// <param name="existing_value">The existing_value.</param>
	/// <param name="reward">The reward.</param>
	/// <returns></returns>
	double CQLearningIntelligence::CalculateQValue(double existing_value, double reward) const
	{
		//dReward = existing_value + _learning_rate * (dReward * _discount_factor - existing_value);
		return  existing_value + _learning_rate * (reward * _discount_factor - existing_value);
	}

	/// <summary>
	/// Selects the square.
	/// </summary>
	/// <param name="state">The state.</param>
	/// <param name="available_squares">The available_squares.</param>
	/// <returns>
	/// The selected square
	/// </returns>
	unsigned int CQLearningIntelligence::SelectSquare(const std::string state, const std::vector<unsigned int>& available_squares)
	{
		auto square = INVALID_SQUARE;
		auto iter = _strategy.find(state);

		if (iter != _strategy.end())
		{
			std::vector<int> best_moves;
			double action_max_value = 0;
			for (auto action_value : iter->second)
			{
				if (action_value->value > action_max_value)
				{
					// clear and add
					best_moves.clear();
					best_moves.push_back(action_value->action);
				}
				else if (action_value->value == action_max_value)
				{
					best_moves.push_back(action_value->action);
				}
			}

			if (best_moves.size() == 1)
			{
				square = best_moves[0];
			}
			else if (best_moves.size() > 1)
			{
				std::uniform_int_distribution<int> distribution(0, best_moves.size() - 1);
				square = best_moves[distribution(_generator)];
			}
		}

		// todo: could add exploration here and ignore selected square.
		if (square == INVALID_SQUARE)
		{
			// no strategy so select random value from available
			std::uniform_int_distribution<int> distribution(0, available_squares.size() - 1);
			square = available_squares[distribution(_generator)];
		}

		// store decision
		_movesInEpisode.emplace_back(make_tuple(state, square));

		return square;
	}

	/// <summary>
	/// Updates the strategy.
	/// Iterate backwards through the moves made from each state and set the value
	/// </summary>
	/// <param name="reward">The reward.</param>
	void CQLearningIntelligence::UpdateStrategy(int reward)
	{
		auto dreward = static_cast<double>(reward);

		UpdateRewardAverage(dreward);

		auto rit = _movesInEpisode.rbegin();
		for (; rit != _movesInEpisode.rend(); ++rit)
		{
			auto episode_state_move = *rit;

			// get state vector of move-value pairs
			auto state = std::get<0>(episode_state_move);
			auto action = std::get<1>(episode_state_move);
			auto iter = _strategy.find(state);

			if (iter != _strategy.end())
			{
				auto bFound = false;
				// try and find existing move-value pair in this state for this move
				for (auto action_value : iter->second)
				{
					if (action_value->action == action)
					{
						bFound = true;
						auto existing_value = action_value->value;
						// calculate
						action_value->value = CalculateQValue(existing_value, dreward);
						//existing_value = value;
						break;
					}
				}

				if (!bFound)
				{
					auto value = CalculateQValue(0, dreward);
					iter->second.emplace_back(std::make_shared<ActionValue>(action, value));
				}
			}
			else
			{
				ActionValueVector action_values;
				auto value = CalculateQValue(0, dreward);
				action_values.push_back(std::make_shared<ActionValue>(action, value));
				_strategy.emplace(state, action_values);
			}
		}

		// reset for next episode
		_movesInEpisode.clear();
	}

	/// <summary>
	/// Loads the specified filename in to the strategy.
	/// </summary>
	/// <param name="filename">The filename.</param>
	void CQLearningIntelligence::Load(const std::string& filename)
	{
		std::ifstream file(filename, std::ios::in);

		_strategy.clear();

		if (file.is_open())
		{
			while (!file.eof())
			{
				std::string line;
				getline(file, line);
				std::vector<std::string> splitline;
				Split(line, ';', splitline);
				if (splitline.size() > 0)
				{
					std::vector<std::string> splitline2;
					Split(splitline[1], '|', splitline2);
					if (splitline2.size() > 0)
					{
						ActionValueVector action_values_for_state;
						for (auto actionValueStr : splitline2)
						{
							std::vector<std::string> action_value;
							Split(actionValueStr, ':', action_value);

							action_values_for_state.emplace_back(std::make_shared<ActionValue>(atoi(action_value[0].c_str()), atof(action_value[1].c_str())));
						}
						_strategy.emplace(splitline[0], action_values_for_state);
					}
				}
			}
			file.close();
		}
		else
		{
			std::cout << "Unable to open file to load training data" << std::endl;
		}

	}

	/// <summary>
	/// Saves the strategy to the specified filename.
	/// </summary>
	/// <param name="filename">The filename.</param>
	void CQLearningIntelligence::Save(const std::string& filename)
	{
		std::ofstream file(filename, std::ios::out);

		if (file.is_open())
		{
			for (auto state : _strategy)
			{
				file << state.first << ";";
				for (auto action_value : state.second)
				{
					file << action_value->action << ":" << action_value->value << "|";
				}
				file << std::endl;
			}
			file.close();
		}
		else
		{
			std::cout << "Unable to open file to persist training data" << std::endl;
		}

	}
}
#include "stdafx.h"
#include "SARSAIntelligence.h"

namespace libTicTacToe
{
	/// <summary>
	/// Selects the square.
	/// </summary>
	/// <param name="state">The state.</param>
	/// <param name="availableSquares">The available squares.</param>
	/// <returns></returns>
	int CSarsaIntelligence::SelectSquare(const std::string state, const std::vector<int>& available_squares)
	{
		auto square = libTicTacToe::INVALID_SQUARE;

		std::vector<int> best_moves;
		double action_max_value = 0;

		for (auto available_square : available_squares)
		{
			StateAction state_action_to_find{ state, available_square };

			auto state_action_vector_iter = _strategy.find(state_action_to_find);
			if (state_action_vector_iter != _strategy.end())
			{
				auto vector_of_state_action_values = state_action_vector_iter->second;

				for (auto state_action_value : vector_of_state_action_values)
				{
					if (state_action_value->value > action_max_value)
					{
						// clear and add
						best_moves.clear();
						best_moves.push_back(available_square);
					}
					else if (state_action_value->value == action_max_value)
					{
						best_moves.push_back(available_square);
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
		}

		// todo: could add exploration here and ignore selected square.
		if (square == libTicTacToe::INVALID_SQUARE)
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
	void CSarsaIntelligence::UpdateStrategy(int reward)
	{
		auto dreward = static_cast<double>(reward);
		
		UpdateRewardAverage(dreward);

		auto rit = _movesInEpisode.rbegin();

		auto move = *rit;

		while (rit != _movesInEpisode.rend())
		{
			++rit;

			if (rit == _movesInEpisode.rend())
				break;

			auto from = *rit;

			StateAction state_action_to_find(std::get<0>(from), std::get<1>(from));
			auto existing_state_action_iter = _strategy.find(state_action_to_find);
			if (existing_state_action_iter != _strategy.end())
			{
				auto searchState = std::get<0>(move);
				auto searchAction = std::get<1>(move);

				auto bFound = false;
				for (auto state_action_value : existing_state_action_iter->second)
				{
					if (state_action_value->state == searchState && state_action_value->action == searchAction)
					{
						bFound = true;
						auto existing_value = state_action_value->value;
						//dReward = existing_value + 0.1 * (dReward * 0.9 - existing_value);
						//existing_value = dReward;
						state_action_value->value = existing_value + 0.1 * (dreward * 0.9 - existing_value);
						break;
					}
				}

				if (!bFound)
				{
					//dReward = 0.1 * (dReward * 0.9);
					auto value = 0.1 * (dreward * 0.9);
					auto newStateActionValue = std::make_shared<StateActionValue>(searchState, searchAction, value);
					existing_state_action_iter->second.push_back(newStateActionValue);
				}
			}
			else
			{
				StateActionValueVector vector_of_state_action_values;
				//dReward = 0.1 * (dReward * 0.9);
				auto value = 0.1 * (dreward * 0.9);
				vector_of_state_action_values.push_back(std::make_shared<StateActionValue>(std::get<0>(move), std::get<1>(move), value));
				_strategy.emplace(StateAction(std::get<0>(from), std::get<1>(from)), vector_of_state_action_values);
			}

			move = from;
		}

		// reset for next episode
		_movesInEpisode.clear();
	}

	/// <summary>
	/// Loads the specified filename in to the strategy.
	/// </summary>
	/// <param name="filename">The filename.</param>
	void CSarsaIntelligence::Load(const std::string& filename)
	{
		std::ifstream file(filename, std::ios::in);

		_strategy.clear();

		if (file.is_open())
		{
			while (!file.eof())
			{
				std::string line;
				std::getline(file, line);
				std::vector<std::string> splitline;
				Split(line, ';', splitline);
				if (splitline.size() > 0)
				{
					// the state action
					std::vector<std::string> splitline1;
					Split(splitline[0], ':', splitline1);
					if (splitline1.size() == 2)
					{
						StateAction state_action(splitline1[0], atoi(splitline1[1].c_str()));

						//the state action values
						std::vector<std::string> splitline2;
						Split(splitline[1], '|', splitline2);
						if (splitline2.size() > 0)
						{
							StateActionValueVector state_action_values_for_state;
							for (auto action_value_str : splitline2)
							{
								std::vector<std::string> state_action_value;
								Split(action_value_str, ':', state_action_value);

								if (state_action_value.size() == 3)
									state_action_values_for_state.push_back(std::make_shared<StateActionValue>(state_action_value[0], atoi(state_action_value[1].c_str()), atof(state_action_value[2].c_str())));
							}

							_strategy.emplace(state_action, state_action_values_for_state);
						}
					}
				}
			}
			file.close();
		}
		else
		{
			std::cout << "Unable to open file" << std::endl;
		}

	}

	/// <summary>
	/// Saves the strategy to the specified filename.
	/// </summary>
	/// <param name="filename">The filename.</param>
	void CSarsaIntelligence::Save(const std::string& filename)
	{
		std::ofstream file(filename, std::ios::out);

		if (file.is_open())
		{
			for (auto state_action : _strategy)
			{
				// state:action;
				file << std::get<0>(state_action.first) << ":" << std::get<1>(state_action.first) << ";";
				for (auto state_action_value : state_action.second)
				{
					// state:action:value | state:action:value | ......
					file << state_action_value->state << ":" << state_action_value->action << ":" << state_action_value->value << "|";
				}
				file << std::endl;
			}
			file.close();
		}
		else
		{
			std::cout << "Unable to open file" << std::endl;
		}

	}
}
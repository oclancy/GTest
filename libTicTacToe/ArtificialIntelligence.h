#pragma once
#include <random>

namespace libTicTacToe
{
	/// <summary>
	/// Abstract base class of AIs
	/// </summary>
	class CArtificialIntelligence
	{
	public:
		typedef std::tuple<std::string, int> Move;
		typedef std::vector<Move> Moves;

	protected:
		/// <summary>
		/// Initializes a new instance of the <see cref="CArtificialIntelligence"/> class.
		/// </summary>
		CArtificialIntelligence()
			:_generator(_rd()), _average_reward(0), _iterations(0)
		{
		}

		// random number generation
		std::random_device _rd;
		std::mt19937 _generator;

		// current average
		double _average_reward;
		//iterations played
		int _iterations;



		// move log per episode
		/// <summary>
		/// The _moves
		/// </summary>
		Moves _movesInEpisode;

	public:

		/// <summary>
		/// Finalizes an instance of the <see cref="CArtificialIntelligence"/> class.
		/// </summary>
		virtual ~CArtificialIntelligence() {};

		/// <summary>
		/// Selects the square.
		/// </summary>
		/// <param name="state">The state.</param>
		/// <param name="availableSquares">The available squares.</param>
		/// <returns>The selected square</returns>
		virtual unsigned int SelectSquare(const std::string state, const std::vector<unsigned int>& available_squares) = 0;

		/// <summary>
		/// Updates the strategy.
		/// </summary>
		/// <param name="reward">The reward.</param>
		virtual void UpdateStrategy(int reward) = 0;

		/// <summary>
		/// Loads the specified filename.
		/// </summary>
		/// <param name="filename">The filename.</param>
		virtual void Load(const std::string& filename) = 0;

		/// <summary>
		/// Saves the specified filename.
		/// </summary>
		/// <param name="filename">The filename.</param>
		virtual void Save(const std::string& filename) = 0;

		/// <summary>
		/// Gets the average reward.
		/// </summary>
		/// <returns></returns>
		double GetAverageReward() const { return _average_reward; };

	protected:
		/// <summary>
		/// Updates the reward average.
		/// </summary>
		/// <param name="reward">The reward.</param>
		void UpdateRewardAverage(double reward)
		{
			//update average
			auto temp = _average_reward*_iterations + reward;
			_average_reward = temp / (++_iterations);
		}
	};


}
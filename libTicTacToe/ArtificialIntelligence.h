#pragma once
#include <random>

namespace libTicTacToe
{
	/// <summary>
	/// Abstract base class of ais
	/// </summary>
	class CArtificialIntelligence
	{
	protected:
		/// <summary>
		/// Initializes a new instance of the <see cref="CArtificialIntelligence"/> class.
		/// </summary>
		CArtificialIntelligence()
			:_generator(_rd())
		{
		}

		std::random_device _rd;
		std::mt19937 _generator;

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
		/// <returns></returns>
		virtual int SelectSquare(const std::string state, const std::vector<int>& available_squares) = 0;

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
	};


}
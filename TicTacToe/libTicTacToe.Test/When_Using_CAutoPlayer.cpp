#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../libTicTacToe/QlearningIntelligence.h"
#include "../../libTicTacToe/Board.h"
#include "../../libTicTacToe/AutoPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace libTicTacToeTest
{		
	using namespace libTicTacToe;

	/// <summary>
	/// Mock AI class to help with testing
	/// </summary>
	class MockAi : public CArtificialIntelligence
	{
	public:
		int _updateStrategyReward;
		bool _selectSquareCalled;
		
		/// <summary>
		/// Selects the square.
		/// </summary>
		/// <param name="state">The state.</param>
		/// <param name="availableSquares">The available squares.</param>
		/// <returns></returns>
		virtual unsigned int SelectSquare(const std::string state, const std::vector<unsigned int>& availableSquares) override final
		{
			_selectSquareCalled = true;
			return 1;
		};

		/// <summary>
		/// Updates the strategy.
		/// </summary>
		/// <param name="reward">The reward.</param>
		virtual void UpdateStrategy(int reward) override final
		{
			_updateStrategyReward = reward;
		};

		/// <summary>
		/// Implements base class interface. No side effects.
		/// </summary>
		/// <param name="filename">The filename.</param>
		void Load(const std::string& filename)  override final {};

		/// <summary>
		/// Implements base class interface. No side effects.
		/// </summary>
		/// <param name="filename">The filename.</param>
		void Save(const std::string& filename)  override final {};
	};


	TEST_CLASS(When_Using_AutoPlayer)
	{
	public:
				
		TEST_METHOD(Can_Take_Turn)
		{
			CBoard test_board;
			MockAi test_ai;
			CAutoPlayer test_player('x', test_ai);

			test_player.TakeTurn(test_board);

			Assert::AreEqual(std::string(" x       "), test_board.GetState());
			Assert::IsTrue(test_ai._selectSquareCalled);
		}

		TEST_METHOD(Can_Update_Ai)
		{
			MockAi test_ai;
			CAutoPlayer test_player('x', test_ai);

			test_player.Learn(1);

			Assert::AreEqual(1, test_ai._updateStrategyReward);
		}

		TEST_METHOD(Can_Get_Token)
		{
			MockAi test_ai;
			CAutoPlayer test_player('x', test_ai);

			Assert::AreEqual('x', test_player.GetToken());
		}

	};
}
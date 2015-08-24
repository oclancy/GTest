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
	/// Mock ASI class t help with testing
	/// </summary>
	class MockAi : public CArtificialIntelligence
	{
	public:
		int _updateStrategyReward;
		bool _selectSquareCalled;
		
		virtual int SelectSquare(const std::string state, const std::vector<int>& availableSquares) override final
		{
			_selectSquareCalled = true;
			return 1;
		};

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
			CBoard testBoard;
			MockAi testAi;
			CAutoPlayer testPlayer('x', testAi);

			testPlayer.TakeTurn(testBoard);

			Assert::AreEqual(std::string(" x       "), testBoard.GetState());
			Assert::IsTrue(testAi._selectSquareCalled);
		}

		TEST_METHOD(Can_Update_Ai)
		{
			MockAi testAi;
			CAutoPlayer testPlayer('x', testAi);

			testPlayer.Learn(1);

			Assert::AreEqual(1, testAi._updateStrategyReward);
		}

		TEST_METHOD(Can_Get_Token)
		{
			MockAi testAi;
			CAutoPlayer testPlayer('x', testAi);

			Assert::AreEqual('x', testPlayer.GetToken());
		}

	};
}
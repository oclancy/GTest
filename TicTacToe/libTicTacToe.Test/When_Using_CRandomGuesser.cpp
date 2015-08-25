#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../libTicTacToe/Board.h"
#include "../../libTicTacToe/libTicTacToe.h"
#include "../../libTicTacToe/RandomGuesser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace libTicTacToeTest
{		
	using namespace libTicTacToe;

	TEST_CLASS(When_Using_CRandomGuesser)
	{
	public:

		TEST_METHOD(Can_Select_Square)
		{
			CBoard test_board;
			CRandomGuesser test_ai;

			auto square = test_ai.SelectSquare(test_board.GetState(), test_board.GetAvailableSquares());

			Assert::AreNotEqual(square, INVALID_SQUARE);
		}

		TEST_METHOD(Can_Get_Reward_Average)
		{
			CRandomGuesser test_ai;

			test_ai.UpdateStrategy(WIN);
			Assert::AreEqual(double(100), test_ai.GetAverageReward());
			test_ai.UpdateStrategy(DRAW);
			Assert::AreEqual(double(45), test_ai.GetAverageReward());
		}
	};
}
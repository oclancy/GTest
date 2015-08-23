#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../libTicTacToe/QlearningIntelligence.h"
#include "../../libTicTacToe/Board.h"
#include "../../libTicTacToe/libTicTacToe.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace libTicTacToeTest
{		
	using namespace libTicTacToe;

	TEST_CLASS(When_Using_CQLearningIntelligence)
	{
	public:
				
		TEST_METHOD(Can_Select_Square)
		{
			CBoard testBoard;
			CQLearningIntelligence testAi;

			auto square = testAi.SelectSquare(testBoard.GetState(), testBoard.GetAvailableSquares());

			Assert::AreNotEqual(square, INVALID_SQUARE);
		}

	};
}
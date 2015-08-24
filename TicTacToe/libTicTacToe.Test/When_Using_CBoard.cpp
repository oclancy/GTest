#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../libTicTacToe/Board.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace libTicTacToeTest
{		
	using namespace libTicTacToe;


	TEST_CLASS(When_Using_CBoard)
	{
	public:

		const char _drawBoard[9] = {'o','o', 'x', 'x', 'x', 'o', 'o', 'o', 'x'};
		
		TEST_METHOD(Can_Select_Square)
		{
			CBoard testBoard;
			
			Assert::AreEqual(std::string(9, CBoard::SPACE), testBoard.GetState());

			// set all squares
			for (unsigned int index = 0;index < 9;++index)
			{
				Assert::IsTrue(testBoard.SetSquare(_drawBoard[index], index));

				if(index != 8)
					Assert::IsFalse(testBoard.IsFinished());
			}
			Assert::AreEqual(std::string(_drawBoard), testBoard.GetState());
			
			Assert::IsTrue(testBoard.IsFinished());

			// can't set set square
			for (auto index = 0;index < 9;++index)
			{
				Assert::IsFalse(testBoard.SetSquare('z', index));
			}

			Assert::AreEqual(std::string(_drawBoard), testBoard.GetState());

		}

		TEST_METHOD(Cant_Select_Square_Out_Of_Bounds)
		{
			CBoard testBoard;

			Assert::AreEqual(std::string( 9, CBoard::SPACE ), testBoard.GetState());

			Assert::IsFalse(testBoard.SetSquare('x', 9));
		}

		TEST_METHOD(Can_Get_State)
		{
			CBoard testBoard;

			Assert::AreEqual(std::string(9, CBoard::SPACE), testBoard.GetState());
		}

		TEST_METHOD(Can_Get_Available_Squares)
		{
			CBoard testBoard;

			// set all squares

			for (unsigned int index = 0;index < 9;++index )
			{
				Assert::IsTrue(testBoard.SetSquare(_drawBoard[index], index));
				Assert::AreEqual(8-index, testBoard.GetAvailableSquares().size());
			}
		}

		TEST_METHOD(Can_Detect_Win_States)
		{
			// board positions
			//012
			//345
			//678

			std::vector<std::vector<int>> winStates{ 
				{ 0,1,2 }, // row 0
				{ 3,4,5 }, // row 1
				{ 6,7,8 }, // row 2
				{ 0,3,6 }, // col 1
				{ 1,4,7 }, // col 2
				{ 2,5,8 }, // col 3
				{ 0,4,8 }, // diag l-r
				{ 2,4,6 }, // diag r-l
			};

			for( auto winState : winStates)
			{
				CBoard board;
				for(auto square : winState)
				{
					board.SetSquare('x', square);
				}

				Assert::IsTrue(board.IsFinished());
				Assert::AreEqual('x',board.GetWinner());
				Assert::AreEqual(100, board.GetReward('x'));
				Assert::AreEqual(-100, board.GetReward('o'));
			}

		}

		TEST_METHOD(Can_Get_Reward_Win_Lose)
		{
				CBoard board;
				board.SetSquare('x', 0);
				board.SetSquare('x', 1);
				board.SetSquare('x', 2);

				Assert::IsTrue(board.IsFinished());
				Assert::AreEqual('x', board.GetWinner());
				Assert::AreEqual(100, board.GetReward('x'));
				Assert::AreEqual(-100, board.GetReward('o'));
		}

		TEST_METHOD(Can_Get_Reward_Draw)
		{
			CBoard testBoard;
			// set all squares
			for (unsigned int index = 0;index < 9;++index)
			{
				Assert::IsTrue(testBoard.SetSquare(_drawBoard[index], index));
			}
			Assert::AreEqual(std::string(_drawBoard), testBoard.GetState());

			Assert::AreEqual(CBoard::SPACE, testBoard.GetWinner());
			Assert::AreEqual(-10, testBoard.GetReward('x'));
			Assert::AreEqual(-10, testBoard.GetReward('o'));
		}
	};
}
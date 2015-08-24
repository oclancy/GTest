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

		const char _draw_board[9] = {'o','o', 'x', 'x', 'x', 'o', 'o', 'o', 'x'};
		
		TEST_METHOD(Can_Select_Square)
		{
			CBoard test_board;
			
			Assert::AreEqual(std::string(9, CBoard::SPACE), test_board.GetState());

			// set all squares
			for (unsigned int index = 0;index < 9;++index)
			{
				Assert::IsTrue(test_board.SetSquare(_draw_board[index], index));

				if(index != 8)
					Assert::IsFalse(test_board.IsFinished());
			}
			Assert::AreEqual(std::string(_draw_board), test_board.GetState());
			
			Assert::IsTrue(test_board.IsFinished());

			// can't set set square
			for (auto index = 0;index < 9;++index)
			{
				Assert::IsFalse(test_board.SetSquare('z', index));
			}

			Assert::AreEqual(std::string(_draw_board), test_board.GetState());

		}

		TEST_METHOD(Cant_Select_Square_Out_Of_Bounds)
		{
			CBoard test_board;

			Assert::AreEqual(std::string( 9, CBoard::SPACE ), test_board.GetState());

			Assert::IsFalse(test_board.SetSquare('x', 9));
		}

		TEST_METHOD(Can_Get_State)
		{
			CBoard test_board;

			Assert::AreEqual(std::string(9, CBoard::SPACE), test_board.GetState());
		}

		TEST_METHOD(Can_Get_Available_Squares)
		{
			CBoard testBoard;

			// set all squares

			for (unsigned int index = 0;index < 9;++index )
			{
				Assert::IsTrue(testBoard.SetSquare(_draw_board[index], index));
				Assert::AreEqual(8-index, testBoard.GetAvailableSquares().size());
			}
		}

		TEST_METHOD(Can_Detect_Win_States)
		{
			// board positions
			//012
			//345
			//678

			std::vector<std::vector<int>> win_states{ 
				{ 0,1,2 }, // row 0
				{ 3,4,5 }, // row 1
				{ 6,7,8 }, // row 2
				{ 0,3,6 }, // col 1
				{ 1,4,7 }, // col 2
				{ 2,5,8 }, // col 3
				{ 0,4,8 }, // diag l-r
				{ 2,4,6 }, // diag r-l
			};

			for( auto win_state : win_states)
			{
				CBoard board;
				for(auto square : win_state)
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
			CBoard test_board;
			// set all squares
			for (unsigned int index = 0;index < 9;++index)
			{
				Assert::IsTrue(test_board.SetSquare(_draw_board[index], index));
			}
			Assert::AreEqual(std::string(_draw_board), test_board.GetState());

			Assert::AreEqual(CBoard::SPACE, test_board.GetWinner());
			Assert::AreEqual(-10, test_board.GetReward('x'));
			Assert::AreEqual(-10, test_board.GetReward('o'));
		}
	};
}
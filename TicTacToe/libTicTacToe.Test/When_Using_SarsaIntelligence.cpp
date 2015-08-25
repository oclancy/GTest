#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../libTicTacToe/SarsaIntelligence.h"
#include "../../libTicTacToe/Board.h"
#include "../../libTicTacToe/libTicTacToe.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace libTicTacToeTest
{
	using namespace libTicTacToe;

	TEST_CLASS(When_Using_CSarsaIntelligence)
	{
	public:

		/// <summary>
		/// Class derived from the test target to enable testing
		/// </summary>
		class CTestSarsaIntelligence : public CSarsaIntelligence
		{
		public:
			/// <summary>
			/// Provide access to the test subjects moves.
			/// </summary>
			/// <returns>The moves</returns>
			Moves* GetMoves() { return &_movesInEpisode; };

			/// <summary>
			/// Provide access to the test subjects strategy.
			/// </summary>
			/// <returns>The strategy</returns>
			Strategy* GetStrategy() { return &_strategy; };

			/// <summary>
			/// Provide access to the test subjects Q calculation function.
			/// </summary>
			/// <param name="existing_value">The existing_value.</param>
			/// <param name="reward">The reward.</param>
			/// <returns>The Q value</returns>
			double CalculateQ(double existing_value, double reward) const { return CalculateQValue(existing_value, reward); };

		};

		TEST_METHOD(Can_Select_Square)
		{
			CBoard test_board;
			CSarsaIntelligence test_ai;

			auto square = test_ai.SelectSquare(test_board.GetState(), test_board.GetAvailableSquares());

			Assert::AreNotEqual(square, INVALID_SQUARE);
		}


		TEST_METHOD(Can_Calculate_QValue_For_Reward)
		{
			CTestSarsaIntelligence test_ai;

			test_ai.CalculateQ(0, 100);

			Assert::AreEqual(double(9), test_ai.CalculateQ(0, 100));
			Assert::AreEqual(double(17.1), test_ai.CalculateQ(9, 100));
			Assert::AreEqual(double(-9), test_ai.CalculateQ(0, -100));
			Assert::AreEqual(double(-17.1), test_ai.CalculateQ(-9, -100));
		}

		TEST_METHOD(Can_Update_Strategy_And_Use_Strategy_To_Select_Square_Then_Update_Strategy)
		{
			CTestSarsaIntelligence test_instance;

			Assert::AreEqual(double(0), test_instance.GetAverageReward());

			auto moves = test_instance.GetMoves();

			moves->push_back(std::make_tuple("         ", 0));
			moves->push_back(std::make_tuple("xo       ", 4));
			moves->push_back(std::make_tuple("xo xo    ", 6)); // wins the game

			test_instance.UpdateStrategy(WIN);

			auto strategy = test_instance.GetStrategy();
			Assert::AreEqual(size_t(2), strategy->size());

			auto action_state_values = strategy->at(std::make_tuple("         ",0));
			Assert::AreEqual(size_t(1), action_state_values.size());
			auto action_state_value = action_state_values[0];
			Assert::AreEqual(double(9), action_state_value->value);
			Assert::AreEqual(4, action_state_value->action);
			Assert::AreEqual(std::string("xo       "), action_state_value->state);

			action_state_values = strategy->at(std::make_tuple("xo       ",4));
			Assert::AreEqual(size_t(1), action_state_values.size());
			action_state_value = action_state_values[0];
			Assert::AreEqual(double(9), action_state_value->value);
			Assert::AreEqual(6, action_state_value->action);
			Assert::AreEqual(std::string("xo xo    "), action_state_value->state);

			Assert::AreEqual(size_t(0), moves->size());

			Assert::AreEqual(double(100), test_instance.GetAverageReward());

			moves->push_back(std::make_tuple("         ", 0));
			moves->push_back(std::make_tuple("xo       ", 4));
			moves->push_back(std::make_tuple("xo xo    ", 6)); // wins the game

			test_instance.UpdateStrategy(WIN);

			Assert::AreEqual(size_t(2), strategy->size());

			action_state_values = strategy->at(std::make_tuple("         ", 0));
			Assert::AreEqual(size_t(1), action_state_values.size());
			action_state_value = action_state_values[0];
			Assert::AreEqual(double(17.1), action_state_value->value);
			Assert::AreEqual(4, action_state_value->action);
			Assert::AreEqual(std::string("xo       "), action_state_value->state);

			action_state_values = strategy->at(std::make_tuple("xo       ", 4));
			Assert::AreEqual(size_t(1), action_state_values.size());
			action_state_value = action_state_values[0];
			Assert::AreEqual(double(17.1), action_state_value->value);
			Assert::AreEqual(6, action_state_value->action);
			Assert::AreEqual(std::string("xo xo    "), action_state_value->state);


			Assert::AreEqual(size_t(0), moves->size());

			Assert::AreEqual(double(100), test_instance.GetAverageReward());
		}

		TEST_METHOD(Can_Save_And_Load_Strategy)
		{
			auto filename("testSarsaStrategySave");
			{
				CTestSarsaIntelligence test_file_save_instance;

				auto moves = test_file_save_instance.GetMoves();

				moves->push_back(std::make_tuple("         ", 0));
				moves->push_back(std::make_tuple("xo       ", 4));
				moves->push_back(std::make_tuple("xo xo    ", 6)); // wins the game

				test_file_save_instance.UpdateStrategy(WIN);

				test_file_save_instance.Save(filename);
			}

			{
				CTestSarsaIntelligence test_file_load_instance;

				test_file_load_instance.Load(filename);

				auto strategy = test_file_load_instance.GetStrategy();
				Assert::AreEqual(size_t(2), strategy->size());

				auto action_state_values = strategy->at(std::make_tuple("         ", 0));
				Assert::AreEqual(size_t(1), action_state_values.size());
				auto action_state_value = action_state_values[0];
				Assert::AreEqual(double(9), action_state_value->value);
				Assert::AreEqual(4, action_state_value->action);
				Assert::AreEqual(std::string("xo       "), action_state_value->state);

				action_state_values = strategy->at(std::make_tuple("xo       ", 4));
				Assert::AreEqual(size_t(1), action_state_values.size());
				action_state_value = action_state_values[0];
				Assert::AreEqual(double(9), action_state_value->value);
				Assert::AreEqual(6, action_state_value->action);
				Assert::AreEqual(std::string("xo xo    "), action_state_value->state);

				Assert::AreEqual(unsigned (4), test_file_load_instance.SelectSquare(std::string("xo       "), std::vector<unsigned int>{2, 3, 4, 5, 6, 7, 8}));
			}
		}

	};
}
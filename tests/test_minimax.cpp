#include "gtest/gtest.h"

#include "ttt_board.h"
#include "player.h"
#include "ttt_minimax.h"


// Make sure the state diff func works
TEST (MinimaxTest, diff_func) {
  ttt_board test_board;
  test_board.make_move(player::O, 0);
  test_board.make_move(player::O, 1);
  test_board.make_move(player::E, 2);
  test_board.make_move(player::O, 3);
  test_board.make_move(player::O, 6);
  test_board.make_move(player::X, 4);
  test_board.make_move(player::X, 5);
  test_board.make_move(player::X, 7);
  test_board.make_move(player::X, 8);
  
  ttt_board test_board1;
  test_board1.make_move(player::O, 0);
  test_board1.make_move(player::O, 1);
  test_board1.make_move(player::O, 2);
  test_board1.make_move(player::O, 3);
  test_board1.make_move(player::O, 6);
  test_board1.make_move(player::X, 4);
  test_board1.make_move(player::X, 5);
  test_board1.make_move(player::X, 7);
  test_board1.make_move(player::X, 8);
  
  int diff_idx = board_diff<board_array> (
    test_board.get_state(),
    test_board1.get_state()
  );
  
  EXPECT_EQ(diff_idx, 2);
}

// Set it up so that the ai has to make only one move to win
// call the recursive funciton directly
TEST (MinimaxTest, one_move) {
  ttt_board test_board;
  test_board.make_move(player::O, 0);
  test_board.make_move(player::O, 1);
  test_board.make_move(player::O, 3);
  test_board.make_move(player::O, 6);
  test_board.make_move(player::X, 4);
  test_board.make_move(player::X, 5);
  test_board.make_move(player::X, 7);
  test_board.make_move(player::X, 8);
  
  int next_state = minimax(test_board, player::O);
  EXPECT_EQ (next_idx, 2);
}

// Set it up so that the ai has to make only one move to win
TEST (MinimaxTest, one_move) {
  ttt_board test_board;
  test_board.make_move(player::O, 0);
  test_board.make_move(player::O, 1);
  test_board.make_move(player::O, 3);
  test_board.make_move(player::O, 6);
  test_board.make_move(player::X, 4);
  test_board.make_move(player::X, 5);
  test_board.make_move(player::X, 7);
  test_board.make_move(player::X, 8);
  
  int next_idx = ttt_minimax(test_board.get_state(), player::O);
  EXPECT_EQ (next_idx, 2);
}

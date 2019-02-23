#include "gtest/gtest.h"

#include "ttt_board.h"
#include "player.h"
#include "ttt_minmax.h"


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
  
  int next_idx = ttt_minimax(board.get_state, player::O);
  EXPECT_EQ (nex_idx, 2);
}

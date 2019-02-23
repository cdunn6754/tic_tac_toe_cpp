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
// board set up with no winner but one move left which will let
// O win:
// O X O
// X E X
// O X O
TEST (DirectMinimaxTest, one_option) {
  ttt_board test_board;
  test_board.make_move(player::O, 0);
  test_board.make_move(player::X, 1);
  test_board.make_move(player::O, 2);
  test_board.make_move(player::X, 3);
  test_board.make_move(player::X, 5);
  test_board.make_move(player::O, 6);
  test_board.make_move(player::X, 7);
  test_board.make_move(player::O, 8);

  // At first the center is unset
  EXPECT_EQ (test_board.get_state()[4], player::E);
  
  board_array next_state = minimax(
    test_board,
    player::O
  ).first.get_state();
  
  // Center is the right move and is set by minimax
  EXPECT_EQ (next_state[4], player::O);
}

// Two ai against eachother. Make sure ai acts to block
// O turn
// O E X
// X E X
// X O O
TEST (DirectMinimaxTest, with_choice) {
  ttt_board test_board;
  test_board.make_move(player::O, 0);
  test_board.make_move(player::X, 2);
  test_board.make_move(player::X, 3);
  test_board.make_move(player::X, 5);
  test_board.make_move(player::X, 6);
  test_board.make_move(player::O, 7);
  test_board.make_move(player::O, 8);
  
  // At first these are unset
  EXPECT_EQ (test_board.get_state()[1], player::E);
  EXPECT_EQ (test_board.get_state()[4], player::E);

  board_array next_state = minimax(test_board, player::O).first.get_state();
  EXPECT_EQ (next_state[4], player::O);
  EXPECT_EQ (next_state[1], player::E);
}

// Set it up so that the ai has to make only one move to win
// O can win in a single move
// O X O
// X E X
// O X O
TEST (MinimaxTest, one_move) {
  ttt_board test_board;
  test_board.make_move(player::O, 0);
  test_board.make_move(player::X, 1);
  test_board.make_move(player::O, 2);
  test_board.make_move(player::X, 3);
  test_board.make_move(player::X, 5);
  test_board.make_move(player::O, 6);
  test_board.make_move(player::X, 7);
  test_board.make_move(player::O, 8);
  
  int next_idx = ttt_minimax(test_board.get_state(), player::O);
  EXPECT_EQ (next_idx, 4);
}

// Set it up so that the ai has to make only one move to win
// this time there is more than one option
// X can win in a single move
// E X O
// X E E
// O X O
TEST (MinimaxTest, one_move_with_options1) {
  ttt_board test_board;
  test_board.make_move(player::X, 1);
  test_board.make_move(player::O, 2);
  test_board.make_move(player::X, 3);
  test_board.make_move(player::O, 6);
  test_board.make_move(player::X, 7);
  test_board.make_move(player::O, 8);
  
  // At first these are unset
  EXPECT_EQ (test_board.get_state()[0], player::E);
  EXPECT_EQ (test_board.get_state()[4], player::E);
  EXPECT_EQ (test_board.get_state()[5], player::E);
  
  int next_idx = ttt_minimax(test_board.get_state(), player::X);
  EXPECT_EQ (next_idx, 4);
}

// Set it up so that the ai has to make only one move to win
// this time there is more than one option
// O can block for a draw
// O X E
// X X O
// O E E
TEST (MinimaxTest, block_for_draw) {
  ttt_board test_board;
  test_board.make_move(player::O, 0);
  test_board.make_move(player::X, 1);
  test_board.make_move(player::X, 3);
  test_board.make_move(player::X, 4);
  test_board.make_move(player::O, 5);
  test_board.make_move(player::O, 6);
  
  // At first these are unset
  EXPECT_EQ (test_board.get_state()[2], player::E);
  EXPECT_EQ (test_board.get_state()[7], player::E);
  EXPECT_EQ (test_board.get_state()[8], player::E);
  
  int next_idx = ttt_minimax(test_board.get_state(), player::O);
  EXPECT_EQ (next_idx, 7);
}

// See if it can think two steps ahead
// O X E
// X X O
// O E E
TEST (MinimaxTest, plan_for_win) {
  ttt_board test_board;
  test_board.make_move(player::O, 0);
  test_board.make_move(player::X, 1);
  test_board.make_move(player::X, 3);
  test_board.make_move(player::X, 4);
  test_board.make_move(player::O, 5);
  test_board.make_move(player::O, 6);
  
  // At first these are unset
  EXPECT_EQ (test_board.get_state()[2], player::E);
  EXPECT_EQ (test_board.get_state()[7], player::E);
  EXPECT_EQ (test_board.get_state()[8], player::E);
  
  int next_idx = ttt_minimax(test_board.get_state(), player::O);
  EXPECT_EQ (next_idx, 7);
}

// Verify that win is selected
// O E X
// X E X
// E O O
TEST (MinimaxTest, plan_for_win_2) {
  ttt_board test_board;
  test_board.make_move(player::O, 0);
  test_board.make_move(player::X, 2);
  test_board.make_move(player::X, 3);
  test_board.make_move(player::X, 5);
  test_board.make_move(player::O, 7);
  test_board.make_move(player::O, 8);
  
  // At first these are unset
  EXPECT_EQ (test_board.get_state()[1], player::E);
  EXPECT_EQ (test_board.get_state()[4], player::E);
  EXPECT_EQ (test_board.get_state()[6], player::E);
  
  int next_idx = ttt_minimax(test_board.get_state(), player::X);
  EXPECT_EQ (next_idx, 4);
}


//#######################################//
// The FullGameSeries is a test suite that ensures,
// that the ai's make the right
// moves from the beginning to the end of a particular game
// O is the human player, whose moves are included in the tests,
// X is the ai.

// Let ai play against itself, should result in draw
TEST (FullGameSeries, full_game) {
  ttt_board test_board;
  player agent = player::X;
  while (test_board.check_winner() == 'N') {
    test_board.make_move(agent, ttt_minimax(test_board.get_state(), agent));
    switch_player_inplace(agent);
  }
  
  // They play eachother to a draw
  EXPECT_EQ (test_board.check_winner(), 'D');
}

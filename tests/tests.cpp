#include "gtest/gtest.h"

#include "ttt_board.h"
#include "player.h"


TEST (BoardTest1, initialization) {
  ttt_board test_board;
  for (const player& p : test_board.get_state()) {
      EXPECT_EQ (p, player::E);
      EXPECT_NE (p, player::X);
      EXPECT_NE (p, player::O);
  }
}

TEST (BoardMove, make_move) {
  // A player can make a move but can not
  ttt_board test_board;
  test_board.make_move(player::O, 3);
  board_array state(test_board.get_state());
  for (std::size_t  idx(0); idx<state.size(); idx++) {
    player p = state[idx];
    if (idx == 3) {
      EXPECT_EQ (p, player::O);
      EXPECT_NE (p, player::X);
      EXPECT_NE (p, player::E);
    }
    else {
      EXPECT_EQ (p, player::E);
      EXPECT_NE (p, player::X);
      EXPECT_NE (p, player::O);
    }
  }
}

TEST (BoardMove, overwite_move){
  // A player can't overwrite a previous move
  ttt_board test_board;
  test_board.make_move(player::O, 3);
  test_board.make_move(player::X, 3);
  EXPECT_EQ (test_board.get_state()[3], player::O);
}

TEST (BoardFinished, finished){
  ttt_board test_board;
  // should be false at this point
  EXPECT_EQ(test_board.check_finished(), false);
  test_board.make_move(player::O, 0);
  test_board.make_move(player::O, 1);
  test_board.make_move(player::O, 2);
  EXPECT_EQ(test_board.check_finished(), false);
  test_board.make_move(player::O, 3);
  test_board.make_move(player::O, 4);
  test_board.make_move(player::O, 5);
  EXPECT_EQ(test_board.check_finished(), false);
  test_board.make_move(player::O, 6);
  test_board.make_move(player::O, 7);
  test_board.make_move(player::O, 8);
  EXPECT_EQ(test_board.check_finished(), true);
}

TEST (BoardWinner, row_winner){
  ttt_board test_board;
  // should be false at this point
  EXPECT_EQ(test_board.check_winner(), 'N');
  test_board.make_move(player::O, 0);
  test_board.make_move(player::O, 1);
  test_board.make_move(player::O, 2);
  EXPECT_EQ(test_board.check_winner(), 'O');
}

TEST (BoardWinner, col_winner){
  ttt_board test_board;
  
  test_board.make_move(player::X, 1);
  test_board.make_move(player::X, 4);
  test_board.make_move(player::X, 7);
  EXPECT_EQ(test_board.check_winner(), 'X');
}

TEST (BoardWinner, diag_winner){
  ttt_board test_board;
  
  test_board.make_move(player::X, 0);
  test_board.make_move(player::X, 4);
  test_board.make_move(player::X, 8);
  EXPECT_EQ(test_board.check_winner(), 'X');
}

TEST (BoardWinner, a_diag_winner){
  ttt_board test_board;
  
  test_board.make_move(player::O, 2);
  test_board.make_move(player::O, 4);
  test_board.make_move(player::O, 6);
  EXPECT_EQ(test_board.check_winner(), 'O');
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

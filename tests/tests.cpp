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

TEST (BoardTest2, make_move) {
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


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

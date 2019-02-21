#ifndef TTT_BOARD
#define TTT_BOARD

#include <array>
#include <iostream>
#include <iomanip>

#include "player.h"

typedef std::array<player, 9> board_array;

class ttt_board {
  board_array state;
  std::string row_decoration;
  
public:
  ttt_board() :
  state{board_array()},
  row_decoration{"|-----|-----|-----|"}
  {
    state.fill(player::E);
  };
  
  // Return const reference to underlying state array.
  board_array get_state();
  // Let player p make a move in board space location (0-8)
  void make_move(player p, int location);
  // See if all of the spaces are taken.
  // Could also just count moves.
  bool check_finished();
  // Check the board for a winner. Returns X or O in the case a winner
  // is found. If the game is completed but there is no winner returns
  // 'D' for draw. Otherwise returns 'N'.
  // board should have a state with only one winner so this needs to be called
  // after every move.
  char check_winner();
  
  // Print a particular board row, either 0,1 or 2.
  void print_row(int row_num);
  void print_board();
  void print_input_error();
  
  
private:
  void set_state(board_array new_state);
  
};


#endif

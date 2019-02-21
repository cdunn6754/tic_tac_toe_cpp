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
  
  board_array get_state();
  void make_move(player p, int location);
  bool check_finished();
  
  // Print a particular board row, either 0,1 or 2.
  void print_row(int row_num);
  void print_board();
  void print_input_error();
  
  
private:
  void set_state(board_array new_state);
  
};


#endif

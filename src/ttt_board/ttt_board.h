#ifndef TTT_BOARD
#define TTT_BOARD

#include <array>

typedef std::array<char,9> board_array;

class ttt_board {
  board_array state;
  
public:
  ttt_board() : state({{'0','1','2','3','4','5','6','7','8'}}) {};
  
  board_array get_state();
  void print_something();
  void set_state(board_array new_state);
  
};


#endif

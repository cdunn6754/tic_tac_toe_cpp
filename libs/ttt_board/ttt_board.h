#ifndef TTT_BOARD
#define TTT_BOARD

#include <array>

#include "player.h"

typedef std::array<player, 9> board_array;

class ttt_board {
  board_array state;
  
public:
  ttt_board() : state{board_array()} {
    state.fill(player::E);
  };
  
  board_array get_state();
  void make_move(player p, int location);
  
  
private:
  void set_state(board_array new_state);
  
};


#endif

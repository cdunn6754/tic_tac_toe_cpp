  #include "ttt_board.h"
  


// Public
board_array ttt_board::get_state(){
    return state;
  }
  
void ttt_board::make_move(player p, int location){
  player location_state = state[location];
  if (location_state == player::E) {
      state[location] = p;
  }
}
  
void ttt_board::set_state(board_array new_state){
    state = new_state;
  }

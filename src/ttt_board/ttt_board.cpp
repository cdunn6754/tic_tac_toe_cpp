  #include "ttt_board.h"
  

board_array ttt_board::get_state(){
    return state;
  }
  
void ttt_board::set_state(board_array new_state){
    state = new_state;
  }

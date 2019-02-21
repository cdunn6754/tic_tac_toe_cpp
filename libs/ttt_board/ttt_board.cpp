  #include "ttt_board.h"
  


// PUBLIC
board_array ttt_board::get_state(){
    return state;
  }
  
void ttt_board::make_move(player p, int location){
  player location_state = state[location];
  if (location_state == player::E) {
      state[location] = p;
  }
  else {
    print_input_error();
  }
}

bool ttt_board::check_finished() {
  for (auto itr = state.begin(); itr != state.end(), itr++){
    if (*itr) == player::E {
      return false;
    }
    return true;
  }
}

char ttt_board::check_winner() {
  if (!check_finished()){
    return false
  }
  
  
}


void ttt_board::print_input_error() {
  std::cout << "That is not a valid selection, choose again" <<
  " make a selection between 0 and 8 that hasn't yet been made."
  << std::endl;
}

void ttt_board::print_row(int row_num) {
  auto itr = state.begin() + 3*row_num;
  
  std::cout << "|" << std::setw(3)
    << player_print(*itr)
    << std::setw(3) << "|" << std::setw(3)
    << player_print(*(++itr))
    << std::setw(3) << "|" << std::setw(3)
    << player_print(*(++itr))
    << std::setw(3) << "|"
    << std::endl;
}
void ttt_board::print_board() {
  std::cout << row_decoration << std::endl;
  print_row(0);
  std::cout << row_decoration << std::endl;
  print_row(1);
  std::cout << row_decoration << std::endl;
  print_row(2);
  std::cout << row_decoration << std::endl;
}


// PRIVATE
void ttt_board::set_state(board_array new_state){
    state = new_state;
  }

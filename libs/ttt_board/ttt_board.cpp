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
  for (auto itr = state.begin(); itr != state.end(); itr++){
    if (*itr == player::E) {
      return false;
    }
  }
    return true;
}

char ttt_board::check_winner() {
  
  // Rows
  for (int i=0; i<3; i++){
    if (state[i*3] == state[i*3 + 1] &&
        state[i*3 + 1] == state[i*3 + 2] &&
        state[i*3 + 2] != player::E)
    {
      return player_print(state[i*3]);
    }

    // Columns
    if (state[i] == state[i+3] &&
        state[i+3] == state[i+6] &&
        state[i+6] != player::E) {
      return player_print(state[i]);
    }
  }
  
  // Diagonal
  if (state[0] == state[4] &&
    state[4] == state[8] &&
    state[8] != player::E) {
      
    return player_print(state[0]);
  }
  if (state[2] == state[4] &&
    state[4] == state[6] &&
    state[6] != player::E) {
      
    return player_print(state[2]);
  }
  
  return check_finished() ? 'D' : 'N';
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

#include <stdexcept>

#include "ttt_board.h"


// PUBLIC

std::string ttt_board::row_decoration = "|-----|-----|-----|";

ttt_board::ttt_board() :
  state{board_array()} {
  state.fill(player::E);
};

ttt_board::ttt_board(const ttt_board& old_board) {
  set_state(old_board.get_state());
}

ttt_board::ttt_board(ttt_board&& old_board) {
  set_state(old_board.get_state());
}
    
ttt_board::ttt_board(const std::array<char, 9>& i_state) :
  state{board_array()} {
  // convert to enum types
  for (std::size_t i = 0; i < state.size(); i++) {
    switch (i_state[i]) {
      case 'E':
        state[i] = player::E;
        break;
      case 'X':
        state[i] = player::X;
        break;
      case 'O':
        state[i] = player::O;
        break;
      default:
        throw std::runtime_error("The board should only contain 'X', 'O', or 'E' entries.");
    }
  }
}

ttt_board::ttt_board(board_array i_state) : state{i_state} {};

ttt_board ttt_board::operator=(const ttt_board& b) {
  state = std::move(b.get_state());
}


board_array ttt_board::get_state() const {
  return state;
}

std::array<char, 9> ttt_board::get_char_state() const {
  std::array<char, 9> char_array;
  
  for (int idx = 0; idx < state.size(); idx++) {
    char_array[idx] = player_to_char(state[idx]);
  }
  return char_array;
}
  
void ttt_board::reset_board(){
  state.fill(player::E);
}

bool ttt_board::make_move(player p, int location){
  player location_state = state[location];
  if (location_state == player::E) {
      state[location] = p;
      return true;
  }
  else {
    print_input_error(location);
    return false;
  }
}

bool ttt_board::check_finished() const {
  for (auto itr = state.begin(); itr != state.end(); itr++){
    if (*itr == player::E) {
      return false;
    }
  }
    return true;
}

char ttt_board::check_winner() const {
  
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

std::vector<unsigned int> ttt_board::empty_indices() {
  std::vector<unsigned int> e_idxs;
  for (std::size_t i = 0; i < state.size(); i++) {
    if (state[i] == player::E) {
      e_idxs.push_back(i);
    }
  }
  return e_idxs;
}

void ttt_board::print_row(int row_num) {
  auto itr = state.begin() + 3*row_num;
  int idx = 3*row_num;
  
  auto print_idx_or_player = [&idx, this]() -> char {
    return (state[idx] == player::E)
      ? '0' + idx++
      : player_print(state[idx++]);
  };
  
  std::cout << "|" << std::setw(3)
    << print_idx_or_player()
    << std::setw(3) << "|" << std::setw(3)
    << print_idx_or_player()
    << std::setw(3) << "|" << std::setw(3)
    << print_idx_or_player()
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

void ttt_board::print_input_error(int selection) {
  std::cout << selection << " is not a valid selection, choose again" <<
  " make a selection between 0 and 8 that hasn't yet been made."
  << std::endl;
}

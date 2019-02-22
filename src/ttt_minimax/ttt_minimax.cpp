#include "ttt_minimax.h"
#include <array>




native_board_array minimax(ttt_board board, player agent) {
  // which indices on the board have yet to be played?
  std::vector<unsigned int> empty_indices = board.empty_indices();
  std::vector<board_array> potential_states;
  
  // for each possibility generate the new state
  for (int idx : empty_indices) {
      board_array state = board.get_state();
      state[idx] = agent;
      potential_states.push_back(std::move(state));
  }
  
  
}

native_board_array ttt_minimax(native_board_array state, const char agent){
  
  ttt_board board{state};
  
  return state;
}

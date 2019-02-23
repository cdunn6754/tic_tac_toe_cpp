#include "ttt_minimax.h"
#include <array>
#include <utility>

board_point  minimax(ttt_board board, const player agent, bool agents_turn=true) {
  // check for terminal state
  char winner = board.check_winner();
  if (winner != 'N') {
    if (player_print(agent) == winner) {
      // agent wins
      return std::make_pair<ttt_board, int>(std::move(board), 10);
    }
    else if (player_print(switch_player(agent)) == winner) {
      // opponent wins
      return std::make_pair<ttt_board, int>(std::move(board), -10);
    }
    else {
      // draw
      return std::make_pair<ttt_board, int>(std::move(board), 0);
    }
  }
  
  // which indices on the board have yet to be played?
  std::vector<unsigned int> empty_indices = board.empty_indices();
  // vector to store the possible states along with the score for each
  std::vector<board_point> potential_states;
  
  // for each possibility generate the new state
  for (int idx : empty_indices) {
      ttt_board new_board(board);
      new_board.make_move(agent, idx);
      
      potential_states.push_back(
        minimax(new_board, agent, !agents_turn)
      );
  }
  
  // Choose the best depending on whether it's agents turn or not
  int max_score = potential_states[0].second;
  board_point best_pair = potential_states[0];
  int adjusted_score;
  for (int i = 1; i < potential_states.size(); i++) {
    adjusted_score = potential_states[i].second * agents_turn;
    if (adjusted_score > max_score) {
      max_score = adjusted_score;
      best_pair = potential_states[i];
    }
  }
  
  return best_pair;
}

template <class BoardType>
int board_diff(BoardType old_board, BoardType new_board) {
  for (int i = 0; i < old_board.size(); i++){
    if (old_board[i] != new_board[i]) {
      return i;
    }
  }
  return -1;
}

// To be called by external users
char_board_array ttt_minimax(char_board_array state, const char agent){
  
  ttt_board board{state};
  player agent_p = char_to_player(agent);
  return minimax(board, agent_p).first.get_char_state();
}

// To be called the the exe in this project, uses our datatypes
int ttt_minimax(board_array state, const player agent) {
  ttt_board board{state};
  board_array next_state = minimax(board, agent).first.get_state();
  int next_move_idx = board_diff<board_array>(board.get_state(), next_state);
  return next_move_idx;
}

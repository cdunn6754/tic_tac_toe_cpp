#include "ttt_minimax.h"
#include <array>
#include <utility>

board_point minimax(ttt_board board, const player agent, bool agents_turn) {
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
  
  // The agent switches for each recursive call
  player current_agent = agents_turn ? agent : switch_player(agent);
  
  // for each possibility generate the new state
  for (int idx : empty_indices) {
      ttt_board new_board(board);
      
      new_board.make_move(
        current_agent,
        idx
      );
      int score = minimax(new_board, agent, !agents_turn).second;
      
      potential_states.push_back(
        std::make_pair<ttt_board, int>(std::move(new_board), std::move(score))
      );
  }
  
  // Choose the best depending on whether it's agents turn or not
  // all of this * (agents_turn? 1 : -1) adjusts the score,
  // if it isn't the agents turn we want to pick the lowest max_score
  // that models the opponent of the agent making the optimal choice
  int max_score = potential_states[0].second * (agents_turn ? 1 : -1);
  board_point best_pair = potential_states[0];
  int adjusted_score;
  for (int i = 1; i < potential_states.size(); i++) {
    adjusted_score = potential_states[i].second * (agents_turn ? 1 : -1);
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
int ttt_minimax(char (&state)[9], const char agent){
  // copy c_array into a std::array
  char_board_array std_state;
  std::copy(std::begin(state), std::end(state), std_state.begin());
  
  ttt_board board{std_state};
  player agent_p = char_to_player(agent);
  char_board_array next_state = minimax(board, agent_p).first.get_char_state();
  return board_diff<char_board_array>(std_state, next_state);
}

// To be called the the exe in this project, uses our datatypes
int ttt_minimax(board_array state, const player agent) {
  ttt_board board{state};
  board_array next_state = minimax(board, agent).first.get_state();
  int next_move_idx = board_diff<board_array>(board.get_state(), next_state);
  return next_move_idx;
}

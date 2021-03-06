#ifndef TTT_BOARD
#define TTT_BOARD

#include <array>
#include <vector>
#include <iostream>
#include <iomanip>

#include "player.h"

typedef std::array<player, 9> board_array;

class ttt_board {
  board_array state;
  
public:
  static std::string row_decoration;
  
  // Constructor default
  ttt_board();
  
  // Copy constructor
  ttt_board(const ttt_board& old_board);
  
  // not really worth it since the state is not public but what the hell
  ttt_board(ttt_board&& old_board);
  
  // Construct from std::array<char, 9> where the chars are
  // either 'X', 'O', or 'E'.
  ttt_board(const std::array<char, 9>& i_state);
  
  // Construct from std::array<player, 9>
  ttt_board(board_array i_state);
  
  ttt_board operator=(const ttt_board& b);
  
  
  // Return const reference to underlying state array.
  board_array get_state() const;
  
  // Sometimes (e.g. for minimax) we want the state as
  // an array of chars instead of the player enums
  std::array<char, 9> get_char_state() const;
  
  // Let player p make a move in board space location (0-8)
  // if the move is invalid returns false
  bool make_move(player p, int location);
  
  // See if all of the spaces are taken.
  // Could also just count moves.
  bool check_finished() const;
  
  // Check the board for a winner. Returns X or O in the case a winner
  // is found. If the game is completed but there is no winner returns
  // 'D' for draw. Otherwise returns 'N'.
  // board should have a state with only one winner so this needs to be called
  // after every move.
  char check_winner() const;
  
  // Reset the board to it's original state
  void reset_board();
  
  // Find and return the indices that have yet to be played
  std::vector<unsigned int> empty_indices();
  
  
  // Print a particular board row, either 0,1 or 2.
  void print_row(int row_num);
  
  // Print the board with the currenst X and O moves
  // print the index of the board location in a spot
  // if no moves have been made there yet
  void print_board();
  
  
private:
  void set_state(board_array new_state);
  void print_input_error(int selection);  
};

#endif

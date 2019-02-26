#include <algorithm>

#include "player.h"
#include "ttt_board.h"


// Very similar to board_array from tt_board but
// contains native chars rather than player types.
// This function can be used by passing normal arrays.
// So hopefully I can call this from Python.
typedef std::array<char, 9> char_board_array;
// Need to group a ttt_board and a score together for
// minimax
typedef std::pair<ttt_board, int> board_point;


// Acutal minimax recursive function, given a board and an agent
// returns a std::pair<ttt_board, int> with the next best state
// and the score , either 10, -10 or 0
board_point minimax(ttt_board board, player agent, bool agents_turn=true);

// Find and return the first index where there is difference
// returns -1 for equal arrays
template <class BoardType>
int board_diff(BoardType old_board, BoardType new_board);

// Main wrapper function for external use
// Uses a C array interface so we can use Python ctypes
int ttt_minimax(char (&state)[9], const char agent);

// Wrapper function for use with this exe
int ttt_minimax(board_array state, const player agent);

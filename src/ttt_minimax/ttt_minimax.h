#include "player.h"
#include "ttt_board.h"

// Very similar to board_array from tt_board but
// contains native chars rather than player types.
// This function can be used by passing normal arrays.
// So hopefully I can call this from Python.
typedef std::array<char, 9> native_board_array;

board_array ttt_minimax(board_array i_state);
native_board_array minimiax(ttt_board, char);

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


// Acutal minimax recursive function
char_board_array minimiax(ttt_board, char);

// Find and return the first index where there is difference
// returns -1 for equal arrays
template <class BoardType>
int board_diff(BoardType old_board, BoardType new_board);

// Main wrapper function for external use
char_board_array ttt_minimax(char_board_array state, const char agent);

// Wrapper function for use with this exe
int ttt_minimax(board_array state, const player agent);

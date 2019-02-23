#include <iostream>

#include "ttt_board.h"
#include "player.h"
#include "ttt_minimax.h"

int main() {
  
  ttt_board board;
  
  char winner = board.check_winner();
  // The human plays X, ai plays O
  bool x_turn = true;

  while (winner=='N') {
    int move_loc;
    
    std::cout << std::endl;
    board.print_board();
    
    // X player move
    if (x_turn) {
      do {
        std::cout << player_print(player::X) <<" player move: ";
        std::cin >> move_loc;
        std::cout << std::endl;
      } while (!board.make_move(player::X, move_loc));
    }
    else {
      board.make_move(player::O,ttt_minimax(board.get_state(), player::O));
    }

    std::cout << std::endl;
    
    x_turn = !x_turn;
    winner = board.check_winner();
  }
  
  std::cout << std::endl;
  board.print_board();
  
  if (winner == 'D') {
    std::cout << "The game was a draw!" << std::endl;
  }
  else {
    std::cout << "Player " << winner << " won this game!" << std::endl;
  }
  
  return 0;
}

#include <iostream>

#include "ttt_board.h"
#include "player.h"

int main() {
  
  ttt_board board;

  while (!board.check_finished()) {
    int move_loc;

    std::cout << std::endl;
    board.print_board();
    // X player move
    do {
      std::cout << "X player move: ";
      std::cin >> move_loc;
      std::cout << std::endl;
    } while (!board.make_move(player::X, move_loc));

    std::cout << std::endl;
    board.print_board();
        
    // O player move
    do {
      std::cout << "O player move: ";
      std::cin >> move_loc;
      std::cout << std::endl;
    } while (!board.make_move(player::O, move_loc));

  }
  
  std::cout << std::endl;
  board.print_board();
  
  char winner = board.check_winner();
  
  if (winner == 'D') {
    std::cout << "The game was a draw" << std::endl;
  }
  else {
    std::cout << "Player " << winner << "won this game." << std::endl;
  }
  
  return 0;
}

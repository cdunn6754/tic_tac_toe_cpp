#include <iostream>

#include "ttt_board.h"
#include "player.h"

int main() {
  
  ttt_board board;
  
  char winner = board.check_winner();
  bool x_turn = true;
  player current_player;

  while (winner=='N') {
    int move_loc;
    current_player = x_turn ? player::X : player::O;
    
    std::cout << std::endl;
    board.print_board();
    // X player move
    do {
      std::cout << player_print(current_player) <<" player move: ";
      std::cin >> move_loc;
      std::cout << std::endl;
    } while (!board.make_move(current_player, move_loc));

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

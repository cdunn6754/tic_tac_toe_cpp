#include <iostream>

#include "ttt_board.h"
#include "player.h"


int main() {
  player p1 = player::E;
  std::cout<< player_as_number(p1) << std::endl;
  
  ttt_board board;
  
  board.make_move(player::X, 2);
  board.print_board();
  
  //std::cout<< player_print(board.print_board()) << std::endl;
  
  return 0;
}

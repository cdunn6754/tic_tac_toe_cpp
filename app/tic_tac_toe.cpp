#include <iostream>

#include "ttt_board.h"
#include "player.h"


int main() {
  player p1 = player::E;
  std::cout<< player_as_number(p1) << std::endl;
  
  ttt_board board;
  
  std::cout<< player_print(board.get_state()[1]) << std::endl;
  
  return 0;
}

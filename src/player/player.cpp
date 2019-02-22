#include <stdexcept>

#include "player.h"
#include "type_traits"

int player_as_number(player const val) {
  return static_cast<typename std::underlying_type<player>::type>(val);
}

player char_to_player(char const val) {
  switch (val){
    case 'X':
      return player::X;
    case 'O':
      return player::O;
    case 'E':
      return player::E;
    default:
      throw std::runtime_error("The only valid possibilities are 'X', 'O', and 'E'.");
  }
}

// Return the string that matches the enum
// in the case of an empty player, 'E', dont print anything
char player_print(player const val) {
  switch (val){
    case player::X:
      return 'X';
    case player::O:
      return 'O';
    case player::E:
      return ' ';
  }
  
}

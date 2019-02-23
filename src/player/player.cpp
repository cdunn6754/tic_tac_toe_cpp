#include <stdexcept>

#include "player.h"
#include "type_traits"



int player_as_number(player const val) {
  return static_cast<typename std::underlying_type<player>::type>(val);
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

char player_to_char(player const val) {
  switch (val){
    case player::X:
      return 'X';
    case player::O:
      return 'O';
    case player::E:
      return 'E';
    default:
      std::string message = R"(The only valid possibilities
        are player::X, player::O, and player::E.)";
      throw std::runtime_error(message);
  }
}


player switch_player(const player p) {
  if (p == player::O) {
    return player::X;
  }
  else if (p == player::X) {
    return player::O;
  }
  else {
    throw std::runtime_error("Can only switch if player is 'X' or 'O'");
  }
}

void switch_player_inplace(player& p) {
  if (p == player::O) {
    p = player::X;
  }
  else if (p == player::X) {
    p =  player::O;
  }
  else {
    throw std::runtime_error("Can only switch if player is 'X' or 'O'");
  }
}

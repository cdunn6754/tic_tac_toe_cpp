#include "player.h"
#include "type_traits"

int player_as_number(player const val) {
  return static_cast<typename std::underlying_type<player>::type>(val);
}

char player_print(player const val) {
  switch (val){
    case player::X:
      return 'X';
    case player::O:
      return 'O';
    case player::E:
      return 'E';            
  }
  
}

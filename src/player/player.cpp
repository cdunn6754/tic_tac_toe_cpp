#include "player.h"
#include "type_traits"

int player_as_number(player const val) {
  return static_cast<typename std::underlying_type<player>::type>(val);
}

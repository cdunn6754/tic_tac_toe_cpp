#ifndef PLAYERENUM
#define PLAYERENUM

enum class player {X, O, E};

int player_as_number(player const val);
char player_print(player const val);

#endif

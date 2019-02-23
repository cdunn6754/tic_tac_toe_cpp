#ifndef PLAYERENUM
#define PLAYERENUM

enum class player {X, O, E};

// Return the underlying int representation of the enum
int player_as_number(const player val);

// Return the char that should be printed in a ttt game for a given
// player enum. E -> ' ', O -> 'O' and X->'X'
char player_print(const player val);

// Convert an 'E', 'O', or 'X' char to an enum
player char_to_player(const char val);

// Convert enum to it's char
char player_to_char(const player p);

// Given 'X' or 'O' player return the other one
player switch_player(const player p);

// Switch in place
void switch_player_inplace(player& p);

#endif

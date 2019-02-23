# Tic Tac Toe unbeatable AI minimax implementation in C++
This project includes some basic io ttt gameplay stuff but the real focus was
writing the minimax algorithm and attempting to do so using modern C++ practices.

The minimax implementation is compiled to a shared library and has two interfaces.
One uses some custom datatypes defined elsewhere in this project. The second uses
more generic datatypes, e.g. a `std::array<char, 9>` to describe the incoming state
of the ttt board and a `char` set to 'O' or 'X' to indicate which marker the ai is
using. That library is available at `<project_root>/build/src/libttt_minimax.so` after following
the installation instructions below.

## Installation:

The project is built 'out of source' using cmake version 3.10.
To build and run the simple C++ frontend:

```
$ git clone https://github.com/cdunn6754/tic_tac_toe_cpp.git
$ cd tic_tac_toe.cpp/build/
$ cmake ..
...
$ make
...
$ ./tic_tac_toe.exe
```

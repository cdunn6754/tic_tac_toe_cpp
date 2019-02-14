cmake_minimum_required(VERSION 3.10)
project(tic_tac_toe LANGUAGES CXX)

add_executable(tic_tac_toe app/tic_tac_toe.cpp src/ttt_board.cpp)
target_compile_features(tic_tac_toe PRIVATE cxx_std_11 )
target_include_directories(tic_tac_toe PUBLIC ./src/)

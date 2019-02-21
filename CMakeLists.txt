cmake_minimum_required(VERSION 3.10)
project(tic_tac_toe LANGUAGES CXX)
set(TTT_LIBS ${CMAKE_SOURCE_DIR}/libs)

add_subdirectory(libs)

set(COMMON_LIBS ttt_board ttt_player)

add_executable(tic_tac_toe.exe app/tic_tac_toe.cpp )
target_link_libraries(tic_tac_toe.exe PRIVATE ${COMMON_LIBS})
target_compile_features(tic_tac_toe.exe PRIVATE cxx_std_11 )
target_include_directories(tic_tac_toe.exe PRIVATE ${TTT_LIBS}/player ${TTT_LIBS}/ttt_board)

add_subdirectory(tests)

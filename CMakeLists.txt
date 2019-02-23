cmake_minimum_required(VERSION 3.10)
project(tic_tac_toe LANGUAGES CXX)

set(TTT_LIBS ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)

set(COMMON_LIBS ttt_board ttt_player)

add_executable(tic_tac_toe.exe app/tic_tac_toe.cpp )
target_link_libraries(tic_tac_toe.exe PRIVATE ${COMMON_LIBS})
target_link_libraries(tic_tac_toe.exe PRIVATE ttt_minimax)
target_compile_features(tic_tac_toe.exe PRIVATE cxx_std_11 )
target_include_directories(tic_tac_toe.exe PRIVATE ${TTT_LIBS}/player)
target_include_directories(tic_tac_toe.exe PRIVATE ${TTT_LIBS}/ttt_board)
target_include_directories(tic_tac_toe.exe PRIVATE ${TTT_LIBS}/ttt_minimax)

add_subdirectory(tests)

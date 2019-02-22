project(TTT_MINIMAX_LIB LANGUAGES CXX)

add_library(ttt_minimax SHARED ttt_minimax.cpp)
target_include_directories(ttt_minimax PRIVATE ${TTT_LIBS}/player)
target_include_directories(ttt_minimax PRIVATE ${TTT_LIBS}/ttt_board)
target_link_libraries(ttt_minimax PRIVATE ttt_player ttt_board)

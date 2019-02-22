project(TTT_MINIMAX_LIB LANGUAGES CXX)

add_library(ttt_minimax STATIC ttt_minimax.cpp)
target_include_directories(ttt_minimax PUBLIC ${TTT_LIBS}/player)
target_link_libraries(ttt_minimax PUBLIC ttt_player)

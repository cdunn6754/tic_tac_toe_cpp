project(TTT_BOARD_LIB LANGUAGES CXX)

add_library(ttt_board STATIC ttt_board.cpp)
target_include_directories(ttt_board PUBLIC ${TTT_LIBS}/player)
target_link_libraries(ttt_board PUBLIC ttt_player)
set_property(TARGET ttt_board PROPERTY POSITION_INDEPENDENT_CODE ON)

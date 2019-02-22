project(TTT_PLAYER_LIB LANGUAGES CXX)

add_library(ttt_player STATIC player.cpp)
set_property(TARGET ttt_player PROPERTY POSITION_INDEPENDENT_CODE ON)

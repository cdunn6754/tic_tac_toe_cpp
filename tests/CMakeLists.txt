
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/tests/extern/googletest)
if(NOT EXISTS ${GOOGLETEST_DIR})
    find_package(Git REQUIRED)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule add https://github.com/google/googletest.git ${GOOGLETEST_DIR}
    )
endif()

add_subdirectory(extern/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(unit_tests tests.cpp test_minimax.cpp)
target_include_directories(unit_tests PRIVATE ${TTT_LIBS}/player)
target_include_directories(unit_tests PRIVATE ${TTT_LIBS}/ttt_board)
target_include_directories(unit_tests PRIVATE ${TTT_LIBS}/ttt_minimax)
target_link_libraries(unit_tests PRIVATE gtest gtest_main)
target_link_libraries(unit_tests PRIVATE ${COMMON_LIBS})
target_link_libraries(unit_tests PRIVATE ${CMAKE_SOURCE_DIR}/build/src/ttt_minimax/libttt_minimax.so)

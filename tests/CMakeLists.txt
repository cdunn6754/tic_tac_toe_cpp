
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/tests/extern/googletest)
if(NOT EXISTS ${GOOGLETEST_DIR})
    find_package(Git REQUIRED)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule add https://github.com/google/googletest.git ${GOOGLETEST_DIR}
    )
endif()

add_subdirectory(extern/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(unit_tests tests.cpp)

target_include_directories(tic_tac_toe PRIVATE ./src/player ./src/ttt_board/)
target_link_libraries(unit_tests PRIVATE gtest gtest_main)

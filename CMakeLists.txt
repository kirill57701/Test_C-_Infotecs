cmake_minimum_required(VERSION 3.14)

project(journal VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(jour_stat STATIC pt1/journal.cpp)
add_library(jour_dyn SHARED pt1/journal.cpp)

add_executable(main pt2/main.cpp)

target_link_libraries(main PRIVATE jour_stat)

enable_testing()

add_executable(jour_test tests/test-journal.cpp)
target_link_libraries(jour_test PRIVATE jour_stat)

add_test(NAME unit_tests COMMAND jour_test)

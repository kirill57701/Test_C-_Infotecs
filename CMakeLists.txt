cmake_minimum_required(VERSION 3.14)

project(journal VERSION 1.0.0 LANGUAGES CXX)

add_library(jour_stat STATIC journal.cpp)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE jour_stat)
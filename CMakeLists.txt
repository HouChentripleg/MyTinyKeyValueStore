cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(MYTINYSKIPLIST LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

set(INCLUDE ./include/listnode.hpp
            ./include/skiplist.hpp)

add_library(TinySkipListLib STATIC ${INCLUDE})
set_target_properties(TinySkipListLib PROPERTIES LINKER_LANGUAGE CXX)
add_executable(MyTinySkipList main.cpp)
target_link_libraries(MyTinySkipList TinySkipListLib)
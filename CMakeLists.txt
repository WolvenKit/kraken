cmake_minimum_required(VERSION 3.21)
project(kraken)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

include_directories(.)

add_library(kraken
        kraken.cpp
        compress.h
        kraken.h
        )
add_executable(main
        kraken.cpp
        compress.h
        kraken.h
        main.cpp)
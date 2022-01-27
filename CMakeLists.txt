cmake_minimum_required(VERSION 3.21)
project(kraken)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

include_directories(.)

set(SOURCE
        bits_rev_table.h
        log_lookup.h
        qsort.h
        compr_util.h
        compress.h
        compress.cpp
        compr_multiarray.cpp
        compr_match_finder.h
        compr_match_finder.cpp
        compr_leviathan.h
        compr_leviathan.cpp
        compr_kraken.h
        compr_kraken.cpp
        compr_tans.cpp
        compr_entropy.h
        compr_entropy.cpp
        match_hasher.h
        kraken.h
        kraken.cpp
        )

add_library(kraken SHARED ${SOURCE})
add_library(kraken_static STATIC ${SOURCE})
add_executable(main ${SOURCE} main.cpp)
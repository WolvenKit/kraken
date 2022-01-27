cmake_minimum_required(VERSION 3.5)
project(kraken)

set(CMAKE_CXX_STANDARD 14)
# disable on win build
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

function(add_cxx_compiler_flags)
    set(CMAKE_REQUIRED_QUIET true)
    include(CheckCXXCompilerFlag)
    set(flags ${CMAKE_CXX_FLAGS})
    foreach(flag ${ARGV})
        string(REGEX REPLACE "[^_A-Za-z0-9]" "_" stripped_flag "${flag}")
        set(var "CXX_COMPILER_FLAG_${stripped_flag}")
        check_cxx_compiler_flag("${flag}" "${var}")
        if(${var})
            set(flags "${flags} ${flag}")
        endif()
    endforeach()
    set(CMAKE_CXX_FLAGS ${flags} PARENT_SCOPE)
endfunction()
add_cxx_compiler_flags(-pedantic -fno-permissive -pedantic-errors -Wall -Wextra -Wshadow -Wstrict-aliasing -Wno-misleading-indentation "-ftemplate-depth=1024")


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
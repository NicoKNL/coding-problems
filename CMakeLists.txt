cmake_minimum_required(VERSION 3.12)
project(code_cpp)

set(CMAKE_CXX_STANDARD 11)
#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -Wextra -Wconversion -pedantic")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
# Recursively add an executable for every CPP file
file( GLOB_RECURSE ALL_SRCS *.cpp)
foreach( file ${ALL_SRCS})
    get_filename_component(barename ${file} NAME)
    string( REPLACE ".cpp" "" barename ${barename})
    string( REPLACE " " "-" barename ${barename})
    add_executable( ${barename} ${file})
endforeach( file ${ALL_SRCS} )
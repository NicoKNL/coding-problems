cmake_minimum_required(VERSION 3.12)
project(code_cpp)

set(CMAKE_CXX_STANDARD 11)

# Recursively add an executable for every CPP file
file( GLOB_RECURSE ALL_SRCS *.cpp)
foreach( file ${ALL_SRCS})
    get_filename_component(barename ${file} NAME)
    string( REPLACE ".cpp" "" name ${file})
    add_executable( ${barename} ${file})
endforeach( file ${ALL_SRCS} )
cmake_minimum_required(VERSION 3.23.1)
project(offline_blockchain VERSION 0.0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
include_directories("./include")
file(GLOB CPP_SOURCES "src/*.cpp")

add_compile_options(
    -Wall
)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_executable(
    offline_blockchain 
    ${CPP_SOURCES}
)
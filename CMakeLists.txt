cmake_minimum_required(VERSION 3.23.1)
project(offline_blockchain)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(
    testlalala 
    src/transaction.cpp
    src/block.cpp 
    src/blockchain.cpp 
    src/transactionPool.cpp 
    src/main.cpp
)
#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "block.hpp"

#include <vector>

class BlockChain{
    static std::vector<Block> blockchain;
    static size_t chainSize;
public:
    void show_blocks(int amount = 1) const;
    void show_block_info(int id) const;
    static Block get_latest_block();
};

#endif BLOCKCHAIN_HPP
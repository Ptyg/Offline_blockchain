#ifndef BLOCKCHAIN
#define BLOCKCHAIN

#include "block.hpp"

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif VECTOR

class BlockChain{
    static std::vector<Block> blockchain;
    static size_t chainSize;
public:
    void show_blocks(int amount = 1) const;
    void show_block_info(int id) const;
    static Block get_latest_block();
};

#endif BLOCKCHAIN
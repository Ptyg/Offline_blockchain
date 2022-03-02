#ifndef BLOCKCHAIN
#define BLOCKCHAIN

#include "block.hpp"

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif VECTOR

class BlockChain{
    std::vector<Block> blockchain;
public:
    void show_blocks(int amount = 1) const;
    void show_block_info(int id) const;
};

#endif BLOCKCHAIN
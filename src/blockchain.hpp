#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "block.hpp"

#include <vector>

class BlockChain{
    static std::vector<Block> blockchain;
    static std::vector<Block> initBlockchain(); 
    static BlockChain *blockchainInstance;
protected:
    BlockChain();
public:
    BlockChain(BlockChain&) = delete;
    void operator=(const BlockChain&) = delete;
    static void show_blocks(int amount = 1);
    static void show_block_info(int id);
    static void add_block(Block&& newBlock);
    static Block& get_latest_block();
    static BlockChain* get_instance();
};

#endif
#include "blockchain.hpp"

#include <iostream>

BlockChain::BlockChain() {}

void BlockChain::show_blocks(int amount /*= 1*/){    
    const size_t chainSize = blockchain.size();

    if (amount > chainSize) {
        std::cout << "Your number is bigger than chain size\nChain size is: " << chainSize;
        return;
    }

    for (size_t i = chainSize - 1; i >= chainSize - amount || i >= 0; i--)
    {
        std::cout << "\n################################## " << i << " ##################################\n";
        blockchain[i].display_block_info();
        std::cout << "\n#############################################################################\n";
    }
}

void BlockChain::show_block_info(int id) { blockchain[id].display_block_info(); }

Block& BlockChain::get_latest_block() { return blockchain[blockchain.size() - 1]; }

void BlockChain::add_block(Block&& newBlock){
    blockchain.push_back(newBlock);
}
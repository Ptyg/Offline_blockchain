#include "blockchain.hpp"

#include <iostream>

int BlockChain::currentBlockNumber = 0;

BlockChain::BlockChain() {}

void BlockChain::show_blocks(int amount /*= 1*/, bool transactionInfo){    
    const int chainSize = blockchain.size();

    if (amount > chainSize) {
        std::cout << "Your number is bigger than chain size\nChain size is: " << chainSize;
        return;
    }

    for (int i = currentBlockNumber - 1; i >= chainSize - amount; i--)
    {
        std::cout << "#######################################################################\n";
        if (transactionInfo){
            blockchain[i].display_block_info_with_transactions_info();
        }
        else{
            blockchain[i].display_block_info();
        }
    }
}

void BlockChain::show_block_info(size_t id) { blockchain[id].display_block_info(); }

Block& BlockChain::get_latest_block() { return blockchain[currentBlockNumber - 1]; }

void BlockChain::add_block(Block&& newBlock){
    blockchain.push_back(std::move(newBlock));
    currentBlockNumber++;
}

std::vector<Block> BlockChain::initBlockchain(){ 
    std::vector<Block> temp;
    temp.reserve(100); 
    return temp;    
}

std::vector<Block> BlockChain::blockchain(initBlockchain());

BlockChain* BlockChain::blockchainInstance = nullptr;

BlockChain* BlockChain::get_instance(){
    if (blockchainInstance == nullptr){
        blockchainInstance = new BlockChain();
    }
    return blockchainInstance;
}
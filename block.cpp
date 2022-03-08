#include "block.hpp"

#include <iostream>
#include <string>

int Block::idx = 0;

Block::Block(std::vector<Transaction>&& transactions, size_t prevHash) 
    : block_id(idx++), prevHash(prevHash), transactions(transactions){}

const size_t& Block::getHash() const{ return blockHash; }
const size_t& Block::getPreviousHash() const{ return prevHash; }

bool Block::isHashValid(){ return generate_hash() == blockHash; }

const size_t& Block::getHash() const{ return blockHash;}
const size_t& Block::getPreviousHash() const{return prevHash; }

size_t Block::generate_hash(){
    std::hash<size_t> finalHash;
    std::hash<std::string> hash1;
    std::hash<size_t> hash2;
    std::string toHash;

    for (Transaction& trans : transactions){
        toHash = std::to_string(trans.get_coin_number()) + trans.get_sender() + trans.get_recipient() + std::to_string(trans.get_create_time()); 
    }

    return finalHash(hash1(toHash) + hash2(prevHash));
}

void Block::display_block_info() const{
    std::cout << "Block id: " << block_id << '\n';
    std::cout << "Previous hash: " << prevHash << '\n';
    std::cout << "Block hash: " << blockHash << '\n';
    std::cout << "Transaction amount: " << transactions.size() << '\n';
}

// NOT USE BCS THIS FUNC IS NOT LOGICALLY COMPLETE
void Block::addTransactions(std::vector<Transaction>&& transactionPool){
    transactions = transactionPool;
}
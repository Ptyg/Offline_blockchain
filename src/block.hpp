#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "transaction.hpp"

#include <vector>

class Block{
    size_t block_id;
    size_t prevHash, blockHash;
    size_t generate_hash();
    
    std::vector<Transaction> transactions;
    static int idx;
    
public:
    Block(Block&) = delete;
    
    Block(std::vector<Transaction>&&, size_t);
    void display_block_info() const;
    const size_t& getHash() const;
    const size_t& getPreviousHash() const;
    bool isHashValid();
    void addTransactions(std::vector<Transaction>&&);
};
#endif
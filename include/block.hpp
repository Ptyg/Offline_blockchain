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
    Block(std::vector<Transaction>&&, size_t&&);
    void display_block_info() const;
    void display_block_info_with_transactions_info() const;
    size_t getHash() const;
    size_t getPreviousHash() const;
    bool isHashValid(int id);
};
#endif
#ifndef BLOCK
#define BLOCK

#include "transaction.hpp"

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif VECT


class Block{
    size_t block_id;
    size_t prevHash, blockHash;
    size_t generate_hash();
    
    std::vector<Transaction> transactions;
    const int transactionNumber = 3;
    static int idx;
    
public:
    Block(std::vector<Transaction>&&, size_t);
    void display_block_info() const;
    const size_t& getHash() const;
    const size_t& getPreviousHash() const;
    bool isHashValid();
    void addTransactions(std::vector<Transaction>&&);
};
#endif BLOCK
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
    void addTransaction();
    std::vector<Transaction> transactions;
    const int transactionNumber = 3;

public:
    Block(size_t idx, std::vector<Transaction>&& transactions, size_t prevHash);
    void display_block_info() const;
    const size_t& getHash() const;
    const size_t& getPreviousHash() const;
    bool isHashValid();
};
#endif BLOCK
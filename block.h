#ifndef TRANSACTION
#define TRANSACTION
#include "transaction.h"
#endif TRANSACTION

#ifndef STRING
#define STRING
#include <string>
#endif STRING

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif VECT

#ifndef BLOCK
#define BLOCK
class Block{
    size_t block_id;
    size_t prevHash;
    size_t generate_hash();
    void addTransaction();
    //std::vector<Transaction> transactions;
public:
    void display_block_info() const;
    size_t& getHash() const;
    size_t& getPreviousHash() const;
};
#endif BLOCK
#ifndef TRANSACTION_POOL
#define TRANSACTION_POOL

#include "transaction.hpp"
#include "block.hpp"

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif VECTOR

class TransactionPool{
    TransactionPool(){};
    std::vector<Transaction> transactionPool;
    const int maxTransactionNumber = 3;
    static int currentTransactionNumber;
public:
    TransactionPool(TransactionPool&) = delete;
    void operator=(const TransactionPool&) = delete;

    void addTransaction(Transaction&&);
    void loadTransactionsInBlock();
};

#endif
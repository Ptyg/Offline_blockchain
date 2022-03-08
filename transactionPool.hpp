#ifndef TRANSACTION_POOL_HPP
#define TRANSACTION_POOL_HPP

#include "transaction.hpp"
#include "block.hpp"

#include <vector>

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
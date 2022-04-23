#ifndef TRANSACTION_POOL_HPP
#define TRANSACTION_POOL_HPP

#include "transaction.hpp"
#include "block.hpp"

#include <vector>

class TransactionPool{
    static std::vector<Transaction> transactionPool;
    static std::vector<Transaction> initPool();
    static int maxTransactionNumber;
    static int currentTransactionNumber;
    static TransactionPool *transactionPoolInstance;
protected:
    TransactionPool();
public:
    TransactionPool(TransactionPool&) = delete;
    void operator=(const TransactionPool&) = delete;

    static void addTransaction(Transaction&&);
    static void loadTransactionsInBlock();
    static void showTransactionsInPool();
    static TransactionPool* get_instance();
};

#endif
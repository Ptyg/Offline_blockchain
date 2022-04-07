#include "transactionPool.hpp"
#include "blockchain.hpp"

#include <iostream>

////// static private things ///////
int TransactionPool::currentTransactionNumber = 0;

int TransactionPool::maxTransactionNumber = 3;

TransactionPool* TransactionPool::transactionPoolInstance = nullptr;

std::vector<Transaction> TransactionPool::transactionPool = initPool();

std::vector<Transaction> TransactionPool::initPool(){
    std::vector<Transaction> tmp;
    tmp.reserve(maxTransactionNumber);
    return tmp;
}
////////////////////////////////////////////////////////////////////////////////////////

TransactionPool::TransactionPool() {}

void TransactionPool::loadTransactionsInBlock(){
    Block newBlock(std::move(transactionPool), std::move(BlockChain::get_latest_block().getHash()));
    BlockChain::add_block(std::move(newBlock));
}

void TransactionPool::addTransaction(Transaction&& transaction){
    if (currentTransactionNumber < maxTransactionNumber - 1){
        transactionPool.push_back(std::move(transaction)); 
        currentTransactionNumber++;
    }
    else{
        loadTransactionsInBlock();
        transactionPool.clear();
        transactionPool.push_back(std::move(transaction));
        currentTransactionNumber = 1;
        std::cout << "Transaction added in pool\n";
    }
}

void TransactionPool::showTransactionsInPool(){ 
    std::cout << "\n\t\t<<Transaction pool>>\n";
    for (const auto& transaction : transactionPool){
        std::cout << "#######################################################################\n";
        transaction.display_transaction_info(); 
        std::cout << "#######################################################################\n";
    }
}

TransactionPool* TransactionPool::get_instance(){
    if (transactionPoolInstance == nullptr){
        transactionPoolInstance = new TransactionPool();
    }
    return transactionPoolInstance;
}
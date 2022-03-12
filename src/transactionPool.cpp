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
    Block newBlock(std::move(transactionPool), BlockChain::get_latest_block().getHash());
    BlockChain::add_block(std::move(newBlock));
}

void TransactionPool::addTransaction(Transaction&& transaction){
    if (currentTransactionNumber < maxTransactionNumber){
        transactionPool.push_back(transaction); 
        currentTransactionNumber++;
    }
    else{
        loadTransactionsInBlock();
        transactionPool.clear();
        transactionPool.push_back(transaction);
        currentTransactionNumber = 1;
    }
}

void TransactionPool::showTransactionsInPool(){ 
    std::cout << "\n\t\t<<Transaction pool>>\n";
    for (size_t i = currentTransactionNumber - 1; i <= 0; i--){
        std::cout << "\n################################## " << i << " ##################################\n"; 
        transactionPool[i].display_transaction_info(); 
        std::cout << "#######################################################################\n";
    }
}

TransactionPool* TransactionPool::get_instance(){
    if (transactionPoolInstance == nullptr){
        transactionPoolInstance = new TransactionPool();
    }
    return transactionPoolInstance;
}
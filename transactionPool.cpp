#include "transactionPool.hpp"
#include "blockchain.hpp"

int TransactionPool::currentTransactionNumber = 0;

void TransactionPool::loadTransactionsInBlock(){
    Block newBlock(std::move(transactionPool), BlockChain::get_latest_block().getHash());
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
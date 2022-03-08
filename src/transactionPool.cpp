#include "transactionPool.hpp"
#include "blockchain.hpp"

TransactionPool::TransactionPool() {}

int TransactionPool::currentTransactionNumber = 0;

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
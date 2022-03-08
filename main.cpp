#include "transactionPool.hpp"
#include "transaction.hpp"
#include "block.hpp"
#include "blockchain.hpp"

#include <iostream>
#include <string>
#include <memory>

void addTransaction(TransactionPool& pool){
    size_t coinNum;
    std::string sender, recipient;
    time_t createdTime;

    std::cout << "Number of coins: "; std::cin >> coinNum;
    std::cout << "Sender: "; std::cin >> sender;
    std::cout << "Recipient: "; std::cin >> recipient;

    Transaction newTransaction(std::move(coinNum), std::move(sender), std::move(recipient), std::move(time(&createdTime)));
    pool.addTransaction(std::move(newTransaction));
}

int main()
{
    BlockChain chain;
    TransactionPool pool;
    return 0;
}
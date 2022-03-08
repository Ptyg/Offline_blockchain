#include "transactionPool.hpp"
#include "transaction.hpp"
#include "block.hpp"
#include "blockchain.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <ctime>

void add_transaction(TransactionPool& pool){
    size_t coinNum;
    std::string sender, recipient;
    time_t createdTime;

    std::cout << "Number of coins: "; std::cin >> coinNum;
    std::cout << "Sender: "; std::cin >> sender;
    std::cout << "Recipient: "; std::cin >> recipient;

    Transaction newTransaction(std::move(coinNum), std::move(sender), std::move(recipient), std::move(time(&createdTime)));
    pool.addTransaction(std::move(newTransaction));
}

void show_all_blocks(BlockChain& chain){
    chain.show_blocks(3);
}

int main()
{
    BlockChain chain;
    TransactionPool pool;
    
    char ch;
    std::cout << "What do you want to do?\n\n";
    std::cout << "01. Add transaction\n";
    std::cout << "02. Show blocks\n";
    std::cout << "Choice: "; std::cin >> ch;

    switch(ch){
        case '1': add_transaction(pool); break;
        case '2': show_all_blocks(chain); break;
        default: std::cout << '\a'; break;
    }


    return 0;
}